#ifndef DISPLAY_H
#define DISPLAY_H

#define ROW 0
#define SLOT 1

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
    // helper function - writes to screen.
    void write(char*, char*);
    void instruction(char);
    Leds led;
  public:
    Display(int, int, int);
    ~Display();

    void setMode(int);
    void setText(int, char*);
    void setBar(int, int);
    void setColor(int, int, int);
};

#endif