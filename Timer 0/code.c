//Autor: Guilherme Lopes
//Universidade Federal do Piauí


#include <16F877A.h> 					//Importação da biblioteca							
#use delay(crystal=20000000)				//Definicação do crital
 
int contador =0;						//Inicialização do contador
#INT_TIMER0								//Parâmetro para indicar que a proxima
										//função é conrrespondete a Timer0
void tratar_t0(void)					//Função para tratar o timer0
{
   clear_interrupt(INT_TIMER0);			//Limpar o bit T0IF
   set_timer0(61);						//Definir o preload
   contador++;							//Incrementar um valor, desse modo
   										//ocorreu uma rotina
   if(contador > 199)					//Se ocorrer 200 rotinas
   {
      contador = 0;						//Retorno para zero
      output_toggle(PIN_B0);			//Comulto o estado do pino RB0
   }
}

//Função principal
void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);	//Definir o clock interno e o prescaler do timer0   
   set_timer0(61);                             // Definir o preload
   clear_interrupt(INT_TIMER0);					// Limpara o bit T0IF                
   enable_interrupts(INT_TIMER0);       		// Habilitar as interrupções pelo timer0       
   enable_interrupts(GLOBAL);                   // Habilitar o bit GIE de interrupção do timer0
   output_low(PIN_B0);
 
   while(TRUE) ;                
}