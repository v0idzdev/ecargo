#ifndef VALIDATE_H
#define VALIDATE_H

#include <stdbool.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

  bool IsValidNumber(char* text);
  bool IsValidIP(char* ip);

#ifdef __cplusplus
}
#endif

#endif