#include <WinSock2.h>
#include <io.h>
#include <stdbool.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int
main(int argc, char* argv[])
{
  WSADATA wsa;
  SOCKET sock;
  struct sockaddr_in server, client;
  int c;
  char* message;

  printf("\nInitialising winsock...");

  if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
    printf("Failed. Error code: %d", WSAGetLastError());
    return 1;
  }

  printf("Initialised.\n");

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
    printf("Could not create socket %d", WSAGetLastError());
    return 2;
  }

  printf("Socket created\n");

  // parameterize these
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8888);

  if (bind(socket, (struct sockaddr*)&server, sizeof(server) == SOCKET_ERROR)) {
    printf("Fuck");
    return 3;
  }

  printf("Socket bound\n");

  listen(sock, 3);
  puts("waiting for connections...");

  while (true) {
    int clientSocketSize = sizeof(struct sockaddr_in);
    SOCKET newSocket =
      accept(sock, (struct sockaddr*)&client, &clientSocketSize);

    if (newSocket == INVALID_SOCKET)
      printf("accept failed w code %d", WSAGetLastError());

    puts("connection accepted");
  }
}