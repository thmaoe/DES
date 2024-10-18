#include <stdio.h>
#include <stdlib.h>
#include "DES_algos.h"

int main(void){

    uint64_t block = 0x6162636465666768;
    uint64_t k = 0x7365637265742121;

    printf("0x%016llX\n", block);
    printf("0x%016llX\n", k);

    uint64_t enc = DESEnc(block, k);
    printf("0x%016llX\n", enc);

    uint64_t dec = DESDec(enc, k);
    printf("0x%016llX\n", dec);

    return 0;

}
