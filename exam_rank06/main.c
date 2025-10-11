#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

typedef struct s_client {
	int id;
	char *buf;
} t_client;

t_client clients[1024];
fd_set readfds, writefds, activefds;
int maxfd = 0, next_id = 0;
int sockfd;

void fatal() {
	write(2, "Fatal error\n", 12);
	close(sockfd);
	exit(1);
}

void send_all(int src, char *msg) {
	for (int fd = 0; fd <= maxfd; fd++) {
		if (FD_ISSET(fd, &writefds) && fd != src && fd != sockfd)
			send(fd, msg, strlen(msg), 0);
	}
}

int extract_message(char **buf, char **msg) {
	char *newbuf;
	int i = 0;

	*msg = 0;
	if (!*buf) return 0;
	while ((*buf)[i]) {
		if ((*buf)[i] == '\n') {
			newbuf = calloc(1, strlen(*buf + i + 1) + 1);
			if (!newbuf) return -1;
			strcpy(newbuf, *buf + i + 1);
			(*buf)[i + 1] = 0;
			*msg = *buf;
			*buf = newbuf;
			return 1;
		}
		i++;
	}
	return 0;
}

char *str_join(char *buf, char *add) {
	char *newbuf;
	int len = buf ? strlen(buf) : 0;

	newbuf = malloc(len + strlen(add) + 1);
	if (!newbuf) return 0;
	newbuf[0] = 0;
	if (buf) strcat(newbuf, buf);
	strcat(newbuf, add);
	free(buf);
	return newbuf;
}

int main(int ac, char **av) {
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) fatal();

	struct sockaddr_in servaddr, cli;
	socklen_t len = sizeof(cli);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		fatal();
	if (listen(sockfd, 128) < 0)
		fatal();

	FD_ZERO(&activefds);
	FD_SET(sockfd, &activefds);
	maxfd = sockfd;
	for (int i = 0; i < 1024; i++) clients[i].buf = NULL;

	while (1) {
		readfds = writefds = activefds;
		if (select(maxfd + 1, &readfds, &writefds, 0, 0) < 0)
			continue;

		for (int fd = 0; fd <= maxfd; fd++) {
			if (FD_ISSET(fd, &readfds)) {
				if (fd == sockfd) {
					int clientfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (clientfd < 0) continue;
					clients[clientfd].id = next_id++;
					clients[clientfd].buf = NULL;
					FD_SET(clientfd, &activefds);
					if (clientfd > maxfd) maxfd = clientfd;

					char msg[64];
					sprintf(msg, "server: client %d just arrived\n", clients[clientfd].id);
					send_all(clientfd, msg);
					break;
				} else {
					char buff[4096];
					int r = recv(fd, buff, 4095, 0);
					if (r <= 0) {
						char msg[64];
						sprintf(msg, "server: client %d just left\n", clients[fd].id);
						send_all(fd, msg);
						FD_CLR(fd, &activefds);
						close(fd);
						free(clients[fd].buf);
						clients[fd].buf = NULL;
						break;
					}
					buff[r] = 0;
					clients[fd].buf = str_join(clients[fd].buf, buff);
					char *msg;
					while (extract_message(&clients[fd].buf, &msg)) {
						char sendbuf[8192];
						sprintf(sendbuf, "client %d: %s", clients[fd].id, msg);
						send_all(fd, sendbuf);
						free(msg);
					}
				}
			}
		}
	}
}