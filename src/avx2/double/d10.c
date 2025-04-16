#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d262144[] = {
#include "roots/p4_262144.txt"
};

static_assert(sizeof(d262144)/sizeof(double) == 131072, "Wrong initializer list for d262144");
