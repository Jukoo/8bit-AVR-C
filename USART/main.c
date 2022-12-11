#include  <avr/io.h> 
#include  <util/delay.h>  
#include  <stdio.h> 

#include "avrio_usart.h" 

// test

void main () { 
    USART_setting (0) ;
    uint8_t  data  ;  
     
    DDRB  |= (1 << DDB5) ; 
     
    while ( 1 )  
    {
        PORTB &=  !_BV(PORTB5);   
        usart_pooling_tx("[Test] USART POOLING TRANSMISSION [ok]  \n\r") ;
        usart_pooling_tx("press 'a' or 'A' to send signal\n\r") ; 
        data  = usart_pooling_rx() ;
        char  sstr = {0} ; 
        sprintf (sstr,"data -> %i : %c \n\r" , data , data ) ; 

        usart_pooling_tx(sstr) ;   
        
        if ( data  == 'a' || data  == 'A') 
        {
            PORTB |= (1<<PORTB5) ;
            _delay_ms(3000) ;  
        }
        
        _delay_ms(1000) ; 
    
    }  
} 
