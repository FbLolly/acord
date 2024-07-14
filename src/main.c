#include <raylib.h>
#include <stdlib.h>

#include "headers/chat.h"
#include "headers/defines.h"
#include "headers/textfield.h"

int width = 1000;
int height = 560;
int scale = 1;
Font font;

int main() {
  Chat chat = chat_init(0, "#2000");
  Textfield textfield = textFieldInit(
      (Rectangle){10, height - 10 - MESSAGE_HEIGHT, width - 20, MESSAGE_HEIGHT},
      (Vector2){20, height - MESSAGE_HEIGHT + 10}, "message");

  font = LoadFontEx("", scale * 20, NULL, 0);

  InitWindow(width, height, "acord");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  while (!WindowShouldClose()) {
    handleInput(&textfield);
    sendMessage(&chat, &textfield);

    BeginDrawing();
    ClearBackground(ACORD_BG);

    drawTextField(&textfield);
    drawChat(&chat);
    EndDrawing();
  }

  UnloadFont(font);
  freeChat(&chat);

  return 0;
}
