#include <stdio.h>

struct pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates
int sum_gold(struct pirate p[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum = sum + p[i].gold_count;

    return sum;
}
// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate
float average_gold(struct pirate p[], int len)
{
    int sum = sum_gold(p, len);
    float average = (float)sum / len;

    return average;
}
// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg
char *richest_wooden_leg(struct pirate p[], int len)
{
    int richest_pirate = 0;
    int richest_index = 0;
    for (int i = 0; i < len; i++){
        if ((richest_pirate < p[i].gold_count) && (p[i].has_wooden_leg == 1)) {
            richest_pirate = p[i].gold_count;
            richest_index = i;
        }
    }
    return (p[richest_index].name);
}
int main()
{
    struct pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };
    int len = sizeof(pirates)/sizeof(pirates[0]);
    printf("Sum gold:\t %d\n", sum_gold(pirates, len));
    printf("Average gold:\t %f\n", average_gold(pirates, len));
    printf("Richest pirate that has wooden leg:\t %s\n", richest_wooden_leg(pirates, len));
    return 0;
}
