/* First steps into using program memory */

// ------- Preamble -------- //
#include <avr/io.h>             
#include <util/delay.h>         
#include <avr/pgmspace.h>
#include "USART.h"

char myVeryLongString[] PROGMEM = "Hi there, \
this is an example of a long string.\r\n\
The kind that you wouldn't want to store in RAM.\r\n";

int main(void){
  initUSART();
  char oneLetter;
  uint8_t i;
  
  while(1){
    for (i = 0; i < sizeof(myVeryLongString); i++){
      oneLetter = pgm_read_byte( &(myVeryLongString[i]) );
      transmitByte(oneLetter);		
      _delay_ms(100);  /* slow it down to simulate typing effect :) */
    }
    _delay_ms(1000);
  }                   /* End event loop */
  return(0);          /* This line is never reached  */
}

