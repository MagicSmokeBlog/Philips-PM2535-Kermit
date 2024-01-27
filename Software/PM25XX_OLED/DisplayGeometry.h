#ifndef PM25XX_OLED_DISPLAY_DISPLAYGEOMETRY_H
#define PM25XX_OLED_DISPLAY_DISPLAYGEOMETRY_H

#include <U8g2lib.h>

/**
 * The x and y coordinates of all items on the display.
 */
class DisplayGeometry
{
public:
    static u8g2_uint_t const WIDTH = 256;
    static u8g2_uint_t const HEIGHT = 64;

    static u8g2_uint_t const X_REMOTE = 0;
    static u8g2_uint_t const X_SERVICE_REQUEST = 16;
    static u8g2_uint_t const X_LISTENER = 32;
    static u8g2_uint_t const X_TALK = 52;
    static u8g2_uint_t const X_ONLY = 68;
    static u8g2_uint_t const X_ANALOG_BAR = 88;
    static u8g2_uint_t const X_ANALOG_BAR_INCREMENT = 4;

    static u8g2_uint_t const X_MANUAL_RANGE = 0;
    static u8g2_uint_t const X_SINGLE_TRIGGER = 24;
    static u8g2_uint_t const X_SPEED = 52;
    static u8g2_uint_t const X_SPEED1 = 72;
    static u8g2_uint_t const X_SPEED2 = 76;
    static u8g2_uint_t const X_SPEED3 = 80;
    static u8g2_uint_t const X_SPEED4 = 84;
    static u8g2_uint_t const X_FILTER = 97;
    static u8g2_uint_t const X_NULL = 117;
    static u8g2_uint_t const X_HOLD = 140;
    static u8g2_uint_t const X_PROBE = 160;

    static u8g2_uint_t const X_POLARITY = 4;
    static u8g2_uint_t const X_VALUE = 21;
    static u8g2_uint_t const X_VALUE_DOT = 19;
    static u8g2_uint_t const X_VALUE_DOT_INCREMENT = 17;
    static u8g2_uint_t const X_UNIT = 138;
    static u8g2_uint_t const X_UNIT_DOT = 151;
    static u8g2_uint_t const X_UNIT_DOT_INCREMENT = 14;
    static u8g2_uint_t const X_UNIT_Z_OF_HERTZ = 168;

    static u8g2_uint_t const X_FUNCTION_ARROW1 = 45;
    static u8g2_uint_t const X_FUNCTION_ARROW2 = 90;
    static u8g2_uint_t const X_FUNCTION_ARROW3 = 133;
    static u8g2_uint_t const X_FUNCTION_ARROW4 = 182;

    static u8g2_uint_t const X_LIGHTING = 0;
    static u8g2_uint_t const X_CREST_FACTOR_EXCEED = 18;

    static u8g2_uint_t const X_ICONS_RIGHT0 = 159;
    static u8g2_uint_t const X_ICONS_RIGHT1 = 175;
    static u8g2_uint_t const X_ICONS_RIGHT2 = 187;

    static u8g2_uint_t const X_TEXT_INDICATOR1 = 203;
    static u8g2_uint_t const X_TEXT_INDICATOR2 = 232;

    static u8g2_uint_t const X_SECONDS = 143;

    static u8g2_uint_t const Y_TOP_LINE = 7;
    static u8g2_uint_t const Y_VALUE = 42;
    static u8g2_uint_t const Y_BOTTOM_LINE = 63;
    static u8g2_uint_t const Y_ICONS_LEFT = 19;
    static u8g2_uint_t const Y_SECONDS = 20;

    static u8g2_uint_t const Y_TEXT_INDICATOR1 = Y_TOP_LINE;
    static u8g2_uint_t const Y_TEXT_INDICATOR2 = Y_TEXT_INDICATOR1 + 11;
    static u8g2_uint_t const Y_TEXT_INDICATOR3 = Y_TEXT_INDICATOR2 + 11;
    static u8g2_uint_t const Y_TEXT_INDICATOR4 = Y_TEXT_INDICATOR3 + 11;
    static u8g2_uint_t const Y_TEXT_INDICATOR5 = Y_TEXT_INDICATOR4 + 11;
    static u8g2_uint_t const Y_TEXT_INDICATOR6 = Y_TEXT_INDICATOR5 + 11;
};

#endif //PM25XX_OLED_DISPLAY_DISPLAYGEOMETRY_H
