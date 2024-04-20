#include <stdio.h>
#include <math.h>


double fat(int n);


double exp_e(double x){
    double e = 1 + x;
    int n = 2;
    int elem = 0;
    do {
        e += pow(x,n)/fat(n);
        elem += 1;
        n += 1;
    } while (exp(x) - e > 0.0001);
    printf("Elementos: %d\n", elem);
    printf("exp(%lf) = %lf\n", x, exp(x));
    return e;
}


int main(void){
    double x;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    printf("exp_e(%lf) = %.4lf\n",x, exp_e(x));
    return 0;
}


double fat(int n){
    if (n == 0){
        return 1;
    } else {
        return n * fat(n-1);
    }
}