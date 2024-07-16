#ifndef MESSAGE_H
#define MESSAGE_H

#include "defines.h"
#include <stdint.h>

typedef struct Message Message;

struct Message {
  uint8_t version;
  uint8_t type;

  char string[MAX_MSG];
  int lenght;

  char *fromID;
  char *toID;

  int height;
};

#endif
