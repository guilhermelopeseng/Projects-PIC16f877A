//Autor: Guilherme Lopes
//Universidade Federal do Piau�


#include <16F877A.h> 		                 		//Importa��o da biblioteca							
#use delay(crystal=20000000)				        //Definica��o do clock do cristal


//Fun��o principal
void main()
{
   setup_timer_0(RTCC_EXT_L_TO_H| RTCC_DIV_1);   
   set_timer0(0); 
 
   while(TRUE){
	   
	   if(get_timer0() == 4){
		   set_timer0(0);
		   output_toggle(PIN_B0);
	   }
   	
   }
}                                  