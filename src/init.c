#include "ecargo/init.h"

void
InitWelshCharacters()
{
  setlocale(LC_ALL, "en_UK.UTF-8");
  SetConsoleOutputCP(CP_UTF8);
}

void
InitWinsock(WSADATA* wsa, int language)
{
  PrintWithAutoTranslate(language,
                         "[?] Winsock is initialising...\n",
                         "[?] Mae Winsock yn cychwyn...\n");

  if (WSAStartup(MAKEWORD(2, 2), wsa) != 0) {
    PrintWithAutoTranslate(
      language,
      "[-] Error executing WSAStartup(). Error code: %d\n",
      "[-] Gwall wrth weithredu WSAStartup(). Cod gwall: %d\n",
      WSAGetLastError());

    exit(EXIT_CODE_FAILED_TO_INITIALISE_WINSOCK);
  }

  PrintWithAutoTranslate(language,
                         "[+] Winsock was started successfully.\n",
                         "[+] Dechreuwyd Winsock yn llwyddiannus.\n");
}

SOCKET
InitSocket(int language)
{
  SOCKET sock;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) != INVALID_SOCKET) {
    PrintWithAutoTranslate(
      language,
      "[-] Error executing socket() - the socket could not be\n"
      "    created. Error code: %d\n",
      "[-] Gwall wrth weithredu socket() - ni fu modd creu'r\n"
      "    soced. Cod gwall: %d\n",
      WSAGetLastError());

    exit(EXIT_CODE_FAILED_TO_CREATE_SOCKET);
  }

  PrintWithAutoTranslate(language,
                         "[+] The socket was created successfully.\n\n",
                         "[+] Crëwyd y soced yn llwyddiannus.\n\n");

  return sock;
}

void
InitServerAddress(struct sockaddr_in* serverAddress,
                  char* ip,
                  unsigned short int port,
                  int language)
{
  serverAddress->sin_addr.s_addr = inet_addr(ip);
  serverAddress->sin_family = AF_INET;
  serverAddress->sin_port = htons(port);

  PrintWithAutoTranslate(language,
                         "[+] The server address was set to %s:%hu.\n",
                         "[+] Gosodwyd cyfeiriad y gweinydd i %s:%hu.\n",
                         ip,
                         port);
}
