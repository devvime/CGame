#ifndef UI_H
#define UI_H

typedef struct Ui {
    void (*Init)(void);
    void (*Draw)();
    void (*Update)(float deltaTime);
    void (*Unload)(void);
} Ui;

#endif