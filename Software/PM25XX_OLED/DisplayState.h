#ifndef PM25XX_OLED_DISPLAY_DISPLAYSTATE_H
#define PM25XX_OLED_DISPLAY_DISPLAYSTATE_H

#include "Glyph.h"

/**
 * Class for the state of the display.
 */
class DisplayState
{
public:
    /**
     * The measured value.
     */
    char value[8] = {'8', '8', '8', '8', '8', '8', '8', '\0'};
    bool isOnValueDecimalDot[7] = {true, true, true, true, true, true, true};

    /**
     * The unit of the measured value.
     */
    char unitChar[3] = {' ', ' ', '\0'};
    int unitGlyph[2] = {Glyph::RISING_EDGE, Glyph::FALLING_EDGE};
    bool isOnUnitDecimalDot[2] = {true, true};

    /**
     * Top line (IEC-625/IEEE-488 messages).
     */
    bool isOnRemote = true;
    bool isOnServiceRequest = true;
    bool isOnListener = true;
    bool isOnTalk = true;
    bool isOnOnly = true;

    /**
     * Analog bargraph indicator.
     */
    bool bargraph[17] = {true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true,
                         true};

    /**
     * Bottom line.
     */
    bool isOnManualRange = true;
    bool isOnSingleTrigger = true;
    bool isOnSpeed = true;
    bool isOnSpeed1 = true;
    bool isOnSpeed2 = true;
    bool isOnSpeed3 = true;
    bool isOnSpeed4 = true;
    bool isOnFilter = true;
    bool isOnNull = true;
    bool isOnHold = true;
    bool isOnProbe = true;

    /**
     * Indicators on the left.
     */
    bool isOnLighting = true; // Did not find in documentation.
    bool isOnCrestFactorExceed = true;
    bool isOnBattery = true;
    char polarity[2] = {'+', '\0'};

    /**
     * Indicators (icons) on the right.
     */
    bool isOnBleeper = true;
    bool isOnSeconds = true;
    bool isOnDiode = true;
    bool isOn2Wire = true;
    bool isOn4Wire = true;
    bool isOnPositivePeak = true;
    bool isOnNegativePeak = true;
    bool isOnHf = true; // Did not find in documentation.
    bool isOnZofHertz = true;
    bool isOnAcIndicator = true;
    bool isOnAcDcIndicator = true;
    bool isOnDcIndicator = true;

    /**
     * Indicators (text) on the right.
     */
    bool isOnShift = true;
    bool isOnLimitsMode = true;
    bool isOnDeltaPercent = true;
    bool isOnCalibrationMode = true;
    bool isOnScaledMeasurements = true;
    bool isOnMin = true;
    bool isOnMax = true;
    bool isOnRead = true;
    bool isOnBurst = true;
    bool isOnSequence = true;
    bool isOnDelay = true;
    bool isOnZero = true;
    bool isOnSet = true;

    /**
     * Function key indicators.
     */
    bool isOnFunction[4] = {true, true, true, true};
};

#endif //PM25XX_OLED_DISPLAY_DISPLAYSTATE_H
