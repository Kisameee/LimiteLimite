//
// Created by soat on 18/07/18.
//

#include "card.h"
#include <stdio.h>
#include "welcome.h"

int choice(int input) {

    switch (input) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        default:
            printf("thank you :) \n");

    }
    return 0;
}

int welcome() {

    int i = 1;
    int userInput;

    //Option du Menu

    printf("\n\t\t\t     _________________________________");
    printf("\n\t\t\t    /                                 /");
    printf("\n\t\t\t   /          welcome to             / ");
    printf("\n\t\t\t  /             Limite              /  ");
    printf("\n\t\t\t /              Limite             /   ");
    printf("\n\t\t\t/_______________________________ _/\n\n\n\n\n");

    printf("the first one :\n");
    printf("*************************************************\n");
    printf("*************************************************\n");
    getBlackCards();
    printf("*************************************************\n");
    printf("*************************************************\n");
    printf("there is your cards:\n");
    printf("please select one of your cards and press enter\n");
    for (i = 1; i < 8; i++) {
        printf("%d-", i);
        getRedCards();
    }
    scanf("%d", &userInput);
    choice(userInput);
    return 0;
}