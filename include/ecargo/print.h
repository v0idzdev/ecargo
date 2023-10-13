#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>

#include "language.h"
#include "text.h"

#ifdef __cplusplus
extern "C"
{
#endif

  void PrintWelcomeMessage();
  void PrintWithAutoTranslate(int language,
                              char* textEnglish,
                              char* textWelsh,
                              ...);
  void PrintStatusMarkerKey(int language);

#ifdef __cplusplus
}
#endif

#endif