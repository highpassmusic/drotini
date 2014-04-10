#ifndef DISPLAY_H
#define DISPLAY_H

#include "Leds.h"

#define ROW 0
#define SLOT 1

#define LCD_COLS 16         //Number of Cols
#define LCD_ROWS 2          //Number of Rows
#define NEXT_STATION 0x10   //Just offscreen Right
#define PREV_STATION 0x18   //Offscreen Left - 16
#define LINE1_START 0x00
#define LINE1_END 0x27
#define LINE2_START 0x40
#define LINE2_END 0x67

#define E_MODE 0x04         //Entry Mode
#define E_MODE_INCDEC 0x02  //Increment/Decrement Cursor
#define E_MODE_SHIFT 0x01   //Display Shift
#define D_CNT 0x08          //Display Control
#define D_CNT_POW 0x04      //Display on/off
#define D_CNT_CUR 0x02      //Cursor on/off
#define D_CNT_BLINK 0x01    //Cursor Blink on/off
#define D_SHIFT 0x10        //Display Shift
#define D_SHIFT_CD 0x08     //Shift Cursor/Display
#define D_SHIFT_LR 0x04     //Move Right/Left
#define SET_DDRAM 0x80      //Set DDRAM Address

class Display {
    // pins and mode
    int e_pin, 
        rs_pin, 
        data_pins[8],
        mode;
    // Keeps track of whether a slot is text
    // or a feedback bar. 0 (default) is text
    // 1 is bar. When in row mode, positions
    // 0 and 1 are the first and second rows
    char bar_text_status;
    // The text at all 8 positions on the display.
    // When in row mode, positions 0 and 1 are
    // the first and second rows of the display.
    char *text[8];
    Leds leds;
    // helper function - writes to screen.
    void write(char*, char*);
    void instruction(char);
    void dataCommand(char);
  public:
    Display(int, int, int);
    ~Display();

    void setMode(int);
    void setText(int, char*);
    void setBar(int, int);
    void setColor(int, int, int);
};

#endif