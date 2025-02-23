#include <stdio.h>
#include <stdlib.h>

double get_double(void) {
    char answer[256]; 
    double x;
  
      fgets(answer, sizeof(answer), stdin); 
  
      while (sscanf(answer, "%lg", &x) != 1) {
          printf("Некорректный ввод: "); 
          fgets(answer, sizeof(answer), stdin); 
      }
  
      return x; 
  }

void resetD(double set[], int size){
    for (int i = 0; i < size; i++){
        set[i] = rand();
    }
}

void insertD(double set[],int size, double element){
    set[size-1] = element;
}

void showD(double set[], int size){
    for (int i = 0; i < size; i++){
        printf("%lg   ", set[i]);
    }
    printf("\n");
}

void deletetD(double set[],int size, double element){
    int flag;
    for (int i = 0; i < size; i++){
        if (set[i] == element){flag = i;};
    }
    for (flag; flag < size - 1; flag++){
        set[flag] = set[flag+1];
    }
}

int IND(double element, double set[], double size){
    for (int i = 0; i < size; i++){
        if (element == set[i]){return 0;}
    }
    return 1;
}

void mainframeD(void){
    int a, b; 
    int key = 0;
    printf("Пожалуйста, введите кол-во элементов первого множества: \n");
    a = get_integer();
    double first[a+1000];
    while (key == 0){
    key = 1;
    printf("Введите элементы первого множества\n");
    for (int i = 0; i < a; i++){
        printf("Введите %d элемент: ", i);
        double num;
        num = get_double();
        if (IND(num, first, a) == 1){first[i] = num;}
        else {printf("Такой элемен уже был введен. Пожалуйста вводите уникальные элементы\n"); key = 0; resetD(first, a);break;};
    }
    };

    printf("\n*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n\n");


    key = 0;
    printf("Пожалуйста, введите кол-во элементов второго множества: \n");
    b = get_integer();
    double second[b+1000];
    while (key == 0){
    key = 1;
    printf("Введите элементы второго множества\n");
    for (int i = 0; i < b; i++){
        printf("Введите %d элемент: ", i);
        double num;
        num = get_double();
        if (IND(num, second, b) == 1){second[i] = num;}
        else {printf("Такой элемен уже был введен. Пожалуйста вводите уникальные элементы\n"); key = 0; resetD(second, b);break;};
    }
    };


    printf("\n*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n\n");

    
    int command;
    double element;
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
                    element = get_double();
                    if (IND(element, first, a)){a++;insertD(first, a, element);}else{printf("Данное множествое уже содержит элемент %lg\n",element);}
                    break;
                case 2:
                    printf("Пожалуйста введите элемент который вы хотите удалить из множества: \n");
                    element = get_double();
                    if (!(IND(element, first, a))){deletetD(first, a, element);a--;}else{printf("Данное множество не содержит элемент %lg\n", element);}
                    break;
                case 3: 
                    showD(first, a); 
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
                    element = get_double();
                    if (IND(element, second, b)){b++;insertD(second, b, element);}else{printf("Данное множествое уже содержит элемент %lg\n",element);}
                    break;
                case 2:
                    printf("Пожалуйста введите элемент который вы хотите удалить из множества: \n");
                    element = get_double();
                    if (!(IND(element, second, b))){deletetD(second, b, element);b--;}else{printf("Данное множество не содержит элемент %lg\n", element);}
                    break;
                case 3: 
                    showD(second, b); 
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

