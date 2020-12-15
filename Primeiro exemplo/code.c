#include <16F877a.h>
#use delay(clock=4000000)

main(){
	while(true){
		int tempo;
		tempo = 100;
		output_high(PIN_B0);
		delay_ms(tempo);
		output_low(PIN_B0);
		delay_ms(tempo);
	}
}