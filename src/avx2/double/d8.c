#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d65536[] = {
#include "roots/p4_65536.txt"
};

static_assert(sizeof(d65536)/sizeof(double) == 32768, "Wrong initializer list for d65536");
