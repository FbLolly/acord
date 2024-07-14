#ifndef CHAT_H
#define CHAT_H

#include "message.h"
#include <stdbool.h>

typedef struct Chat Chat;
struct Chat {
  int lenght;
  char *chatWith;

  Message *items;
};

Chat chat_init(int lenght, char *to);
int append_message(Chat *chat, Message message);
Message atIdx(Chat *chat, int idx);
int freeChat(Chat *chat);

#endif
