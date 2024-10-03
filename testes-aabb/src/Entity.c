#include <stdbool.h>

#include "Entity.h"
#include "raylib/raylib.h"

void updateEntity( Entity *entity, float delta ) {
    Vector2 newPos = {
        entity->pos.x + entity->vel.x * delta,
        entity->pos.y + entity->vel.y * delta
    };
    updateEntityPosition( entity, newPos );
}

void updateEntityPosition( Entity *entity, Vector2 pos ) {
    entity->lastPos = entity->pos;
    entity->pos = pos;
}

void drawEntity( Entity *entity ) {
    //DrawRectangleRec( getEntityLastBB( entity ), Fade( entity->color, 0.5f ) );
    DrawRectangleRec( getEntityBB( entity ), entity->color );
}

Rectangle getEntityBB( Entity *entity ) {
    return (Rectangle) {
        .x = entity->pos.x,
        .y = entity->pos.y,
        .width = entity->dim.x,
        .height = entity->dim.y
    };
}

Rectangle getEntityLastBB( Entity *entity ) {
    return (Rectangle) {
        .x = entity->lastPos.x,
        .y = entity->lastPos.y,
        .width = entity->dim.x,
        .height = entity->dim.y
    };
}

Rectangle getEntityEntityOverlapBB( Entity *e1, Entity *e2 ) {
    return GetCollisionRec( getEntityBB( e1 ), getEntityBB( e2 ) );
}

bool checkCollisionEntityPosition( Entity *entity, Vector2 pos ) {
    return CheckCollisionPointRec( pos, getEntityBB( entity ) );
}

EntityOverlapType checkCollisionEntityEntityPrivate( Entity *e1, Entity *e2, bool currentPosition ) {
    
    Vector2 e1Pos;

    if ( currentPosition ) {
        e1Pos = e1->pos;
    } else {
        e1Pos = e1->lastPos;
    }

    bool horizontalOverlap = 
        e1Pos.y < e2->pos.y + e2->dim.y &&
        e2->pos.y < e1Pos.y + e1->dim.y;

    bool verticalOverlap = 
        e1Pos.x < e2->pos.x + e2->dim.x &&
        e2->pos.x < e1Pos.x + e1->dim.x;
    
    if ( horizontalOverlap && verticalOverlap ) {
        return EOT_OVERLAP;
    } else if ( horizontalOverlap ) {
        return EOT_H_OVERLAP;
    } else if ( verticalOverlap ) {
        return EOT_V_OVERLAP;
    }

    return EOT_NO_OVERLAP;

}

EntityOverlapType checkCollisionEntityEntityCurrentPos( Entity *e1, Entity *e2 ) {
    return checkCollisionEntityEntityPrivate( e1, e2, true );
}

EntityOverlapType checkCollisionEntityEntityLastPos( Entity *e1, Entity *e2 ) {
    return checkCollisionEntityEntityPrivate( e1, e2, false );
}

// ref: https://www.youtube.com/watch?v=nQnELmUIVFk
void resolveCollisionEntityEntity( Entity *e1, Entity *e2 ) {

    EntityOverlapType currentOv = checkCollisionEntityEntityCurrentPos( e1, e2 );
    EntityOverlapType laspOv = checkCollisionEntityEntityLastPos( e1, e2 );
    Rectangle overlapRect = getEntityEntityOverlapBB( e1, e2 );

    if ( currentOv == EOT_OVERLAP ) {

        if ( laspOv == EOT_H_OVERLAP ) {

            Vector2 newPos = e1->pos;

            if ( e1->pos.x <= e2->pos.x ) {
                newPos.x -= overlapRect.width;
            } else if ( e2->pos.x <= e1->pos.x ) {
                newPos.x = e2->pos.x + e2->dim.x;
            }

            updateEntityPosition( e1, newPos );

        } else if ( laspOv == EOT_V_OVERLAP ) {

            Vector2 newPos = e1->pos;

            if ( e1->pos.y <= e2->pos.y ) {
                newPos.y -= overlapRect.height;
            } else if ( e2->pos.y <= e1->pos.y ) {
                newPos.y = e2->pos.y + e2->dim.y;
            }

            updateEntityPosition( e1, newPos );

        }

    }

}
