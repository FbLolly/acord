#include <raylib.h>
#include <stdlib.h>

#include "headers/chat.h"
#include "headers/defines.h"
#include "headers/message.h"

int width = 1000;
int height = 560;
int scale = 1;
Font font;

int main() {
  Chat chat = chat_init(0, "#2000");
  append_message(&chat, (Message){0, 0, "hello", 6, "#1000", "#2000"});
  append_message(&chat,
                 (Message){0, 0, "hello to you too", 6, "#2000", "#1000"});
  append_message(&chat, (Message){0, 0, "how are you", 6, "#1000", "#2000"});

  font = LoadFontEx("", scale * 20, NULL, 0);

  InitWindow(width, height, "acord");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(ACORD_BG);

    drawChat(&chat);
    EndDrawing();
  }

  UnloadFont(font);
  freeChat(&chat);

  return 0;
}
