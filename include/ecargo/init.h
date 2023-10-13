#ifndef INIT_H
#define INIT_H

#include <WinSock2.h>
#include <locale.h>

#include "exit_code.h"

#ifdef __cplusplus
extern "C"
{
#endif

  void InitWelshCharacters();
  void InitWinsock(WSADATA* wsa, int language);
  SOCKET InitSocket(int language);
  void InitServerAddress(struct sockaddr_in* serverAddress,
                         char* ip,
                         unsigned short int port,
                         int language);

#ifdef __cplusplus
}
#endif

#endif