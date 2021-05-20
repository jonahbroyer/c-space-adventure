// C Space Adventure
// Author: Jonah Broyer
#include <stdio.h>
#include <string.h>

void printWelcome() {
    printf("Welcome to the Solar System!\n");
    printf("There are 9 planets to explore.\n");
}

void printGreeting() {
    printf("What is your name?\n");
    char name[32];
    fgets(name, 32, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa.\n", name);
    printf("Let's go on an adventure!\n");
}

// void printRandomPlanet() {
//     char chooseRandomPlanet[2];
//     fgets(chooseRandomPlanet, 32, stdin);
//     chooseRandomPlanet[strcspn(chooseRandomPlanet, "\n")] = 0;
//     printf("Choice is %s\n", chooseRandomPlanet);
//     printf("Traveling to Pluto...\n");
//     printf("Arrived at Pluto, it's very cold here.\n");
// }

// void printChosenPlanet() {
//     printf("Name the planet you would like to visit.");
// }

int main(int argc, char** argv) {
    printWelcome();
    printGreeting();
    while (1) {
        printf("Shall I randomly choose a planet for you to visit? (Y or N)\n");
        char chooseRandomPlanet[2];
        fgets(chooseRandomPlanet, 32, stdin);
        chooseRandomPlanet[strcspn(chooseRandomPlanet, "\n")] = 0;
        if (!strcmp(chooseRandomPlanet, "Y")) {
            printf("Traveling to Pluto...\n");
            printf("Arrived at Pluto, it's very cold here.\n");
            break;
        }
        if (!strcmp(chooseRandomPlanet, "N")) {
            printf("Name the planet you would like to visit.\n");
            char choosePlanet[32];
            fgets(choosePlanet, 32, stdin);
            choosePlanet[strcspn(chooseRandomPlanet, "\n")] = 0;
            printf("Traveling to Jupiter...\n");
            printf("Arrived at Jupiter. A gas giant, with a noticeable red spot.\n");
            break;
        }
        else {
            printf("Sorry, I didn't get that.\n");
            continue;
        }
    }

    return 0;
}
