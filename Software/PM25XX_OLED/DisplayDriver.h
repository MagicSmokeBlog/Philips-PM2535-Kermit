#ifndef PM25XX_OLED_DISPLAY_DISPLAYDRIVER_H
#define PM25XX_OLED_DISPLAY_DISPLAYDRIVER_H

#include <U8g2lib.h>

#include "DisplayState.h"

class DisplayDriver
{
public:
    /**
     * Object constructor.
     *
     * @param u8g2 The U8g2 display driver.
     */
    DisplayDriver(U8G2 &u8g2);

    /**
     * Renders the display according to the display state.
     *
     * @param displayState The display state.
     */
    void render(DisplayState const &displayState);

private:
    /**
     * The U8g2 display driver.
     */
    U8G2 &u8g2;

    /**
     * Draws the measured value.
     *
     * @param displayState The display state.
     */
    void drawValue(DisplayState const &displayState);

    /**
     * Draws the measured unit.
     *
     * @param displayState The display state.
     */
    void drawUnit(DisplayState const &displayState);

    /**
     * Draws the measured unit glyphs.
     *
     * @param displayState The display state.
     */
    void drawUnitGlyphs(DisplayState const &displayState);

    /**
     * Draws the measured unit dots.
     *
     * @param displayState The display state.
     */
    void drawUnitDots(DisplayState const &displayState);

    /**
     * Draws the top line.
     *
     * @param displayState The display state.
     */
    void drawTopLine(DisplayState const &displayState);

    /**
     * Draws the analog bar.
     *
     * @param displayState The display state.
     */
    void drawAnalogBar(DisplayState const &displayState);

    /**
     * Draws the bottom line.
     *
     * @param displayState The display state.
     */
    void drawBottomLine(DisplayState const &displayState);

    /**
     * Draws the function arrows.
     *
     * @param displayState The display state.
     */
    void drawFunctionArrows(DisplayState const &displayState);

    /**
     * Draws the icon indicator on the left of the display.
     *
     * @param displayState The display state.
     */
    void drawIndicatorsIconLeft(DisplayState const &displayState);

    /**
     * Draws the icon indicators on the right of the display.
     *
     * @param displayState The display state.
     */
    void drawIndicatorsIconRight(DisplayState const &displayState);

    /**
     * Draws the text indicators on the right of the display.
     *
     * @param displayState The display state.
     */
    void drawIndicatorsTextRight(DisplayState const &displayState);

    /**
     * Draws a text with inverse color.
     *
     * @param displayState The display state.
     */
    void drawStrInverse(u8g2_uint_t x, u8g2_uint_t y, char const *text);

    /**
     * Draws a frame on the other edges of the display.
     */
     void drawRealEstate();
};

#endif //PM25XX_OLED_DISPLAY_DISPLAYDRIVER_H
