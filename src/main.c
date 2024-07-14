#include <raylib.h>

#include "headers/defines.h"

int width = 1000;
int height = 560;

int main() {
  InitWindow(width, height, "acord");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(ACORD_BG);

    EndDrawing();
  }

  return 0;
}
