#include "textfind.h"

int main()
{
    // char const* const fileName = "find_input.txt";
    // FILE* file = fopen(fileName, "r");
    // char line[256];
    // char *dataLine = "";
    // int i,j,index;
    // char w[WORD];

    // char flag = 'c';
    // while (fgets(line, sizeof(line), file)) {
    //     dataLine = line;
    //     int j = index = 0;
    //     for(i = 0; i < strlen(dataLine) && dataLine[i] != ' '; i++){
    //         w[j++] = dataLine[i];
    //         index = i;
    //     }
    //     while (i < strlen(dataLine)){   
    //         if(dataLine[i] != ' '){
    //             flag = dataLine[i];
    //             break;
    //         }
    //         i++;
    //     }
    //     break;
    // }

    // //printf("flag = %c |||| word = %s \n",flag,word);
    // if(flag == 'a'){
    //     print_lines(w);
    // }else if(flag == 'b'){
    //     print_similar_words(w);
    // }

    char word[WORD];
    getWord(word);
    printf("%s\n", word);



    return 0;

}