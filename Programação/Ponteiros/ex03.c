#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    char vetor[3][20] = { "Ola", "Tudo", "Bem?" };
    char (*pointer)[20] = vetor; //Ponteiro para apontar pras strings
    char *p; //Ponteiro para apontar para os caracteres

    while(pointer - vetor < 3) { //Enquanto houver mais uma string a ser lida
        p = *pointer; //p vai apontar para a primeira letra da string
        while(*p != '\0') { //Enquanto não for a última letra da string
            printf("%c", *p++);
        }
        printf("\n");
        pointer++; //Passa para a proxima string
    }


    return 0;
}
