#include <stdio.h>

int main(int argc, char const *argv[]) {
    int v[5] = { 10, 20, 30, 40, 50 };
    int *pv;
    int **ppv;

    pv = &v[0];
    ppv = &pv;

    printf("%d %d %d\n", v[0], *(pv), **(ppv));
    printf("%d %d %d\n", v[1], *(pv+1), *(*ppv + 1));
    printf("%d %d %d\n", v[2], *(pv+3), *(*ppv + 4));
    printf("%d %d %d\n", (v[0] - 1), *(pv+1) - 1, (*(*ppv + 2)) - 1);

    //LETRA C
    // v[0] imprime a posição 0 do vetor
    // pv imprime o endereço de v[0]
    // ppv imprime o endereço de pv

    return 0;
}
