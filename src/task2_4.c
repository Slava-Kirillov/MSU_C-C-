//
// Created by slava on 15.10.17.
//

#include <stdio.h>

double str2double(char *string){
    int sign = 1;
    double a,x = 10,b = 0,deg = 1;
    switch (*string){
        case '\0':
            return b;
        case '-':
            string++;
            return 1/str2double(string);
        case '+':
            string++;
            return str2double(string);
        case 'E':
            string++;
            deg = str2double(string);
        case 'e':
            string++;
            deg = str2double(string);
    }
    if (*string == '.'){
        x = 1/10;
        string++;
    }
    while (*string > '0' && *string < '9'){
        a = *string - 48;
        b = b + a*x;
        string++;
    }
    return (b + str2double(string)) * deg;
}

void main(){
    char str[100];
    double b;
    scanf("%s", str);
    b = str2double(str);
    printf("%.10g\n", b);
}

