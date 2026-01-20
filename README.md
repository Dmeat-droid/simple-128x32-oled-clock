# Clock

## Overview
A physical clock that will display information current date and time. To make the layout for the lcd, i use the [lopaka](https://lopaka.app).

## Components
- Arduino Nano (or the other will be fine)
- RTC DS1302
- LCD 128x32 (you can also use the other size)
- Jumper wires
- USB cable (to upload the program)

## Pin Configuration
| Component | Arduino Pin |
|-----------|-------------|
| RTC (VCC) | 5V          |
| RTC (GND) | GND         |
| RTC (CLK) | D4          |
| RTC (DAT) | D5          |
| RTC (RST) | D6          |
| LCD (VCC) | 5V          |
| LCD (GND) | GND         |
| LCD (SDA) | A4          |
| LCD (SCK) | A5          |

## Requred Libraries
Please install the following library via the Arduino IDE Library Manager:
* [Ds1302](https://github.com/Treboada/Ds1302)
* [U8g2lib](https://github.com/olikraus/u8g2)

## How It Works
The lcd will display the curernt date and time

## Setup & Usage
1.  **Assemble:** Connect the components according to the pin configuration table above.
2.  **Install Libraries:** Ensure the required libraries are installed in your Arduino IDE.
3.  **Set Time:** Open the code, uncomment the lines responsible for setting the time (usually `rtc.setSeconds`, etc.), and upload the sketch.
4.  **Run:** Comment those lines out again and re-upload the sketch. This ensures the clock doesn't reset every time the Arduino restarts.
5.  **Enjoy:** Your clock is now running!

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
