#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
int GetSurface(struct rectangular_cuboid rec_cub)
{
    int surface;
    surface = 2*(rec_cub.a*rec_cub.b + rec_cub.b*rec_cub.c + rec_cub.a * rec_cub.c);
    return surface;
}
// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
int GetVolume(struct rectangular_cuboid rec_cub)
{
    int volume;
    volume = rec_cub.a*rec_cub.b*rec_cub.c;
    return volume;
}
int main()
{
    struct rectangular_cuboid rec_cub = {2, 3, 4};
    printf("surface:\t %d m2\nvolume: \t %d m3", GetSurface(rec_cub), GetVolume(rec_cub));
    return 0;
}
