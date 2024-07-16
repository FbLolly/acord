#include "headers/textReformat.h"
#include "headers/globalData.h"
#include <raylib.h>
#include <string.h>

void drawTextBoxed(char *text, Message *message, Vector2 pos,
                   GlobalData *data) {
  int i;
  Vector2 inuse = pos;
  int len = strlen(text);

  for (i = 0; i < len; i++) {
    if (inuse.x >
        data->width -
            (data->scale * 40)) { // width-scale*40 is to avoid text overflow
      inuse.x = pos.x;
      inuse.y += data->scale * 20;
    }
    if (inuse.y + data->scale * 20 > pos.y + message->height) {
      message->height += data->scale * 20;
    }
    DrawTextEx(data->font, TextFormat("%c", text[i]), inuse, data->scale * 20,
               0, RAYWHITE);

    inuse.x += data->scale * 10;
  }
}
