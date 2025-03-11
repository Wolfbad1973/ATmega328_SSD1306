#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SSD1306_ADDR 0x3C
#define SDA_PIN PC4
#define SCL_PIN PC5

// Размеры дисплея
#define WIDTH 128
#define HEIGHT 64

// Текущие координаты пикселя
uint8_t pos_x = 64;
uint8_t pos_y = 32;

void I2C_Init() {
	PORTC |= (1 << SDA_PIN) | (1 << SCL_PIN);
	DDRC |= (1 << SDA_PIN) | (1 << SCL_PIN);
}

void I2C_Start() {
	PORTC &= ~(1 << SDA_PIN);
	_delay_us(4);
	PORTC &= ~(1 << SCL_PIN);
	_delay_us(4);
}

void I2C_Stop() {
	PORTC &= ~(1 << SDA_PIN);
	_delay_us(4);
	PORTC |= (1 << SCL_PIN);
	_delay_us(4);
	PORTC |= (1 << SDA_PIN);
	_delay_us(4);
}

uint8_t I2C_Write(uint8_t data) {
	for(uint8_t i = 0; i < 8; i++) {
		(data & 0x80) ? (PORTC |= (1 << SDA_PIN)) : (PORTC &= ~(1 << SDA_PIN));
		data <<= 1;
		PORTC |= (1 << SCL_PIN);
		_delay_us(4);
		PORTC &= ~(1 << SCL_PIN);
		_delay_us(4);
	}
	
	// ACK check
	DDRC &= ~(1 << SDA_PIN);
	PORTC |= (1 << SDA_PIN);
	PORTC |= (1 << SCL_PIN);
	_delay_us(2);
	uint8_t ack = !(PINC & (1 << SDA_PIN));
	PORTC &= ~(1 << SCL_PIN);
	_delay_us(2);
	DDRC |= (1 << SDA_PIN);
	return ack;
}

void SSD1306_Command(uint8_t cmd) {
	I2C_Start();
	I2C_Write(SSD1306_ADDR << 1);
	I2C_Write(0x00);
	I2C_Write(cmd);
	I2C_Stop();
}

void SSD1306_Init() {
	_delay_ms(100);
	const uint8_t init_seq[] = {
		0xAE, 0xD5, 0x80, 0xA8, 0x3F, 0xD3, 0x00, 0x40,
		0x8D, 0x14, 0x20, 0x00, 0xA1, 0xC8, 0xDA, 0x12,
		0x81, 0xCF, 0xD9, 0xF1, 0xDB, 0x40, 0xA4, 0xA6, 0xAF
	};
	
	for(uint8_t i = 0; i < sizeof(init_seq); i++) {
		SSD1306_Command(init_seq[i]);
	}
}

void Set_Pixel(uint8_t x, uint8_t y, uint8_t color) {
	if(x >= WIDTH || y >= HEIGHT) return;
	
	uint8_t page = y / 8;
	uint8_t bit_mask = 1 << (y % 8);
	
	SSD1306_Command(0xB0 + page);
	SSD1306_Command(x & 0x0F);
	SSD1306_Command(0x10 + (x >> 4));
	
	I2C_Start();
	I2C_Write(SSD1306_ADDR << 1);
	I2C_Write(0x40);
	I2C_Write(color ? bit_mask : 0x00);
	I2C_Stop();
}

void Clear_Screen() {
	for(uint8_t page = 0; page < 8; page++) {
		SSD1306_Command(0xB0 + page);
		SSD1306_Command(0x00);
		SSD1306_Command(0x10);
		
		I2C_Start();
		I2C_Write(SSD1306_ADDR << 1);
		I2C_Write(0x40);
		for(uint8_t col = 0; col < 128; col++) {
			I2C_Write(0x00);
		}
		I2C_Stop();
	}
}



// Функция для инициализации ADC
void ADC_Init() {
	// Настройка опорного напряжения (AVCC) и выравнивание результата вправо
	ADMUX = (1 << REFS0);

	// Включение ADC и установка предделителя (деление на 128)
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Функция для чтения значения ADC
uint16_t ADC_Read(uint8_t channel) {
	// Выбор канала ADC (0–7) и сброс остальных битов
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

	// Запуск преобразования
	ADCSRA |= (1 << ADSC);

	// Ожидание завершения преобразования
	while (ADCSRA & (1 << ADSC));

	// Возврат результата
	return ADC;
}

int main(void) {
	// Инициализация ADC
	ADC_Init();
	I2C_Init();
	SSD1306_Init();
	Clear_Screen();
	// Настройка порта B (PB0) как выхода для светодиода
	DDRB |= (1 << PB1);

	while (1) {
		// Чтение значения с канала ADC0
		uint16_t adcValue = ADC_Read(0);

		// Если значение ADC больше 512, включить светодиод
//		if (adcValue > 512) {
//			PORTB |= (1 << PB1);  // Включить светодиод
//			} else {
//			PORTB &= ~(1 << PB1); // Выключить светодиод
//			}
//			Set_Pixel(pos_x, pos_y, 0);
		pos_x = (pos_x + 1) % WIDTH; // Автоматическое движение
//		pos_y = (pos_y + 1) % HEIGHT; // Автоматическое движение
//			pos_x= 1;
			pos_y= adcValue/10;
			Set_Pixel(pos_x, pos_y, 1);
		if	(pos_x > 126)
		{
			Clear_Screen();
		}
		
//			_delay_ms(5);
			
		

		// Задержка для стабилизации
//		_delay_ms(50);
		
	}

	return 0;
}
