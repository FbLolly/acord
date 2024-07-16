#include "headers/globalData.h"
#include <raylib.h>
#include <string.h>
#include <time.h>

GlobalData init_GlobalData(int width, int height, int scale, char *userID,
                           char *toID) {
  return (GlobalData){.scale = scale,
                      .height = height,
                      .width = width,
                      .userID = userID,
                      .toID = toID}; //<- the fonts have been left out couse you
                                     // first need width and height to
                                     // init the window to load fonts
}

GlobalData *loadFonts(GlobalData *data, char *font) {
  data->font = LoadFontEx(font, data->scale * 20, NULL, 0);
  data->smallFont = LoadFontEx(font, data->scale * 16, NULL, 0);

  return data;
}
