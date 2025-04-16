#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d2048[] = {
#include "roots/p4_2048.txt"
};

static_assert(sizeof(d2048)/sizeof(double) == 1024, "Wrong initializer list for d2048");
