#ifndef CHAT_H
#define CHAT_H

#include "globalData.h"
#include "message.h"
#include <stdbool.h>

typedef struct Textfield Textfield;
typedef struct Chat Chat;

struct Chat {
  int lenght;
  char *chatWith;

  Message *items;
};

struct Textfield {
  Rectangle rect;
  Vector2 margins;
  char *placeholder;

  char text[2048];
  bool active;

  int counter;
};

Textfield textFieldInit(Rectangle rect, Vector2 margins, char *placeholder);
void drawTextField(Textfield *Textfield, GlobalData *data);
void handleInput(Textfield *Textfield);
void sendMessage(Chat *chat, Textfield *Textfield, GlobalData *data);

Chat chat_init(int lenght, GlobalData *data);
Chat *append_message(Chat *chat, Message message);
Message atIdx(Chat *chat, int idx);
int freeChat(Chat *chat);
int drawChat(Chat *chat, Textfield *tf, GlobalData *data);

#endif
