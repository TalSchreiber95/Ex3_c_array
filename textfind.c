#include "textfind.h"

int arr[SIZE];

int similar (char *s, char *t, int n){
    if (!strcmp(s, t) && n == 0){ //if s.equals(t) && n > 0 then should return false
        return 1;
    }else if(n < (strlen(t)+strlen(s))/2){ 
        //Let integers n, k, t. n < k, n < t. 2n < k + t
        //if n sustains n < (k+t)/2
        //then it is not possible ommiting n letters from s to get to t.
        return 0;
    }

    int i,j,index;
    int count = n;
    j = 0;

    // t = a   c    | n = 2
    //     |\ \ -->  
    // s = a b c d
    for(i = 0; i < strlen(t); i++){
        if(t[i] == s[j]){
            j++;
        }else{
            while (t[i] != s[j]){
                count--;
                j++;
            }
            if(i == strlen(t)-1){ 
                //If reached the end of string break and calculate result.
                break;
            } 
            i--; //Decrease i to
        }
        index = i;
    }
    //RETHINK THIS WHOLE SECTION OF IF'S
    if(index == strlen(t)-1 && count == abs(strlen(t) - strlen(s))){
        return 1;
    }else if(count == 0 && index == strlen(t)-1){
        return 1;
    }else{
        return 0;
    }
}
void printArr(const int arr[],int size){
    int i;
    for(i = 0 ; i < size ; i++){
        printf("var[%d] = %d\n",i,arr[i]);
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
    int i = 0;
    char c = ' ';

    while(1){

        c = getchar();
        if(c == '\n' || c == EOF) {
            break;
        }
        s[i++] = c;
    }
    s[i] = '\n';
    printf("getLine received: %s\n", s);
    return i;
}
int getWord(char w[]){
    int i,k;
    char c;
    k = i = 0;

    while (k < WORD){
        // scanf("%c" , &c); //This method waits for input from user.
        c = getchar();

        if(c == '\n' || c == ' ' || c == '\t'){
            break;
        }
        else {
            w[i++] = c;   
        }
        k++;
    }
    w[i] = '\0'; // <==> '' (empty char)
    // printf("%s", w);
    return i;
}
int Substring(char * str1, char * str2){
    if (!strcmp(str1, str2)){ //if str1.compareTo(str2) == 0 <==> str1 == str2
        return 1;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i,j
    ,size; 

    size = len2;
    for(i = 0; i < len1; i++){
        for(j = 0; j < len2; j++){
            if(str1[i] == str2[j]){
                size--;
                i++;
            }else{
                size = len2;
            }
            if(size == 0){ //if size == 0 --> all chars of 
                           //  str2 are located continuesly in str1
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
