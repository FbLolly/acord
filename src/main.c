#include <raylib.h>

#include "headers/chat.h"
#include "headers/defines.h"
#include "headers/globalData.h"

int main() {
  GlobalData data = init_GlobalData(1000, 520, 1, "01", "02");
  Chat chat = chat_init(0, &data);
  Textfield textfield = textFieldInit(
      (Rectangle){10, data.height - 10 - MESSAGE_HEIGHT, data.width - 20,
                  MESSAGE_HEIGHT},
      (Vector2){20, data.height - MESSAGE_HEIGHT + 10}, "message");

  InitWindow(data.width, data.height, "acord");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  data = *loadFonts(&data, "font/CaskaydiaCove-Regular.ttf");

  while (!WindowShouldClose()) {
    handleInput(&textfield);
    sendMessage(&chat, &textfield, &data);

    BeginDrawing();
    ClearBackground(ACORD_BG);

    drawTextField(&textfield, &data);
    drawChat(&chat, &textfield, &data);
    EndDrawing();
  }

  UnloadFont(data.font);
  UnloadFont(data.smallFont);
  freeChat(&chat);

  return 0;
}
