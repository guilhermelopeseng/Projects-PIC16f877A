//Autor: Guilherme Lopes
//Universidade Federal do Piauí


#include <16F877A.h> 		                 		//Importação da biblioteca							
#use delay(crystal=20000000)				        //Definicação do clock do cristal
#bit TMR1IF = 0x0e.0
//Função principal
void main()
{
   setup_timer_1(T1_EXTERNAL_SYNC|T1_DIV_BY_1);			// Configurações do Timer1
   set_timer1(0);
   output_low(PIN_D0);
   while(true) {
   	if(get_timer1() == 2){
   		output_toggle(PIN_D0);
   		set_timer1(0);
   	}
   }
}                                  