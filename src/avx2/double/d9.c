#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d131072[] = {
#include "roots/p4_131072.txt"
};

static_assert(sizeof(d131072)/sizeof(double) == 65536, "Wrong initializer list for d131072");
