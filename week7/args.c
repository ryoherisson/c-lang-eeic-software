#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Error. #arg must be 3: method, seed, and v0\n");
        return -1;
    }
    
    char *method = argv[1];
    int seed = atoi(argv[2]);
    double v0 = atof(argv[3]);

    printf("method: %s\nseed: %d\nv0: %f\n", method, seed, v0);

    return 0;
}