#include <avr/io.h> 
#include <util/delay.h>
#include <stdio.h> 

#include  "avrio_usart.h"
#include  "adc.h" 

void
main () { 

    USART_setting(0) ; 
    ADMUX |= a2dc_select_vref(ENABLE_IE_VREF) ;  
    ADMUX |= a2dc_analog_read(ANALOG_GPIO_0) ;  
    ADMUX |= ( 0 << ADLAR) ;  
    
    //!set speed  prescaler 
    set_prescaler(); 
    uint16_t value = 0 ; 
    usart_pooling_tx("A2DC version 1 \n\r") ; 
    while (1) 
    {
         char serial_value[0x64] = {0} ; 
         a2dc_enable_convertion_logic()  ;
         a2dc_start_convertion_logic() ; 
         a2dc_check_convertion_logic_is_over()  ; 

         
         value = ADCL  | (  ADCH >> 8 ) ;
         sprintf(serial_value , "A2DC value  => %i\n\r" , value) ; 
         value  =  1023  - value  ;  
        
         sprintf(serial_value , "A2DC value  => %i\n\r" , value) ; 
         usart_pooling_tx(serial_value) ;
         _delay_ms(1000) ;  
    }   

} 
