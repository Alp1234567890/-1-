#include <stdio.h>

#include <stdlib.h>

void resetC(char * set, int size) {
        for (int i = 0; i < size; i++) {
                set[i] = rand();
        }
}

char * insertC(char * set, int size, char element) {
        char * new_set = realloc(set, size);
        new_set[size - 1] = element;
        return new_set;
}

void showC(char * set, int size) {
        for (int i = 0; i < size; i++) {
                printf("%c   ", set[i]);
        }
        puts("");
}

void deletetC(char * set, int size, char element) {
        int flag;
        for (int i = 0; i < size; i++) {
                if (set[i] == element) {
                        flag = i;
                };
        }
        for (flag; flag < size - 1; flag++) {
                set[flag] = set[flag + 1];
        }
}

int INC(char element, char * set, int size) {
        for (int i = 0; i < size; i++) {
                if (element == set[i]) {
                        return 0;
                }
        }
        return 1;
}

void mainframeC(void) {
        int a, b; // a  - длина первого множества, b - второго 
        int key = 0;
        char num;
        printf("Пожалуйста, введите кол-во элементов первого множества: \n");
        a = get_integer();
        char * first = malloc(a * sizeof(char));
        while (key == 0) {
                key = 1;
                printf("Введите элементы первого множества\n");
                for (int i = 0; i < a; i++) {
                        printf("Введите %d элемент: ", i);
                        scanf(" %c", & num);
                        if (INC(num, first, a) == 1) {
                                first[i] = num;
                        } else {
                                printf("Такой элемен уже был введен. Пожалуйста вводите уникальные элементы\n");
                                key = 0;
                                resetC(first, a);
                                break;
                        };
                }
        };

        printf("\n*******************************************************************************\n");
        printf("*******************************************************************************\n");
        printf("*******************************************************************************\n\n");

        key = 0;
        printf("Пожалуйста, введите кол-во элементов второго множества: \n");
        b = get_integer();
        char * second = malloc(b * sizeof(char));
        while (key == 0) {
                key = 1;
                printf("Введите элементы второго множества\n");
                for (int i = 0; i < b; i++) {
                        printf("Введите %d элемент: ", i);
                        char num;
                        scanf(" %c", & num);
                        if (INC(num, second, b) == 1) {
                                second[i] = num;
                        } else {
                                printf("Такой элемен уже был введен. Пожалуйста вводите уникальные элементы\n");
                                key = 0;
                                resetC(second, b);
                                break;
                        };
                }
        };

        printf("\n*******************************************************************************\n");
        printf("*******************************************************************************\n");
        printf("*******************************************************************************\n\n");

        int command;
        char element;
        int set;
        do {
                printf("С каким множеством вы хотите работать?\n");
                printf("1 - c первым\n");
                printf("2 - со вторым\n");
                printf("3 - прекратить работу программы\n");
                set = get_integer();
                if (set == 1) {
                        printf("Введите команду:\n");
                        printf("1 - чтобы добавить элемент в множество\n");
                        printf("2 - чтобы удалить элемент из множества\n");
                        printf("3 - чтобы вывести множество\n");
                        command = get_integer();
                        switch (command) {
                        case 1:
                                printf("Пожалуйста введите элемент который вы хотите добавить в множество: \n");
                                scanf(" %c", & element);
                                if (INC(element, first, a)) {
                                        a++;
                                        first = insertC(first, a, element);
                                } else {
                                        printf("Данное множествое уже содержит элемент %c\n", element);
                                }
                                break;
                        case 2:
                                printf("Пожалуйста введите элемент который вы хотите удалить из множества: \n");
                                scanf(" %c", & element);
                                if (!(INC(element, first, a))) {
                                        deletetC(first, a, element);
                                        a--;
                                        first = realloc(first, a);
                                } else {
                                        printf("Данное множество не содержит элемент %c\n", element);
                                }
                                break;
                        case 3:
                                showC(first, a);
                                break;
                        default:
                                printf("Вы ввели не верную команду\n");
                                break;
                        }
                } else if (set == 2) {
                        printf("Введите команду:\n");
                        printf("1 - чтобы добавить элемент в множество\n");
                        printf("2 - чтобы удалить элемент из множества\n");
                        printf("3 - чтобы вывести множество\n");
                        command = get_integer();
                        switch (command) {
                        case 1:
                                printf("Пожалуйста введите элемент который вы хотите добавить в множество: \n");
                                scanf(" %c", & element);
                                if (INC(element, second, b)) {
                                        b++;
                                        second = insertC(second, b, element);
                                } else {
                                        printf("Данное множествое уже содержит элемент %c\n", element);
                                }
                                break;
                        case 2:
                                printf("Пожалуйста введите элемент который вы хотите удалить из множества: \n");
                                scanf(" %c", & element);
                                if (!(INC(element, second, b))) {
                                        deletetC(second, b, element);
                                        b--;
                                        second = realloc(second, b);
                                } else {
                                        printf("Данное множество не содержит элемент %c\n", element);
                                }
                                break;
                        case 3:
                                showC(second, b);
                                break;
                        default:
                                printf("Вы ввели не верную команду\n");
                                break;
                        }
                } else if (set == 3) {
                        printf("До скорых встреч !!!\n");
                } else {
                        printf("Вы ввели не верную команду\n");
                }

        } while (set != 3);
}