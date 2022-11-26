#include  <avr/io.h> 
#include  <util/delay.h>  
#include "include/avrio_usart.h" 

// test
void main () { 
    USART_setting (0) ; 
   
    while ( 1 )  
    {
        usart_pooling_tx("[Test] USART POOLING TRANSMISSION [ok]  \n\r") ; 
        _delay_ms(1000) ; 
    
    }  
} 
