#include "textfind.h"

int main()
{
    char firstWord[WORD];
    char op[1];
    getWord(firstWord);
    // getWord(c);// Calling this method for the second time make 'firstWord' lose its value.
    scanf("%c", &op[0]); //Use scanf() instead.
    
    // printf("first word: %s\nsecond word: %c\n", firstWord, op[0]);

    if (op[0] == 'a') {
        print_lines(firstWord);
    }
    if (op[0] == 'b') {
        print_similar_words(firstWord);
    }
    


    return 0;

}