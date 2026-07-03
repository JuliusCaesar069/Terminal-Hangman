#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

char words[MAX_WORDS][MAX_LEN];


int getIndex(int word_count){

    return rand() % word_count;
}



void reveal(char phrase[],int i,char guess){
    phrase[i] = guess;
}

void game(char phrase[],int index){
    char guesses[50];
    int guesses_taken =0;

    int wrong_guesses = 0;

    while(wrong_guesses <6){
        char input;
        printf("Take your guess \n");
        scanf(" %c",&input);
        guesses[guesses_taken] = input;
        guesses_taken++;

        int i =0;
        bool found = false;

        while(words[index][i]!= '\0'){
            if(words[index][i] == input){
                found = true;

                reveal(phrase,i,input);
            }
            i++; 
        }
        if(!found){
            printf("Your guess is not present in the word \n");
            wrong_guesses++;
        }
        else{
            for(int i=0;i<strlen(words[index]);i++){
                printf("%c ",phrase[i]);
            }
            printf("\n");
        }
    }

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
    
    // printf("%s \n",words[index]);

    int length = strlen(words[index]);
    printf("The word has %d letters \n",length);
    
    char phrase[length+1];
    for(int i=0;i<length;i++){
        phrase[i] = '_';
    }
    phrase[length] = '\0';

    for(int i=0;i<length;i++){
        printf("%c ", phrase[i]);
    }
    
    printf("\n");

    game(phrase,index);

    return 0;
}