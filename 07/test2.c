#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AL 100
#define SL 80



void print_LTA(char **wl, int n, double av) {
    if (n > 0) {
        if (strlen(wl[0]) > av) {
            printf("%s\n", wl[0]);

        }
        print_LTA(wl + 1, n - 1, av);
    }
}


void *emalloc(size_t s) {
   
    void *result = malloc(s);
      if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return result;
}




int main(void) {
    char word[SL];
    char *wl[AL];
    int i = 0;/*num_words*/
    int j = 0;
    double av = 0.0;
    

    while (i < AL && 1 == scanf("%79s", word)) {
       
        wl[i] = emalloc((strlen(word) + 1) * sizeof wl[0][0]);
        
        strcpy(wl[i++], word);
        av += strlen(word);
    }

  
    if (i > 0) {
        av /=  i;
        fprintf(stderr, "%.2f\n", av);
        print_LTA(wl, i, av);
    }


    for (j = 0; j < i; j++) {
        free(wl[j]);
    }
    return EXIT_SUCCESS;
}
