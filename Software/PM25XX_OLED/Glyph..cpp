#include "Glyph.h"

/**
 * Ohms.
 */
u8g2_uint_t const Glyph::OMEGA_WIDTH = 14;
u8g2_uint_t const Glyph::OMEGA_HEIGHT = 16;
uint8_t const Glyph::OMEGA_BITS[32] = {0x00,
                                       0x00,
                                       0x00,
                                       0x00,
                                       0x00,
                                       0x00,
                                       0xe0,
                                       0x01,
                                       0xf8,
                                       0x07,
                                       0x1c,
                                       0x0e,
                                       0x0c,
                                       0x0c,
                                       0x06,
                                       0x18,
                                       0x06,
                                       0x18,
                                       0x06,
                                       0x18,
                                       0x06,
                                       0x18,
                                       0x0c,
                                       0x0c,
                                       0x18,
                                       0x06,
                                       0x18,
                                       0x06,
                                       0x1e,
                                       0x1e,
                                       0x1e,
                                       0x1e};

/**
 * Zap.
 */
u8g2_uint_t const Glyph::ZAP_WIDTH = 12;
u8g2_uint_t const Glyph::ZAP_HEIGHT = 9;
uint8_t const Glyph::ZAP_BITS[18] = {0x00,
                                     0x08,
                                     0x00,
                                     0x0c,
                                     0x20,
                                     0x06,
                                     0x70,
                                     0x03,
                                     0xd8,
                                     0x01,
                                     0x8d,
                                     0x00,
                                     0x07,
                                     0x00,
                                     0x07,
                                     0x00,
                                     0x0f,
                                     0x00};

/**
 * S of seconds.
 */
u8g2_uint_t const Glyph::S_WIDTH = 5;
u8g2_uint_t const Glyph::S_HEIGHT = 7;
uint8_t const Glyph::S_BITS[7] = {0x0e, 0x01, 0x01, 0x0e, 0x10, 0x10, 0x0e};

/**
 * Up arrow.
 */
u8g2_uint_t const Glyph::UP_ARROW2_WIDTH = 7;
u8g2_uint_t const Glyph::UP_ARROW2_HEIGHT = 7;
uint8_t const Glyph::UP_ARROW2_BITS[7] = {0x08, 0x1c, 0x2a, 0x49, 0x08, 0x08, 0x08};

/**
 * Decimal dot.
 */
u8g2_uint_t const Glyph::DP_WIDTH = 2;
u8g2_uint_t const Glyph::DP_HEIGHT = 2;
uint8_t const Glyph::DP_BITS[2] = {0x03, 0x03};

/**
 * Bleeper.
 */
u8g2_uint_t const Glyph::BLEEPER_WIDTH = 8;
u8g2_uint_t const Glyph::BLEEPER_HEIGHT = 7;
uint8_t const Glyph::BLEEPER_BITS[7] = {0x60, 0x50, 0x4e, 0x46, 0x4e, 0x50, 0x60};

/**
 * Diode.
 */
u8g2_uint_t const Glyph::DIODE_WIDTH = 8;
u8g2_uint_t const Glyph::DIODE_HEIGHT = 7;
uint8_t const Glyph::DIODE_BITS[7] = {0x00, 0x24, 0x34, 0xff, 0x34, 0x24, 0x00};

/**
 * DC.
 */
u8g2_uint_t const Glyph::DC_WIDTH = 8;
u8g2_uint_t const Glyph::DC_HEIGHT = 6;
uint8_t const Glyph::DC_BITS[6] = {0xff, 0x00, 0x00, 0xdb, 0x00, 0x00};

/**
 * AC.
 */
u8g2_uint_t const Glyph::AC_WIDTH = 7;
u8g2_uint_t const Glyph::AC_HEIGHT = 3;
uint8_t const Glyph::AC_BITS[3] = {0x06, 0x49, 0x30};

/**
 * DC on to of the AC.
 */
u8g2_uint_t const Glyph::AC_DC_WIDTH = 7;
u8g2_uint_t const Glyph::AC_DC_HEIGHT = 1;
uint8_t const Glyph::AC_DC_BITS[1] = {0x7f};

/**
 * Down arrow.
 */
u8g2_uint_t const Glyph::DOWN_ARROW_WIDTH = 5;
u8g2_uint_t const Glyph::DOWN_ARROW_HEIGHT = 3;
uint8_t const Glyph::DOWN_ARROW_BITS[3] = {0x11, 0x0a, 0x04};

/**
 * Up arrow.
 */
u8g2_uint_t const Glyph::UP_ARROW_WIDTH = 5;
u8g2_uint_t const Glyph::UP_ARROW_HEIGHT = 3;
uint8_t const Glyph::UP_ARROW_BITS[3] = {0x04, 0x0a, 0x11};

/**
 * Z of Hertz.
 */
u8g2_uint_t const Glyph::Z_WIDTH = 9;
u8g2_uint_t const Glyph::Z_HEIGHT = 11;
uint8_t const Glyph::Z_BITS[22] = {0x00,
                                   0x00,
                                   0xfc,
                                   0x00,
                                   0x80,
                                   0x00,
                                   0x40,
                                   0x00,
                                   0x20,
                                   0x00,
                                   0x10,
                                   0x00,
                                   0x08,
                                   0x00,
                                   0x04,
                                   0x00,
                                   0x02,
                                   0x00,
                                   0x7e,
                                   0x00,
                                   0x00,
                                   0x00};

/**
 * Function arrows at the bottom line.
 */
u8g2_uint_t const Glyph::FUNCTION_ARROW_WIDTH = 5;
u8g2_uint_t const Glyph::FUNCTION_ARROW_HEIGHT = 6;
uint8_t const Glyph::FUNCTION_ARROW_BITS[6] = {0x04, 0x04, 0x04, 0x1f, 0x0e, 0x04};

/**
 * Rising edge.
 */
u8g2_uint_t const Glyph::RISING_EDGE_WIDTH = 14;
u8g2_uint_t const Glyph::RISING_EDGE_HEIGHT = 16;
uint8_t const Glyph::RISING_EDGE_BITS[32] = {0x00,
                                             0x00,
                                             0x00,
                                             0x00,
                                             0x80,
                                             0x0f,
                                             0x80,
                                             0x00,
                                             0x80,
                                             0x00,
                                             0x80,
                                             0x00,
                                             0x80,
                                             0x00,
                                             0xc0,
                                             0x01,
                                             0xe0,
                                             0x03,
                                             0x80,
                                             0x00,
                                             0x80,
                                             0x00,
                                             0x80,
                                             0x00,
                                             0x80,
                                             0x00,
                                             0xfc,
                                             0x00,
                                             0x00,
                                             0x00,
                                             0x00,
                                             0x00};

/**
 * Falling edge.
 */
u8g2_uint_t const Glyph::FALLING_EDGE_WIDTH = 14;
u8g2_uint_t const Glyph::FALLING_EDGE_HEIGHT = 16;
uint8_t const Glyph::FALLING_EDGE_BITS[32] = {0x00,
                                              0x00,
                                              0x00,
                                              0x00,
                                              0xfc,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0xe0,
                                              0x03,
                                              0xc0,
                                              0x01,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x00,
                                              0x80,
                                              0x0f,
                                              0x00,
                                              0x00,
                                              0x00,
                                              0x00};