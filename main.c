#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

char words[MAX_WORDS][MAX_LEN];

int getIndex(int word_count)
{
    return rand() % word_count;
}

int main(void)
{
    srand(time(NULL));

    FILE *fp = fopen("words.txt", "r");
    int word_count = 0;

    if (fp == NULL) {
        printf("Error finding the file\n");
        return 1;
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (fgets(words[i], MAX_LEN, fp) == NULL) {
            break;
        }

        words[i][strcspn(words[i], "\n")] = '\0';
        word_count++;
    }

    fclose(fp);

    int index = getIndex(word_count);
    printf("%d \n",word_count);

    printf("%s\n", words[index]);

    return 0;
}