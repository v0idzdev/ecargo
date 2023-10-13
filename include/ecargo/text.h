#ifndef TEXT_H
#define TEXT_H

#ifdef __cplusplus
extern "C"
{
#endif

#define TEXT_ECARGO_LOGO                                                       \
  "\n"                                                                         \
  "============================================================\n"             \
  " ____|  ___|                         ___| |_)            |\n"               \
  " __|   |      _` |  __| _` |  _ \\   |     | |  _ \\ __ \\  __|\n"          \
  " |     |     (   | |   (   | (   |  |     | |  __/ |   | |\n"               \
  "_____|\\____|\\__,_|_|  \\__, |\\___/  \\____|_|_|\\___|_|  _|\\__|\n"      \
  "                      |___/\n"                                              \
  "============================================================\n\n"

#define TEXT_STATUS_MARKER_KEY_DIALOG_ENGLISH                                  \
  "ECargo uses markers surrounded by [] to denote the status\n"                \
  "of each command within the console.\n\n"                                    \
  "+----------------------------------------------------------+\n"             \
  "| [+] - The action was executed successfully.              |\n"             \
  "| [?] - The action is in progress; thus, it has an         |\n"             \
  "|       undetermined status.                               |\n"             \
  "| [-] - The action was not executed successfully.          |\n"             \
  "+----------------------------------------------------------+\n\n"           \
  "Press any key to continue...\n\n"

#define TEXT_STATUS_MARKER_KEY_DIALOG_WELSH                                    \
  "Mae ECargo yn defnyddio symbolau a amgylchynnir gan [] i\n"                 \
  "ddarparu statws y weithred gyfredol yn y consol.\n\n"                       \
  "+----------------------------------------------------------+\n"             \
  "| [+] - Cyflawnwyd y weithred yn llwyddiannus.             |\n"             \
  "| [?] - Mae'r weithred ar y gweill ac yn aros am statws    |\n"             \
  "|       pendant ar ôl ei chwblhau.                         |\n"            \
  "| [-] - Ni chyflawnwyd y weithred yn llwyddiannus.         |\n"             \
  "+----------------------------------------------------------+\n\n"           \
  "Pwyswch unrhyw bysell i barhau...\n\n"

#define TEXT_HORIZONTAL_BAR                                                    \
  "============================================================\n\n"

#ifdef __cplusplus
}
#endif

#endif