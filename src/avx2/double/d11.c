#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d524288[] = {
#include "roots/p4_524288.txt"
};

static_assert(sizeof(d524288)/sizeof(double) == 262144, "Wrong initializer list for d524288");
