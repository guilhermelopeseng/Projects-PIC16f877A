#line 1 "C:/Guilherme/Github/Projetos Assembly/timer0MikroC/Timer0.c"


int contador = 0x00;

void configPic(){
 TRISA = 0xFF;
 TRISB = 0b01111111;
 TRISC = 0xFF;
 TRISD = 0xFF;
}

void interrupt(){
 if(T0IF_bit)
 {
 contador++;

 TMR0 = 0x06;
 T0IF_bit = 0x00;
 }
}

void configTimer(){
 OPTION_REG = 0b10000011;


 GIE_bit = 0x01;
 PEIE_bit = 0x01;
 T0IE_bit = 0x01;

 TMR0 = 0x06;
 TRISB.RB7 = 0x00;
 RB7_bit = 0x00;

}

void main() {
 configPic();
 configTimer();

while(1){
 if(contador == 1000) {

 RB7_bit = ~RB7_bit;
 contador = 0x00;
 }
 }
}
