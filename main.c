#include <stdio.h>

//создание типа структуры и выделение памяти
typedef struct {
    char name[20];
    char eduBool[16];
} Disciplines;
// union выделяет кол-во памяти под самый большой тип данных
typedef union {
    char name[20];
    char size[36];
} MyUnion;


int main(void) {
    Disciplines math;  //инициализация структуры
    //math.name=() "mathem", "1111000011110000";
    //mathem 1111000011110000
    scanf("%d", &(math.name));
    scanf("%d", &(math.eduBool));

    //union MyUnion u = {math.name};

    printf("%d", sizeof(math));
    printf("\n name ", math.name);
    return 0;
}
