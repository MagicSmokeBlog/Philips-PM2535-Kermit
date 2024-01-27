#ifndef PM25XX_OLED_DISPLAY_DISPLAYAPP_H
#define PM25XX_OLED_DISPLAY_DISPLAYAPP_H

#include <U8g2lib.h>

#include "Decoder.h"
#include "DisplayState.h"
#include "DisplayDriver.h"

/**
 * The application for driving the OLED display.
 */
class DisplayApp
{
public:
    /**
     * Object constructor.
     *
     * @param u8g2 The display controller.
     * @param pcf8576Address The address of the PCF8576 IC.
     */
    DisplayApp(U8G2 &u8g2, uint8_t pcf8576Address);

    /**
     * Runs the app.
     */
    void run();

private:
    /**
     * The singleton instance of this class (without protection).
     */
    static DisplayApp *app;

    /**
     * The display controller.
     */
    U8G2 &u8g2;

    /**
     * The address of the PCF8576 IC.
     */
    uint8_t pcf8576Address;

    /**
     * The state of the display.
     */
    DisplayState displayState;

    /**
     * The decoder for decoding the received 40 nibbles from the processor.
     */
    Decoder decoder;

    /**
     * The display driver.
     */
    DisplayDriver displayDriver;

    /**
     * The buffer frame for receiving data from the processor.
     */
    uint8_t frame[20] = {255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255,
                         255};

    /**
     * Static wrapper around the singleton and method receiveData().
     *
     * @param count The number of received bytes.
     */
    static void wireReceiveHandler(int count);

    /**
     * Receives the data only.
     *
     * @param count The number of received bytes.
     */
    void receiveData(int count);

    /**
     * Handles the received data event.
     *
     * @param count The number of received bytes.
     */
    void receiveHandler(int count);
};

#endif //PM25XX_OLED_DISPLAY_DISPLAYAPP_H
