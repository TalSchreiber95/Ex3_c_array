#include <stdio.h>  
#include <math.h>
#include <string.h> 
#include <stdlib.h>   


#define SIZE 50
#define LINE 256
#define WORD 30

int arr[SIZE];

int similar (char *s, char *t, int n){
    if (!strcmp(s, t) && n == 0){
        return 1;
    }else if(!strcmp(s, t)){
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
void printArr(int var[],int run){
    int j;
    for(j = 0 ; j < run ; j++){
        printf("var[%d] = %d\n",j,var[j]);
    }
    printf("\n\n");
}
void toString(int var[],int run){
    int j;
    for(j = 0 ; j < run ; j++){
        if(j == 0){
            printf("%d",*(var + j));
        }else{
            printf(",%d",*(var + j));
        }
    }
    printf("\n");
}
void shift_element(int *arr, int i) {
    int j;
    for(j = 0; j < i; j++){
        *(arr+i+1-j) = *(arr+i-j);
    }
    *(arr+1) = 0;
}
void insertion_sort(int* arr , int len){
    int temp,i,count,*point = NULL;
    for(i = 1; i < len; i++ ){
        point = (arr+i-1);
        count = 0;
        while(point > (arr-1)){
            if(*(arr+i) < *point){
                count++;
            }
            point--;
        }
        temp = *(arr + i);
        shift_element((arr+i-count-1),count);
        *(arr+i-count) = temp;
    }

}
void addValueForArray(char *str, int len){
    int j,count = 1;
    for(j = 0 ; j < len ; j++){
        if(*(str+j) == ' ' && j != 0 && j != len-1){
            count++;
        }
    }
    int array[count];
    int *pointArr = &array[0];

    int i = 0;
    char * token = strtok(str, " ");
    while( token != NULL ) {
        int x = atoi(token);
        token = strtok(NULL, " ");
        *(pointArr+i++) = x;
    }
    insertion_sort(pointArr,sizeof(array)/4);
    toString(pointArr,sizeof(array)/4);
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

    char word[] = "cat";
    int lines = 0;
    printf("sizeof(line) = %ld\n",sizeof(file));
    while (fgets(line, sizeof(line), file)) {
        lines++;
        if(lines >= 3){
            if(Substring(line,word) == 1){
                printf("%s", line);
            }
            lines++;          
        }
    }
    fclose(file);
}
void searchSimilarWordInFile(char *str){
    char const* const fileName = "testSimilarWords.txt";
    FILE* file = fopen(fileName, "r");
    char line[256];
    char word[] = "cat";
    int lines = 0;

    while (fgets(line, sizeof(line), file)) {
         lines++; 
        if(similar(line,word,1) == 1){
            printf("%s", line);
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

int main () {
   /*
    int i = 4,j ,*ptr;
    int var[] = {0,1,5,4,3,2,6,0};
    ptr = &var[2];
   
   //Q1
    printf("Q1 i = %d , ptr = &var[2]\n", i);
    toString(var,sizeof(var)/4);
    shift_element(ptr,4);
    toString(var,sizeof(var)/4);

   //Q2 -> a
    printf("\n\nQ2  ptr = &var[0] , sizeof(var) = %ld\n",sizeof(var)/4);
    ptr = &var[0];
    toString(var,sizeof(var)/4);
    insertion_sort(ptr,sizeof(var)/4);
    toString(var,sizeof(var)/4);

   //Q2 -> b
   int number;
   for ( i = 0; i < SIZE; i++) {
     printf("enetr a number:");
     scanf("%d",&number);
     *(arr+i)=number;
   }
    printf("\n\nQ3  ptr = &string[0] , strlen(string) = 8 \n");
    char *ptr2;
    char string[] = "10 9 3 6";
    char *point = &string[0];
    printf("string = \"10 9 3 6\"\n");
    addValueForArray(point,strlen(string));


    //Q3
    //getLine
    char c[LINE] = "";
    int a = getLine(c);
    printf("a = %d",a);


    //Q3
    //getword
    char cc[LINE] = "";
    int b = getWord(cc);
    printf("b = %d",b);
 
    char str2[] = "moti";
    char str1[] = "123456moti12346";
    int result = subString(str1,str2);
    printf("result = %d\n",result);

//Q3
    //getword
    char s[] = "swsystems";
    char t[] = "ssysems";
    int result = similar(s,t,2);
    printf("result = %d\n",result);
*/

//Q3
    //getword

    // char str[] = "cat s\n"
    // "this is a text file\n"
    // "looking for the word cat\n"
    // "the program should print also cats\n"
    // "and crat and lcat but it shouldn’t\n"
    // "print the word caats\n";
    // char word[WORD] = "";
    // readFromFile();



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
    printf("flag = %c |||| word = %s \n",flag,word);
    if(flag == 'a'){
        print_lines(word);
    }else if(flag == 'b'){
        print_similar_words(word);
    }

    
    // char word[WORD] = "ZZZ";
    // scanf("%s",word);
    // print_lines(word);


    // char word[WORD] = "ZZZ";
    // scanf("%s",word);
    // print_similar_words(word);


    // char t[] = "cat";
    // char s1[WORD] = "cat";
    // int result = similar(s1,t,1);
    // printf("result = %d\n",result);
    // char s2[WORD] = "cats";
    //  result = similar(s2,t,1);
    // printf("result = %d\n",result);
    // char s3[WORD] = "cats";
    //  result = similar(s3,t,1);
    // printf("result = %d\n",result);
    // char s4[WORD] = "crat";
    //  result = similar(s4,t,1);
    // printf("result = %d\n",result);
    // char s5[WORD] = "lcat";
    //  result = similar(s5,t,1);
    // printf("result = %d\n",result);




    return 0;
}

