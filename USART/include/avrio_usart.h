/**
 * USART  GENERIQUE DRIVER FOR AVR mcu  
 * Copyright  (C) , 2022  Umar <jUmarB@protonmail.com>  @OpenWireLab
 * 
 */

#ifndef  _USART_AVR_MCU
#define  _USART_AVR_MCU 


#ifndef F_CPU 
#define F_CPU  16000000UL 
#endif 
//! usart  default baud  
#define UDEF_BAUD  9600

#define  PRESCALER_BAUDRATE(ubrr) ((F_CPU  /  ( 16UL * ubrr )) - 1)  

typedef  enum  { 
    ASYNC_MODE  =  (0 << UMSEL00) , 
    SYNC_MODE   =  (1 << UMSEL00) , 
    MASTER_SPI  =  (3 << UMSEL00) 
    
} IO_MODE ; 

typedef enum  { 
    PARTY_MODE_EEPARITY = (2 <<UPM00) , 
    PARTY_MODE_EOPARITY = (3 <<UPM00)  
} PARTY_MODE  ;  

typedef  enum { 
    STOP_BIT_1  = ( 0 << USBS0) ,
    STOP_BIT_2  = ( 1 << USBS0) 
     
} STOP ; 

typedef enum  { 
    FRAME_BUFFER_5b  = ( 0 << UCSZ00 ) , 
    FRAME_BUFFER_6b  = ( 1 << UCSZ00 ) , 
    FRAME_BUFFER_7b  = ( 2 << UCSZ00 ) , 
    FRAME_BUFFER_8b  = ( 3 << UCSZ00 ) ,  
    FRAME_BUFFER_9b  = ( 7 << UCSZ00 )  
} DATA_FRAME ;

typedef  struct  { 
  IO_MODE  io_mode  ; 
  DATA_FRAME data_frame_buffer_size ; 
  STOP stop_bit  ; 
  PARTY_MODE parity_mode ;    

} Uscr0c_register_t  ; 
 
#define  ENABLE_RTX 0x18   //!  ( 1 <<  RXEN0 )  |  ( 1 << TXEN0)  


static void usart_baudrate_calibration ( int __baudrate  ) ;  

void  USART_setting ( int __baudrate)   ;  
void  usart_pooling_tx (char  * cbits )   ; 

#endif   
