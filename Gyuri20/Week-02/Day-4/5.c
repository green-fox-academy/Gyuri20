
#include <stdio.h>

int main() {
    char buffer[255];
    char buffer2[255];
    char buffers[255] = ""; // Buffer variable for user input


    //TODO:
    // Get the user's name with gets
    gets(buffer);


    //TODO:
    // Print it out with puts
    puts(buffer);

    //TODO:
    // Get the user's pet name with getch
    gets(buffer2);

    //TODO:
    // Print it out
    strcat(buffers, buffer);
     strcat(buffers, " & ");
    strcat(buffers, buffer2);
    puts(buffers);


    return 0;
}
