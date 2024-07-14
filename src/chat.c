#include "headers/chat.h"

#include "headers/defines.h"
#include <assert.h>
#include <limits.h>
#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>

extern int width;
extern int height;
extern int scale;
extern Font font;

Chat chat_init(int lenght, char *to) {
  return (Chat){.lenght = lenght,
                .items = malloc(sizeof(Message) * lenght),
                .chatWith = to};
}

Chat *append_message(Chat *chat, Message message) {
  assert(chat != NULL);

  if (chat->items == NULL) {
    chat->items = malloc(sizeof(Message) * 1);
    chat->items[0] = message;
    chat->lenght = 1;

    if (chat->items == NULL)
      return NULL;

    return chat;
  }

  chat->items = realloc(chat->items, (chat->lenght + 1) * sizeof(Message));
  chat->items[chat->lenght] = message;

  assert(chat->lenght + 1 > chat->lenght);
  chat->lenght++;

  if (chat->items == NULL)
    return NULL;

  return chat;
}

Message atIdx(Chat *chat, int idx) {
  if (idx > chat->lenght)
    return (Message){0};

  return chat->items[idx];
}

int freeChat(Chat *chat) {
  if (chat->items == NULL)
    return 1;

  free(chat->items);

  return 0;
}

int drawChat(Chat *chat) {
  int i, pos = height - ((chat->lenght + 1) * (MESSAGE_HEIGHT + (scale * 10)));

  if (chat == NULL)
    return 1;
  if (chat->items == NULL)
    return 0;

  for (i = 0; i < chat->lenght; i++) {
    DrawRectangle(5, pos, width - 20, MESSAGE_HEIGHT, BLACK);
    DrawTextEx(font, chat->items[i].string, (Vector2){20, pos + 10}, scale * 20,
               10, RAYWHITE);

    pos += MESSAGE_HEIGHT + (scale * 10);
  }

  return 0;
}
