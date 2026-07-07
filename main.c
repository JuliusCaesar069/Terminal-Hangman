#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

char words[MAX_WORDS][MAX_LEN];

bool win_check(int correct , int  req){
    if(correct == req){
        return true;
    }
    else{
        return false;
    }
}




bool duplicate_guess(char guesses[],char guess,int guesses_taken){
    bool already_guessed = false;
    for(int i=0;i<guesses_taken;i++){
        if(guess == guesses[i]){
            already_guessed = true;
            break;
        }
    }

    return already_guessed;
}


int getIndex(int word_count){

    return rand() % word_count;
}



void reveal(char phrase[],int i,char guess){
    phrase[i] = guess;
}

void game(char phrase[],int index,int win_condition){
    char guesses[50];
    int guesses_taken =0;

    int wrong_guesses = 0;
    int correct_guesses = 0;

    while(wrong_guesses <6){
        char input;
        printf("Take your guess \n");
        scanf(" %c",&input);
        guesses[guesses_taken] = input;

        // printf("%zu \n",sizeof(input));

        if(sizeof(input) >1){
            printf("Error! Please enter a single character");
            continue;
        }

        if(!duplicate_guess(guesses,input,guesses_taken)){
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
            printf("Lives left : %d \n",6-wrong_guesses);
            if(wrong_guesses == 6){
                printf("Sorry, you lost!\n");
                printf("The word was: %s\n", words[index]);
                return;
            }
        }
        else{
            for(int i=0;i<strlen(words[index]);i++){
                printf("%c ",phrase[i]);
            }
            printf("\n");
            correct_guesses++;
            if(win_check(correct_guesses,win_condition)){
                printf("Congratulations,you have guessed the word \n");
                return;
            }
        }
    }


        else{
            printf("You have already guessed this character before , please guess another character\n");
            continue;
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
        return 0;
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

    int win_condition = 0;

    bool arr[26] = {false};

    for(int i = 0;i<length;i++){
        arr[ words[index][i] - 'a'] = true;
    }

    for(int i=0;i<26;i++){
        if(arr[i]){
            win_condition++;
        }
    }
    // printf("%d \n",win_condition);
    
    char phrase[length+1];
    for(int i=0;i<length;i++){
        phrase[i] = '_';
    }
    phrase[length] = '\0';

    for(int i=0;i<length;i++){
        printf("%c ", phrase[i]);
    }
    
    printf("\n");

    game(phrase,index,win_condition);

    return 0;
}