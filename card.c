//
// Created by soat on 17/07/18.
//

#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

int rand_a_b(int min, int max) {
    return rand() % (max - min) + min;
}

int getBlackCards() {
    int lines = 89;
    int i = 0;
    FILE *fp;

    /* opening file for reading */
    fp = fopen("/home/soat/CLionProjects/Limite/card/Black", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }

    char current[256];
    int random = rand_a_b(0, lines);
    int currentLine = 0;

    while (fgets(current, sizeof(current), fp)) {
        if (random == currentLine++) {
            printf(current);
        }
    }
    return 0;
}

int getRedCards() {
    int lines = 454;
    FILE *fp;

    /* opening file for reading */
    fp = fopen("/home/soat/CLionProjects/Limite/card/Red", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }

    char current[256];
    int random = rand_a_b(0, lines);
    int currentLine = 0;


    while (fgets(current, sizeof(current), fp)) {
        if (random == currentLine++) {
            printf(current);
        }
    }
    return 0;
}


