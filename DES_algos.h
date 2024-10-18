#ifndef DES_ALGOS
#define DES_ALGOS

#include <stdlib.h>
#include "DES_keys.h"

uint64_t DESEnc(uint64_t input, uint64_t key);

uint64_t DESDec(uint64_t input, uint64_t key);

#endif
