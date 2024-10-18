#include "DES_utils.h"

void permutIP(uint64_t *in){

    uint64_t temp = *in;

    for (int i = 0; i<64; ++i){

        uint8_t bit1 = (temp >> (63 - i)) & 1; //on shift le bit voulu vers la droite et on recup sa valeur avec & 1
        uint8_t bit2 = (temp >> (63 - (IP[i] - 1))) & 1;

        if (bit1 != bit2){
            *in ^= (1ULL << (63 - i));
        }  
    
    }
}

void invpermutIP(uint64_t *in){

    uint64_t temp = *in;

    for (int i = 0; i<64; ++i){

        uint8_t bit1 = (temp >> (63 - i)) & 1;
        uint8_t bit2 = (temp >> (63 - (IP_[i] - 1))) & 1;

        if (bit1 != bit2){
            *in ^= (1ULL << (63 - i));
        }  
    
    }
}

uint64_t Eselec(uint32_t vec32){
    uint64_t res48 = 0;

    for (int i = 0; i<48; ++i){

        uint8_t bit1 = (vec32 >> (31 - (E[i] - 1))) & 1;
        uint8_t bit2  = (res48 >> (63 - i)) & 1;

        if (bit1 != bit2){
            res48 ^= (1ULL << (63 - i));
            res48 &= mask48;
        }
        
    }

    return res48;
}

void permP(uint32_t *in){
    uint32_t temp = *in;

    for (int i = 0; i<32; ++i){

        uint8_t bit1 = (temp >> (31 - i)) & 1;
        uint8_t bit2 = (temp >> (31 - (P[i] - 1))) & 1;

        if (bit1 != bit2){
            *in ^= (1ULL << (31 - i));
        }
    }
}

uint64_t permutChoice1(uint64_t key){
    uint64_t res = 0;

    for (int i = 0; i<56; ++i){
        
        uint8_t bit1 = (res >> (63 - i)) & 1; //useless since 0 anyway but clearer to me for now.
        uint8_t bit2 = (key >> (63 - (PC1[i] - 1))) & 1;

        if (bit1 != bit2){
            res ^= (1ULL << (63 - i));
            res &= mask56;
        }
    }

    return res;
}

uint64_t permutChoice2(uint64_t key){
    uint64_t res = 0;

    for (int i = 0; i<48; ++i){
        
        uint8_t bit1 = (res >> (63 - i)) & 1; //useless since 0 anyway but clearer to me for now.
        uint8_t bit2 = (key >> (63 - (PC2[i] - 1))) & 1;

        if (bit1 != bit2){
            res ^= (1ULL << (63 - i));
            res &= mask48;
        }
    }

    return res;
}

uint64_t bitShifts(uint64_t vec56){
    uint64_t res = 0; 

    uint8_t bit0 = (vec56 >> (63 - 0)) & 1;
    uint8_t bit28 = (vec56 >> (63 - 28)) & 1;
    
    if (bit0 == 1){ //we set res to 0 so if = 1 they are different
        res ^= (1ULL << (63 - 27));
        res &= mask56;
    } 

    if (bit28 == 1){
        res ^= (1ULL << (63 - 55));
        res &= mask56;
    } 

    for (int i = 0; i<27; ++i){
        uint8_t bit = (vec56 >> (63 - (i + 1))) & 1;

        if (bit == 1){
            res ^= (1ULL << (63 - i));
            res &= mask56;
        }
    }

    for (int i = 28; i<55; ++i){
        uint8_t bit = (vec56 >> (63 - (i + 1))) & 1;

        if (bit == 1){
            res ^= (1ULL << (63 - i));
            res &= mask56;
        }
    }

    return res;

}
