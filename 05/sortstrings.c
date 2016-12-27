#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LEN 80
#define ARRAY_LEN 10000

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void array_sort(char** a, int n)/*sorting algorithm is not right*/
{
    int i, x;
    /*char temp[STRING_LEN];*/
    char *temp;
    for (i = 1; i < n; i++)
	{
            x =i;
            /*cant do this comparision in the while loop use strcmp*/
            /*using strcpy is bad because the words are different sizes and we have only allocated
              a certain amount of memory to the words so this causes conflict*/
            while (strcmp(a[x],a[x-1]) < 0 && x > 0)
            /*while ((temp > a[j]) && (j >= 0))*/
		{
                    temp = a[x];
                    a[x] = a[x-1];
                    a[x-1] = temp;
                    x--;
		}
            
	}
}

int main(void) {
    /* FILE* ifp = fopen("randwords.txt", "r");r means read*/
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN]; /*10000 char pointers currently pointing at nothing*/
    /*int num_words = 0;*/
    int i, num_words;
    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf( "%79s", word)) {
        /*allocate memory to array of char pointers*/
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }

    array_sort(wordlist, num_words);
    for (i = 0; i < num_words; i++) {
        printf("%s\n", wordlist[i]);
    }


    for (i = 0; i < num_words; i++) {
        free(wordlist[i]);
    }
    return EXIT_SUCCESS;
}
