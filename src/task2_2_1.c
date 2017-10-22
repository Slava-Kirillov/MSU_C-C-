//
// Created by slava on 15.10.17.
//

#include <stdio.h>

void main(){
    double x, a, p, dp;
    scanf("%lf%lf", &x, &a);
    p = a;
    dp = 0;
    while (scanf("%lf", &a) == 1){
        dp = dp * x + p;
        p = p * x + a;
    }
    printf("%s = %g\n","Polynomial", p);
    printf("%s = %g\n","Derivative", dp);
}