#include <stdio.h>

// как передавать данные через консоль



typedef struct {            //создание типа структуры и выделение памяти
    char name[20];
    char eduBool[16];
} Disciplines;


typedef union {             // union выделяет кол-во памяти под самый большой тип данных
    char Disciplines;
    char bytes[sizeof(Disciplines)];
} MyUnions;


//xor
unsigned printBinary(char digit) {
    char y = digit ^ 15;//15 == 00001111
    return 0;
}

unsigned serialization(unsigned char byte) {
    for (
            int i = 0;
            i < sizeof(Disciplines); ++i) {
//unsigned y = x^15; // 15=00001111 - младшая половина
//из 10 в 2 , xor

    }
}


int main(void) {
    Disciplines math;  //инициализация структуры

    MyUnions u = {};

//union MyUnion u = {math.name};
    printBinary(24);
    return 0;
}

//
//FILE *ptrFile = fopen("file.txt", "r");
//char mystring[100];
//
//if (ptrFile == NULL) perror("Ошибка открытия файла");
//else
//{
//if (
//fgets(mystring,
//100, ptrFile) != NULL) // считать символы из файла
//puts(mystring);  // вывод на экран
//fclose (ptrFile);
//}