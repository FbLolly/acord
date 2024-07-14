#include "headers/chat.h"
#include <malloc.h>
#include <stdbool.h>

Chat chat_init(int lenght, char *to) {
  return (Chat){.lenght = lenght,
                .items = malloc(sizeof(Message) * lenght),
                .chatWith = to};
}

int append_message(Chat *chat, Message message) {
  if (chat == NULL)
    return 1;
  chat->items = realloc(chat->items, chat->lenght + 1);

  if (chat->items == NULL)
    return 1;

  chat->lenght++;
  return 0;
}

Message atIdx(Chat *chat, int idx) {
  if (idx > chat->lenght)
    return (Message){0};

  return chat->items[idx];
}

int freeChat(Chat *chat) {
  if (chat == NULL)
    return 1;

  free(chat);

  if (chat->items != NULL) {
    free(chat->items);
  }

  return 0;
}
