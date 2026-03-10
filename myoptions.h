/* 
   2026-03-09: Production version
    
   Note: Some of the options in this file might have been moved 
   to the configuration menu system in later Fusion-releases.
*/

#ifndef myoptions_h
#define myoptions_h

#ifndef ARDUINO_ESP32S3_DEV
  #define ARDUINO_ESP32S3_DEV
#endif

/* You can set the program language here. */
#define L10N_LANGUAGE EN

/* Display name days (Norwegian: Navnedag) */
// #define NAMEDAYS_FILE en

#define USE_BUILTIN_LED false /* The RGB LED does not turn on.. */

/* Display */
/* Alt. #1: */
/* ILI9341*/
#define DSP_MODEL DSP_ILI9341
#define TS_MODEL  TS_MODEL_XPT2046
#define TS_CS			41
#define TFT_ROTATE      1        /*  Display rotation. 0 - 0, 1 - 90, 2 - 180, 3 - 270 degrees */

/* Alt. #2 */
/* ST7796 */
//#define DSP_MODEL DSP_ST7796

/* Common SPI setup */
#define TFT_MOSI  	11
#define TFT_MISO  	13       // SPI MISO (if supported by your module, otherwise set to -1
#define TFT_CLK   	12
#define TFT_DC			 2
#define TFT_CS			10
#define TFT_RST     21
#define TFT_BL    	14       // Backlight control (set -1 if not connected)
/* If your display has a brightness control pin, you can set it here. */
// #define BRIGHTNESS_PIN 14

/* PCM5102A  DAC */
#define VS1053_CS		255
#define I2S_DOUT		7
#define I2S_BCLK		3
#define I2S_LRC     1

/* ENCODER 1 */
/* ------- */
/* Encoder */
/* ------- */
/* */
#define ENC_BTNR		5
#define ENC_BTNL		6
#define ENC_BTNB		15
#define ENC_INTERNALPULLUP	false
/* */

/* ENCODER 2 
   Not implemented on my PCB */
/*
#define ENC2_BTNR		-1
#define ENC2_BTNL		-1
#define ENC2_BTNB		-1
#define ENC2_INTERNALPULLUP	true
*/

/* CLOCK MODUL RTC DS3132 
   Not implemented on my PCB */
// #define RTC_SCL        -1
// #define RTC_SDA        -1
// #define RTC_MODULE DS3231

/* REMOTE CONTROL INFRARED RECEIVER */
#define IR_PIN 42

// #define WAKE_PIN	-1

/* DS CARD */
/* SCK, MISO, MOSI */
/* */
#define SD_SPIPINS	39,40,47
#define SDC_CS  		48
#define USE_SD
#define SDSPISPEED	4000000 
/* */

/* 
   Inactive segments of the clock, true or false. */
#define CLOCKFONT_MONO true

/* Define 12-hour time format.*/
//#define AM_PM_STYLE

/* Turn on the original seven-segment font. */
// #define CLOCKFONT VT_DIGI_OLD

/* 
   Speaks the time using Google TTS voice in the specified language and every specified minute.
*/
#define CLOCK_TTS_ENABLED          true  // Enabled (true) or disabled (false)
#define CLOCK_TTS_LANGUAGE         "EN"  // Language ( EN, HU, PL, NL, DE, RU, RO ,FR, GR)
#define CLOCK_TTS_INTERVAL_MINUTES 30    // Hány percenként mondja be. - How many times a minute does it say.

/* With this setting there is no scrolling on the weather bar. */
// #define WEATHER_FMT_SHORT
/* With this setting, the full weather report is displayed. */
#define EXT_WEATHER  true

/* With this setting, the wind speed will be km/h. */
//#define WIND_SPEED_IN_KMH

/* 
The VU meter supports two types of display modes.
BOOMBOX_STYLE is the style when the display swings out from the center to two sides. You can set it here.
If there is a // sign at the beginning of the line, the basic VU meter is working, swinging out from left to right. 
*/
#define BOOMBOX_STYLE

/* 
 A white bar will appear at the end of the VU meter at the peak values ​​if you enable this. The // at the beginning of the line will disable it.
*/
#define VU_PEAK

/* 
When selecting from the station list, you do not need to press the rotary encoder button, the channel will automatically
change when you exit. (By Zsigmond Becskehazi) */
#define DIRECT_CHANNEL_CHANGE

/* How long to return to the main screen from the station list. (seconds) */
#define STATIONS_LIST_RETURN_TIME 2

#endif  //myoptions_h