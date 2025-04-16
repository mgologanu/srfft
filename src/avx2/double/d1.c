#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d512[] = {
#include "roots/p4_512.txt"
};

static_assert(sizeof(d512)/sizeof(double) == 256, "Wrong initializer list for d512");
