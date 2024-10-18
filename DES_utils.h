#ifndef DES_UTILS
#define DES_UTILS

#include <stdlib.h>
#include "constants.h"

void permutIP(uint64_t *in);

void invpermutIP(uint64_t *in);

uint64_t Eselec(uint32_t vec32);

void permP(uint32_t *in);

uint64_t permutChoice1(uint64_t key);

uint64_t permutChoice2(uint64_t key);

uint64_t bitShifts(uint64_t vec56);

#endif

