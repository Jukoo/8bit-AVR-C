#ifndef  __usart_serial_driver
#define  __usart_serial_dirver 


#ifndef  F_OSC 
#define  F_OSC   16000000UL 
#endif  

#define  DEFAULT_BAUDRATE 9600 
#define  PRESCALER(BAUD)  (F_OSC / (BAUD * 0x10) -1 ) 


typedef enum  { 
     ASYNC_MODE  , 
     SYNC_MODE   ,  
     MSPI_MODE   = 3   
} SerialComode  ; 


typedef enum {   
    STOP_BIT1  ,   
    STOP_BIT2    
} SerialStbit; 


typedef enum { 
     DISABLE , 
     EVENT_PARITY = 2 , 
     ODD_PARITY   
}SerialPamode  ; 

typedef  enum  { 
    _5BIT , 
    _6BIT , 
    _7BIT , 
    _8BIT , 
    _9BIT =  7 
} SerialChsize  ; 

#define DEFAULT_BITSIZE   0b011 

typedef struct   { 
    SerialComode  scom ; 
    SerialPamode  spam ; 
    SerialStbit   ssbit; 
    SerialChsize  scsiz;  
}Serial_config  ; 

typedef  struct  { 
    int baud  ;  
    
    void (*load_sconf) ( struct  Serial  * ,  struct Serial_config *)  ;  
    void (*how)(int) ;
    void (*sbit)(int) ; 
    void (*pam) (int) ; 
    void (*chsize)(int) ; 
     
    void (*start) (int ) ;  
    void (*write) (const char  * ) ; 
    void (*read ) (void) ; 
    
}Serial ; 


void new_serial(Serial * serial  ,  int initial_baudrate  , Serial_config  * sc ) ;
void serial_register_config  ( Serial  *  , Serial_config  *  )  ;
void serial_init ( int  __desired_baud_rate ) ; 
void select_communication_mode ( int __SerialComode  )   ; 
void set_stop_bit ( int __SerialSbit) ;  
void set_parity_mode (int  __SerialPamode ) ; 
void serial_buffer_size ( int __SerialChsize) ;  


void  serial_write (const  char * data ) ;  
void  enable_chanel () ; 
#endif  
