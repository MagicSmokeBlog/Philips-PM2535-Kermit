#include <Arduino.h>

#include "DisplayApp.h"

/**
 * The driver chip. Either, SSD1322 or SSD1362.
 *
 * When using hardware emulated SPI (i.e. *_4W_HW_SPI constructor) connect serial clock and data according to the table
 * below.
 *
 *  |           OLED            | Nano |
 *  |---------------------------|------|
 *  | Din (SDA or Serial Data)  | D11  |
 *  | CLK (SCL or Serial Clock) | D13  |
 */
#define DRIVER_SSD1322_HW 0
#define DRIVER_SSD1322_SW 1
#define DRIVER_SSD1362_HW 0
#define DRIVER_SSD1362_SW 0

/**
 * Serial clock pin, a.k.a. SC or CLK.
 */
const uint8_t PIN_SERIAL_CLOCK = 3;

/**
 * Serial data pin, a.k.a. SD.
 */
const uint8_t PIN_SERIAL_DATA = 4;

/**
 * Data command pin, a.k.a. DC or D/C.
 */
const uint8_t PIN_DATA_COMMAND = 5;

/**
 * Chip select pin, a.k.a. CS.
 */
const uint8_t PIN_CHIP_SELECT = 6;

/**
 * Reset pin.
 */
const uint8_t PIN_RESET = 7;

/**
 * The I2C address of the PCF8576 IC, default 0x38.
 */
const uint8_t PCF8576_ADDRESS = 0x38;

#if DRIVER_SSD1322_HW
U8G2_SSD1322_NHD_256X64_F_4W_HW_SPI u8g2(U8G2_R0, PIN_CHIP_SELECT, PIN_DATA_COMMAND, PIN_RESET);
#elif DRIVER_SSD1322_SW
U8G2_SSD1322_NHD_256X64_F_4W_SW_SPI u8g2(U8G2_R0,
                                         PIN_SERIAL_CLOCK,
                                         PIN_SERIAL_DATA,
                                         PIN_CHIP_SELECT,
                                         PIN_DATA_COMMAND,
                                         PIN_RESET);
#elif DRIVER_SSD1362_HW
U8G2_SSD1362_256X64_F_4W_HW_SPI u8g2(U8G2_R0, PIN_CHIP_SELECT, PIN_DATA_COMMAND, PIN_RESET);
#elif DRIVER_SSD1362_SW
U8G2_SSD1362_256X64_F_4W_SW_SPI u8g2(U8G2_R0,
                                     PIN_SERIAL_CLOCK,
                                     PIN_SERIAL_DATA,
                                     PIN_CHIP_SELECT,
                                     PIN_DATA_COMMAND,
                                     PIN_RESET);
#endif

void setup(void)
{
    DisplayApp app = DisplayApp(u8g2, PCF8576_ADDRESS);
    app.run();
}

void loop(void)
{
    // Nothing to do.
}
