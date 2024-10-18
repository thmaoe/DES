#include "DES_algos.h"

uint64_t DESEnc(uint64_t input, uint64_t key){
    uint64_t enc = 0;

    permutIP(&input);

    uint32_t L = (input >> (63 - 31));
    uint32_t R = input;

    uint64_t* keys = generateKeys(key);

    for (int i = 0; i<15; ++i){ //first 15 rounds
        uint64_t k = keys[i];

        uint32_t f = fKR(R, k);

        uint32_t temp = R;
        R = L ^ f;
        L = temp;

    }

    uint64_t k = keys[15];

    uint32_t f = fKR(R,k);

    L = L ^ f;

    uint64_t Ll = L;
    Ll = (Ll << (63 - 31));
    uint64_t Rr = R;

    enc ^= Ll;
    enc ^= Rr;

    invpermutIP(&enc);

    return enc;

}

uint64_t DESDec(uint64_t input, uint64_t key){
    uint64_t enc = 0;

    permutIP(&input);

    uint32_t L = (input >> (63 - 31));
    uint32_t R = input;

    uint64_t* keys = generateKeys(key);

    for (int i = 0; i<15; ++i){ //first 15 rounds
        uint64_t k = keys[15 - i];

        uint32_t f = fKR(R, k);

        uint32_t temp = R;
        R = L ^ f;
        L = temp;

    }

    uint64_t k = keys[0];

    uint32_t f = fKR(R,k);

    L = L ^ f;

    uint64_t Ll = L;
    Ll = (Ll << (63 - 31));
    uint64_t Rr = R;

    enc ^= Ll;
    enc ^= Rr;

    invpermutIP(&enc);

    return enc;

}
