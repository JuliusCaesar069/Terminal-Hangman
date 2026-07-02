#include <stdio.h>

int main(void){
    FILE *  fp;
    fp = fopen("hello.txt", "r");
    int c;

    if(fp == NULL){
        printf("The file could not be found \n");

    }
    else{

    while( ( c = fgetc(fp)) != EOF){
        
        printf("%c \n",c);
        }
    }
    fclose(fp);
    

return 0;
}