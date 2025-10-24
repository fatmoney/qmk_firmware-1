#include "report.h"         // report_mouse_t
#include "host.h"           // host_mouse_send
#include "n81.h"

// ADC mux for analog joypad (ATMEGA32U4)
#define ADC_MUX_PAD_X 0x00
#define ADC_MUX_PAD_Y 0x01

static report_mouse_t mouseReport = {};

#define MAP(x, in_min, in_max, out_min, out_max) \
    ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

analogpad_pointer_t pad;
        
void pointing_device_init(void)
{

    init_analogpad_pointer(&pad, ADC_MUX_PAD_X, ADC_MUX_PAD_Y);
}

void pointing_device_send(void){
    //If you need to do other things, like debugging, this is the place to do it.
    host_mouse_send(&mouseReport);
	//send it and 0 it out except for buttons, so those stay until they are explicity over-ridden using update_pointing_device
	mouseReport.x = 0;
	mouseReport.y = 0;
	mouseReport.v = 0;
	mouseReport.h = 0;
}

void pointing_device_task(void) {
	report_mouse_t currentReport = {};

    read_analogpad_pointer(&pad, 6);

    currentReport = mouseReport;

    currentReport.x = pad.x;           // pointer -127 .. 127
    currentReport.y = pad.y;           // pointer -127 .. 127
 
    mouseReport = currentReport;
    pointing_device_send();
}
