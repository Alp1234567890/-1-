#include "INT.c"
#include "DOUBLE.c"
#include "CHAR.c"
#include <stdio.h>

#define typename(x) _Generic((x),                                                 \
            _Bool: "_Bool",                  unsigned char: "unsigned char",          \
             char: "char",                     signed char: "signed char",            \
        short int: "short int",         unsigned short int: "unsigned short int",     \
              int: "int",                     unsigned int: "unsigned int",           \
         long int: "long int",           unsigned long int: "unsigned long int",      \
    long long int: "long long int", unsigned long long int: "unsigned long long int", \
            float: "float",                         double: "double",                 \
      long double: "long double",                   char *: "pointer to char",        \
           void *: "pointer to void",                int *: "pointer to int",         \
          default: "other")

int main(void){
    int absolute;
    int c = 1;
    while (c == 1){
    printf("Выберите с каким видом данных вы хотите работать\n");
    printf("1 - INT \n");
    printf("2 - DOUBLE \n");
    printf("3 - CHAR \n");
    scanf("%d", &absolute);
    switch (absolute){
        case 1:
            printf("Так как вы выбрали работать с целыми числами, то у дробныйх чисел цифры после . не учитываются\n");
            mainframeINT();
            c = 0;
            break;
        case 2:
            mainframeD();
            c = 0;
            break;
        case 3:
            printf("При вводе учтите, что используестя только первый введеный символ\n");
            mainframeC();
            c = 0;
            break;
        default:
            printf("Не корректный ввод. \n");
            break;
    }}
    return 0;
}