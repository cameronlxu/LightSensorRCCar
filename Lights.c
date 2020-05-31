#include "gpio.hpp"
#include "io.hpp"
#include "utilities.h"
#include <stdio.h>

// Code for the headlights (SJSUOne Board #1)
int main(void) {
	GPIO myPin(P0_1);
	myPin.setAsOutput();
	typedef enum { on, off } ledState;

	ledState ledCurr = off;
	bool sw1_pressed, sw2_pressed;
	sw1_pressed  = false;
	sw2_pressed = false;


	while (1) {

		sw1_pressed = SW.getSwitch(1);
		sw2_pressed = SW.getSwitch(2);

		switch (ledCurr) {
		case off:
			// Check if button 0 is pressed in this state and transition out of
			// this state

			if (sw1_pressed == true) {
				printf("Going to State : ON\n");
			   
				LE.on(1);
				myPin.setAsOutput();
				myPin.set(true);

				ledCurr = on;
			}
			break;

		case on:
			if (sw2_pressed == true) {
				printf("Going to State : OFF\n");
			 
				LE.off(1);
				myPin.setAsOutput();
				myPin.set(false);

				ledCurr = off;
			}

			break;

		default:

			printf("State machine ERROR!\n");
		}
	}

	return 0;
}