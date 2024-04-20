#include <stdio.h>
#include <math.h>


int soma_cpf(int cpf){
    int resultado = 0;
    for (int i = 1; i < 10; i++){
        int digito = cpf % 10;
        cpf = cpf / 10;
        resultado += digito * (i+1);
    }
    return resultado;
}
int digito_verificador(int cpf){
    int soma = soma_cpf(cpf);
    if (soma % 11 == 1 || soma % 11 == 0){
        return 0;
    } else {
        return 11 - (soma % 11);
    }
}
int soma_com_digito(int cpf){
    int soma = soma_cpf(cpf);
    int digito_verif = digito_verificador(cpf);
    int resultado = 0;
    int pesos[9] = {3,4,5,6,7,8,9,10,11};

    for (int i = 1; i < 11; i++){
        if (i == 1) {
            resultado += digito_verif * 2;
        } else {
            int digito = cpf % 10;
            cpf = cpf / 10;
            resultado += pesos[i-2] * digito;
        }
    }
    return resultado;
}

int segundo_digito(int cpf){
    int soma = soma_cpf(cpf);
    int digito_verif = digito_verificador(cpf);
    int soma_com_digit = soma_com_digito(cpf);
    if (soma_com_digit % 11 == 1 || soma_com_digit % 11 == 0){
        return 0;
    } else {
        return 11 - (soma_com_digit % 11);
    }
}

int main(void){
    int cpf;
    printf("Digite o CPF: ");
    scanf("%d", &cpf);
    printf("Resultado soma cpf: %d\n", soma_cpf(cpf));
    printf("Digito verificador: %d\n", digito_verificador(cpf));
    printf("Soma com digito: %d\n", soma_com_digito(cpf));
    printf("Segundo digito: %d\n", segundo_digito(cpf));
    return 0;
}