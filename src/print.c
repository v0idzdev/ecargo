#include "ecargo/print.h"

void
PrintWelcomeMessage()
{
  printf(TEXT_ECARGO_LOGO);
  printf("ECargo Client 0.1.0-a1\n"
         "Copyright (C) Matthew G. Flegg 2023\n\n"
         "This application is licensed under the GNU GPL V3.\n"
         "Trwyddedir y meddalwedd hwn o dan y GNU GPL V3.\n\n");
}

void
PrintWithAutoTranslate(int language, char* textEnglish, char* textWelsh, ...)
{
  char* text;

  if (language == LANGUAGE_ENGLISH)
    text = textEnglish;

  if (language == LANGUAGE_WELSH)
    text = textWelsh;

  // TODO: Check both languages have same format specifiers

  // Find required buffer size
  va_list args;
  va_start(args, text);
  int length = vsnprintf(NULL, 0, text, args);
  va_end(args);

  if (length < 0) // TODO: Print appropriate error message and/or repeat
    return;

  // Format the message
  char* message = calloc(length + 1, sizeof(char)); // FREE
  va_start(args, text);
  vsnprintf(message, length + 1, text, args);
  va_end(args);

  // Display the message
  printf("%s", message);
}

void
PrintStatusMarkerKey(int language)
{
  printf(TEXT_HORIZONTAL_BAR);
  PrintWithAutoTranslate(language,
                         TEXT_STATUS_MARKER_KEY_DIALOG_ENGLISH,
                         TEXT_STATUS_MARKER_KEY_DIALOG_WELSH);

  printf(TEXT_HORIZONTAL_BAR);
  getch();
}
