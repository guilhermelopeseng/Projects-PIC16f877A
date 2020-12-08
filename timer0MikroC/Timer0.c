// Guilherme Alexandre Lopes Neto
// Exemplo de uso do Timer 0
int contador = 0x00;           // Variável para utilização

void configPic(){
     TRISA = 0xFF;
     TRISB = 0b01111111;
     TRISC = 0xFF;
     TRISD = 0xFF;
}

void interrupt(){             // Rotina de interrupção
     if(T0IF_bit)             // Flag para verificar se houve estouro
     {
         contador++;          // Ficar incrementando
         // A variável contador vai determinar quantas vezes ocorreu o estouro
         TMR0 = 0x06;         // Retorno o TMR0 para o valor inicial que foi determinado
         T0IF_bit = 0x00;     // Zera a flag T0IF
     }
}

void configTimer(){
   OPTION_REG = 0b10000011;         // Configuração do OPTION_REG. Verificar no datasheet
                                    // Foi determinado pull-ups desabilitados
                                    // Configuração do Presacaler 1: 16
   GIE_bit = 0x01;            // Habilitar a interupção global
   PEIE_bit = 0x01;           // Habilitar a interrupção por periféricos
   T0IE_bit = 0x01;           // Habilitar a interrupção estouro TMR0

   TMR0 = 0x06;               // Inicialização da contagem em 6
   TRISB.RB7 = 0x00;          // Define RB7 como saída
   RB7_bit = 0x00;            // Inicia RB7 em LOW

}

void main() {
     configPic();
     configTimer();

while(1){
         if(contador == 1000)  {  // Cálculo = (256 - 6)*16*0,000001*1000 = 4 seg.
                                  // Vai haver 1000 estouros
         RB7_bit = ~RB7_bit;     // Comutar o estado
         contador = 0x00;         // Zera a variável contador
         }
    }
}