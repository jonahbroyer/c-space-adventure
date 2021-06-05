// C Space Adventure
// Author: Jonah Broyer
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <json-c/json.h>
#include "functions.h"
#include "planets.h"

#define PLANETS 9

planet arr_planets[PLANETS];

int randomPlanet() {
    time_t t;
    int random_num;
    srand((unsigned) time(&t));
    random_num = rand() % PLANETS;
    return random_num;
}

int main(int argc, char** argv) {
    // ideas implemented from https://www.youtube.com/watch?v=dQyXuFWylm4
    FILE *fp;
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *planets;

    struct json_object *planet_name;
    struct json_object *description;

    size_t n_planets;
    size_t i;

    char *fPath = "./planetarySystem.json";

    fp = fopen(fPath, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error number: %d\n", errno);
        perror("Error");
        printf("Error opening: \'%s'.\n", fPath);
        exit(1);
    }

    fread(buffer, 1024, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "name", &name);
    json_object_object_get_ex(parsed_json, "planets", &planets);

    printf("Name: %s\n", json_object_get_string(name));

    n_planets = json_object_array_length(planets);
    printf("Found %lu friends\n", n_planets);

    for (i = 0; i < n_planets; i++) {
        planet_name = json_object_array_get_idx(planets, i);
        printf("%lu. %s\n", i+1, json_object_get_string(planet_name));
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