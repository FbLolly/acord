#include "headers/textfield.h"
#include "headers/chat.h"
#include "headers/defines.h"
#include "headers/message.h"
#include <raylib.h>
#include <string.h>

extern Font font;
extern int scale;

Textfield textFieldInit(Rectangle rect, Vector2 margins, char *placeholder) {
  return (Textfield){
      .rect = rect,
      .active = false,
      .margins = margins,
      .placeholder = placeholder,
      .text = "",
      .counter = 0,
  };
}

void handleInput(Textfield *Textfield) {
  char key;

  if (CheckCollisionPointRec(GetMousePosition(), Textfield->rect) &&
      IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Textfield->active = true;
  }

  if (Textfield->active) {
    key = GetCharPressed();

    while (key > 0 && Textfield->counter < MAX_MSG - 2) {
      Textfield->text[Textfield->counter] = key;
      Textfield->text[Textfield->counter + 1] = '_';
      Textfield->text[Textfield->counter + 2] = '\0';

      Textfield->counter++;
      key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) && Textfield->counter > 0) {
      Textfield->text[Textfield->counter - 1] = '_';
      Textfield->text[Textfield->counter] = '\0';
      Textfield->counter--;
    }
  }
}

void drawTextField(Textfield *Textfield) {
  float text_width = MeasureTextEx(font, Textfield->text, scale * 15, 5).x;

  DrawRectangleRec(Textfield->rect, WHITE);

  if (Textfield->active) {
    DrawTextEx(font, Textfield->text,
               (Vector2){Textfield->margins.x, Textfield->margins.y},
               scale * 20, 5, BLACK);
  } else {
    DrawTextEx(font, Textfield->placeholder,
               (Vector2){Textfield->margins.x, Textfield->margins.y},
               scale * 20, 5, BLACK);
  }
}

void sendMessage(Chat *chat, Textfield *Textfield) {
  Message msg;
  int i;

  if (IsKeyPressed(KEY_ENTER) && Textfield->counter != 0) {
    msg = (Message){
        .lenght = Textfield->counter + 1,
        .toID = "asd",
        .fromID = "asd",
        .type = 0,
        .version = 0,
    };
    strcpy(msg.string, Textfield->text);
    msg.string[Textfield->counter] =
        '\0'; // eliminates the _ at the end of the string

    chat = append_message(chat, msg);

    for (i = 0; i <= Textfield->counter; i++) {
      Textfield->text[i] = '\0';
    }

    Textfield->counter = 0;
  }
}
