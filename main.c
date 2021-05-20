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
}

void printRandomPlanet() {
    char chooseRandomPlanet[2];
    fgets(chooseRandomPlanet, 32, stdin);
    chooseRandomPlanet[strcspn(chooseRandomPlanet, "\n")] = 0;
    printf("Choice is %s\n", chooseRandomPlanet);
    printf("Traveling to Pluto...\n");
    printf("Arrived at Pluto, it's very cold here.\n");
}

int main(int argc, char** argv) {
    printWelcome();
    printGreeting();
    printf("Let's go on an adventure!\n");
    printf("Shall I randomly choose a planet for you to visit? (Y or N)\n");
    printRandomPlanet();
}
