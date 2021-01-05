#include "textfind.h"

int main()
{
    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    char *dataLine = "";
    int i,j,index;
    char word[WORD];
    char flag = 'c';
    while (fgets(line, sizeof(line), file)) {
        dataLine = line;
        int run = j = index = 0;
        for(i = 0; i < strlen(dataLine) && dataLine[i] != ' '; i++){
            word[j++] = dataLine[i];
            index = i;
        }
        while (i < strlen(dataLine)){   
            if(dataLine[i] != ' '){
                flag = dataLine[i];
                break;
            }
            i++;
        }
        break;
    }

    printf("adawdasdasdasdasdasd\n");
    //printf("flag = %c |||| word = %s \n",flag,word);
    if(flag == 'a'){
        print_lines(word);
    }else if(flag == 'b'){
        print_similar_words(word);
    }
    return 0;
}