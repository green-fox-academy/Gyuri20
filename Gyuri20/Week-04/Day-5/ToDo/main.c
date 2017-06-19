#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct add_new_task array[100];

struct add_new_task {
    char first_todo[255];
    //int prio
};

int main()
{
    FILE* fPointer;
    fPointer = fopen("Print_usage.txt", "w");
    fprintf(fPointer, "Todo application\n\
====================\n\
Commands:\n\
-a   Adds a new task\n\
-wr  Write current todos to file\n\
-rd  Read todos from a file\n\
-l   Lists all the tasks\n\
-e   Empty the list\n\
-r   Removes a task\n\
-c   Completes a task\n\
-p   Add priority to a task\n\
-lp  Lists all the tasks by priority\n\n");
    fclose(fPointer);

    fPointer = fopen("Print_usage.txt", "r");
    char Print_usage[1024];
        while(!feof(fPointer)) {
            fgets(Print_usage, 1023, fPointer);
            printf("%s", Print_usage);

    }
    fclose(fPointer);

    struct add_new_task add;

    while (1) {
        char buffer[100];
        printf("\nenter something:\n");
        gets(buffer);
        if ( strstr(buffer, "-a \"") != NULL) {
            strtok(buffer, "\"");
            char *p = strtok(NULL, "\"");
            printf("%s", p);
            struct add_new_task add;
            add.first_todo[0] = p;




        } else if ( strstr(buffer, "-wr \"") != NULL) {
            printf("you have entered something good: -wr \"\n");
        } else if ( strstr(buffer, "-rd \"") != NULL) {
             printf("you have entered something good: -rd \"\n");
        } else if ( strstr(buffer, "-l \"") != NULL) {
            printf("you have entered something good: -l \"\n");
        } else if ( strstr(buffer, "-e \"") != NULL) {
            printf("you have entered something good: -e \"\n");
        } else if ( strstr(buffer, "-r \"") != NULL) {
            printf("you have entered something good: -r \"\n");
        } else if ( strstr(buffer, "-c \"") != NULL) {
            printf("you have entered something good: -c \"\n");
        } else if ( strstr(buffer, "-p \"") != NULL) {
            printf("you have entered something good: -p \"\n");
        } else if ( strstr(buffer, "-lp \"") != NULL) {
            printf("you have entered something good: -lp \"\n");
        } else if ( strstr(buffer, "exit") != NULL) {
            printf("The program is closed!");
            return 0;
        } else {
        printf("Bad command. Try again:\n");
        }
    }
    return 0;
}
