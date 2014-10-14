/*
 * This program test poll syscall with a timeout of 0. Skype is acting stupid.
 * Copyright: Catalin(ux) M. BOIE
 * Part of force_bind package
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <poll.h>

int main(void)
{
	struct pollfd fds;
	int ret;

	fds.fd = 0;
	fds.events = POLLIN;
	ret = poll(&fds, 1, 0);
	printf("ret = %d\n", ret);

	return 0;
}
