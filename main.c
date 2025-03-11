#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define n asm volatile("nop");

void LED_Init() {
	DDRB |= (1 << PB1);
}

void LED_FF() {
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)  8bit FF
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
}


void LED_00() {
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns) 8bit 00
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
}

void LED_07() {
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns) 8bit 00
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T0H  5     (312.5ns)
	n n n
	PORTB &= ~(1<<(PORTB1));//T0L  15    (937.5ns)
	n n n n n n n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
	PORTB |= (1<<(PORTB1));//T1H  11    (687.5ns)
	n n n n n n n n n
	PORTB &= ~(1<<(PORTB1));//T1L  9     (562.5ns)
	n n n n n n n
}

void a(){
			LED_00();//GREEN
			LED_00();
			LED_00();
			LED_00();//red
			LED_00();
			LED_00();
			LED_00();//blue
			LED_00();
			LED_00();
			LED_00();//GREEN
			LED_00();
			LED_00();
			LED_00();//red
			LED_00();
			LED_00();
			LED_00();//blue
			LED_00();
			LED_00();
			LED_00();//GREEN
			LED_00();
			LED_00();
			LED_00();//red
			LED_00();
			LED_00();
			LED_00();//blue
			LED_00();
			LED_00();
			LED_00();//GREEN
			LED_00();
			LED_00();
			LED_00();//red
			LED_00();
			LED_00();
			LED_00();//blue
			LED_00();
			LED_00();
			LED_00();//GREEN
			LED_00();
			LED_00();
			LED_00();//red
			LED_00();
			LED_00();
			LED_00();//blue
			LED_00();
			LED_00();
			LED_00();//GREEN
			LED_00();
			LED_00();
}

void b(){
	LED_07();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void c(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_07();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void d(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_07();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void e(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_07();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void f(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_07();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void g(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_07();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void h(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_07();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void i(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_07();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void j(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_07();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void k(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_07();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void l(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_07();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void m(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_07();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void o(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_07();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void p(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_07();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void q(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_07();
	LED_00();//GREEN
	LED_00();
	LED_00();
}

void r(){
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_00();//GREEN
	LED_00();
	LED_00();
	LED_00();//red
	LED_00();
	LED_00();
	LED_00();//blue
	LED_00();
	LED_00();
	LED_07();//GREEN
	LED_00();
	LED_00();
}

void s(){
	LED_FF();//white
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//
	LED_FF();
	LED_FF();
	LED_FF();//blue
	LED_FF();
	LED_FF();
	LED_FF();//GREEN
	LED_FF();
	LED_FF();
	LED_FF();//red
	LED_FF();
	LED_FF();
	LED_FF();//blue
	LED_FF();
	LED_FF();
	LED_FF();//GREEN
	LED_FF();
	LED_FF();
	LED_FF();//red
	LED_FF();
	LED_FF();
	LED_FF();//blue
	LED_FF();
	LED_FF();
	LED_FF();//GREEN
	LED_FF();
	LED_FF();
}

int main(void)
{

	LED_Init();

	while(1)
	{
		b();
		_delay_ms(500);
		c();
		_delay_ms(100);
		d();
		_delay_ms(100);
		e();
		_delay_ms(100);
		f();
		_delay_ms(100);
		g();
		_delay_ms(100);
		h();
		_delay_ms(100);
		i();
		_delay_ms(100);
		j();
		_delay_ms(100);
		k();
		_delay_ms(100);
		l();
		_delay_ms(100);
		m();
		_delay_ms(100);
		o();
		_delay_ms(100);
		p();
		_delay_ms(100);
		q();
		_delay_ms(100);
		r();
		_delay_ms(500);


		
		q();
		_delay_ms(100);		
		p();
		_delay_ms(100);
		o();
		_delay_ms(100);
		m();
		_delay_ms(100);
		l();
		_delay_ms(100);
		k();
		_delay_ms(100);
		j();
		_delay_ms(100);
		i();
		_delay_ms(100);
		h();
		_delay_ms(100);
		g();
		_delay_ms(100);
		f();
		_delay_ms(100);
		e();
		_delay_ms(100);
		d();
		_delay_ms(100);
		c();
		_delay_ms(100);

		for (uint8_t y = 0; y < 10; y++)
		{
		s();
		_delay_ms(100);	
				a();
		_delay_ms(100);
		}
	}
}











































































				

		

