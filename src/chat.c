#include "headers/chat.h"

#include "headers/globalData.h"
#include "headers/textReformat.h"
#include <assert.h>
#include <limits.h>
#include <raylib.h>
#include <stdint.h>
#include <stdlib.h>

Chat chat_init(int lenght, GlobalData *data) {
  return (Chat){.lenght = lenght,
                .items = malloc(sizeof(Message) * lenght),
                .chatWith = data->toID};
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

int drawChat(Chat *chat, Textfield *tf, GlobalData *data) {
  int i, pos = data->height - (tf->rect.height + (data->scale * 10));

  for (i = 0; i < chat->lenght; i++) {
    pos -= chat->items[i].height + (data->scale * 30);
  }

  if (chat == NULL)
    return 1;
  if (chat->items == NULL)
    return 0;

  for (i = 0; i < chat->lenght; i++) {
    DrawRectangle(5, pos, data->width - 20, chat->items[i].height, BLACK);

    DrawTextEx(
        data->smallFont,
        TextFormat("from %s to %s", chat->items[i].fromID, chat->items[i].toID),
        (Vector2){data->scale * 16, pos - (data->scale * 16)}, data->scale * 16,
        1, RAYWHITE);
    drawTextBoxed(chat->items[i].string, &chat->items[i],
                  (Vector2){data->scale * 30, pos + data->scale * 5}, data);

    pos += chat->items[i].height + (data->scale * 30);
  }

  return 0;
}
