#ifndef SSD1306_H
#define SSD1306_H 
/*
SSD1306 LCD uses I2C
SSD1306    |STM32F10x/STM32F40x   |DESCRIPTION

VCC        |3.3V         					|
GND        |GND       						|
SCL        |PB6         					|Serial clock line
SDA        |PB7        					  |Serial data line
*/

#include "stm32f4xx.h"
#include "fonts.h"

#include "stdlib.h"
#include "string.h"
#include "init_I2C.h"

/*I2C адрес SSD1306 по даташиту*/
#define SSD1306_I2C_ADDR         0x78

#define ssd1306_I2C_TIMEOUT					20000

/*Ширина SSD1306 в пикселях*/
#define SSD1306_WIDTH            128

/*Высота SSD1306 в пикселях*/
#define SSD1306_HEIGHT           64

/*Цвета SSD1306*/
typedef enum {
	SSD1306_COLOR_BLACK = 0x00, /*!< Черный цвет */
	SSD1306_COLOR_WHITE = 0x01  /*!< Белый цвет */
} SSD1306_COLOR_t;

/*Инициализация SSD1306*/
uint8_t SSD1306_Init(void);

/*Обновляет буфер из RAM SSD1306*/
void SSD1306_UpdateScreen(void);

/*Включает/выключает инверсию пикселей SSD1306*/
void SSD1306_ToggleInvert(void);

/*Заполняет весь экран цветом*/
void SSD1306_Fill(SSD1306_COLOR_t Color);

/**
 * @brief  Рисует пиксель
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x: X location. Этот параметр может иметь значение между 0 и SSD1306_WIDTH - 1
 * @param  y: Y location. Этот параметр может иметь значение между 0 и SSD1306_HEIGHT - 1
 * @param  color: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR_t color);

/*Устанавливает указатель курсора в желаемое место для строк*/
void SSD1306_GotoXY(uint16_t x, uint16_t y);

/**
 * @brief  Помещает символ в RAM
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  ch: символ который будет написан
 * @param  *Font: Указатель @ref FontDef_t на структуру шрифта
 * @param  color: Цвет, который будет использоваться для заливки экрана
 * @retval Character written
 */
char SSD1306_Putc(char ch, FontDef_t* Font, SSD1306_COLOR_t color);

/**
 * @brief  Помещает строку в RAM
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  *str: строка который будет написан
 * @param  *Font: Указатель @ref FontDef_t на структуру шрифта
 * @param  color: Цвет, который будет использоваться для заливки экрана
 * @retval Ноль в случае успеха или символьное значение в случае сбоя функции
 */
char SSD1306_Puts(char* str, FontDef_t* Font, SSD1306_COLOR_t color);

/**
 * @brief  Рисование линии в LCD
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x0: Line X start point. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y0: Line Y start point. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  x1: Line X end point. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y1: Line Y end point. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  c: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, SSD1306_COLOR_t c);

/**
 * @brief  Рисование прямоугольника в LCD
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x: Top left X start point. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y: Top left Y start point. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  w: Ширина прямоугольника в pixels
 * @param  h: Высота прямоугольника в pixels
 * @param  c: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR_t c);

/**
 * @brief  Рисование прямоугольника с заливкой в LCD
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x: Top left X start point. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y: Top left Y start point. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  w: Ширина прямоугольника в pixels
 * @param  h: Высота прямоугольника в pixels
 * @param  c: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawFilledRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR_t c);

/**
 * @brief  Рисование треугольника в LCD
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x1: First coordinate X location. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y1: First coordinate Y location. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  x2: Second coordinate X location. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y2: Second coordinate Y location. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  x3: Third coordinate X location. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y3: Third coordinate Y location. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  c: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, SSD1306_COLOR_t color);

/**
 * @brief  Рисование круга в LCD
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x: X location for center of circle. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y: Y location for center of circle. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  r: Радиус круга в pixels
 * @param  c: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawCircle(int16_t x0, int16_t y0, int16_t r, SSD1306_COLOR_t c);

/**
* @brief  Рисование круга с заливкойв LCD
 * @note   @ref SSD1306_UpdateScreen() необходимо вызвать для обновления
 * @param  x: X location for center of circle. Размеры от 0 до SSD1306_WIDTH - 1
 * @param  y: Y location for center of circle. Размеры от 0 до SSD1306_HEIGHT - 1
 * @param  r: Радиус круга в pixels
 * @param  c: Цвет, который будет использоваться для заливки экрана
 * @retval None
 */
void SSD1306_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, SSD1306_COLOR_t c);

/**
* @brief Инициализирует ЖК-дисплей SSD1306
* @param Нет
* @retval Статус инициализации:
* - 0: ЖК-дисплей не обнаружен на порту I2C
* - > 0: ЖК-дисплей инициализирован успешно и готов к использованию
*/
void ssd1306_I2C_Init();



/**
* @brief Записывает один байт в подчиненное устройство
* @param *I2Cx: используется I2C
* @param address: 7-битный адрес подчиненного устройства, выровнен по левому краю, используются биты 7:1, бит LSB не используется
* @param reg: регистр для записи
* @param data: данные для записи
* @retval None
*/
void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data);

/**
* @brief Записывает несколько байтов в подчиненное устройство
* @param *I2Cx: используется I2C
* @param address: 7-битный адрес подчиненного устройства, выровнен по левому краю, используются биты 7:1, бит LSB не используется
* @param reg: регистр для записи
* @param *data: указатель на массив данных для записи в подчиненное устройство
* @param count: сколько байт будет записано
* @retval None
*/
void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t *data, uint16_t count);

/**
* @brief Рисует растровое изображение
* @param X: Координата X для начала рисования
* @param Y: Координата Y для начала рисования
* @param *bitmap : Указатель на растровое изображение
* @param W : ширина изображения
* @param H : высота изображения
* @param color : 1-> белый/синий, 0-> черный
*/
void SSD1306_DrawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, int16_t w, int16_t h, uint16_t color);

/*прокрутите экран для фиксированных строк*/
void SSD1306_ScrollRight(uint8_t start_row, uint8_t end_row);

void SSD1306_ScrollLeft(uint8_t start_row, uint8_t end_row);

void SSD1306_Scrolldiagright(uint8_t start_row, uint8_t end_row);

void SSD1306_Scrolldiagleft(uint8_t start_row, uint8_t end_row);

void SSD1306_Stopscroll(void);

/*инвертирует отображение i = 1->инвертированный, i = 0->нормальный*/
void SSD1306_InvertDisplay (int i);

/*очистить дисплей*/
void SSD1306_Clear (void);
#endif