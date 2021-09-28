#include <stdio.h>

int strlength(char *string) {
    int i = 0;
    while(*string != '\0') {
        string++;
        i++;
    }
    return i;
}

void strconcat(char *s1, char *s2) {
    int l1 = strlength(s1);
    int l2 = strlength(s2);
    int i;
    for(i = 0; i < l2; i++) {
        *(s1 + l1 + i) = *(s2 + i);
    }
    *(s1 + l1 + i) = '\0';
}


void strcopy(char *to, char *from) {
    int lfrom = strlength(from);
    int i = 0;
    for(i = 0; i < lfrom; i++) {
        *(to + i) = *(from + i);
    }
    *(to + i) = '\0';
}


int strcompare(char *s1, char* s2) {
    //Retorna 0 caso sejam iguais e retorna 1 caso sejam difetentes
    int l1 = strlength(s1);
    int l2 = strlength (s2);
    if(l1 != l2) { return 1; }

    for(int i = 0; i < l1; i++) {
        if(*(s1 + i) != *(s2 + i)) { return 1; }
    }
    return 0;
}


int main(int argc, char const *argv[])  {
    
    char s1[20], s2[20];
    scanf("%s %s", s1, s2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    int equal = strcompare(s1, s2);
    printf("%d\n", equal);

    // int i = strlength(string);
    // printf("O tamando da string é %d\n", i);

    return 0;
}
