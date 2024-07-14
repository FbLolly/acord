#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "chat.h"
#include <raylib.h>
typedef struct Textfield Textfield;

struct Textfield {
  Rectangle rect;
  Vector2 margins;
  char *placeholder;

  char text[2048];
  bool active;

  int counter;
};

Textfield textFieldInit(Rectangle rect, Vector2 margins, char *placeholder);
void drawTextField(Textfield *Textfield);
void handleInput(Textfield *Textfield);
void sendMessage(Chat *chat, Textfield *Textfield);

#endif
