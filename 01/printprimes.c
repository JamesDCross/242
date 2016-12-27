#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int c)
{
    int i;
    for (i = 2; i < c; i++)
        {
            if (c % i == 0)
                {
                    return 0;/*false*/
                }

        }
    return 1;/*true*/
}

int main(void)
{
    int candidate = 2;
    int numPrinted = 0;
    while (numPrinted < 100)
        {
            if (is_prime(candidate)){/*if is prime candidate = true*/
                printf("%d,", candidate);
                numPrinted++;
            }
            candidate++;
        }
    return EXIT_SUCCESS;  /* defined in stdlib.h */
}
