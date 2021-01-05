#include "textfind.h"

int arr[SIZE];

int similar (char *s, char *t, int n){
    if (!strcmp(s, t) && n == 0){ //if s.equals(t) && n > 0 then should return false
        return 1;
    }else if(!strcmp(s, t)){ //if s.equals(t) and n==0 return true
        return 1;
    }else if(strlen(t) > strlen(s)){
        return 0;
    }


    int i,j,index;
    int count = n;
    j = 0;
    for(i = 0; i < strlen(t); i++){
        if(s[j] == t[i]){
            j++;
        }else{
            while (s[j] != t[i] && j < 100){
                count--;
                j++;
            }
            if(i == strlen(t)-1){
                break;
            } 
            i--;
        }
        index = i;
    }
    if(index == strlen(t)-1 && count == abs(strlen(t) - strlen(s))){
        return 1;
    }else if(count == 0 && index == strlen(t)-1){
        return 1;
    }else{
        return 0;
    }
}
void printArr(const int arr[],int size){
    int j;
    for(j = 0 ; j < size ; j++){
        printf("var[%d] = %d\n",j,arr[j]);
    }
    printf("\n\n");
}
void readFromFile(){
    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int lines = 0;

    while (fgets(line, sizeof(line), file)) {
        lines++; 
    }
    fclose(file);

    char *arrString[lines];
    int i = 0;
    file = fopen(fileName, "r");
    while (fgets(line, sizeof(line), file)) {
        // if(Substring(line,word) == 1){
            arrString[i] = line;
        // }
        printf("arrString[%d] = %s",i, arrString[i]); 
        i++;
    }
    fclose(file);
}
int getLine(char s[]){
    int i,k;
    char c;
    k = i = 0;

    while (k < LINE ){
        scanf("%c" , &c);
        if(c == '\n' || c == '\0'){
            break;
        }
        if(c != '\n' && c != '\0'){
            s[i++] = c;
        }
        k++; 
        while (getchar() != '\n');
    }

    s[i] = '\n';
    printf("%s", s);
    return i;
}
int getWord(char w[]){
    int i,k;
    char c;
    k = i = 0;

    while (k < WORD ){
        scanf("%c" , &c);
        if(c == '\n' || c == ' ' || c == '\t'){
            break;
        }
        if(c != '\t' && c != '\n' && c != ' '){
            w[i++] = c;   
        }
        k++; 
        while (getchar() != '\n');
    }
    w[i] = '\n';
    printf("%s", w);
    return i;
}
int Substring( char * str1, char * str2){
    if (!strcmp(str1, str2)){
        return 1;
    }

    int sizeStr1 = strlen(str1);
    int sizeStr2 = strlen(str2);
    //printf("sizeStr1 = %d , sizeStr2 = %d\n", sizeStr1,sizeStr2);
    int i,j,size;
    size = sizeStr2;
    for(i = 0; i < sizeStr1; i++){
        for(j = 0; j < sizeStr2; j++){
            //printf("str1[%d] = %c, str2[%d] = %c, size = %d\n",i,str1[i],j,str2[j],size);
            if(str1[i] == str2[j]){
                size--;
                i++;
            }else{
                size = sizeStr2;
            }
            if(size == 0){
                return 1;
            }            
        }
    }
    return 0;
}
void searchWordInFile(char *str){
    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];

    int lines = 0;
    //printf("sizeof(line) = %ld\n",sizeof(file));
    while (fgets(line, sizeof(line), file)) {
        lines++;
        if(lines >= 3){
            if(Substring(line,str) == 1){
                printf("%s", line);
            }
            lines++;          
        }
    }
    fclose(file);
}
void searchSimilarWordInFile(char *str){
    char const* const fileName = "find_input.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    int lines = 0;

    while (fgets(line, sizeof(line), file)) {
        lines++; 
        if(lines >= 3){
            if(similar(line,str,1) == 1 || Substring(line,str) == 1){
                printf("%s", line);
            }
        }        
    }
    fclose(file);
}
void print_lines(char *str){
    searchWordInFile(str);
}
void print_similar_words(char * str){
    searchSimilarWordInFile(str);
}
