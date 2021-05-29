// C Space Adventure
// Author: Jonah Broyer
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "functions.h"
#include "planets.h"

#define PLANETS 9

void printWelcome();
void printGreeting();
void printRandomPlanet();
void printChosenPlanet();

int main(int argc, char** argv) {
    struct Planets planet;
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