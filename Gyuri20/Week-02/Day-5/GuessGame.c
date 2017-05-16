#include <stdio.h>
#include <stdlib.h>


int main(void) {

srand(time(NULL));
int r = rand() % 100;
int MyGuess = r + 1;
int YourGuess = 0;
int counter = 5;

printf("I've the number between 1-100. You have 5 lives. Write your first number: ");


while(counter > 0){
  scanf("%d", &YourGuess);
  if (YourGuess < MyGuess)
    {
    printf("Your guess was to low. You have %d lives left. \n", --counter);
    }

  else if (YourGuess > MyGuess)
    {
    printf("Your guess was to high. You have %d lives left. \n", --counter);
    }

  else if (YourGuess = MyGuess)
    {
    printf("Congratulations. You won!\n");
    break;
    }

}
 printf("My guess was: %d", MyGuess);
return 0;
}
