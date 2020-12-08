
_configPic:

;Timer0.c,5 :: 		void configPic(){
;Timer0.c,6 :: 		TRISA = 0xFF;
	MOVLW      255
	MOVWF      TRISA+0
;Timer0.c,7 :: 		TRISB = 0b01111111;
	MOVLW      127
	MOVWF      TRISB+0
;Timer0.c,8 :: 		TRISC = 0xFF;
	MOVLW      255
	MOVWF      TRISC+0
;Timer0.c,9 :: 		TRISD = 0xFF;
	MOVLW      255
	MOVWF      TRISD+0
;Timer0.c,10 :: 		}
L_end_configPic:
	RETURN
; end of _configPic

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;Timer0.c,12 :: 		void interrupt(){             // Rotina de interrupção
;Timer0.c,13 :: 		if(T0IF_bit)             // Flag para verificar se houve estouro
	BTFSS      T0IF_bit+0, BitPos(T0IF_bit+0)
	GOTO       L_interrupt0
;Timer0.c,15 :: 		contador++;          // Ficar incrementando
	INCF       _contador+0, 1
	BTFSC      STATUS+0, 2
	INCF       _contador+1, 1
;Timer0.c,17 :: 		TMR0 = 0x06;         // Retorno o TMR0 para o valor inicial que foi determinado
	MOVLW      6
	MOVWF      TMR0+0
;Timer0.c,18 :: 		T0IF_bit = 0x00;     // Zera a flag T0IF
	BCF        T0IF_bit+0, BitPos(T0IF_bit+0)
;Timer0.c,19 :: 		}
L_interrupt0:
;Timer0.c,20 :: 		}
L_end_interrupt:
L__interrupt6:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

_configTimer:

;Timer0.c,22 :: 		void configTimer(){
;Timer0.c,23 :: 		OPTION_REG = 0b10000011;         // Configuração do OPTION_REG. Verificar no datasheet
	MOVLW      131
	MOVWF      OPTION_REG+0
;Timer0.c,26 :: 		GIE_bit = 0x01;            // Habilitar a interupção global
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;Timer0.c,27 :: 		PEIE_bit = 0x01;           // Habilitar a interrupção por periféricos
	BSF        PEIE_bit+0, BitPos(PEIE_bit+0)
;Timer0.c,28 :: 		T0IE_bit = 0x01;           // Habilitar a interrupção estouro TMR0
	BSF        T0IE_bit+0, BitPos(T0IE_bit+0)
;Timer0.c,30 :: 		TMR0 = 0x06;               // Inicialização da contagem em 6
	MOVLW      6
	MOVWF      TMR0+0
;Timer0.c,31 :: 		TRISB.RB7 = 0x00;          // Define RB7 como saída
	BCF        TRISB+0, 7
;Timer0.c,32 :: 		RB7_bit = 0x00;            // Inicia RB7 em LOW
	BCF        RB7_bit+0, BitPos(RB7_bit+0)
;Timer0.c,34 :: 		}
L_end_configTimer:
	RETURN
; end of _configTimer

_main:

;Timer0.c,36 :: 		void main() {
;Timer0.c,37 :: 		configPic();
	CALL       _configPic+0
;Timer0.c,38 :: 		configTimer();
	CALL       _configTimer+0
;Timer0.c,40 :: 		while(1){
L_main1:
;Timer0.c,41 :: 		if(contador == 1000)  {  // Cálculo = (256 - 6)*16*0,000001*1000 = 4 seg.
	MOVF       _contador+1, 0
	XORLW      3
	BTFSS      STATUS+0, 2
	GOTO       L__main9
	MOVLW      232
	XORWF      _contador+0, 0
L__main9:
	BTFSS      STATUS+0, 2
	GOTO       L_main3
;Timer0.c,43 :: 		RB7_bit = ~RB7_bit;     // Comutar o estado
	MOVLW
	XORWF      RB7_bit+0, 1
;Timer0.c,44 :: 		contador = 0x00;         // Zera a variável counter
	CLRF       _contador+0
	CLRF       _contador+1
;Timer0.c,45 :: 		}
L_main3:
;Timer0.c,46 :: 		}
	GOTO       L_main1
;Timer0.c,47 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
