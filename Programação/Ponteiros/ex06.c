#include <stdio.h>

int strlength(char *string) {
    int i = 0;
    while(*string != '\0') {
        string++;
        i++;
    }
    return i;
}


int strcompare(char *s1, char* s2) {
    //Retorna 0 caso sejam iguais e retorna 1 caso sejam difetentes
    int l1 = strlength(s1);

    for(int i = 0; i < l1; i++) {
        if(*(s1 + i) != *(s2 + i)) { return 1; }
    }
    return 0;
}


void stringReplace(char *s1, char *s2, int start) {
    int l1 = strlength(s1);
    int l2 = strlength(s2);
    for(int i = start; i < l2; i++) {
        *(s2 + i) = *(s2 + i + l1);
    }
}


char *strDelUpper(char *s1, char *s2) {
    int l1 = strlength(s1);
    int l2 = strlength(s2);
    for(int i = 0; i < l2; i++) {
        if(*(s1) == *(s2 + i)) {
            if(!strcompare(s1, s2 + i)) {
                stringReplace(s1, s2, i);
                return s2;
            }
        }
    }
    return s2;
}


int main(int argc, char const *argv[])  {
    
    char s1[20], s2[20];
    scanf("%s %s", s1, s2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    
    char *s3 = strDelUpper(s1, s2);
    printf("%s\n", s3);

    return 0;
}