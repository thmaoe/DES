#ifndef DES_KEYS
#define DES_KEYS

#include <stdlib.h>
#include "DES_utils.h"

uint64_t* generateKeys (uint64_t key);

uint32_t fKR(uint32_t R, uint64_t K);

#endif

