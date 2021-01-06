#include "textfind.h"

int arr[SIZE];

int similar (char *s, char *t, int n){

    int size_S, size_T;
    size_S = strlen(s);
    size_T = strlen(t);
    // printf("ommit %d chars to make %s = %s\n", n, s, t);
    if (size_S < size_T) {return 0;}
    if (!strcmp(s,t) && n == 0) { //If strings are equal (string lib) and n == 0.
        return 1;
    } else {

        int i, j, count;
        i = j = 0;
        count = n;

        while((i < size_S && j < size_T)) { //While NOT end of word.
            if (s[i] == t[j]) { 
                i++;
                j++;
            } else {
                count--; //add an error of 1 char.
                i++;
            }
        }
        // printf("count = %d, similar returns %d\n", count, !count);

        if (count == 0)
        {
            //Then there are exactly n chars to remove from string s
            //to get to string t.
            return 1;
        }
    }

    return 0;
    
    // if (!strcmp(s, t) && n == 0){ //if s.equals(t) && n > 0 then should return false
    //     return 1;
    // }else if(n < (strlen(t)+strlen(s))/2){ 
    //     //Let integers n, k, t. n < k, n < t. 2n < k + t
    //     //if n sustains n >= (k+t)/2
    //     //then it is not possible ommiting n letters from s to get to t.
    //     //So n must sustain n < (k+t)/2.
    //     return 0;
    // }

    // int i,j,index;
    // int count = n;
    // j = 0;

    // // t = a b c    | n = 1
    // //     |\ | X -->  count == 0 => s is similar to t by n=1 chars.
    // // s = a b c d
    // for(i = 0; i < strlen(t); i++){
    //     if(t[i] == s[j]){
    //         j++;
    //     }else{
    //         while (t[i] != s[j]){
    //             count--;
    //             j++;
    //         }
    //         if(i == strlen(t)-1){ 
    //             //If reached the end of string break and calculate result.
    //             break;
    //         } 
    //         i--; //Decrease i to
    //     }
    //     index = i; // i sustains t[i] == s[j].
    // }
    // //RETHINK THIS WHOLE SECTION OF IF'S
    // if(index == strlen(t)-1 && count == abs(strlen(t) - strlen(s))){
    //     return 1;
    // }else if(count == 0 && index == strlen(t)-1){
    //     return 1;
    // }else{
    //     return 0;
    // }
}
// void readFromFile(){
//     char const* const fileName = "find_input.txt";
//     FILE* file = fopen(fileName, "r");
//     char line[256];
//     int lines = 0;

//     while (fgets(line, sizeof(line), file)) {
//         lines++; 
//     }
//     fclose(file);

//     char *arrString[lines];
//     int i = 0;
//     file = fopen(fileName, "r");
//     while (fgets(line, sizeof(line), file)) {
//         // if(Substring(line,word) == 1){
//             arrString[i] = line;
//         // }
//         printf("arrString[%d] = %s",i, arrString[i]); 
//         i++;
//     }
//     fclose(file);
// }


int getLine(char s[]){

    int i = 0;
    char c = ' ';

    while(1){

        c = getchar();
        if(c == '\n' || c == EOF) {
            break;
        }
        // printf("This is c: %c\n", c);
        s[i++] = c;
    }
    s[i] = '\n';

    return i;
}
int getWord(char w[]){
    int count = 0;
    char c;
    count = 0;
    int endOfWord = 0;

    while (!endOfWord){
        // scanf("%c" , &c); //This method waits for input from user.
        c = getchar(); //To continuously recieve chars from the buffer - use this method.

        if((c == '\n' || c == ' ' || c == '\t' || c == EOF)){
            endOfWord = 1;
            continue;
        }
        else {
            *(w + count) = c;
            count++;
        }
    }
    w[count] = '\0'; // <==> '' (empty char - end of word)

    return count;
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
                           //  str2 are located continuously in str1
                return 1;
            }            
        }
    }
    return 0;
}

void searchSimilarWordInFile(char *str){
    
    char word[WORD];
    int size = 1;

    while (size > 0) {
        size = getWord(word);
        if ((size = similar(str, word, 1)) == 1)
        {
            printf("%s\n", word);
        }
        
    }
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
    // searchSimilarWordInFile(str);

    char word[WORD];

    while (getWord(word) > 0) {
        if (similar(word, str, 1))
        {
            printf("%s\n", word);
        }
        
    }
}
