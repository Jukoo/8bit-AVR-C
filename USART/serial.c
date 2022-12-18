#include <avr/io.h> 
#include <util/delay.h> 

#include "include/serial.h"



void new_serial ( Serial  * serial  , int baudrate  , Serial_config  *sconf ) {
    if (baudrate == 0  )  baudrate = DEFAULT_BAUDRATE ; 
    serial->baud =   baudrate ; 
    
    serial->start = serial_init ; 
    serial->start(serial->baud) ; 
    
    serial->how  = select_communication_mode ; 
    serial->sbit = set_stop_bit ; 
    serial->pam  = set_parity_mode ;
    serial->chsize = serial_buffer_size  ; 
    serial->write = serial_write ;   
    
    serial->load_sconf = serial_register_config  ;  
    
    if (sconf  ==  (void *) 0 )  
    {
         Serial_config  serial_cfg =  { 
             .scom = ASYNC_MODE , .scsiz= _9BIT, 
             .ssbit= STOP_BIT2  , .spam = EVENT_PARITY  
         } ; 
         
         serial->load_sconf(serial  , &serial_cfg) ; 
    }else  
       serial->load_sconf(serial , sconf)  ;   
    

    
    enable_chanel() ; 
    
    UCSR0B |= _BV(UDRIE0 ) ;   
        
    
} 

void enable_chanel() { 
    UCSR0B  |= _BV(TXEN0) | _BV(RXEN0)  ; 
}

void serial_register_config( Serial *s   , Serial_config  *sc )  {  
    
    s->how(sc->scom) ; 
    s->chsize(sc->scsiz) ; 
    s->sbit(sc->ssbit) ;
    s->pam(sc->spam) ;  
}  

void  serial_init ( int baudrate)  {  
    if (  baudrate == 0  || baudrate < 0  ) 
        baudrate  = DEFAULT_BAUDRATE ; 
    
    UBRR0H =  PRESCALER(baudrate) >> 8  ; 
    UBRR0L =  PRESCALER(baudrate) ; 
    
} 

void select_communication_mode  ( int   comode ) {  
    if (
            comode ==   2  /* reserved*/   
            || comode < 0  /* no negative allowed*/
            || comode > 3  /* not defined */
            )  
    {
        comode = 0  ; /*use async mode by default */ 
    } 
    
    UCSR0C |= (comode  <<  UMSEL00) ;
       
} 

void set_stop_bit (int  stopbit ) {
    if (stopbit < 0  || stopbit > 2 )  
    { 
        stopbit =  0  ; 
    }

    if (stopbit == 2  )  stopbit -=1  ;  

    UCSR0C |= (stopbit << USBS0 ) ; 
    
} 


void  set_parity_mode (int  pmode )  {
   
   if (pmode < 0  || pmode > 3 ) pmode = 0 ;  
   
   UCSR0C |=(pmode <<  UPM00)  ; 
    
}  

void serial_buffer_size (int  serialbuffsize ) {  
    if (serialbuffsize  < 0  || serialbuffsize >  7 ) serialbuffsize = DEFAULT_BITSIZE ; 
    switch ( serialbuffsize)  
    {
        /*Are Reserved */
        case 4:
        case 5:
        case 6: 
            serialbuffsize = DEFAULT_BITSIZE  ; 
            break ;
    }
   
    UCSR0C |=(serialbuffsize << UCSZ00) ; 

}


void serial_write (const char *  data )  {  

   while  ( (UCSR0A  & _BV(UDRE0) ) == 0 );  
   
   while  (*data != 0)  
   { 
       UDR0  = *data ;
       _delay_ms(1.5)  ;  
       data++;  
   }
     
}

