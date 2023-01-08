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

char one_byte_decode(char byte) {
    return byte ^ 15;
}

void decode_bytes_array(char *in_buffer, char *out_buffer, size_t size, char(f)(char)) {
    for (int i = 0; i < size; i++) {
        *out_buffer = f(*in_buffer);
        out_buffer++;
        in_buffer++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("The number of arguments should be strongly 1!");
        return -1;
    }
    FILE *pf = fopen(argv[1], "rb");
    if (pf == NULL) {
        printf("File with name %s doesn't exist", argv[1]);
        fclose(pf);
        return -1;
    }
    char *enc_buffer = (char *) malloc(sizeof(struct Disciplines));
    union U u1;
    fread(enc_buffer, sizeof(struct Disciplines), 1, pf);
    fclose(pf);
    decode_bytes_array(enc_buffer, u1.byte, sizeof(struct Disciplines), one_byte_decode);
    free(enc_buffer);
    printf("The encrypted name of the lesson: %s\n", u1.subject.name);
    for (int i = 0; i < 16; i++) {
        printf("[%d] ", u1.subject.studying[i]);
    }
    return 0;
}

// qwe
