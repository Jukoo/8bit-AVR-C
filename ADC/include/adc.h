#ifndef  _a2dc_h
#define  _a2dc_h  

/**  
 * ADMUX SETTING 
 */

/*Analog 2 Digital converter  Select  Power Voltage  reference...*/ 

#define a2dcmux_basevref_register  REFS0 
typedef  enum   { 
    TURN_OFF_INTERNAL_VREF ,  
    ENABLE_EXTERNAL_VREF   , 
    ENABLE_IE_VREF         = 3 
}A2DC_SPVREF;


uint16_t  a2dc_select_vref (A2DC_SPVREF  ) ;  

// ADLAR  :  ADC Left Adjust Result   
// tell how the convertion logic  register  should be organise 
typedef enum { 
    LEFT_ADJUSTMENT_RESULT, 
    RIGTH_ADJUSTMENT_RESULT 

} A2DC_CONVERTION_LOGIC_LAYOUT_REGISTER  ; 

uint16_t a2dc_convertion_logic_dispaching_register ( A2DC_CONVERTION_LOGIC_LAYOUT_REGISTER) ; 


/*A2DC  ANALOG CHANNEL PIN SELECTION*/ 

#define a2dcmux_base_channel_register  MUX0 
static uint16_t  a2dcmux_decoder (uint16_t  a2dc_analog_pin ) ; 

#define ANALOG_GPIO_0  0  
#define ANALOG_GPIO_1  1 
#define ANALOG_GPIO_2  2 
#define ANALOG_GPIO_3  3 
#define ANALOG_GPIO_4  4 
#define ANALOG_GPIO_5  5
#define ANALOG_GPIO_6  6 
#define ANALOG_GPIO_7  7 

#define ANALOG_GPIO_INTERNAL_TMPSENSOR  8    

#define ENABLE_ANALOG_PIN0   ( ANALOG_GPIO_0 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN1   ( ANALOG_GPIO_1 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN2   ( ANALOG_GPIO_2 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN3   ( ANALOG_GPIO_3 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN4   ( ANALOG_GPIO_4 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN5   ( ANALOG_GPIO_5 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN6   ( ANALOG_GPIO_6 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN7   ( ANALOG_GPIO_7 << a2dcmux_base_channel_register )  
#define ENABLE_ANALOG_PIN8   ( 8 << a2dcmux_base_channel_register )  


uint16_t a2dc_analog_read  (uint16_t  __pin)  ; 


/*ADCSRA*/ 

#define a2dcmux_base_psb  ADPS0 
typedef  enum   { 
    D_FACTOR_0  =  (  0 << a2dcmux_base_psb),
    D_FACTOR_1  =  (  1 << a2dcmux_base_psb),
    D_FACTOR_2  =  (  2 << a2dcmux_base_psb),  
    D_FACTOR_3  =  (  3 << a2dcmux_base_psb),  
    D_FACTOR_4  =  (  4 << a2dcmux_base_psb),  
    D_FACTOR_5  =  (  5 << a2dcmux_base_psb),  
    D_FACTOR_6  =  (  6 << a2dcmux_base_psb),  
    D_FACTOR_7  =  (  7 << a2dcmux_base_psb),  
} A2DC_DIVSION_FACTOR_PRESCALL_SELECT ;  

void set_prescaler () ; 

void  a2dc_enable_convertion_logic ()  ; 

void  a2dc_start_convertion_logic  ()   ; 

void  a2dc_check_convertion_logic_is_over() ; 

#endif  
