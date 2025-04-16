#include <stdalign.h>
#include <assert.h>
#include "pre8_V4.h"
#include "i.h"
 
const _Alignas(32) double d4194304[] = {
#include "roots/p4_4194304.txt"
};

static_assert(sizeof(d4194304)/sizeof(double) == 2097152, "Wrong initializer list for d1048576");


