#include <avr/io.h> 
#include "adc.h" 


uint16_t  a2dc_select_vref ( A2DC_SPVREF   vref )  {  
    
    if ( vref == 2 ) //! RESERVED  ADDRESS ...  
       vref++ ;      //! add +1 
    
    return  (vref  << a2dcmux_basevref_register ) ;   
}

uint16_t a2dc_convertion_logic_dispaching_register(  A2DC_CONVERTION_LOGIC_LAYOUT_REGISTER  _clreg)  {
    if  (_clreg > 2 )  
        _clreg = LEFT_ADJUSTMENT_RESULT  ; 

    return   (_clreg <<  ADLAR) ; 
} 

static  uint16_t a2dcmux_decoder (uint16_t analogpin )  { 
    if ( analogpin >  8  ||  !analogpin ) 
        return ENABLE_ANALOG_PIN0 ;

    return  ( analogpin << a2dcmux_base_channel_register) ; 
}

uint16_t a2dc_analog_read(uint16_t pin )  {
    return a2dcmux_decoder(pin) ; 
}
  
void set_prescaler() {
    ADCSRA |=  D_FACTOR_7 ; 
} 


void a2dc_enable_convertion_logic ()   { 
    ADCSRA |= (1 << ADEN) ;  
       
}

void a2dc_start_convertion_logic () { 
    ADCSRA |=  ( 1 << ADSC)  ;  
}

void  a2dc_check_convertion_logic_is_over() {  

    while ( (ADCSRA &( 1 << ADSC )))  ; 

    return ; 
}


// int value =  ADCL |   ( ADCH << 8 ) 
