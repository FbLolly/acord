#include "headers/chat.h"
#include "headers/defines.h"
#include "headers/message.h"
#include <raylib.h>
#include <string.h>

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
  } else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Textfield->active = false;
  }

  if (Textfield->active) {
    key = GetCharPressed();

    while (key > 0 && Textfield->counter < MAX_MSG - 2) {

      if (Textfield->counter == 0 && Textfield->text[0] == ' ') {
        Textfield->text[0] = '_';
        Textfield->text[1] = '\0';
      }

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

void drawTextField(Textfield *Textfield, GlobalData *data) {
  float text_width =
      MeasureTextEx(data->font, Textfield->text, data->scale * 15, 5).x;

  DrawRectangleRec(Textfield->rect, WHITE);

  if (Textfield->active) {
    DrawTextEx(data->font, Textfield->text,
               (Vector2){Textfield->margins.x, Textfield->margins.y},
               data->scale * 20, 1, BLACK);
  } else {
    DrawTextEx(data->font, Textfield->placeholder,
               (Vector2){Textfield->margins.x, Textfield->margins.y},
               data->scale * 20, 1, BLACK);
  }
}

void sendMessage(Chat *chat, Textfield *Textfield, GlobalData *data) {
  Message msg;
  int i;

  if (IsKeyPressed(KEY_ENTER) && Textfield->counter != 0) {
    msg = (Message){.lenght = Textfield->counter + 1,
                    .toID = data->toID,
                    .fromID = data->userID,
                    .type = 0,
                    .version = 0,
                    .height = data->scale * 30 + data->scale * 20};

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
