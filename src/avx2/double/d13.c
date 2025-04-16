#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d2097152[] = {
#include "roots/p4_2097152.txt"
};

static_assert(sizeof(d2097152)/sizeof(double) == 1048576, "Wrong initializer list for d1048576");

