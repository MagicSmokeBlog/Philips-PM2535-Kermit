#include <Wire.h>

#include "DisplayApp.h"

DisplayApp *DisplayApp::app;

DisplayApp::DisplayApp(U8G2 &u8g2, uint8_t pcf8576Address) : u8g2(u8g2), displayDriver(DisplayDriver(u8g2))
{
    DisplayApp::app = this;

    this->pcf8576Address = pcf8576Address;
}

void DisplayApp::run()
{
    Wire.begin(this->pcf8576Address);
    u8g2.begin();
    this->displayDriver.render(this->displayState);
    Wire.onReceive(DisplayApp::wireReceiveHandler);
}

void DisplayApp::receiveData(int count)
{
    uint8_t index = 0;
    while (Wire.available())
    {
        uint8_t data = Wire.read();
        if (index > 4)
        {
            if (count == 22)
            {
                this->frame[index - 2] = data;
            }

            if (count == 8)
            {
                this->frame[index - 5] = data;
            }
        }
        index++;
    }
}

void DisplayApp::receiveHandler(int count)
{
    this->receiveData(count);
    this->decoder.decode(this->displayState, this->frame);
    this->displayDriver.render(this->displayState);
}

void DisplayApp::wireReceiveHandler(int count)
{
    DisplayApp::app->receiveHandler(count);
}