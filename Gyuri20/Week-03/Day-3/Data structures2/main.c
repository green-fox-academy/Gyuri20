#include <stdio.h>

struct RectangularCuboid {
    double a;
    double b;
    double c;
};
int GetVolume();
int GetSurface() {
    struct RectangularCuboid surface;
    surface.a = 1;
    surface.b = 2;
    surface.c = 3;
    int Surface = 2*(surface.a * surface.b) + (surface.a * surface.c) + (surface.b * surface.c);
    printf("Surface: %f\n", Surface);
return Surface;
}

int GetVolume() {
    struct RectangularCuboid volume;
    volume.a = 1;
    volume.b = 2;
    volume.c = 3;
    int Volume = (volume.a * volume.b * volume.c);
    printf("Volume: %f\n", Volume);
return Volume;

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface

// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

int main() {


return 0;
}
