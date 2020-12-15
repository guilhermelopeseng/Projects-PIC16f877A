//Autor: Guilherme Lopes
//Universidade Federal do Piauí


#include <16F877A.h> 		                 		//Importação da biblioteca							
#use delay(crystal=20000000)				        //Definicação do clock do cristal


//Função principal
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