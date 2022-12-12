#include <stdio.h>
#include <stdlib.h>

struct Disciplines {
    char name[20];
    char studying[16];
};
union U {
    struct Disciplines subject;
    char byte[sizeof(struct Disciplines)];
};

char one_byte_encode(char byte) {
    return byte ^ 15;
}

void encode_bytes_array(char *byte, char *out_buffer, size_t size,
                        char(f)(char)) {
    for (int i = 0; i < size; i++) {
        *out_buffer = f(*byte);
        out_buffer++;
        byte++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("The number of arguments should be strongly 1!");
        return -1;
    }
    union U u1;
    printf("Warning. For each item name only the first 20 characters will be used\n");
    printf("Please, Enter the name of the discipline within 20 characters\n");
    scanf("%20s", u1.subject.name);
    printf("Please, type a 16 logical values indicating whether the discipline is taught in each of the modules.\n");
    for (int i = 0; i < sizeof(u1.subject.studying); ++i) {
        int x = -1;
        while (x != 0 && x != 1) {
            scanf("%d", &x);
            printf("Вы ввели: %d\n", x);
            if (x == 0 || x == 1) {
                u1.subject.studying[i] = (char) x;
            } else printf("The wrong number, please write 0 or 1");
            return -1;
        }
    }

    //scanf("%s", u1.subject.studying);
    printf("Please, type an id of the person\n");
//    while (1) {
//        scanf("%ld", &u1.person.id);
//        if (u1.person.id <= 0) printf("Number should be positive only. Try again\n");
//        else break;
//    }
    char *buffer = (char *) malloc(sizeof(struct Disciplines));
    encode_bytes_array(u1.byte, buffer, sizeof(struct Disciplines),
                       one_byte_encode);
    FILE *ptrf = fopen(argv[1], "wb");
    if (ptrf == NULL) {
        printf("Can't write to the file. Failure.");
        fclose(ptrf);
        return 0;
    }
    fwrite(buffer, sizeof(struct Disciplines), 1, ptrf);
    free(buffer);
    fclose(ptrf);
    printf("Everything is awesome! Success.");
    return 0;
}
// gcc -o main encrypt.c




//#include <stdio.h>
//#include <locale.h>
//
//// принять данные, записать в структуру, записать в юнион, провести xor, записать в файл, сделать то же самое в обратном порядке
//
//
////создание типа структуры и выделение памяти
//typedef struct {
//    char name[20];
//    char eduBool[16];
//} Disciplines;
//
//// union выделяет кол-во памяти под самый большой тип данных
//typedef union {
//    char Disciplines;
//    char bytes[sizeof(Disciplines)];
//} MyUnions;
//
//
////xor
//unsigned printBinary(char digit) {
//    char y = digit ^ 15;//15 == 00001111
//    return 0;
//}
//
//unsigned serialization(unsigned char byte) {
//    for (
//            int i = 0;
//            i < sizeof(Disciplines); ++i) {
////unsigned y = x^15; // 15=00001111 - младшая половина
////из 10 в 2 , xor
//    }
//}
//
//
//int main(void) {
//    //setlocale(LC_ALL, "ru_RU.1251");
//
//    // Переменная, в которую будет помещен указатель на созданный
//    // поток данных
//    FILE *mf;
////            // Переменная, в которую поочередно будут помещаться считываемые байты
//    int sym;
//    // Открытие фала с режимом доступа «только чтение» и привязка к нему
//    // потока данных
//    printf("opening file: ");
//    mf = fopen("test.txt", "r");
//    // Проверка открытия файла
//    if (mf == NULL) {
//        perror("error opening");
//        return -1;
//    } else printf("выполнено\n");
//
//    printf("Коды считанных символов:\n");
//
//    //Чтение (побайтно) данных из файла в бесконечном цикле
//    while (1) {
//        // Чтение одного байта из файла
//        sym = fgetc(mf);
//
//        //Проверка на конец файла или ошибку чтения
//        if (sym == EOF) {
//            // Проверяем что именно произошло: кончился файл
//            // или это ошибка чтения
//            if (feof(mf) != 0) {
//                //Если файл закончился, выводим сообщение о завершении чтения
//                //и выходим из бесконечного цикла
//                printf("\nЧтение файла закончено\n");
//                break;
//            } else {
//                //Если при чтении произошла ошибка, выводим сообщение об
//                // ошибке и выходим из бесконечного цикла
//                printf("\nОшибка чтения из файла\n");
//                break;
//            }
//        }
//        //Если файл не закончился, и не было ошибки чтения
//        //выводим код считанного символа на экран
//        printf("%d ", sym);
//    }
//
//    // Закрываем файл
//    printf("Закрытие файла:");
//    if (fclose(mf) == EOF) printf("ошибка\n");
//    else printf("выполнено\n");
//    Disciplines math;  //инициализация структуры
//
//    MyUnions u = {};
//
////union MyUnion u = {math.name};
//    printBinary(24);
//    return 0;
//}

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