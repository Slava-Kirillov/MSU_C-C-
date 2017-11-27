//
// Created by slava on 15.10.17.
//

#include <stdio.h>

double str2double(char *string){
    double a, b = 0, c = 0, e, x = 10, y = 10;
    int i, n;
    if (*string == '\0') {
        return 0;
    }
    while (*string == '0') {
        string++;
    }
    if (*string != '.' && *string != 'E' && *string != 'e') {
        b = *string - 48;
        string++;
        while (*string >= '0' && *string <= '9') {
            a = *string - 48;
            b = b * x + a;
            string++;
        }
    }
    if (*string == '.') {
        string++;
        if (*string != 'E' && *string != 'e') {
            c = *(string) - 48;
            string++;
            while (*string >= '0' && *string <= '9') {
                a = *string - 48;
                c = c * x + a;
                string++;
                y *= 10;
            }
            c = c / y;
        }else{
            c = 0;
        }
        b = b + c;
        if (*string != '\0') {
            return b * str2double(string);
        }else{
            return b;
        }
    }
    if (*string == 'E' || *string == 'e') {
        string++;
        if (*string == '+'){
            e = 10;
        }else{
            e = 0.1;
        }
        string++;
        b = e;
        n = (int) str2double(string);
        for (i = 1; i < n; i++){
            b *= e;
        }
        return b;
    }
    return b;
}

void main(){
    char str[100];
    double b;
    scanf("%s", str);
    b = str2double(str);
    printf("%.10g\n", b);
}

