//
// Created by slava on 15.10.17.
//

#include <stdio.h>

void main(){
    double x, a, b, bn;
    scanf("%lf%lf", &x, &a);
    bn = a;
    while (scanf("%lf", &a) == 1){
        b = a + bn * x;
        bn = b;
    }
    printf("%g\n", b);
}