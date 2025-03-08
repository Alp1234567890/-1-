#include "INT.c"

#include "DOUBLE.c"

#include "CHAR.c"

#include <stdio.h>

int main(void) {
        int command;
        int c = 1;
        while (c == 1) {
                printf("Выберите с каким видом данных вы хотите работать\n");
                printf("1 - INT \n");
                printf("2 - DOUBLE \n");
                printf("3 - CHAR \n");
                scanf("%d", & command);
                switch (command) {
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
                }
        }
        return 0;
}