//
// Created by soat on 18/07/18.
//

#include "server_utils.h"
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
int playerPerRoom[3][2/*room*/];


void addNewConnection(int fd_client) {
    for (int i = 0; i < 10; i++) {
        if (list_socket[i] == 0) {
            list_socket[i] = fd_client;
            break;
        }
    }
}

int ifConnectionExist(int fd) {
    for (int i = 0; i < 10; i++) {
        if (list_socket[i] == fd) {
            return 1;
        }
    }
    return 0;
}

void *setList() {
    for (int i = 0; i < 10; i++) {
        list_socket[i] = 0;
    }
}

void *setRoom() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            playerPerRoom[i][j] = 0;
        }
    }
}

int ifPartyFull(int numParty) {
    if (playerPerRoom[0][numParty] != 0 && playerPerRoom[1][numParty] != 0)
        return 1;
    else
        return 0;
}