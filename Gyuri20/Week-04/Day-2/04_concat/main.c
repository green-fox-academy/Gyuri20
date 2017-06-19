#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
char *string_function(char *dest, char *source)
{
    int i;
    int j;
    char result[30];
    for (i = 0; dest[i] != '\0'; i++)
         ;


    for (j = 0; source[j] != '\0'; j++)
        dest[i+j] = source[j];

    dest[i+j]='\0';
return dest;
}

int main()
{
    char string1[20] = "hello ";
    char string2[] = "world";

    char *a = string_function(string1, string2);

    for (int i = 0;  a[i] != '\0'; i++)
        printf("%c", a[i]);

    return 0;
}
