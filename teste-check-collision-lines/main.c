/**
 * @file main.c
 * @author Prof. Dr. David Buzatto
 * @brief Checking bug in CheckCollisionLines function.
 * 
 * @copyright Copyright (c) 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "raylib.h"

#define PI 3.14159265358979323846f
#define DEG2RAD (PI/180.0f)
#define RAD2DEG (180.0f/PI)

void setup();
void inputAndUpdate();
void draw();

typedef struct Line {
    Vector2 start;
    Vector2 end;
    float angle;
    Color color;
} Line;

#define LINESQ 120
#define OBSTSQ 64

Line lines[LINESQ];
Line obstacles[OBSTSQ];
float magnitude = 2000.0f;

int main( void ) {

    SetConfigFlags( FLAG_MSAA_4X_HINT );
    InitWindow( 800, 800, "Testing CheckCollisionLines" );
    SetTargetFPS( 60 );

    setup();

    while ( !WindowShouldClose() ) {
        inputAndUpdate();
        draw();
    }

    CloseWindow();
    return 0;

}

void setup() {

    float currentAngle = 0.0f;
    float angleStep = 360.0f / LINESQ;
    
    int w = GetScreenWidth();
    int h = GetScreenHeight();
    int xc = w / 2;
    int yc = h / 2;

    for ( int i = 0; i < LINESQ; i++ ) {
        lines[i] = (Line){
            .start = { xc, yc },
            .end = { 
                xc + magnitude * cosf( DEG2RAD * currentAngle ),
                yc + magnitude * sinf( DEG2RAD * currentAngle )
            },
            .angle = currentAngle,
            .color = Fade( ColorFromHSV( currentAngle, 1, 1 ), 0.5f )
        };
        currentAngle += angleStep;
    }

    int k = 0;
    for ( int i = 0; i < OBSTSQ; i += 8 ) {

        int st = 50 * k++;
        int cw = w - st;
        int ch = h - st;

        obstacles[i]   = (Line){ { st, st }, { cw, st }, 0, WHITE };
        obstacles[i+1] = (Line){ { cw, st }, { cw, ch }, 0, WHITE };
        obstacles[i+2] = (Line){ { cw, ch }, { st, ch }, 0, WHITE };
        obstacles[i+3] = (Line){ { st, ch }, { st, st }, 0, WHITE };

        obstacles[i+4]   = (Line){ { st, yc }, { xc, st }, 0, WHITE };
        obstacles[i+5] = (Line){ { xc, st }, { cw, yc }, 0, WHITE };
        obstacles[i+6] = (Line){ { cw, yc }, { xc, ch }, 0, WHITE };
        obstacles[i+7] = (Line){ { xc, ch }, { st, yc }, 0, WHITE };

    }

}

void inputAndUpdate() {

    Vector2 mousePos = GetMousePosition();

    for ( int i = 0; i < LINESQ; i++ ) {
        Line *li = &lines[i];
        li->start = mousePos;
        li->end.x = li->start.x + magnitude * cosf( DEG2RAD * li->angle );
        li->end.y = li->start.y + magnitude * sinf( DEG2RAD * li->angle );
    }

}

void draw() {

    BeginDrawing();
    ClearBackground( BLACK );

    /*for ( int i = 0; i < OBSTSQ; i++ )    {
        Line *ob = &obstacles[i];
        DrawLineV( ob->start, ob->end, ob->color );
    }*/

    /*for ( int i = 0; i < LINESQ; i++ )    {
        Line *li = &lines[i];
        DrawLineV( li->start, li->end, li->color );
    }*/

    for ( int i = 0; i < LINESQ; i++ ) {
        Line *li = &lines[i];
        for ( int j = 0; j < OBSTSQ; j++ ) {
            Line *ob = &obstacles[j];
            Vector2 ip;
            if ( CheckCollisionLines( li->start, li->end, ob->start, ob->end, &ip ) ) {
                DrawCircleV( ip, 10, Fade( li->color, 0.5f ) );
                //DrawCircleV( ip, 1, YELLOW );
            }
        }
    }

    EndDrawing();

}