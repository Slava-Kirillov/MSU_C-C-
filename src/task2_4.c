//
// Created by slava on 15.10.17.
//

#include <stdio.h>

//Вычисляет степень десяти, d - степень, sign - знак степени
// (0 - отрицательная степень, 1 - положительная степень)
double tenDegree(int d, int sign){
    double res = 1;
    double x = 10;
    int i;
    if (sign){
        for (i = 0; i < d; ++i) {
            res = res * x;
        }
        return res;
    }else{
        for (i = 0; i < d; ++i) {
            res = res * (1/x);
        }
        return res;
    }
}

double str2double(char *string){
    int i = 0, n;
    double dig, res1 = 0, res2 = 0;
    char *dig_dec;
    while (*string != '.' && *string != '\0'){
        ++i;
        ++string;
    }
    dig_dec = string;
    n = 0;
    while (n < i) {
        dig = ((double) (*--string - '0')) * tenDegree(n, 1);
        res1 = res1 + dig;
        n++;
    }
    n = 1;
    ++dig_dec;
    while (*dig_dec != '\0'){
        dig = ((double) (*dig_dec - '0')) * tenDegree(n, 0);
        res2 = res2 + dig;
        ++dig_dec;
        n++;
    }
    return res1 + res2;
}

void main(){
    char str[100];
    scanf("%s", str);
    printf("%.10g\n", str2double(str));
}

