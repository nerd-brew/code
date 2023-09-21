#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    char *nameBuffer = malloc(sizeof(char)*16);

    printf("Enter your name: ");
    fgets(nameBuffer, 16, stdin);

    printf("%s", nameBuffer);
   
}