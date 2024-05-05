#pragma once

#include "raylib.h"

typedef struct Keyframe {
    Vector2 pos;
    int index;
} Keyframe;

Keyframe *newKeyframe( Vector2 pos, int index );
void deleteKeyframe( Keyframe **keyframe );
void updateKeyframe( Keyframe *keyframe );
void drawKeyframe( Keyframe *keyframe );