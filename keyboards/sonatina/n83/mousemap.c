// Simple analog to digitial conversion

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include "analog.h"

#include "print.h"

static uint8_t aref = (1<<REFS0); // default to AREF = Vcc


void analogReference(uint8_t mode)
{
	aref = mode & 0xC0;
}


// Arduino compatible pin input
int16_t analogRead(uint8_t pin)
{
#if defined(__AVR_ATmega32U4__)
	static const uint8_t PROGMEM pin_to_mux[] = {
		0x00, 0x01, 0x04, 0x05, 0x06, 0x07,
		0x25, 0x24, 0x23, 0x22, 0x21, 0x20};
	if (pin >= 12) return 0;
	return adc_read(pgm_read_byte(pin_to_mux + pin));
#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
	if (pin >= 8) return 0;
	return adc_read(pin);
#else
	return 0;
#endif
}

// Mux input
int16_t adc_read(uint8_t mux)
{
#if defined(__AVR_AT90USB162__)
	return 0;
#else
	uint8_t low;

	ADCSRA = (1<<ADEN) | ADC_PRESCALER;		// enable ADC
	ADCSRB = (1<<ADHSM) | (mux & 0x20);		// high speed mode
	ADMUX = aref | (mux & 0x1F);			// configure mux input
	ADCSRA = (1<<ADEN) | ADC_PRESCALER | (1<<ADSC);	// start the conversion
	while (ADCSRA & (1<<ADSC)) ;			// wait for result
	low = ADCL;					// must read LSB first
	return (ADCH << 8) | low;			// must read MSB only once!
#endif
}

void pointing_device_task(void){
	report_mouse_t currentReport = {};

  int xMove = 0;
  int yMove = 0;
  int xValue = analogRead(8);
  int yValue = analogRead(9);
  
  if (xValue <= 510 || xValue >= 520) {
    xMove = map(xValue, 0, 1023, -40, 40);
  }

  if (yValue <= 510 || yValue >= 520) {
    yMove = map(yValue, 0, 1023, -40, 40);
  }

  if (xMove != 0 || yMove != 0)
  {
    currentReport = pointing_device_get_report();
        //shifting and transferring the info to the mouse report varaible
        //mouseReport.x = 127 max -127 min
    currentReport.x = xMove;
        //mouseReport.y = 127 max -127 min
    currentReport.y = yMove;
        //mouseReport.v = 127 max -127 min (scroll vertical)
    // currentReport.v = uart_data[2];
        //mouseReport.h = 127 max -127 min (scroll horizontal)
    // currentReport.h = uart_data[3];
        //mouseReport.buttons = 0x31 max (bitmask for mouse buttons 1-5) 0x00 min
    //mouse buttons 1 and 2 are handled by the keymap, but not 3
    // if (uart_data[4] == 0x0F) { //then 3 is not pressed
      // currentReport.buttons &= ~MOUSE_BTN3; //MOUSE_BTN3 is def in report.h
    // } else { //3 must be pressed
    // 	currentReport.buttons |= MOUSE_BTN3;
    // }
    pointing_device_set_report(currentReport);
  }
  pointing_device_send();
}