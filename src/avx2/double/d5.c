#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d8192[] = {
#include "roots/p4_8192.txt"
};

static_assert(sizeof(d8192)/sizeof(double) == 4096, "Wrong initializer list for d8192");
