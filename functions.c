// Separate file for all of the functions
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "planets.h"

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

void printRandomPlanet() {
    printf("Traveling to Pluto...\n");
    printf("Arrived at Pluto, it's very cold here.\n");
}

void printChosenPlanet() {
    printf("Traveling to Jupiter...\n");
    printf("Arrived at Jupiter. A gas giant, with a noticeable red spot.\n");
}