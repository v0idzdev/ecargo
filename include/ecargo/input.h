#ifndef INPUT_H
#define INPUT_H

#include <WinSock2.h>
#include <stdbool.h>
#include <stdio.h>

#include "language.h"
#include "print.h"
#include "validate.h"

#ifdef __cplusplus
extern "C"
{
#endif

  int GetLanguageInput();
  char* GetIpInput(int language);
  unsigned short int GetPortInput(int language);

#ifdef __cplusplus
}
#endif

#endif