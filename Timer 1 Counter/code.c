//Autor: Guilherme Lopes
//Universidade Federal do Piau�


#include <16F877A.h> 		                 		//Importa��o da biblioteca							
#use delay(crystal=20000000)				        //Definica��o do clock do cristal
#bit TMR1IF = 0x0e.0
//Fun��o principal
void main()
{
   setup_timer_1(T1_EXTERNAL_SYNC|T1_DIV_BY_1);			// Configura��es do Timer1
   set_timer1(0);
   output_low(PIN_D0);
   while(true) {
   	if(get_timer1() == 2){
   		output_toggle(PIN_D0);
   		set_timer1(0);
   	}
   }
}                                  