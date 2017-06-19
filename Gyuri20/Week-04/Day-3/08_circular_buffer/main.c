#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a struct called CircularBuffer
// It should store:
// A pointer that points to the start of a dynamically allocated array of ints (could be null) (head pointer)
// A pointer that points to the end of the dynamically allocated array of ints (could be null) (tail pointer)
// A pointer that points to the currently readable buffer item (could be null) (read pointer))
// A pointer that points to the currently writable buffer item (could be null) (write pointer)
// The lenght of the buffer
typedef struct {
    int* head;
    int* tail;
    int* read;
    int* write;
}CircularBuffer;
// TODO:
// Create a function that returns a dynamically allocated CircularBuffer (the buffer itself should be allocated as well, not just the array inside)
// It should take a normal array and it's length as argument, and it should fill all the buffer values from the array
CircularBuffer* GetNewCircularBuffer(int* source, int len)
{
   int* buffer = (int*)calloc(len, sizeof(int));
   memcpy(buffer, source_array, len*sizeof(int));

   CircularBuffer* to_return = malloc(sizeof(CircularBuffer));
   to_return->head = buffer;
   to_return->read = buffer;
   to_return->write = buffer;
   to_return->tail = &buffer[len-1];

   return to_return;
}
// TODO:
// Create a function that resizes a CircularBuffer, it should take a CircularBuffer as a pointer and change that buffers length and reallocate it's array as well. (copying it's values)

// TODO:
// Create a function that takes a CircularBuffer and returns a new CircularBuffer that only contains the even numbers from the old CircularBuffer

// TODO:
// Try all the functions in the main function, plase deallocate any buffer and the array inside it after using them

int main()
{

    return 0;
}
