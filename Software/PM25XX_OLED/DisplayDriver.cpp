#include "DisplayDriver.h"
#include "DisplayGeometry.h"
#include "Glyph.h"
#include "PM25XX_OLED.h"

DisplayDriver::DisplayDriver(U8G2 &u8g2) : u8g2(u8g2)
{
    // Nothing to do.
}

void DisplayDriver::render(DisplayState const &displayState)
{
    this->u8g2.clearBuffer();

#if DEBUG == 1
    this->drawRealEstate();
#endif

    this->drawValue(displayState);
    this->drawUnit(displayState);
    this->drawTopLine(displayState);
    this->drawAnalogBar(displayState);
    this->drawBottomLine(displayState);
    this->drawFunctionArrows(displayState);
    this->drawIndicatorsIconLeft(displayState);
    this->drawIndicatorsIconRight(displayState);
    this->drawIndicatorsTextRight(displayState);

    this->u8g2.sendBuffer();
}

void DisplayDriver::drawValue(DisplayState const &displayState)
{
    this->u8g2.setFont(u8g2_font_inr19_mf);
    this->u8g2.drawStr(DisplayGeometry::X_POLARITY, DisplayGeometry::Y_VALUE, displayState.polarity);
    this->u8g2.drawStr(DisplayGeometry::X_VALUE, DisplayGeometry::Y_VALUE, displayState.value);

    int const n = sizeof(displayState.isOnValueDecimalDot) / sizeof(displayState.isOnValueDecimalDot[0]);
    for (int i = 0; i < n; i++)
    {
        if (displayState.isOnValueDecimalDot[i])
        {
            this->u8g2.drawXBM(DisplayGeometry::X_VALUE_DOT + i * DisplayGeometry::X_VALUE_DOT_INCREMENT,
                               DisplayGeometry::Y_VALUE - Glyph::DP_HEIGHT,
                               Glyph::DP_WIDTH,
                               Glyph::DP_HEIGHT,
                               Glyph::DP_BITS);
        }
    }
}

void DisplayDriver::drawUnit(DisplayState const &displayState)
{
    this->u8g2.setFont(u8g2_font_inr16_mf);
    this->u8g2.drawStr(DisplayGeometry::X_UNIT, DisplayGeometry::Y_VALUE, displayState.unitChar);
    this->drawUnitGlyphs(displayState);
    this->drawUnitDots(displayState);
}

void DisplayDriver::drawUnitGlyphs(const DisplayState &displayState)
{
    int const n = sizeof(displayState.unitGlyph) / sizeof(displayState.unitGlyph[0]);
    for (int i = 0; i < n; i++)
    {
        int const x = DisplayGeometry::X_UNIT + i * DisplayGeometry::X_UNIT_DOT_INCREMENT;
        switch (displayState.unitGlyph[i])
        {
            case Glyph::OMEGA:
                u8g2.drawXBM(x,
                             DisplayGeometry::Y_VALUE - Glyph::OMEGA_HEIGHT,
                             Glyph::OMEGA_WIDTH,
                             Glyph::OMEGA_HEIGHT,
                             Glyph::OMEGA_BITS);
                break;

            case Glyph::FALLING_EDGE:
                u8g2.drawXBM(x,
                             DisplayGeometry::Y_VALUE - Glyph::FALLING_EDGE_HEIGHT + 2,
                             Glyph::FALLING_EDGE_WIDTH,
                             Glyph::FALLING_EDGE_HEIGHT,
                             Glyph::FALLING_EDGE_BITS);
                break;

            case Glyph::RISING_EDGE:
                u8g2.drawXBM(x,
                             DisplayGeometry::Y_VALUE - Glyph::RISING_EDGE_HEIGHT + 2,
                             Glyph::RISING_EDGE_WIDTH,
                             Glyph::RISING_EDGE_HEIGHT,
                             Glyph::RISING_EDGE_BITS);
                break;
        }
    }
}

void DisplayDriver::drawUnitDots(const DisplayState &displayState)
{
    int const n = sizeof(displayState.isOnUnitDecimalDot) / sizeof(displayState.isOnUnitDecimalDot[0]);
    for (int i = 0; i < n; i++)
    {
        if (displayState.isOnUnitDecimalDot[i])
        {
            u8g2.drawXBM(DisplayGeometry::X_UNIT_DOT + i * DisplayGeometry::X_UNIT_DOT_INCREMENT,
                         DisplayGeometry::Y_VALUE - Glyph::DP_HEIGHT,
                         Glyph::DP_WIDTH,
                         Glyph::DP_HEIGHT,
                         Glyph::DP_BITS);
        }
    }
}

void DisplayDriver::drawTopLine(DisplayState const &displayState)
{
    this->u8g2.setFont(u8g2_font_tom_thumb_4x6_tr);

    if (displayState.isOnRemote)
    {
        this->u8g2.drawStr(DisplayGeometry::X_REMOTE, DisplayGeometry::Y_TOP_LINE, "REM");
    }

    if (displayState.isOnServiceRequest)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SERVICE_REQUEST, DisplayGeometry::Y_TOP_LINE, "SRQ");
    }

    if (displayState.isOnListener)
    {
        this->u8g2.drawStr(DisplayGeometry::X_LISTENER, DisplayGeometry::Y_TOP_LINE, "LSTN");
    }

    if (displayState.isOnTalk)
    {
        this->u8g2.drawStr(DisplayGeometry::X_TALK, DisplayGeometry::Y_TOP_LINE, "TLK");
    }

    if (displayState.isOnOnly)
    {
        this->u8g2.drawStr(DisplayGeometry::X_ONLY, DisplayGeometry::Y_TOP_LINE, "ONLY");
    }
}

void DisplayDriver::drawAnalogBar(DisplayState const &displayState)
{
    int const n = sizeof(displayState.bargraph) / sizeof(displayState.bargraph[0]);
    for (int i = 0; i < n; i++)
    {
        if (displayState.bargraph[i])
        {
            char const *symbol = (i == 0 or i == (n - 1)) ? "|" : ".";
            this->u8g2.drawStr(DisplayGeometry::X_ANALOG_BAR + i * DisplayGeometry::X_ANALOG_BAR_INCREMENT,
                               DisplayGeometry::Y_TOP_LINE,
                               symbol);
        }
    }
}

void DisplayDriver::drawBottomLine(DisplayState const &displayState)
{
    this->u8g2.setFont(u8g2_font_tom_thumb_4x6_tr);

    if (displayState.isOnManualRange)
    {
        this->u8g2.drawStr(DisplayGeometry::X_MANUAL_RANGE, DisplayGeometry::Y_BOTTOM_LINE, "M RNG");
    }

    if (displayState.isOnSingleTrigger)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SINGLE_TRIGGER, DisplayGeometry::Y_BOTTOM_LINE, "S TRG");
    }

    if (displayState.isOnSpeed)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SPEED, DisplayGeometry::Y_BOTTOM_LINE, "SPEED");
    }

    if (displayState.isOnSpeed1)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SPEED1, DisplayGeometry::Y_BOTTOM_LINE, "1");
    }

    if (displayState.isOnSpeed2)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SPEED2, DisplayGeometry::Y_BOTTOM_LINE, "2");
    }

    if (displayState.isOnSpeed3)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SPEED3, DisplayGeometry::Y_BOTTOM_LINE, "3");
    }

    if (displayState.isOnSpeed4)
    {
        this->u8g2.drawStr(DisplayGeometry::X_SPEED4, DisplayGeometry::Y_BOTTOM_LINE, "4");
    }

    if (displayState.isOnFilter)
    {
        this->u8g2.drawStr(DisplayGeometry::X_FILTER, DisplayGeometry::Y_BOTTOM_LINE, "FILT");
    }

    if (displayState.isOnNull)
    {
        this->u8g2.drawStr(DisplayGeometry::X_NULL, DisplayGeometry::Y_BOTTOM_LINE, "NULL");
    }

    if (displayState.isOnHold)
    {
        this->u8g2.drawStr(DisplayGeometry::X_HOLD, DisplayGeometry::Y_BOTTOM_LINE, "HOLD");
    }

    if (displayState.isOnProbe)
    {
        this->u8g2.drawStr(DisplayGeometry::X_PROBE, DisplayGeometry::Y_BOTTOM_LINE, "PROBE");
    }
}

void DisplayDriver::drawFunctionArrows(DisplayState const &displayState)
{
    int const x[4] = {DisplayGeometry::X_FUNCTION_ARROW1,
                      DisplayGeometry::X_FUNCTION_ARROW2,
                      DisplayGeometry::X_FUNCTION_ARROW3,
                      DisplayGeometry::X_FUNCTION_ARROW4};
    int const n = sizeof(displayState.isOnFunction) / sizeof(displayState.isOnFunction[0]);
    for (int i = 0; i < n; i++)
    {
        if (displayState.isOnFunction[i])
        {
            this->u8g2.drawXBM(x[i],
                               DisplayGeometry::Y_BOTTOM_LINE - Glyph::FUNCTION_ARROW_HEIGHT + 1,
                               Glyph::FUNCTION_ARROW_WIDTH,
                               Glyph::FUNCTION_ARROW_HEIGHT,
                               Glyph::FUNCTION_ARROW_BITS);
        }
    }
}

void DisplayDriver::drawIndicatorsIconLeft(DisplayState const &displayState)
{
    if (displayState.isOnLighting)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_LIGHTING,
                           DisplayGeometry::Y_ICONS_LEFT,
                           Glyph::ZAP_WIDTH,
                           Glyph::ZAP_HEIGHT,
                           Glyph::ZAP_BITS);
    }

    if (displayState.isOnCrestFactorExceed)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_CREST_FACTOR_EXCEED,
                           DisplayGeometry::Y_ICONS_LEFT,
                           Glyph::UP_ARROW2_WIDTH,
                           Glyph::UP_ARROW2_HEIGHT,
                           Glyph::UP_ARROW2_BITS);
    }

    if (displayState.isOnBattery)
    {
        // Batteries not included.
    }
}

void DisplayDriver::drawIndicatorsIconRight(DisplayState const &displayState)
{
    if (displayState.isOnSeconds)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_SECONDS,
                           DisplayGeometry::Y_SECONDS,
                           Glyph::S_WIDTH,
                           Glyph::S_HEIGHT,
                           Glyph::S_BITS);
    }

    if (displayState.isOnBleeper)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT0,
                           DisplayGeometry::Y_TOP_LINE - Glyph::BLEEPER_HEIGHT + 1,
                           Glyph::BLEEPER_WIDTH,
                           Glyph::BLEEPER_HEIGHT,
                           Glyph::BLEEPER_BITS);
    }

    if (displayState.isOnDiode)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT0,
                           DisplayGeometry::Y_TEXT_INDICATOR2 - Glyph::DIODE_HEIGHT + 1,
                           Glyph::DIODE_WIDTH,
                           Glyph::DIODE_HEIGHT,
                           Glyph::DIODE_BITS);
    }

    if (displayState.isOn2Wire)
    {
        this->u8g2.drawStr(DisplayGeometry::X_ICONS_RIGHT1, DisplayGeometry::Y_TEXT_INDICATOR2, "2w");
    }

    if (displayState.isOn4Wire)
    {
        this->u8g2.drawStr(DisplayGeometry::X_ICONS_RIGHT2, DisplayGeometry::Y_TEXT_INDICATOR2, "4w");
    }

    if (displayState.isOnHf)
    {
        this->u8g2.drawStr(DisplayGeometry::X_ICONS_RIGHT2, DisplayGeometry::Y_TEXT_INDICATOR3, "HF");
    }

    if (displayState.isOnAcIndicator)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT2,
                           DisplayGeometry::DisplayGeometry::Y_TEXT_INDICATOR4 - Glyph::AC_DC_HEIGHT - 2,
                           Glyph::AC_WIDTH,
                           Glyph::AC_HEIGHT,
                           Glyph::AC_BITS);
    }

    if (displayState.isOnAcDcIndicator)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT2,
                           DisplayGeometry::DisplayGeometry::Y_TEXT_INDICATOR4 - Glyph::AC_DC_HEIGHT - 5,
                           Glyph::AC_DC_WIDTH,
                           Glyph::AC_DC_HEIGHT,
                           Glyph::AC_DC_BITS);
    }

    if (displayState.isOnDcIndicator)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT2,
                           DisplayGeometry::DisplayGeometry::Y_TEXT_INDICATOR5 - Glyph::DC_HEIGHT + 1,
                           Glyph::DC_WIDTH,
                           Glyph::DC_HEIGHT,
                           Glyph::DC_BITS);
    }

    if (displayState.isOnNegativePeak)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT1,
                           DisplayGeometry::Y_TOP_LINE + 21,
                           Glyph::DOWN_ARROW_WIDTH,
                           Glyph::DOWN_ARROW_HEIGHT,
                           Glyph::DOWN_ARROW_BITS);
    }

    if (displayState.isOnPositivePeak)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_ICONS_RIGHT1,
                           DisplayGeometry::Y_TOP_LINE + 16,
                           Glyph::UP_ARROW_WIDTH,
                           Glyph::UP_ARROW_HEIGHT,
                           Glyph::UP_ARROW_BITS);
    }

    if (displayState.isOnZofHertz)
    {
        this->u8g2.drawXBM(DisplayGeometry::X_UNIT_Z_OF_HERTZ,
                           DisplayGeometry::Y_VALUE - Glyph::Z_HEIGHT + 1,
                           Glyph::Z_WIDTH,
                           Glyph::Z_HEIGHT,
                           Glyph::Z_BITS);
    }
}

void DisplayDriver::drawIndicatorsTextRight(DisplayState const &displayState)
{
    if (displayState.isOnShift)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1 - 28, DisplayGeometry::Y_TOP_LINE, "SHIFT");
    }

    if (displayState.isOnLimitsMode)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1, DisplayGeometry::Y_TOP_LINE, "LIM");
    }

    if (displayState.isOnScaledMeasurements)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR2, DisplayGeometry::Y_TOP_LINE, "DELTA%");
    }

    if (displayState.isOnCalibrationMode)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1, DisplayGeometry::Y_TEXT_INDICATOR2, "CAL");
    }

    if (displayState.isOnDeltaPercent)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR2, DisplayGeometry::Y_TEXT_INDICATOR2, "AX+B");
    }

    if (displayState.isOnMin)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1, DisplayGeometry::Y_TEXT_INDICATOR3, "MIN");
    }

    if (displayState.isOnMax)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR2, DisplayGeometry::Y_TEXT_INDICATOR3, "MAX");
    }

    if (displayState.isOnRead)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1, DisplayGeometry::Y_TEXT_INDICATOR4, "READ");
    }

    if (displayState.isOnBurst)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR2, DisplayGeometry::Y_TEXT_INDICATOR4, "BURST");
    }

    if (displayState.isOnSequence)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1, DisplayGeometry::Y_TEXT_INDICATOR5, "SEQU");
    }

    if (displayState.isOnDelay)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR2, DisplayGeometry::Y_TEXT_INDICATOR5, "DELAY");
    }

    if (displayState.isOnZero)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR1, DisplayGeometry::Y_TEXT_INDICATOR6, "ZERO");
    }

    if (displayState.isOnSet)
    {
        this->drawStrInverse(DisplayGeometry::X_TEXT_INDICATOR2, DisplayGeometry::Y_TEXT_INDICATOR6, "SET");
    }
}

void DisplayDriver::drawStrInverse(u8g2_uint_t x, u8g2_uint_t y, char const *text)
{
    u8g2_uint_t const width = 6;

    this->u8g2.setFont(u8g2_font_tom_thumb_4x6_tr);

    this->u8g2.setFontMode(1);
    this->u8g2.setDrawColor(1);
    this->u8g2.drawBox(x - 1, y - 6, 4 * width + 1, 7);
    this->u8g2.setDrawColor(0);
    this->u8g2.drawStr(x + 2 * (width - strlen(text)), y, text);
    this->u8g2.setDrawColor(1);
}

void DisplayDriver::drawRealEstate()
{
    this->u8g2.drawFrame(0, 0, DisplayGeometry::WIDTH, DisplayGeometry::HEIGHT);
}
