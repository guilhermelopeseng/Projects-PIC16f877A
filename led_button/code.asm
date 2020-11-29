; Prática ligar LED com botao para o PIC16F877A
;
;
;Autor: Guilherme Lopes
;Universidade Federal do Piauí
;
;  

list 		p=16F877A
#include 	P16F877A.inc
__CONFIG   _CP_OFF & _WDT_OFF & _PWRTE_ON & _XT_OSC

;--- Configuração inicial ---
	org 0x0000 				; Origem do codigo

	bsf 	STATUS,RP0 			; Ir banco 1	
	bcf 	STATUS,RP1

	movlw 	b'11111111' 		; PORTC como entrada
	movwf 	TRISC				; Atribuir
	movlw 	b'11111110'			; RB0 como saída
	movwf 	TRISB				; Atribui
	bcf 	STATUS,RP0 			; Ir banco 0
	bcf 	STATUS,RP1
	
main
	
	movlw 	b'1'				;Inicializo com LED HIGH
	movwf	PORTB				;Atribui
	goto	loop				; Vai para o loop

loop:
	movfw	PORTC				;Botão pressionado?
	btfsc	STATUS, Z			;Verificar o status
	goto	apaga_led1			;Se não, vai para apaga o led
	movlw	b'1'				;Se sim, led continua HIGH
	movwf	PORTB				;Atribui
	goto	loop				;Reinicia

apaga_led1:
	movlw	b'0'				;Apaga o LED
	movwf	PORTB				;Atribui
	goto	loop				;Retorna para o loop

end								;Fim do código