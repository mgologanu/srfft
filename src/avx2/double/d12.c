#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d1048576[] = {
#include "roots/p4_1048576.txt"
};

static_assert(sizeof(d1048576)/sizeof(double) == 524288, "Wrong initializer list for d1048576");
