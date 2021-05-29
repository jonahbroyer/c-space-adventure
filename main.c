// C Space Adventure
// Author: Jonah Broyer
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "functions.h"
#include "planets.h"

#define PLANETS 9

planet arr_planets[PLANETS];

void printWelcome();
void printGreeting();
void printRandomPlanet();
void printChosenPlanet();

int randomPlanet() {
    time_t t;
    int random_num;
    srand((unsigned) time(&t));
    random_num = rand() % PLANETS;
    return random_num;
}

int main(int argc, char** argv) {
    FILE *fp;

    char *fPath = "./planetarySystem.txt";

    fp = fopen(fPath, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error number: %d\n", errno);
        perror("Error");
        printf("Error opening: \'%s'.\n", fPath);
        exit(1);
    }

    printWelcome();
    printGreeting();
    while (1) {
        printf("Shall I randomly choose a planet for you to visit? (Y or N)\n");
        char chooseRandomPlanet[2];
        fgets(chooseRandomPlanet, 32, stdin);
        chooseRandomPlanet[strcspn(chooseRandomPlanet, "\n")] = 0;
        if (!strcmp(chooseRandomPlanet, "Y")) {
            printRandomPlanet();
            break;
        }
        if (!strcmp(chooseRandomPlanet, "N")) {
            printf("Name the planet you would like to visit.\n");
            char choosePlanet[32];
            fgets(choosePlanet, 32, stdin);
            choosePlanet[strcspn(chooseRandomPlanet, "\n")] = 0;
            printChosenPlanet();
            break;
        }
        else {
            printf("Sorry, I didn't get that.\n");
            continue;
        }
    }

    return 0;
}