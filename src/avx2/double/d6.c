#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d16384[] = {
#include "roots/p4_16384.txt"
};

static_assert(sizeof(d16384)/sizeof(double) == 8192, "Wrong initializer list for d16384");
