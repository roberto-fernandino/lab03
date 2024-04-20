#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long digito_verificador(long long cpnj){
   long long resultado = 0;
    char cnpj_str[15];
    sprintf(cnpj_str, "%lld", cpnj);
    int pesos[12] = {5,4,3,2,9,8,7,6,5,4,3,2};
    for (int i = 0; cnpj_str[i] != '\0'; i++){
        int digito = cnpj_str[i] - '0';
        resultado += digito * pesos[i];
    }
    if (resultado < 2){
        return 0;
    }
    else {
        return 11 - (resultado % 11);
    }
}
long long segundo_digito_verificador(long long cpnj, int primeiro_digito){
   long long resultado = 0;
    char cnpj_str[15];
    sprintf(cnpj_str, "%lld%d", cpnj, primeiro_digito);
    int pesos[13] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
    for (int i = 0; cnpj_str[i] != '\0'; i++){
        int digito = cnpj_str[i] - '0';
        resultado += digito * pesos[i];
    }
    if (resultado < 2){
        return 0 ;
    }
    else {
        return 11 - (resultado % 11);
    }
}

int main(void){
    long long cnpj;
    printf("Digite o CNPJ: ");
    scanf("%lld", &cnpj);
    printf("Resultado digito verificador: %lld\n", digito_verificador(cnpj));
    printf("Resultado segundo digito verificador: %lld\n", segundo_digito_verificador(cnpj, digito_verificador(cnpj)));
}