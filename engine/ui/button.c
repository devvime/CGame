#include "button.h"

Button Button_Create(
    float x, float y,
    float w, float h,
    const char* text,
    Color text_color,
    int font_size,
    Color color,
    Color hover_color
)
{
    Button btn;

    btn.rect = (Rectangle){ x, y, w, h };
    btn.text = text;

    btn.text_color = text_color;
    btn.font_size = font_size;
    btn.color = color;
    btn.hover_color = hover_color;

    return btn;
}

bool Button_Draw(Button* button)
{
    Vector2 mouse = GetMousePosition();
    bool hover = CheckCollisionPointRec(mouse, button->rect);

    DrawRectangleRec(
        button->rect,
        hover ? button->hover_color : button->color
    );

    int textWidth = MeasureText(button->text, button->font_size);

    float textX = button->rect.x + (button->rect.width - textWidth) / 2.0f;
    float textY = button->rect.y + (button->rect.height - button->font_size) / 2.0f;

    DrawText(
        button->text,
        (int)textX,
        (int)textY,
        button->font_size,
        button->text_color
    );

    return hover && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}