#ifndef INIT_I2C
#define INIT_I2C

#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "init_LED.h"

#define BUFFER_SIZE_I2C 10
#define I2C_ADDRESSINGMODE_7BIT 0x00004000U
#define CLOCK_SPEED 100000

#define I2C_FLAG_BUSY 0x00100002U
#define I2C_FLAG_BTF 0x00010004U
#define I2C_FLAG_MASK 0x0000FFFFU

#define ENABLE_BIT(reg, bit) ((reg) |= (bit))
#define DISABLE_BIT(reg, bit) ((reg) &= ~(bit))
#define Read_BIT(reg, bit)    ((reg) & (bit))

/*макс число*/
#define MAX_DELAY      0xFFFFFFFF

/*задержки на ошибку*/
#define I2C_TIMEOUT_FLAG          35U         /*!< Timeout 35 ms             */
#define I2C_TIMEOUT_BUSY_FLAG     25U         /*!< Timeout 25 ms             */
#define I2C_TIMEOUT_STOP_FLAG     5U          /*!< Timeout 5 ms              */

/** @defgroup I2C_Flag_definition I2C Flag definition
  * @{
  */

#define I2C_FLAG_OVR                    0x00010800U
#define I2C_FLAG_AF                     0x00010400U
#define I2C_FLAG_ARLO                   0x00010200U
#define I2C_FLAG_BERR                   0x00010100U
#define I2C_FLAG_TXE                    0x00010080U
#define I2C_FLAG_RXNE                   0x00010040U
#define I2C_FLAG_STOPF                  0x00010010U
#define I2C_FLAG_ADD10                  0x00010008U
#define I2C_FLAG_BTF                    0x00010004U
#define I2C_FLAG_ADDR                   0x00010002U
#define I2C_FLAG_SB                     0x00010001U
#define I2C_FLAG_DUALF                  0x00100080U
#define I2C_FLAG_GENCALL                0x00100010U
#define I2C_FLAG_TRA                    0x00100004U
#define I2C_FLAG_BUSY                   0x00100002U
#define I2C_FLAG_MSL                    0x00100001U


void Init_I2C(void);
void Enable_RCC_I2C(void);
void Config_GPIO_I2C(void);
void Config_I2C(void);

uint32_t RCC_GetPCLK1Freq(void);
uint32_t I2C_Speed(uint32_t pclk, uint32_t speed, uint32_t dutyCycle);
uint32_t I2C_Rise_Time(uint32_t freqrange, uint32_t clockSpeed);
uint8_t I2C_AdresSetTime(void);
uint8_t I2C_StartBit_SetTime(void);
uint8_t I2C_BTFBit_SetTime(void);
uint8_t I2C_TX_SetTime(void);
uint8_t I2C_MasterRequestRead(uint16_t DevAddress);
uint8_t I2C_MasterRequestWriteT(uint16_t DevAddress);
uint8_t I2C_RX_SetTime(void);
uint8_t I2C_GET_FLAG(I2C_TypeDef *instance, uint32_t flag);
uint8_t I2C_BUSYBit_SetTime(void);

uint8_t I2C_IsDeviceReady(I2C_TypeDef *instance, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout);
uint8_t I2C_WaitOnFlagUntilTimeout(I2C_TypeDef *instance, uint32_t Flag, FlagStatus Status, uint32_t Timeout);

uint8_t I2C_Master_ReceiveT(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
uint8_t I2C_Master_TransmitT(uint16_t DevAddress, uint8_t *pData, uint16_t Size);

void Error_Handler(void);
#endif
