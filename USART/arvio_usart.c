#include <avr/io.h> 
#include <util/delay.h>  

#include "include/avrio_usart.h" 


static void usart_baudrate_calibration (int  __ubrr ) { 
    if  ( __ubrr  == 0  ) 
        __ubrr  =  UDEF_BAUD  ; 
    
    UBRR0H =  PRESCALER_BAUDRATE(__ubrr)   >> 8 ; 
    UBRR0L =  PRESCALER_BAUDRATE(__ubrr);   
 
}

void  USART_setting ( int __ubrr ) {  
    usart_baudrate_calibration(__ubrr) ; 

    Uscr0c_register_t   usart_rgt  =  { 
        ASYNC_MODE , 
        FRAME_BUFFER_8b , 
        STOP_BIT_1 ,
        PARTY_MODE_EEPARITY 
    }  ; 

    UCSR0C |= usart_rgt.io_mode | usart_rgt.data_frame_buffer_size | usart_rgt.stop_bit | usart_rgt.parity_mode ; 

    
    UCSR0B  = ENABLE_RTX ; 
      
} 

void usart_pooling_tx ( char * cbits ) {  
    while ( (UCSR0A   &  _BV(UDRE0) ) == 0 ) {}  ; 
    
    while ( *cbits  != 0 )
    {
        UDR0 = *cbits; 
        _delay_ms(1.5) ;    
        cbits++ ; 
    }

} 
