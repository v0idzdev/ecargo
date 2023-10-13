#include "ecargo/input.h"

#define LANGUAGE_INPUT_ERROR_MESSAGE                                           \
  "[-] You selected an invalid option. Please try again.\n"                    \
  "[-] Ni wnaethoch ddewis unrhyw un o'r opsiynau a oedd ar\n"                 \
  "    gael. Triwch eto os gwelwch yn dda.\n\n"

int
GetLanguageInput()
{
  while (true) {
    printf("Please select the language you would like to use.\n"
           "Dewiswch yr iaith yr hoffech ei defnyddio.\n\n"
           "+----------------------------------------------------------+\n"
           "| [1] - English                                            |\n"
           "| [2] - Cymraeg                                            |\n"
           "+----------------------------------------------------------+\n\n"
           ">>> ");

    int languageChoice;
    int scanStatus = scanf("%d", &languageChoice);

    printf("\n");

    if (scanStatus == EOF) {
      printf(LANGUAGE_INPUT_ERROR_MESSAGE);
      continue;
    }

    if (scanStatus == 0) {
      bool linebreakFound = fgetc(stdin) == '\n';

      while (!linebreakFound)
        ;
    }

    if (languageChoice == LANGUAGE_ENGLISH ||
        languageChoice == LANGUAGE_WELSH) {
      PrintWithAutoTranslate(languageChoice,
                             "[+] The language was set to English.\n\n",
                             "[+] Gosodwyd yr iaith i'r Gymraeg.\n\n");

      return languageChoice;
    }

    printf(LANGUAGE_INPUT_ERROR_MESSAGE);
  }
}

char*
GetIpInput(int language)
{
  while (true) {
    unsigned char ipParts[4];
    char ip[BUFSIZ];

    printf(TEXT_HORIZONTAL_BAR);
    PrintWithAutoTranslate(
      language,
      "Enter the IP of the server to connect to:\n>>> ",
      "Rhowch gyfeiriad IP y gweinydd yr ydych am gysylltu â fo:\n>>> ");

    bool validInput = scanf("%s", &ip) == 1;

    if (validInput && IsValidIP(ip))
      return ip;

    PrintWithAutoTranslate(
      language,
      "[-] You entered an invalid IP. Please try again.\n",
      "[-] Rydych wedi rhoi cyfeiriad IP annilys. Triwch eto os\n"
      "    gwelwch yn dda.\n");
  }
}

unsigned short int
GetPortInput(int language)
{
  while (true) {
    unsigned short int port;

    printf("\n");
    PrintWithAutoTranslate(language,
                           "Enter the port of the server to connect to:\n>>> ",
                           "Rhowch rhif porthladd y gweinydd yr ydych am "
                           "gysylltu â fo:\n>>> ");

    bool validInput = scanf("%hu", &port) == 1;

    if (validInput)
      return port;

    printf("\n");
    PrintWithAutoTranslate(
      language,
      "[-] You entered an invalid IP. Please try again.\n",
      "[-] Rydych wedi rhoi rhif porthladd IP annilys. Triwch eto\n"
      "    os gwelwch yn dda.\n");
  }
}
