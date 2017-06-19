#include <stdio.h>

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level
void car_stats(struct car car) {
    printf("%.1f\n", car.km);
    if (car.type != TESLA)
        printf("%.1f\n", car.gas);
}

int main()
{
    struct car volvo = {VOLVO, 100000, 7};
    struct car tesla = {TESLA, 100000, 7};
    car_stats(volvo);
    car_stats(tesla);

    return 0;
}
