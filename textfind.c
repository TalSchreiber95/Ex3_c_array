#include "textfind.h"

int arr[SIZE];

//This method returns true iff s is similar to t.
//S is similar to T if up to N chars can be ommited from S to receive T.
int similar(char *s, char *t, int n) {

    
    int sSize = strlen(s); // 
    int tSize = strlen(t); // 

    //This is the best logic term for this problem!
    //If T is a substring of S then S >= T --> IF S-T <= N Then N letters can be ommited
    //from S to receive T.
    if (Substring(s, t))
    {
        if (sSize - tSize <= n)
        {
            return 1;
        }
    }
    

    if (strcmp(s,t) == 0 && n >= 0)
    {
        return 1;
    } else if(sSize < tSize) {
        return 0;
    } else if(sSize - tSize > n) {
        return 0;
    }
    
    
    int i = 0, j = 0;
    int errorCount = n;
    // s:= LCATS
    // t:= C ATS

    while (i < sSize && j < tSize && errorCount >= 0)
    {
        if (*(s+i) == *(t+j)) {
            i++;
            j++;
        } else {
            i++;
            errorCount--;
        }
        if (j == tSize)
        {
            //if finished comparing t to s successfully 
            //and the error count is positive we can return true.
            if (errorCount >= 0) {return 1;} 
        }
        
    }
    return 0;
}

//This method reads chars from the input buffer and 
//stops when it hits the end of a line (\n).
//Then stores the data in @param 's'.
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

    return i;
}

//This method reads chars until hits a \n, \t or \0 
// -> meaning its the end of a word.
//So this method reads a word and stores it in @param 'w'.
int getWord(char w[]) {
    int i = 0;
    char c = 'P';

    while(!(c == '\n' || c == '\t' || c == '\0' || c == '\r' || c == EOF || c == ' ')){
        
        c = getchar();
        *(w + i) = c;
        i++;
    }
    i--;
    *(w + i) = '\0';
    if(c == EOF){
        return EOF;
    }
    return i;
}

//This method returns true iff str2 is a substring of str1.
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
                           //  str2 are located continuously in str1
                return 1;
            }            
        }
    }
    return 0;
}

void print_lines(char *str){ //WORKS

    char line[LINE] = "";
    int size;

    while ((size = getLine(line)) > 0)
    {        
        if (Substring(line, str))
        {
            printf("%s", line);
        }
        
    }
}

void print_similar_words(char * str){

    char word[WORD];
    int size = 1;

    while (size > 0 || size != EOF) {

        size = getWord(word);
        if (similar(word, str, 1))
        {
            printf("%s\n", word);
        }
        
    }
}