#include <stdlib.h>
#include "Keyframe.h"
#include "raylib.h"

Keyframe *newKeyframe( Vector2 pos, int index ) {
    Keyframe *keyframe = (Keyframe*) malloc( sizeof( Keyframe ) );
    keyframe->pos = pos;
    keyframe->index = index;
    return keyframe;
}

void deleteKeyframe( Keyframe **keyframe ) {
    if ( *keyframe != NULL ) {
        free( *keyframe );
        *keyframe = NULL;
    }
}

void updateKeyframe( Keyframe *keyframe ) {

}

void drawKeyframe( Keyframe *keyframe ) {

}