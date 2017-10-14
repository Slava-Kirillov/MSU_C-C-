//
// Created by slava on 25.09.17.
//

#include <stdio.h>

double x, eps, sqrX;

double myAbs(double y) {
    if (y < 0) {
        return -y;
    }
    return y;
}

double mySqrt(double x, double eps) {
    double x0, abs;
    double x1 = 1;
    do{
        x0 = x1;
        x1 = ((double) 1 / 2) * (x0 + x / x0);
        abs = myAbs(x1-x0);
    }while (abs > eps);
    return x1;
}

void main() {
    scanf("%lf", &eps);
    while (scanf("%lf", &x) == 1) {
        sqrX = mySqrt(x, eps);
        printf("%.10g\n", sqrX);
    }
}