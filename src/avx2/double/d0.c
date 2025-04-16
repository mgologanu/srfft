#include <stdalign.h>
#include <assert.h>

#include "pre8_V4.h"
#include "i.h"


#if V==2
const double sq2[] = {SQRT_HALF, SQRT_HALF};

const double c_16[] = {0.92387953251128675612818318939678829, 0.92387953251128675612818318939678829};

const double s_16[] = {0.38268343236508977172845998403039887, 0.38268343236508977172845998403039887};

#else
const double sq2[]   = {SQRT_HALF};

const double sq2_u[] = {0x16A09E667F3BCCp-53L};

const double c_16[]  = {0.92387953251128675612818318939678829};

const double s_16[]  = {0.38268343236508977172845998403039887};
#endif


const _Alignas(32) double rad8_d32[] = {
#include "roots/rad8_32.txt"
};

static_assert(sizeof(rad8_d32)/sizeof(double) == 32, "Wrong initializer list for rad8_32");

const _Alignas(32) double rad8_d64[] = {
#include "roots/rad8_64.txt"
};

static_assert(sizeof(rad8_d64)/sizeof(double) == 64, "Wrong initializer list for rad8_64");

const _Alignas(32) double rad8_d128[] = {
#include "roots/rad8_128.txt"
};

static_assert(sizeof(rad8_d128)/sizeof(double) == 128, "Wrong initializer list for rad8_128");



const _Alignas(32) double d16[] = {
#include "roots/p4_16.txt"
};

const _Alignas(32) double d32[] = {
#include "roots/p4_32.txt"
};


const _Alignas(32) double d64[] = {
#include "roots/p4_64.txt"
};

const _Alignas(32) double d128[] = {
#include "roots/p4_128.txt"
};

static_assert(sizeof(d128)/sizeof(double) == 64, "Wrong initializer list for d128");

const _Alignas(32) double d256[] = {
#include "roots/p4_256.txt"
};

static_assert(sizeof(d256)/sizeof(double) == 128, "Wrong initializer list for d256");

