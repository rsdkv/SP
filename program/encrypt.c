#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//аргументы переданные пользователем, argv – массив строк
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("The number of arguments should be strongly 1!");
        return -1;
    }
    union U u1;
    printf("Warning. For each item name only the first 20 characters will be used.\n");
    printf("Please, Enter the name of the discipline within 20 characters: \n");
    scanf("%20s", u1.subject.name);
    if (strlen(u1.subject.name) > 20) {
        errno = 1;
        printf("error: length more than it should be. ", errno, strerror(errno));
        return -1;
    }
    printf("Please, type a 16 logical values indicating whether the discipline is taught in each of the modules.\n");
    for (int i = 0; i < 16; i++) {
        int x = -1;
        while (x != 0 && x != 1) {
            scanf("%d", &x);
            printf("your input: %d\n", x);
            if (x == 0 || x == 1) {
                u1.subject.studying[i] = (char) x;
            } else {
                errno = 1;
                printf("Value of errno: %d\nError message: %s\n", errno, strerror(errno));
                printf("The wrong number, please write 0 or 1");
                return -1;
            }
        }
    }
//malloc выделяет блок памяти под Disciplines. Результирующий буфер сохранен в динамической памяти
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
// .\main test.txt