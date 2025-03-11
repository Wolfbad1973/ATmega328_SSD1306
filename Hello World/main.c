#include <avr/io.h>
#include <util/delay.h>

// Адрес дисплея SSD1306 на шине I2C
#define SSD1306_I2C_ADDRESS 0x3C

// Команды для SSD1306
#define SSD1306_SET_CONTRAST 0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME 0xA4
#define SSD1306_DISPLAY_ON 0xAF
#define SSD1306_DISPLAY_OFF 0xAE
#define SSD1306_NORMAL_DISPLAY 0xA6
#define SSD1306_INVERT_DISPLAY 0xA7
#define SSD1306_SET_DISPLAY_OFFSET 0xD3
#define SSD1306_SET_COM_PINS 0xDA
#define SSD1306_SET_VCOM_DETECT 0xDB
#define SSD1306_SET_DISPLAY_CLOCK_DIV 0xD5
#define SSD1306_SET_PRECHARGE 0xD9
#define SSD1306_SET_MULTIPLEX 0xA8
#define SSD1306_SET_LOW_COLUMN 0x00
#define SSD1306_SET_HIGH_COLUMN 0x10
#define SSD1306_SET_START_LINE 0x40
#define SSD1306_MEMORY_MODE 0x20
#define SSD1306_COLUMN_ADDR 0x21
#define SSD1306_PAGE_ADDR 0x22
#define SSD1306_COM_SCAN_INC 0xC0
#define SSD1306_COM_SCAN_DEC 0xC8
#define SSD1306_SEG_REMAP 0xA0
#define SSD1306_CHARGE_PUMP 0x8D
#define SSD1306_EXTERNAL_VCC 0x1
#define SSD1306_SWITCH_CAP_VCC 0x2

// Функция для инициализации I2C
void I2C_Init() {
	TWSR = 0x00;  // Предделитель = 1
	TWBR = 0x0C;  // Установка скорости (16 МГц / (16 + 2 * 12) = 400 кГц)
	TWCR = (1 << TWEN);  // Включение I2C
}

// Функция для отправки стартового условия
void I2C_Start() {
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

// Функция для отправки стопового условия
void I2C_Stop() {
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

// Функция для отправки байта данных
void I2C_Write(uint8_t data) {
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}

// Функция для отправки команды на SSD1306
void SSD1306_Command(uint8_t command) {
	I2C_Start();
	I2C_Write(SSD1306_I2C_ADDRESS << 1);  // Адрес дисплея + бит записи
	I2C_Write(0x00);  // Контрольный байт (команда)
	I2C_Write(command);  // Команда
	I2C_Stop();
}

// Функция для инициализации дисплея SSD1306
void SSD1306_Init() {
	_delay_ms(100);  // Задержка для стабилизации питания

	SSD1306_Command(SSD1306_DISPLAY_OFF);
	SSD1306_Command(SSD1306_SET_DISPLAY_CLOCK_DIV);
	SSD1306_Command(0x80);
	SSD1306_Command(SSD1306_SET_MULTIPLEX);
	SSD1306_Command(0x3F);
	SSD1306_Command(SSD1306_SET_DISPLAY_OFFSET);
	SSD1306_Command(0x00);
	SSD1306_Command(SSD1306_SET_START_LINE | 0x00);
	SSD1306_Command(SSD1306_CHARGE_PUMP);
	SSD1306_Command(0x14);
	SSD1306_Command(SSD1306_MEMORY_MODE);
	SSD1306_Command(0x00);
	SSD1306_Command(SSD1306_SEG_REMAP | 0x01);
	SSD1306_Command(SSD1306_COM_SCAN_DEC);
	SSD1306_Command(SSD1306_SET_COM_PINS);
	SSD1306_Command(0x12);
	SSD1306_Command(SSD1306_SET_CONTRAST);
	SSD1306_Command(0xCF);
	SSD1306_Command(SSD1306_SET_PRECHARGE);
	SSD1306_Command(0xF1);
	SSD1306_Command(SSD1306_SET_VCOM_DETECT);
	SSD1306_Command(0x40);
	SSD1306_Command(SSD1306_DISPLAY_ALL_ON_RESUME);
	SSD1306_Command(SSD1306_NORMAL_DISPLAY);
	SSD1306_Command(SSD1306_DISPLAY_ON);
}

// Функция для вывода текста на дисплей
void SSD1306_Print(const char* text) {
	for (uint8_t i = 0; text[i] != '\0'; i++) {
		SSD1306_Command(0x21);  // Установка адреса столбца
		SSD1306_Command(0x00);
		SSD1306_Command(0x7F);
		SSD1306_Command(0x22);  // Установка адреса страницы
		SSD1306_Command(0x00);
		SSD1306_Command(0x07);
		I2C_Start();
		I2C_Write(SSD1306_I2C_ADDRESS << 1);
		I2C_Write(0x40);  // Контрольный байт (данные)
		I2C_Write(text[i]);
		I2C_Stop();
	}
}

int main(void) {
	// Инициализация I2C
	I2C_Init();

	// Инициализация дисплея SSD1306
	SSD1306_Init();

	// Вывод текста "HELLO WORLD"
	SSD1306_Print("HELLO WORLD");

	while (1) {
		// Бесконечный цикл
	}
}