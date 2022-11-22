#include <stdio.h>
#include <locale.h>

// принять данные, записать в структуру, записать в юнион, провести xor, записать в файл, сделать то же самое в обратном порядке


//создание типа структуры и выделение памяти
typedef struct {
    char name[20];
    char eduBool[16];
} Disciplines;

// union выделяет кол-во памяти под самый большой тип данных
typedef union {
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
    setlocale(LC_ALL, "ru");
    // Переменная, в которую будет помещен указатель на созданный
    // поток данных
    FILE *mf;
    // Переменная, в которую поочередно будут помещаться считываемые байты
    int sym;

    // Открытие фала с режимом доступа «только чтение» и привязка к нему
    // потока данных
    printf("Открытие файла:");
    mf = fopen("test.txt", "r");

    // Проверка открытия файла
    if (mf == NULL) {
        printf("ошибка\n");
        printf("error\n");
        return -1;
    } else printf("выполнено\n");

    printf("Коды считанных символов:\n");

    //Чтение (побайтно) данных из файла в бесконечном цикле
    while (1) {
        // Чтение одного байта из файла
        sym = fgetc(mf);

        //Проверка на конец файла или ошибку чтения
        if (sym == EOF) {
            // Проверяем что именно произошло: кончился файл
            // или это ошибка чтения
            if (feof(mf) != 0) {
                //Если файл закончился, выводим сообщение о завершении чтения
                //и выходим из бесконечного цикла
                printf("\nЧтение файла закончено\n");
                break;
            } else {
                //Если при чтении произошла ошибка, выводим сообщение об
                // ошибке и выходим из бесконечного цикла
                printf("\nОшибка чтения из файла\n");
                break;
            }
        }
        //Если файл не закончился, и не было ошибки чтения
        //выводим код считанного символа на экран
        printf("%d ", sym);
    }

    // Закрываем файл
    printf("Закрытие файла:");
    if (fclose(mf) == EOF) printf("ошибка\n");
    else printf("выполнено\n");
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