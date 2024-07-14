#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdint.h>

typedef struct Message Message;

struct Message {
  uint8_t version;
  uint8_t type;

  char *string;
  int lenght;

  char *fromID;
  char *toID;
};

#endif
