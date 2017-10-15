//
// Created by slava on 15.10.17.
//

#include <stdio.h>

int j, i, fib1, fib2;

int fIter(int n){
    fib1 = 0;
    fib2 = 1;
    if (n == 0)
        return fib1;
    for (j = 1; j < n; j++){
        fib2 += fib1;
        fib1 = fib2 - fib1;
    }
    return fib2;
}

int fRec(int n){
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    return fRec(n - 1) + fRec(n - 2);
}

void main(){
    while (scanf("%d", &i) == 1) {
        printf("%s", "Iter = ");
        printf("%d\n", fIter(i));
        printf("%s", "Rec = ");
        printf("%d\n", fRec(i));
    }
}
