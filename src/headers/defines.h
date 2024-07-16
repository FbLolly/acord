#ifndef DEFINES_H
#define DEFINES_H

#define ACORD_BG                                                               \
  (Color) { 50, 50, 55, 255 }

#define DELTA                                                                  \
  GetFrameTime() *                                                             \
      50 // <- *50 to get it back to scale, *100 is also completly fine but I
         // find myself more comfortable working with 50
#define MESSAGE_HEIGHT_PTR                                                     \
  data->height / (data->scale * 10.0) // <- *10 couse when the scale is 1:1 you
                                      // will have to have 10x pixels

#define MESSAGE_HEIGHT data.height / (data.scale * 10.0)

#define MAX_MSG 2048

enum flags { CHAT, FRIENDS_SHOWN, PROFILE_SHOWN }; // <- todo

#endif
