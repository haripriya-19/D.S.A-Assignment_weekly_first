#include <stdio.h>
#include <stdlib.h>
#include <time.h> // to use time function

#define scalingfactor 999 // to print random no. between 0 to 999

int base(int); // function to check base

int base(int n)
{
  int r, max_base = 0; // variable r to store random no. and max_base for greatest digit of random no.
  while (n > 0)        // loop will work till the random no. become 0
  {
    r = n % 10;       // remainder of no. is stored every time loop works
    if (r > max_base) // to check greatest digit
    {
      max_base = r; // greatest digit is stored here after comparision
    }
    n = n / 10; // n will get shorten ever time loop works
  }

  return max_base + 1; // retrns the base of random no. as base is one more than greatest digit
}

int main()
{
  int random_numbers[500], large[500], frequency[11] = {0}; // array to store random no.s there base and frequency of each base
  srand(time(NULL));                                        // to generate new random no. every time because time is not constant

  for (size_t i = 0; i < 500; i++) // loop to store random no.s and their base (by calling base funtion) in array
  {
    random_numbers[i] = rand() % scalingfactor; // random numbers stored in array
    large[i] = base(random_numbers[i]);         // base function is called

    printf(" random number = %d \t base = %d \n", random_numbers[i], large[i]); // prints random number and base
  }

  for (int i = 0; i < 500; i++) // loop for ferquency distribution
  {
    if (large[i] <= 10) // as base is less than equal to 10
    {
      frequency[large[i]]++; // it will increase 1 at the base place
    }
  }

  int max_frequency = 0;
  for (int i = 2; i <= 10; i++) // loop to check maximum frequency
  {
    if (frequency[i] > max_frequency) // checks wether the upcoming frequency is greater than previos one or not
    {
      max_frequency = frequency[i]; // maximum frequency is stored in max frequency
    }
  }

  // loop to print frequency distribution chart
  for (int i = max_frequency; i > 0; i--) // i will store max frequency and get decreased by on every time
  {
    for (int j = 2; j <= 10; j++) // loop to print * or space
    {
      if (frequency[j] < i) // if freqency at jth place is less than maximum frequency it will print space
      {
        printf("       ");
      }
      else // if frequency at jth place is =not less than maximum frequency then loop will print *
      {
        printf("*      ");
      }
    }
    printf("\n");
  }
  printf("base_2 base_3 base_4 base_5 base_6 base_7 base_8 base_9 base_10");
}
