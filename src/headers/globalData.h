#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include <raylib.h>

typedef struct GlobalData GlobalData;

struct GlobalData {
  int width;
  int height;
  int scale;
  Font font;
  Font smallFont;

  char *userID;
  char *toID;
};

GlobalData init_GlobalData(int width, int height, int scale, char *userID,
                           char *toID);
GlobalData *loadFonts(GlobalData *data, char *font);

#endif
