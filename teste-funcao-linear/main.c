/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Main function and logic for the game. Base template for game
 * development in C using Raylib (https://www.raylib.com/).
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "GameWindow.h"

int main( void ) {

    GameWindow *gameWindow = createGameWindow(
        800,                // height
        450,                // width   
        "Slope Collision",  // title
        60,                // target FPS
        true,              // antialiazing
        false,             // resizable
        false,             // full screen
        false,             // undecorated
        false,             // always on top
        false,             // always run
        false              // init audio
    );

    initGameWindow( gameWindow );

    return 0;

}