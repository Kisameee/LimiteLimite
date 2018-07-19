//
// Created by soat on 18/07/18.
//

#include <sys/types.h>
#include <sys/socket.h>
#include "server_utils.h"
#include "welcome.h"
#include <netdb.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

struct sockaddr_in servaddr;
int list_socket[10];
int maxPartyServeur = 2;
int playerPerRoom[3][2/*room*/];


int main() {

    srand(time(NULL));
    printf("Bonjour, bienvenue sur\n");
    printf("<<<<<<< Limite  Limite   >>>>>>\n");
    setList();
    setRoom();

    char str_player1[100];
    char str_player2[100];
    int listen_fd;
    fd_set rdfs;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    list_socket[0] = listen_fd;

    //creating  server
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(8088);

    FD_ZERO(&rdfs);
    FD_SET (listen_fd, &rdfs);

    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(listen_fd, 20);

    printf("Chargement ...\n");

    while (1) {
        printf("En attente de joueur\n");

        int playerFd = 0;
        if (select(FD_SETSIZE, &rdfs, NULL, NULL, NULL) > 0) {
            printf("Nouveau joueur connecté\n");
            playerFd = accept(listen_fd, (struct sockaddr *) NULL, NULL);
            if (ifConnectionExist(playerFd) == 0) {
                addNewConnection(playerFd);
            }

            //reset str

            write(playerFd, "Choisissez une room.\n", strlen("Choisissez une room") + 1);

            int menuOpen = 0;
            while (menuOpen == 0) {
                bzero(str_player1, 100);
                read(playerFd, str_player1, 100);

                printf("Joueur choisi la room: %s\n", str_player1);
                int numParty = atoi(str_player1) - 1;

                if (numParty >= 0 && numParty < maxPartyServeur) {

                    //Connection des client vers les salles de partie
                    if (playerPerRoom[0][numParty] == 0) {
                        playerPerRoom[0][numParty] = playerFd;
                        menuOpen = 1;
                    } else if (playerPerRoom[1][numParty] == 0) {
                        playerPerRoom[1][numParty] = playerFd;
                        menuOpen = 1;
                    } else if (playerPerRoom[2][numParty] == 0) {
                        playerPerRoom[2][numParty] = playerFd;
                        menuOpen = 1;
                    } else if (playerPerRoom[3][numParty] == 0) {
                        playerPerRoom[3][numParty] = playerFd;
                        menuOpen = 1;
                    } else {
                        printf("La partie est pleine :/\n");

                        write(playerFd, "partie pleine choisissez en une autre\n",
                              strlen("partie pleine choisissez en une autre") + 1);
                    }

                    if (ifPartyFull(numParty) == 1) {


                        //TODO: verifier la creation de thread a chque fois que la salle est pleine

                        printf("C'est parti\n");
                        write(playerFd,welcome(),255);

                        //pthread_t thPrim;
                        //pthread_create(&thPrim,NULL,welcome,NULL);

                        playerPerRoom[0][numParty] = 0;
                        playerPerRoom[1][numParty] = 0;
                        playerPerRoom[2][numParty] = 0;

                    } else {
                        write(playerFd, "en attente d'autres joueurs\n",
                              strlen("en attente d'autres joueurs") + 1);
                    }

                }
            }

        }
    }
}