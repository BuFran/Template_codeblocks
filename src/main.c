#include <hal/pin.h>
#include <hal/delay.h>

#include "board.h"



int main(void)
{
	pin_clock_enable(LED);
	pin_set(LED,false);
	pin_output_pushpull(LED);

	pin_clock_enable(BUTTON);
	pin_input(BUTTON);

	while(true) {
		pin_toggle(LED);
		delay_ms(500, CPU_CLOCK);

		if (pin_get(BUTTON) == false) {
			delay_ms(500, CPU_CLOCK);
		}
	}
	return 0;
}
