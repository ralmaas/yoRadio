# yoradio
How to handle some issues regarding display and nordic characters.\
The last batch of ILI9341 displays received from China turned out to be rotated 90 degree and was using 2/3 of the display; the wrong orientation.\
Also Nordic characters was displayed as two-byte graphical symbols on the ILI9341

## Prerequisite
Install Visual Studio Code\
Add the pioarduino extension\
Download he latest repositor:\
https://github.com/SimZs/yoRadio-Fusion\
Uncomment the two lines regarding ILI934 and XPT2046\
Perform a compilation in order to download the libraries

## ILI9341
This section is only used for the 90 degree oriented Chinees variant
### .pio/libdeps/yoradio-esp32s3n16r8/Adafruit ILI9341/Adafruit_ILI9341.h
On line 46 make this update:\
#define ILI9341_TFTWIDTH 320  ///< ILI9341 max TFT width was 240\
#define ILI9341_TFTHEIGHT 240 ///< ILI9341 max TFT height was 320\

### src/displays/displayILI9341.cpp
On line 21:\
void DspCore::flip(){ setRotation(config.store.flipscreen?0:2); } // Was 1:3

## GFX
Copy the file fonts/glcdfont_EN.c to directory .pio/libdeps/yoradio-esp32s3n16r8/Adafruit GFX Library and rename to glcdfont.c
### .pio/libdeps/yoradio-esp32s3n16r8/Adafruit GFX Library/Adafruit_GFX.h:
Line 253 (below bool_cp437...) add this:\
  bool _inLongChar;
### .pio/libdeps/yoradio-esp32s3n16r8/Adafruit GFX Library/Adafruit_GFX.cpp:
In the initialization function (Adafruit_GFX::Adafruit_GFX(....)
After line 119 (gfxFont = NULL) add this:\
  _inLongChar = false;

In function "Adafruit_GFX::write(...)" around line 1362) insert this just under "if (!gfxFont){  // 'Classic' built-in font":

    // If character is 194 or 195, this flags the next as a special character.
    if ((c == 194) || (c == 195)) 
    {
    	// A two-byte unicode is in progress....
        _inLongChar = true; // Just flag and return
        return(1);
    } 
    if (_inLongChar)
    {
    	// Handle the character - just make it a space if unknown
      unsigned char c1 = 0;

      if ((c == 134) || (c == 166))
        c1 = 146; // Map  æ/Æ
      if (c == 184)
        c1 = 236; // Map  ø
      if ((c == 152) || (c == 182))
        c1 = 237; // Map  Ø/¨Ø
      if (c == 165)
        c1 = 134; // Map  å
      if (c == 133)
        c1 = 143; // Map  Å
      if (c == 164)
        c1 = 142; // Map  Ä
      if (c == 169)
        c1 = 130; // Map  é
      if (c1 == 0) 
        c1 = 32; // Map 'odd' character to space, which is close enough for now
                  // Or return(1) may look better 
      c = c1;
      _inLongChar = false;
    }

