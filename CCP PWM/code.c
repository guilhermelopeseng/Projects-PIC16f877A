/*
	Autor: Guilherme Alexandre Lopes Neto
	Universidade Federal do Piauí

*/
#include <16f877a.h>
#bit TMR2IF = 0x0c.1
#bit CCP2IF = 0x0d.0
void main()
{
	unsigned t1, tempo;
	unsigned int1 cap1;
	unsigned int8 cont=0; 
	unsigned int16 x;
	// setup_timer_2(PRESCALER, PR2 Reg, Postcaler)
	setup_timer_2(T2_DIV_BY_1,249,16); // 1/20kHz = ( y + 1)*4*(1/20MHz)*1
	/*
		Calculando o prescaler do Timer2:
		0.1s/(1/20kHz) = 2000/16 = 125
		Lê-se:
		Presciso de 2000 estouros para obter um tempo de 0.1 segundos,
		logo se utilizar o prescaler de 16 vou precisar fazer uma contagem
		de 125 vezes
		
		Verificando:
		16*50us = 800us * 125 = 0.1s
		Lê-se:
		16 vezes o período do sinal gerado vai retornar um tempo de 800us
		fazendo esse laço 125 vezes vai retornar 0.1s 
	*/
	SETUP_TIMER_1(T1_INTERNAL| T1_DIV_BY_1);
	SETUP_CCP1(CCP_PWM);
	SETUP_CCP2(CCP_CAPTURE_RE);
	
	x=0;
	SET_PWM1_DUTY(x);
	cap1 = 1;
	while(1)
	{
		if(TMR2IF == 1) // passou 50*16us = 800us
		{
			TMR2IF = 0;
			cont++;
			if (cont == 125){
				cont=0;
				x = x + 100; // incrementando 10%, que corresponde 5us (10%*50us)
				if (x > 1000) {
					x = 0;
				}
				SET_PWM1_DUTY(x);
			}
		}
		if(CCP2IF == 1)
		{
			if(cap1 == 1)
			{
				t1 = CCP_2;
				SETUP_CCP2(CCP_CAPTURE_FE);
			}else 
			{
				tempo = CCP_2 - t1;
				SETUP_CCP2(CCP_CAPTURE_RE);
			}
			CCP2IF = 0;
			cap1 = cap1 ^ 1;
			
			if(tempo > 125)
			{
				output_high(pin_d0);
			}
			else
			{
				output_low(pin_d0);
			}
		}
		
	}

}