#include <stdio.h>
#include <stdint.h>

uint32_t my_ntohl(uint32_t n){
    uint32_t n1 = (n & 0xFF000000) >> 24;
    uint32_t n2 = (n & 0x00FF0000) >> 8;
    uint32_t n3 = (n & 0x0000FF00) << 8;
    uint32_t n4 = (n & 0x000000FF) << 24;

    return n1 | n2 | n3 | n4;
}

int main() {
    /* FILE TYPE variable */
    FILE *fp1;
    FILE *fp2;

    /* uint32_t TYPE fread variable */
    uint32_t f1;
    uint32_t f2;

    /* Open files for reading in binary mode */
    fp1 = fopen("thousand.bin", "rb");
    fp2 = fopen("five-hundred.bin", "rb");

    /* File read check */
    if (fp1 == NULL || fp2 == NULL) {
        printf("Invalid File.");
        return 1;
    }

    /* Read 32-bit numbers from files */
    fread(&f1, sizeof(uint32_t), 1, fp1);
    fread(&f2, sizeof(uint32_t), 1, fp2);

    /* Convert from network byte order to host byte order */
    f1 = my_ntohl(f1);
    f2 = my_ntohl(f2);

    /* Calculate and print the sum */
    uint32_t sum = f1 + f2;
    printf("%d(%#x) + %d(%#x) = %d(%#x)\n",f1, f1, f2, f2,sum, sum);

    /* Close files */
    fclose(fp1);
    fclose(fp2);

    return 0;
}
