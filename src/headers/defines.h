#ifndef DEFINES_H
#define DEFINES_H

#define ACORD_BG                                                               \
  (Color) { 50, 50, 55, 255 }

#define DELTA GetFrameTime() * 50
#define MESSAGE_HEIGHT height / (scale * 10)

enum flags { CHAT, FRIENDS_SHOWN, PROFILE_SHOWN };

#endif
