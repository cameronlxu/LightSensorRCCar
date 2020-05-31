#include "gpio.hpp"
#include "io.hpp"
#include "utilities.h"
#include <stdio.h>

// Code for the motor (SJSUOne Board #2)
int main(void) {
	GPIO myPin(P0_0);

	myPin.setAsOutput();

	while (1) {
		float light_value = LS.getPercentValue();
		LE.on(1);
		LD.setNumber(light_value);

		if (light_value < 20) {
			myPin.set(true);

			delay_ms(100);

		} // if statement ends

		else {
			myPin.set(false);
		}
		delay_ms(1);
	}

	return (0);
}
