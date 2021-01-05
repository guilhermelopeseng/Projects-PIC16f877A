//Autor: Guilherme Lopes
//Universidade Federal do Piau�


#include <16F877A.h> 		                 		//Importa��o da biblioteca							
#use delay(crystal=20000000)				        //Definica��o do clock do cristal


//Fun��o principal
void main()
{
   setup_timer_1(T1_EXTERNAL|T1_CLK_OUT);
   set_timer1(0);
   output_low(PIN_D0); 
 
   while(TRUE){
	   
	   if(get_timer1() == 2){
		   set_timer1(0);
		   output_toggle(PIN_D0);
	   }
   	
   }
}                                  