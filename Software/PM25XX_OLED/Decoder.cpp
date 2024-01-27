#include <Arduino.h>

#include "Decoder.h"

void Decoder::decode(DisplayState &state, uint8_t frame[20]) const
{
    // Frame[0]
    state.isOnScaledMeasurements = frame[0] & 0x01;
    state.isOnDeltaPercent = frame[0] & 0x02;
    state.isOnMax = frame[0] & 0x04;
    state.isOnBurst = frame[0] & 0x08;
    state.isOnSequence = frame[0] & 0x10;
    state.isOnDelay = frame[0] & 0x20;
    state.isOnAcIndicator = frame[0] & 0x40;
    state.isOnDcIndicator = frame[0] & 0x80;

    // Frame[1]
    state.isOnShift = frame[1] & 0x01;
    state.isOnBleeper = frame[1] & 0x02;
    state.isOn4Wire = frame[1] & 0x04;
    // Bit 0x08 is unused.
    state.isOnLimitsMode = frame[1] & 0x20;
    state.isOnCalibrationMode = frame[1] & 0x40;
    state.isOnMin = frame[1] & 0x40;
    state.isOnRead = frame[1] & 0x80;

    // Frame[2]
    state.isOnNegativePeak = frame[2] & 0x01;
    state.isOnPositivePeak = frame[2] & 0x02;
    state.isOnZofHertz = frame[2] & 0x04;
    state.isOnUnitDecimalDot[0] = frame[2] & 0x08;
    state.isOnUnitDecimalDot[1] = frame[2] & 0x08;
    state.isOn2Wire = frame[2] & 0x10;
    state.isOnDiode = frame[2] & 0x20;
    state.isOnHf = frame[2] & 0x40;
    state.isOnAcDcIndicator = frame[2] & 0x80;

    // Frame[3] and Frame[4]
    uint16_t frame34;
    frame34 = (uint16_t) frame[3];
    frame34 = frame34 << 8;
    frame34 += (uint16_t) frame[4];
    state.unitChar[1] = this->decodeSixteenSegmentChar(frame34);
    state.unitGlyph[1] = this->decodeSixteenSegmentGlyph(frame34);

    // Frame[5] and Frame[6]
    uint16_t frame56;
    frame56 = (uint16_t) frame[5];
    frame56 = frame56 << 8;
    frame56 += (uint16_t) frame[6];
    state.unitChar[0] = this->decodeSixteenSegmentChar(frame56);
    state.unitGlyph[0] = this->decodeSixteenSegmentGlyph(frame56);

    // Frame[7]
    state.bargraph[10] = frame[7] & 0x01;
    state.bargraph[9] = frame[7] & 0x02;
    state.bargraph[11] = frame[7] & 0x04;
    state.bargraph[12] = frame[7] & 0x08;
    state.bargraph[15] = frame[7] & 0x10;
    state.bargraph[16] = frame[7] & 0x20;
    state.bargraph[14] = frame[7] & 0x40;
    state.bargraph[13] = frame[7] & 0x80;

    // Frame[8]
    state.bargraph[2] = frame[8] & 0x01;
    state.bargraph[1] = frame[8] & 0x02;
    state.bargraph[3] = frame[8] & 0x04;
    state.bargraph[4] = frame[8] & 0x08;
    state.bargraph[7] = frame[8] & 0x10;
    state.bargraph[8] = frame[8] & 0x20;
    state.bargraph[6] = frame[8] & 0x40;
    state.bargraph[5] = frame[8] & 0x80;

    // Frame[9]
    state.isOnValueDecimalDot[6] = frame[9] & 0x08;
    state.value[6] = this->decodeSevenSegment(frame[9] & 0xf7);

    // Frame[10]
    state.isOnValueDecimalDot[5] = frame[10] & 0x08;
    state.value[5] = this->decodeSevenSegment(frame[10] & 0xf7);

    // Frame[11]
    state.isOnValueDecimalDot[4] = frame[11] & 0x08;
    state.value[4] = this->decodeSevenSegment(frame[11] & 0xf7);

    // Frame[12]
    state.isOnValueDecimalDot[3] = frame[12] & 0x08;
    state.value[3] = this->decodeSevenSegment(frame[12] & 0xf7);

    // Frame[13]
    state.isOnValueDecimalDot[2] = frame[13] & 0x08;
    state.value[2] = this->decodeSevenSegment(frame[13] & 0xf7);

    // Frame[14]
    state.isOnValueDecimalDot[1] = frame[14] & 0x08;
    state.value[1] = this->decodeSevenSegment(frame[14] & 0xf7);

    // Frame[15]
    state.value[0] = this->decodeSevenSegment(frame[15]);

    // Frame[16]
    state.isOnLighting = frame[16] & 0x01;
    state.isOnRemote = frame[16] & 0x02;
    state.isOnBattery = frame[16] & 0x08;
    state.isOnCrestFactorExceed = frame[16] & 0x10;
    state.isOnServiceRequest = frame[16] & 0x20;
    state.isOnValueDecimalDot[0] = frame[16] & 0x80;
    if (frame[16] & 0x04)
    {
        state.polarity[0] = '+';
    }
    else if (frame[16] & 0x40)
    {
        state.polarity[0] = '-';
    }
    else
    {
        state.polarity[0] = ' ';
    }

    // Frame[17]
    state.isOnManualRange = frame[17] & 0x01;
    state.isOnListener = frame[17] & 0x02;
    state.isOnSingleTrigger = frame[17] & 0x04;
    state.isOnFunction[0] = frame[17] & 0x08;
    state.isOnZero = frame[17] & 0x10;
    state.isOnSet = frame[17] & 0x20;
    // Bits 0x40 and 0x80 are unused.

    // Frame[18]
    state.isOnSpeed3 = frame[18] & 0x01;
    state.isOnOnly = frame[18] & 0x02;
    state.isOnSpeed4 = frame[18] & 0x04;
    state.isOnFunction[1] = frame[18] & 0x08;
    state.isOnSpeed2 = frame[18] & 0x10;
    state.isOnTalk = frame[18] & 0x20;
    state.isOnSpeed1 = frame[18] & 0x40;
    state.isOnSpeed = frame[18] & 0x80;

    // Frame[19]
    state.isOnHold = frame[19] & 0x01;
    state.isOnSeconds = frame[19] & 0x02;
    state.isOnProbe = frame[19] & 0x04;
    state.isOnFunction[3] = frame[19] & 0x08;
    state.isOnFunction[2] = frame[19] & 0x10;
    state.bargraph[0] = frame[19] & 0x20;
    state.isOnNull = frame[19] & 0x40;
    state.isOnFilter = frame[19] & 0x80;
}

char Decoder::decodeSevenSegment(uint8_t value) const
{
    switch (value)
    {
        case 0x00:
            return ' ';

        case 0x01:
            return '-';

        case 0x02:
            return '\'';

        case 0x05:
            return 'R';

        case 0x08:
            return '.';

        case 0x12:
            return '\"';

        case 0x27:
            return 'F';

        case 0x35:
            return '?';

        case 0x37:
            return 'P';

        case 0x50:
            return '1';

        case 0x53:
            return '4';

        case 0x57:
            return 'H';

        case 0x70:
            return '7';

        case 0x73:
            return 'Q';

        case 0x76:
            return 'N';

        case 0x77:
            return 'A';

        case 0x80:
            return '_';

        case 0x81:
            return '=';

        case 0x86:
            return 'L';

        case 0x87:
            return 'T';

        case 0xA6:
            return 'C';

        case 0xA7:
            return 'E';

        case 0xB5:
            return '2';

        case 0xC7:
            return 'B';

        case 0xD3:
            return 'Y';

        case 0xD5:
            return 'D';

        case 0xD6:
            return 'U';

        case 0xE3:
            return '5';

        case 0xE6:
            return 'G';

        case 0xE7:
            return '6';

        case 0xF0:
            return ']';

        case 0xF1:
            return '3';

        case 0xF3:
            return '9';

        case 0xF4:
            return 'J';

        case 0xF5:
            return '@';

        case 0xF6:
            return 'O';

        case 0xF7:
            return '8';

        default:
            return '?';
    }
}

char Decoder::decodeSixteenSegmentChar(uint16_t value) const
{
    switch (value)
    {
        case 0x0145:
            return 'V';

        case 0x0217:
            return 'P';

        case 0x0E80:
            return 'k';

        case 0x2017:
            return 'F';

        case 0x3600:
            return 0xB0; // '°'

        case 0x4480:
            return 'n';

        case 0x4494:
            return 'm';

        case 0x5125:
            return 'M';

        case 0x5415:
            return 'H';

        case 0x7417:
            return 'A';

        case 0xA00F:
            return 'C';

        case 0xC7D3:
            return '%';

        case 0xD480:
            return 'd';

        case 0xF68A:
            return 'B';

        case 0xc080:
            return 0xb5; // micro

        default:
            return ' ';
    }
}

int Decoder::decodeSixteenSegmentGlyph(uint16_t value) const
{
    switch (value)
    {
        case 0x2288:
            return Glyph::RISING_EDGE;

        case 0x7007:
            return Glyph::OMEGA;

        case 0x8282:
            return Glyph::FALLING_EDGE;

        default:
            return Glyph::NONE;
    }
}
