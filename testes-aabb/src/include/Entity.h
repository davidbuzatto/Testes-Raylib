#pragma once

#include <stdbool.h>

#include "raylib/raylib.h"

typedef struct Entity {
    Vector2 pos;
    Vector2 lastPos;
    Vector2 vel;
    Vector2 dim;
    Color color;
    bool dragging;
} Entity;

typedef enum EntityOverlapType {
    EOT_NO_OVERLAP,
    EOT_H_OVERLAP,
    EOT_V_OVERLAP,
    EOT_OVERLAP
} EntityOverlapType;

void updateEntity( Entity *entity, float delta );
void updateEntityPosition( Entity *entity, Vector2 pos );
void drawEntity( Entity *entity );
Rectangle getEntityBB( Entity *entity );
Rectangle getEntityLastBB( Entity *entity );
Rectangle getEntityEntityOverlapBB( Entity *e1, Entity *e2 );
bool checkCollisionEntityPosition( Entity *entity, Vector2 pos );
EntityOverlapType checkCollisionEntityEntityCurrentPos( Entity *e1, Entity *e2 );
EntityOverlapType checkCollisionEntityEntityLastPos( Entity *e1, Entity *e2 );
void resolveCollisionEntityEntity( Entity *e1, Entity *e2 );
