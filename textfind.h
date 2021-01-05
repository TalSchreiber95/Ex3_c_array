#include <stdio.h>  
#include <math.h>
#include <string.h> 
#include <stdlib.h>   

#define SIZE 50
#define LINE 256
#define WORD 30

int similar (char *s, char *t, int n);
int Substring( char * str1, char * str2);
int getWord(char w[]);
int getLine(char s[]);
void print_lines(char *str);
void print_similar_words(char * str);