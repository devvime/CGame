#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"
#include <stdbool.h>

typedef struct Button {
    Rectangle rect;
    const char* text;

    Color text_color;
    int font_size;

    Color color;
    Color hover_color;
} Button;

Button Button_Create(
    float x, float y,
    float w, float h,
    const char* text,
    Color text_color,
    int font_size,
    Color color,
    Color hover_color
);

bool Button_Draw(Button* button);

#endif