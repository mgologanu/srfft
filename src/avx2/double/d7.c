#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d32768[] = {
#include "roots/p4_32768.txt"
};

static_assert(sizeof(d32768)/sizeof(double) == 16384, "Wrong initializer list for d32768");
