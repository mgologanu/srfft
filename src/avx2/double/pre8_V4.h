#include<immintrin.h>

typedef double real;
typedef __m256d real_packed;

#define V 4

#define V2 8

#define VPOW 2


#define SQRT_HALF 0.70710678118654752440084436210484903e0

#define MUL(a,b)     _mm256_mul_pd(a,b)
#define ADD(a,b)     _mm256_add_pd(a,b)
#define SUB(a,b)     _mm256_sub_pd(a,b)
#define LOAD(a)      _mm256_load_pd(&a)
#define LOADU(a)     _mm256_loadu_pd(&a)
#define STORE(a,b)   _mm256_store_pd(&a,b)
#define BROADCAST(a) _mm256_broadcast_sd(&a)

#define PERM(a,b,p)  _mm256_permute2f128_pd(a,b,p)
#define SHUF(a,b,i)  _mm256_shuffle_pd(a,b,i)

//Root packing

//Forward: 0x20, 0x31, 0x00, 0xF
#define P1_F 0x20
#define P2_F 0x31
#define I1_F 0x0
#define I2_F 0xF

//Backward: 0x13, 0x02, 0xF, 0x00
#define P1_B 0x13
#define P2_B 0x02
#define I1_B 0xF
#define I2_B 0x0

