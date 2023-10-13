#include "validate.h"

bool
IsValidNumber(char* text)
{
  while (*text) {
    if (!isdigit(*text)) {
      return false;
    }

    text++;
  }

  return true;
}

bool
IsValidIP(char* ip)
{
  int i, number, dotCount = 0;
  char* token;

  if (ip == NULL)
    return false;

  token = strtok(ip, ".");

  if (token == NULL)
    return false;

  while (token) {
    if (!IsValidNumber(token))
      return false;

    number = atoi(token);

    if (number < 0 || number > 255)
      return false;

    token = strtok(NULL, ".");

    if (token != NULL)
      dotCount++;
  }

  if (dotCount != 3)
    return false;

  return true;
}
