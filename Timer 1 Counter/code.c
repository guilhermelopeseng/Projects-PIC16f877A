//Autor: Guilherme Lopes
//Universidade Federal do Piauí


#include <16F877A.h> 		                 		//Importação da biblioteca							
#use delay(crystal=20000000)				        //Definicação do clock do cristal


//Função principal
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