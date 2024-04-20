#include <stdio.h>
#include <math.h>

int main(void){
    int a,b;
    printf("Digite o intervalo de numeros: ");
    scanf("%d %d", &a, &b);
    long long result = 0;
    for (int i = b; i >= a; i--){
        result += pow(i, 3);
    }
    printf("Resultado: %lld\n", result);
    
}