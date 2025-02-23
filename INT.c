#include <stdio.h>
#include <stdlib.h>

int get_integer(void) {
    char answer[256];
    int n;
    
    fgets(answer, sizeof(answer), stdin); 
    int check = 1;
    while (sscanf(answer, "%d", &n) != 1) {
        if (check == 0){
        printf("Некорректный ввод.\n"); }
        fgets(answer, sizeof(answer), stdin);
        check = 0; 
    }

    return n; 
}

void resetINT(int set[], int size){
    for (int i = 0; i < size; i++){
        set[i] = rand();
    }
}

void insertINT(int set[],int size, int element){
    set[size-1] = element;
}

void showINT(int set[], int size){
    for (int i = 0; i < size; i++){
        printf("%d   ", set[i]);
    }
    printf("\n");
}

void deletetINT(int set[],int size, int element){
    int flag;
    for (int i = 0; i < size; i++){
        if (set[i] == element){flag = i;};
    }
    for (flag; flag < size - 1; flag++){
        set[flag] = set[flag+1];
    }
}

int ININT(int element, int set[], int size){
    for (int i = 0; i < size; i++){
        if (element == set[i]){return 0;}
    }
    return 1;
}

void mainframeINT(void){
    int a, b; 
    int key = 0;
    printf("Пожалуйста, введите кол-во элементов первого множества: \n");
    a = get_integer();
    int first[a+1000];
    while (key == 0){
    key = 1;
    printf("Введите элементы первого множества\n");
    for (int i = 0; i < a; i++){
        printf("Введите %d элемент: ", i);
        int num;
        num = get_integer();
        if (ININT(num, first, a) == 1){first[i] = num;}
        else {printf("Такой элемен уже был введен. Пожалуйста вводите уникальные элементы\n"); key = 0; resetINT(first, a);break;};
    }
    };

    printf("\n*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n\n");


    key = 0;
    printf("Пожалуйста, введите кол-во элементов второго множества: \n");
    b = get_integer();
    int second[b+1000];
    while (key == 0){
    key = 1;
    printf("Введите элементы второго множества\n");
    for (int i = 0; i < b; i++){
        printf("Введите %d элемент: ", i);
        int num;
        num = get_integer();
        if (ININT(num, second, b) == 1){second[i] = num;}
        else {printf("Такой элемен уже был введен. Пожалуйста вводите уникальные элементы\n"); key = 0; resetINT(second, b);break;};
    }
    };


    printf("\n*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n\n");

    
    int command;
    int element;
    int set;
    do {
        printf("С каким множеством вы хотите работать?\n");
        printf("1 - c первым\n");
        printf("2 - со вторым\n");
        printf("3 - прекратить работу программы\n");
        set = get_integer();
        if (set == 1){
                printf("Введите команду:\n");
                printf("1 - чтобы добавить элемент в множество\n");
                printf("2 - чтобы удалить элемент из множества\n");
                printf("3 - чтобы вывести множество\n");
                command = get_integer();
            switch( command )
            {
                case 1:
                    printf("Пожалуйста введите элемент который вы хотите добавить в множество: \n");
                    element = get_integer();
                    if (ININT(element, first, a)){a++;insertINT(first, a, element);}else{printf("Данное множествое уже содержит элемент %d\n",element);}
                    break;
                case 2:
                    printf("Пожалуйста введите элемент который вы хотите удалить из множества: \n");
                    element = get_integer();
                    if (!(ININT(element, first, a))){deletetINT(first, a, element);a--;}else{printf("Данное множество не содержит элемент %d\n", element);}
                    break;
                case 3: 
                    showINT(first, a); 
                    break;
                default:
                    printf("Вы ввели не верную команду\n");
                    break;
            }}else if(set == 2){
                printf("Введите команду:\n");
                printf("1 - чтобы добавить элемент в множество\n");
                printf("2 - чтобы удалить элемент из множества\n");
                printf("3 - чтобы вывести множество\n");
                command = get_integer();
            switch( command )
            {
                case 1:
                    printf("Пожалуйста введите элемент который вы хотите добавить в множество: \n");
                    element = get_integer();
                    if (ININT(element, second, b)){b++;insertINT(second, b, element);}else{printf("Данное множествое уже содержит элемент %d\n",element);}
                    break;
                case 2:
                    printf("Пожалуйста введите элемент который вы хотите удалить из множества: \n");
                    element = get_integer();
                    if (!(ININT(element, second, b))){deletetINT(second, b, element);b--;}else{printf("Данное множество не содержит элемент %d\n", element);}
                    break;
                case 3: 
                    showINT(second, b); 
                    break;
                default:
                    printf("Вы ввели не верную команду\n");
                    break;
            }}else if(set == 3){
                printf("До скорых встреч !!!\n");
            } else {
                printf("Вы ввели не верную команду\n");}

} while (set != 3);
}

