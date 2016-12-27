
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void)
{
    float s1, s2, s3;
    scanf("%1f%1f%1f", &s1, &s2, &s3);
    printf("%-4.1f%-4.1f%-4.1f", s1, s2, s3);/*-4 for left justified*/


    if (s1 < s2 && s1 < s3)
        {
            float result = (s1 + s2) / 2;
            printf("%-4.1f", result);

        }
    else if (s2 < s1 && s2 < s3)
        {
            float result = (s1 + s3) / 2;
            printf("%-4.1f", result);

        }
    else {
        float result = (s1 + s2) / 2;
        printf("%-4.1f", result);

    }

    return EXIT_SUCCESS;  /* defined in stdlib.h */
}
