#include <stdio.h>
#include <string.h>
#define MAX_WORDS 1000
#define MAX_LENGTH  50


int main(void){
    char word[MAX_LENGTH];

    FILE *fp = fopen("words.txt","r");

    FILE *fe = fopen("easy.txt","w");
    FILE *fm = fopen("medium.txt","w");
    FILE *fh = fopen("hard.txt","w");



    for(int i=0;i<MAX_WORDS;i++){
        if(fgets(word,MAX_LENGTH,fp) == NULL){
            break;
        }
        else{
        int length = strlen(word);

        if(length >4 && length <6){
            fputs(word,fe);
        }
        else if (length >5 && length <8){
            fputs(word,fm);
        }
        else if(length >= 8){
            fputs(word,fh);
        }
        }

    }
    fclose(fp);
    fclose(fe);
    fclose(fm);
    fclose(fh);




    return 0;
}