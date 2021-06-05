// C Space Adventure
// Author: Jonah Broyer
#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(int argc, char** argv) {
    printWelcome();
    printAdventure(printGreeting());
    printChosenPlanet(printRandomPlanet());

    return 0;
}