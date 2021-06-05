// Separate file for all of the function implementations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <json-c/json.h>
#include "functions.h"

#define FILE_NAME "./planetarySystem.json"

struct Planet {
    char *name;
    char *description;
};

struct Planet *planets;

void printWelcome(void) {
    printf("Welcome to the Solar System!\n");
    printf("There are 9 planets to explore.\n");
}

char* printGreeting() {
    char name[STRING_SIZE];
    char *retval = name;
    printf("What is your name?\n");
    scanf(" %[^\n]s", name);
    return retval;
}

void printAdventure(const char* name) {
    printf("Nice to meet you, %s. My name is Eliza, I'm an old friend of Alexa.\n", name);
    printf("Let's go on an adventure!\n");
}

char printRandomPlanet(void) {
    char choice;
    printf("Shall I randomly choose a planet for you to visit? (Y or N)\n");
    scanf(" %c", &choice);
    return choice;
}

void printChosenPlanet(char choice) {
    char planet[STRING_SIZE];
    if ('Y' == choice) {
        printf("Traveling to Null...\n");
    }
    else if('N' == choice) {
        printf("Name the planet you would like to visit.\n");
        scanf(" %[^\n]s", planet);
            
        printf("Traveling to %s...\n", planet);
        printf("Arrived at %s.\n", planet);
    }
    else {
        printf("Sorry, I didn't get that.\n");
    }
}

void parseJson() {
    // ideas implemented from https://www.youtube.com/watch?v=dQyXuFWylm4
    FILE *fp;
    char buffer[2048];

    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *jsonPlanets;
    struct json_object *description;
    struct json_object *planet;
    struct Planet structPlanet;

    size_t n_planets;
    size_t i;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error number: %d\n", errno);
        perror("Error");
        printf("Error opening: \'%s'.\n", FILE_NAME);
        exit(1);
    }

    fread(buffer, 2048, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "planets", &jsonPlanets);

    n_planets = json_object_array_length(jsonPlanets);
    struct Planet colPlanets[n_planets];

    for(i = 0; i < n_planets; i++) {
        planet = json_object_array_get_idx(jsonPlanets, i);

        json_object_object_get_ex(planet, "name", &name);
        json_object_object_get_ex(planet, "description", &description);
        structPlanet.name = json_object_get_string(name);
        structPlanet.description = json_object_get_string(description);

        colPlanets[i] = structPlanet;
    }
    planets = colPlanets;
}