#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void)
{
    
    int r, tempreg = 0;

    float s1, s2, s3, winner = 0.0;
    float currentScore;



    while (4 == scanf("%d%f%f%f", &r, &s1, &s2, &s3)) /*while there are 4 things to scan*/
        {/*while there are 4 things to scan*/
            printf("%-3d%-4.1f%-4.1f%-4.1f\n", r, s1, s2, s3); /*max pattern*/
            currentScore = s1 + s2 + s3;
            if (currentScore > winner)
                {/*max pattern*/
                    winner = currentScore;
                    tempreg = r;
                }
        }
    printf("the winner is: %d\n ", tempreg);


    return EXIT_SUCCESS;  /* defined in stdlib.h */
}
