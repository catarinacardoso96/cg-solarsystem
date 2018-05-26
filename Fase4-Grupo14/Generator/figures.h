#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "aux_func.h"
#define _USE_MATH_DEFINES

void plane (float x, float z, float d, char const *file);
void box (float x, float y, float z, float d, char const *file);
void sphere (float r, float sl, float st, char const *file);
void cone (float r, float h, float sl, float st, char const *file);
void cylinder (float br, float tr, float h, float sl, float st, char const *file);
void torus (float ir, float r, float sides, float rings, char const *file);
void ellipsoid (float a, float b, float c, float sl, float st, char const *file);
void crown(float inr, float outr, float slices, char const *file);
void belt(float n, float r, float sl, float st, float inr, float outr, char const *file);