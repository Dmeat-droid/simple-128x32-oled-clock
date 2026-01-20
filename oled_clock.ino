#include <U8g2lib.h>
#include <Ds1302.h>


Ds1302 rtc(6 /*ENA/RST pin*/, 4 /*CLK pin*/, 5/*DAT pin*/);


// you can use another pin for the SCL and SDA by replace the 'SDA' and 'SCL' with the pin you wish for
U8G2_SSD1306_128X32_UNIVISION_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE); 


//
const static char* WeekDays[] =
{
    "Monday,",
    "Tuesday,",
    "Wednesday,",
    "Thursday,",
    "Friday,",
    "Saturday,",
    "Sunday,"
};

const static char* Months[] =
{
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Okt",
    "Nov",
    "Dec"
};

void setup() {
  u8g2.begin();
  Serial.begin(9600);
  rtc.init();// Initiating the rtc

  // UNCOMMENT THIS PART IF YOU WANT TO SET UP THE DATE AND TIME
  // // Create a DateTime structure
  //   Ds1302::DateTime dt;

  // // --- SET YOUR DATE AND TIME HERE ---
  // dt.year = 26;    // Set Year (Last 2 digits, e.g., 26 for 2026)
  // dt.month = 1;    // Set Month (1-12)
  // dt.day = 20;     // Set Day of Month (1-31)
  // dt.hour = 14;    // Set Hour (0-23)
  // dt.minute = 30;  // Set Minute (0-59)
  // dt.second = 0;   // Set Second (0-59)
  // dt.dow = 2;      // Set Day of Week (1=Mon, 2=Tue, ... 7=Sun)
  
  // // Upload the time to the RTC module
  // rtc.setDateTime(&dt);


}

void loop() {
  Ds1302::DateTime now;
  rtc.getDateTime(&now);
  char buffer[10];

  static uint8_t last_second = 0;
  //displaying to serial monitor
    if (last_second != now.second)
    {
      last_second = now.second;
      u8g2.firstPage();

      Serial.print("20");
      Serial.print(now.year);    // 00-99
      Serial.print('-');
      if (now.month < 10) Serial.print('0');
      Serial.print(now.month);   // 01-12
      Serial.print('-');
      if (now.day < 10) Serial.print('0');
      Serial.print(now.day);     // 01-31
      Serial.print(' ');
      Serial.print(WeekDays[now.dow - 1]); // 1-7
      Serial.print(' ');
      if (now.hour < 10) Serial.print('0');
      Serial.print(now.hour);    // 00-23
      Serial.print(':');
      if (now.minute < 10) Serial.print('0');
      Serial.print(now.minute);  // 00-59
      Serial.print(':');
      if (now.second < 10) Serial.print('0');
      Serial.print(now.second);  // 00-59
      Serial.println();
    }
  delay(100);

  //display to lcd
  do{
      u8g2.setFontMode(1);
      u8g2.setBitmapMode(1);
      u8g2.setFont(u8g2_font_t0_22b_tr);
      u8g2.drawStr(37, 15, ":");
      
      u8g2.setFont(u8g2_font_haxrcorp4089_tr);
      u8g2.drawStr(4, 30, (WeekDays[now.dow-1]));

      // Input the day, year, and etc into buffer first so if there's only a digit, it will replace the front digit to 0
      sprintf(buffer, "%02d", now.day);
      u8g2.drawStr(64, 30, buffer);
      
      sprintf(buffer, "%04d", (now.year + 2000));
      u8g2.drawStr(100, 30, buffer);

      u8g2.drawStr(78, 30, (Months[now.month-1]));

      u8g2.setFont(u8g2_font_profont29_tr);
      sprintf(buffer, "%02d", (now.minute));
      u8g2.drawStr(48, 21, buffer);

      sprintf(buffer, "%02d", (now.hour));
      u8g2.drawStr(4, 21, buffer);

      u8g2.setFont(u8g2_font_t0_22b_tr);
      u8g2.drawStr(81, 15, ":");

      u8g2.setFont(u8g2_font_profont29_tr);
      sprintf(buffer, "%02d", (now.second));
      u8g2.drawStr(93, 21, buffer);


    
    } while(u8g2.nextPage());
  
}
