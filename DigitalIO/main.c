#include <avr/io.h> 
#include <util/delay.h> 
/** 
 * Once the button is pressed  it should toggle the builtin led in permenant  stat 
 */


typedef enum BtnStat { 
   OFF,  
#define  OFF OFF 
   ON  
#define ON ON 
}BtnStat; 

void main () 
{
 
   
  DDRB |=  (1 << DDB5)  ; 
  DDRD  &= !(1 << DDD3);  

  BtnStat   is_pressed = OFF  ; 
  while(1) 
  {
     is_pressed = (PIND >>3) & ((1<<PIND3) >> 3) ; 
     if(is_pressed  == ON) {
       PORTB ^=  (1 << PORTB5) ;
     }
  }
}
