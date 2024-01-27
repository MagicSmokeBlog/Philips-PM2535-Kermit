#ifndef PM25XX_OLED_DISPLAY_GLYPH_H
#define PM25XX_OLED_DISPLAY_GLYPH_H

#include <U8g2lib.h>

/**
 * Utility class for glyphs.
 */
class Glyph
{
public:
    enum
    {
        NONE, RISING_EDGE, FALLING_EDGE, OMEGA
    };

    /**
    * Ohms.
    */
    static u8g2_uint_t const OMEGA_WIDTH;
    static u8g2_uint_t const OMEGA_HEIGHT;
    static uint8_t const OMEGA_BITS[32];

    /**
     * Zap.
     */
    static u8g2_uint_t const ZAP_WIDTH;
    static u8g2_uint_t const ZAP_HEIGHT;
    static uint8_t const ZAP_BITS[18];

    /**
     * S of seconds.
     */
    static u8g2_uint_t const S_WIDTH;
    static u8g2_uint_t const S_HEIGHT;
    static uint8_t const S_BITS[7];

    /**
     * Up arrow.
     */
    static u8g2_uint_t const UP_ARROW2_WIDTH;
    static u8g2_uint_t const UP_ARROW2_HEIGHT;
    static uint8_t const UP_ARROW2_BITS[7];

    /**
     * Decimal dot.
     */
    static u8g2_uint_t const DP_WIDTH;
    static u8g2_uint_t const DP_HEIGHT;
    static uint8_t const DP_BITS[2];

    /**
     * Bleeper.
     */
    static u8g2_uint_t const BLEEPER_WIDTH;
    static u8g2_uint_t const BLEEPER_HEIGHT;
    static uint8_t const BLEEPER_BITS[7];

    /**
     * Diode.
     */
    static u8g2_uint_t const DIODE_WIDTH;
    static u8g2_uint_t const DIODE_HEIGHT;
    static uint8_t const DIODE_BITS[7];

    /**
     * DC.
     */
    static u8g2_uint_t const DC_WIDTH;
    static u8g2_uint_t const DC_HEIGHT;
    static uint8_t const DC_BITS[6];

    /**
     * AC.
     */
    static u8g2_uint_t const AC_WIDTH;
    static u8g2_uint_t const AC_HEIGHT;
    static uint8_t const AC_BITS[3];

    /**
     * DC on to of the AC.
     */
    static u8g2_uint_t const AC_DC_WIDTH;
    static u8g2_uint_t const AC_DC_HEIGHT;
    static uint8_t const AC_DC_BITS[1];

    /**
     * Down arrow.
     */
    static u8g2_uint_t const DOWN_ARROW_WIDTH;
    static u8g2_uint_t const DOWN_ARROW_HEIGHT;
    static uint8_t const DOWN_ARROW_BITS[3];

    /**
     * Up arrow.
     */
    static u8g2_uint_t const UP_ARROW_WIDTH;
    static u8g2_uint_t const UP_ARROW_HEIGHT;
    static uint8_t const UP_ARROW_BITS[3];

    /**
     * Z of Hertz.
     */
    static u8g2_uint_t const Z_WIDTH;
    static u8g2_uint_t const Z_HEIGHT;
    static uint8_t const Z_BITS[22];

    /**
     * Function arrows at the bottom line.
     */
    static u8g2_uint_t const FUNCTION_ARROW_WIDTH;
    static u8g2_uint_t const FUNCTION_ARROW_HEIGHT;
    static uint8_t const FUNCTION_ARROW_BITS[6];

    /**
     * Rising edge.
     */
    static u8g2_uint_t const RISING_EDGE_WIDTH;
    static u8g2_uint_t const RISING_EDGE_HEIGHT;
    static uint8_t const RISING_EDGE_BITS[32];

    /**
     * Falling edge.
     */
    static u8g2_uint_t const FALLING_EDGE_WIDTH;
    static u8g2_uint_t const FALLING_EDGE_HEIGHT;
    static uint8_t const FALLING_EDGE_BITS[32];
};

#endif //PM25XX_OLED_DISPLAY_GLYPH_H
