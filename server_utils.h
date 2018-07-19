//
// Created by soat on 18/07/18.
//

#ifndef LIMITE_SERVER_UTILS_H
#define LIMITE_SERVER_UTILS_H

void addNewConnection(int fd_client);
int ifConnectionExist(int fd);
void *setList();
void *setRoom();
int ifPartyFull(int numParty);





#endif //LIMITE_SERVER_UTILS_H
