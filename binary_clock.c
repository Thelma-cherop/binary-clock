#define F_CPU 16000000UL
#include <avr/io.h>
#include <interript.h>
#include <util/delay.h>

int seconds =0;

void timer1_setup(){
TCCR1B =(1<<WGM01) /*ENABLE ctc mode , it ensential compare the value to the OCR1A IF ITS same resets and fires an interrupt*/
OCR1A=15624;/*EQUIVALENT to one second */

/*to avoid unintended bit bitchanges*/
TCCR1B =O;
TCNT1=0;
TCCR1B |= (1<<CS12) | (1<<CS10); /*THE prescaler to 1024 ,have roughly  or exactly 15624 counts */

TIMSK1 |= (OCIEA <<1);/*TIMER INTERRUOT INTERRUPT TRIggered every time the counter TCNTA and OCR1A matches their value*/
}

ISR(TIMER1_COMP_vect){


int main(void){

timer1setup();
sei()
