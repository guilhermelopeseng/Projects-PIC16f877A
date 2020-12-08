// Guilherme Alexandre Lopes Neto
// Exemplo de uso do Timer 0
int contador = 0x00;           // Vari�vel para utiliza��o

void configPic(){
     TRISA = 0xFF;
     TRISB = 0b01111111;
     TRISC = 0xFF;
     TRISD = 0xFF;
}

void interrupt(){             // Rotina de interrup��o
     if(T0IF_bit)             // Flag para verificar se houve estouro
     {
         contador++;          // Ficar incrementando
         // A vari�vel contador vai determinar quantas vezes ocorreu o estouro
         TMR0 = 0x06;         // Retorno o TMR0 para o valor inicial que foi determinado
         T0IF_bit = 0x00;     // Zera a flag T0IF
     }
}

void configTimer(){
   OPTION_REG = 0b10000011;         // Configura��o do OPTION_REG. Verificar no datasheet
                                    // Foi determinado pull-ups desabilitados
                                    // Configura��o do Presacaler 1: 16
   GIE_bit = 0x01;            // Habilitar a interup��o global
   PEIE_bit = 0x01;           // Habilitar a interrup��o por perif�ricos
   T0IE_bit = 0x01;           // Habilitar a interrup��o estouro TMR0

   TMR0 = 0x06;               // Inicializa��o da contagem em 6
   TRISB.RB7 = 0x00;          // Define RB7 como sa�da
   RB7_bit = 0x00;            // Inicia RB7 em LOW

}

void main() {
     configPic();
     configTimer();

while(1){
         if(contador == 1000)  {  // C�lculo = (256 - 6)*16*0,000001*1000 = 4 seg.
                                  // Vai haver 1000 estouros
         RB7_bit = ~RB7_bit;     // Comutar o estado
         contador = 0x00;         // Zera a vari�vel contador
         }
    }
}