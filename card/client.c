//
// Created by soat on 18/07/18.
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <memory.h>

int main(int argc, char **argv) {
    int sockfd, n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;

    printf("Bienvenue sur Limite Limite, le jeu qui n'a pas de limite lol\n");


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof servaddr);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8088);

    //TO Set ip address
    inet_pton(AF_INET, "10.33.3.70", &(servaddr.sin_addr));

    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    while (1) {
        bzero(sendline, 100);
        bzero(recvline, 100);

        read(sockfd, recvline, 100);
        printf("message serveur: %s\n", recvline);

        fgets(sendline, 100, stdin);
        write(sockfd, sendline, strlen(sendline) + 1);


    }

}