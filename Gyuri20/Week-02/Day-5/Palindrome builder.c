#include <stdio.h>
#include <string.h>
int main(){


  polyndrom_function();

 return 0;
}

void polyndrom_function(){

char a[20];

  printf("Write something\n");

  gets(a);

  
  int length;
  length = strlen(a);
    int i;

  for(i = 0; i < length; i++)
   {
      printf("%c", a[i]);
   }


  for(i = length-1; i >= 0; i--)
   {
      printf("%c", a[i]);
   }

}
