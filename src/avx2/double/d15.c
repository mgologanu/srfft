#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d8388608[] = {
#include "roots/p4_8388608.txt"
};

static_assert(sizeof(d8388608)/sizeof(double) == 4194304, "Wrong initializer list for d1048576");

