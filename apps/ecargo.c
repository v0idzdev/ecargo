#include "ecargo/init.h"
#include "ecargo/input.h"
#include "ecargo/print.h"

#pragma comment(lib, "ws2_32.lib")

#define IP_LENGTH 16

int
main(int argc, char* argv[])
{
  InitWelshCharacters();
  PrintWelcomeMessage();

  int language = GetLanguageInput();

  PrintStatusMarkerKey(language);

  WSADATA wsa;
  InitWinsock(&wsa, language);

  SOCKET sock = InitSocket(language);
  char ip* = GetIpInput(language);
  unsigned short int port = GetPortInput(language);

  printf(TEXT_HORIZONTAL_BAR);

  struct sockaddr_in serverAddress;
  InitServerAddress(&serverAddress, ip, port, language);

  while (true) {
  }

  // closesocket(sock); // Is this needed?
}