#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function that takes a double array as a parameter, and the length of the array.
// This function should calculate the avarage of the elements.
double double_array(double *array_1, int length)
{
    double avarage  = 0;
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array_1[i];
    }
    avarage = sum / length;

    return avarage;
}
// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It calculates how much elements are under the avarage, and returns with that.
double double_array2(double *array_1, int length, int average)
{
    double under_average = 0;
        for (int i = 0; i < length; i++) {
            if (array1[i] < average) {
                under_average++;
            }
        }

    return under_average;
}
// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It allocates a new array, and loads into it the elements which are under the average.
// It returns a pointer to the new array.
double double_array(double *array_1, int length, double average)
{
    int j = 0;
    ptr = (double*)calloc(length, sizeof(double));
    for (int i = 0; i < length; i++) {
            if (array1[i] < average) {
                ptr[j] = array_1[i];
                j++;
            }
    free ptr;
    return *ptr;
}

int main()
{

    return 0;
}
