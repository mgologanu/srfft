#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d4096[] = {
#include "roots/p4_4096.txt"
};

static_assert(sizeof(d4096)/sizeof(double) == 2048, "Wrong initializer list for d4096");
