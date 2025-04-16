#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d1024[] = {
#include "roots/p4_1024.txt"
};

static_assert(sizeof(d1024)/sizeof(double) == 512, "Wrong initializer list for d1024");
