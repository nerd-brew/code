#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototypes
char* choiceCheck(char *, int);

int main(){

    printf("Enter an Integer: ");
    int choice;
    scanf("%d", &choice);

    char first[] = "Red";
    char second[] = "Green";
    char third[] = "Blue";

    char* modified_first = choiceCheck(first, 1);
    char* modified_second = choiceCheck(second, 2);
    char* modified_third = choiceCheck(third, 3);

    printf("%s%s%s\n", modified_first, modified_second, modified_third);

    // Don't forget to free the memory
    free(modified_first);
    free(modified_second);
    free(modified_third);
}

char* choiceCheck(char current[], int order){

    char branchless[3] = {0,0,0}; //trying to solve this without branches
    order--;
    branchless[order] = 1;

    char* modified = malloc(strlen(current) + 1);

    for(int i = 0; i <= strlen(current); i++){
        modified[i] = current[i] * branchless[order];
    }

    return modified;
}