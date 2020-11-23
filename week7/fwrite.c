#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Error. #arg must be 1: filename\n");
        return -1;
    }

    char *filename = argv[1];

    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot open %s\n", filename);
        return -1;
    }

    fprintf(fp, "ID:%d", 13);

    fclose(fp);
}