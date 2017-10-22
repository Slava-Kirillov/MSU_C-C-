//
// Created by slava on 15.10.17.
//

#include <stdio.h>

void main(){
    double x, a, b, bn, d;
    scanf("%lf%lf", &x, &a);
    bn = a;
    d = 0;
    while (scanf("%lf", &a) == 1){
        d = bn + d * x;
        b = a + bn * x;
        bn = b;
    }
    printf("%g\n", b);
    printf("%g\n", d);
}