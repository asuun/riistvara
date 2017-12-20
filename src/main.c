#include <avr/io.h>
#include <util/delay.h>

//Viitemuutujate defineerimine 2,3 ja 4 sec
#define BLINK_DELAY_MS1 2000    
#define BLINK_DELAY_MS2 3000
#define BLINK_DELAY_MS3 4000

void main ()
{
    /* Set port B pin 7 for output for Arduino Mega yellow LED 
    DDRB |= _BV(DDB7);
    */
    DDRA |= _BV(DDA0);      // Pin 22 seatakse outputiks Punane LED 
    DDRA |= _BV(DDA2);      // Pin 24 seatakse outputiks Valge LED
    DDRA |= _BV(DDA4);      // Pin 26 seatakse outputiks Roheline LED
    
    while (1) {
            /*
             PORTB |= _BV(PORT7);           // Punane LED polema
            _delay_ms(BLINK_DELAY_MS3);
            PORTB &= ~_BV(PORTB7);  
              _delay_ms(BLINK_DELAY_MS3);
               */
               
            PORTB &= ~_BV(PORTB7);
            PORTA |= _BV(PORTA0);           // Punane LED polema
            PORTA &= ~_BV(PORTA2);      // Valge LED kustu
            PORTA &= ~_BV(PORTA4);      // Roheline LED kustu
    
            _delay_ms(BLINK_DELAY_MS1);
            PORTA &= ~_BV(PORTA0);      // Punane LED kustu
            PORTA |= _BV(PORTA2);       // Valge LED polema
         
            _delay_ms(BLINK_DELAY_MS2);
            PORTA &= ~_BV(PORTA2);      // Valge LED kustu
             PORTA |= _BV(PORTA4);           // Roheline LED polema
             
            _delay_ms(BLINK_DELAY_MS3);

        }
       
    }
