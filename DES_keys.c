#include "DES_keys.h"

uint64_t* generateKeys (uint64_t key){
    static uint64_t res[16];

    uint64_t pc = permutChoice1(key);

    for (int i = 0; i<16; ++i){
        if (BShifts[i] == 1){
            pc = bitShifts(pc);
        }else{
            pc = bitShifts(bitShifts(pc));
        }

        res[i] = permutChoice2(pc);

    }
    
    return res;
}

uint32_t fKR(uint32_t R, uint64_t K){

    uint32_t res = 0;

    uint64_t E = Eselec(R);

    uint64_t xoR = E ^ K;

    for (int i = 0; i<8; ++i){

        uint8_t si = (xoR >> (63 - (5 + i*6))) & 0x3F; //block of 6 bits, preceded by 2 0s

        uint8_t row = ((si >> (7 - 2)) & 1) * 2 + ((si >> (7 - 7)) & 1);
        uint8_t col = ((si >> (7 - 3)) & 1) * 8 + ((si >> (7 - 4)) & 1) * 4 + ((si >> (7 - 5)) & 1) * 2 + ((si >> (7 - 6)) & 1);

        uint64_t d = S[i][row*16 + col];

        res ^= (d << (31 - (3 + 4*i)));  
    }

    permP(&res);

    return res;
}
