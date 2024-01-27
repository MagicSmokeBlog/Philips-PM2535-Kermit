#ifndef PM25XX_OLED_DISPLAY_DECODER_H
#define PM25XX_OLED_DISPLAY_DECODER_H

#include "DisplayState.h"

/**
 * Class for decoding 40 nibbles.
 */
class Decoder
{
public:
    /**
     * Decodes 40 nibbles to a display state.
     *
     * @param state The display state.
     * @param frame The 40 nibbles.
     */
    void decode(DisplayState &state, uint8_t frame[20]) const;

private:
    /**
     * Decodes 2 nibbles of a seven segment display to a char.
     *
     * @param value The 2 nibbles.
     */
    char decodeSevenSegment(uint8_t value) const;

    /**
     * Decodes 4 nibbles of a sixteen segment display to a char.
     *
     * @param value The 4 nibbles.
     */
    char decodeSixteenSegmentChar(uint16_t value) const;

    /**
     * Decodes 4 nibbles of a sixteen segment display to a enumeration of a glyph.
     *
     * @param value The 4 nibbles.
     */
    int decodeSixteenSegmentGlyph(uint16_t value) const;
};

#endif //PM25XX_OLED_DISPLAY_DECODER_H
