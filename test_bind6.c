#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sock, err, client_sock;
	struct sockaddr_in6 sa, sa2, client;
	socklen_t sa_len;
	int port = 4444;
	char junk[128];
	unsigned char tos;
	socklen_t sock_len;

	sock = socket(AF_INET6, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("socket");
		return 1;
	}

	if (argc >= 2)
		port = strtol(argv[1], NULL, 10);

	memset(&sa, 0, sizeof(struct sockaddr_in6));
	sa.sin6_family = AF_INET6;
	sa.sin6_port = htons(port);

	sa_len = sizeof(struct sockaddr_in6);
	err = bind(sock, (struct sockaddr *) &sa, sa_len);
	if (err != 0) {
		perror("bind");
		return 1;
	}

	err = getsockname(sock, (struct sockaddr *) &sa2, &sa_len);
	if (err != 0) {
		perror("getsockname");
		return 1;
	}

	fprintf(stderr, "Socket bound to %s/%d.\n",
		inet_ntop(sa2.sin6_family, &sa2.sin6_addr, junk, sa_len),
		ntohs(sa2.sin6_port));

	tos = 0x00;
	err = setsockopt(sock, IPPROTO_IP, IP_TOS, &tos, 1);
	if (err != 0)
		perror("setsockopt");

	err = listen(sock, 10);
	if (err != 0) {
		perror("listen");
		return 1;
	}

	sock_len = sizeof(client);
	client_sock = accept4(sock, (struct sockaddr *) &client, &sock_len, 0);
	sleep(1);
	close(client_sock);

	close(sock);

	return 0;
}
