#include "pre8_V4.h"
#include "i.h"

#define HALF_SQRT_HALF 0.35355339059327376220042218105242452

void unfinalize_c4_from_r8(real * a0,  real * b0, real *  a1, real * b1, real *  a2, real *   b2, real *   a3, real *  b3)
{
  real t0, t1, t2, t3, t4, t5;

  t0 = 0.5e0 * (*a0 + *b0);
  t1 = 0.5e0 * (*a0 - *b0);

  *a0 = t0;
  *b0 = t1;

  *b2 = -*b2;


  t0 = 0.5e0 * (*b3 - *b1);
  t1 = 0.5e0 * (*a3 + *a1);
  
  t2 = HALF_SQRT_HALF * (*b3 + *b1);
  t3 = HALF_SQRT_HALF * (*a3 - *a1);

  t4 = t2 + t3; 
  t5 = t2 - t3; 
  
  *a1 =  t1 - t5; //	-((b3+b1-a3+a1)*sq2-a3-a1)/2  
  *b1 = -t0 - t4; //  	-((b3+b1+a3-a1)*sq2+b3-b1)/2

  *a3 = t1 + t5;  //	((b3+b1-a3+a1)*sq2+a3+a1)/2
  *b3 = t0 - t4;  //	-((b3+b1+a3-a1)*sq2-b3+b1)/2
  
}



void v32(register real *a)
{
  real_packed t0, t1, t2, t3;


  unfinalize_c4_from_r8(&a[0],&a[4],&a[24],&a[28],&a[8],&a[12],&a[16],&a[20]);

  u4_vert(a);
   
  t0 = LOAD(a[0]);
  t1 = LOAD(a[4]);
  t2 = SHUF(t0,t1,I1_B);
  t3 = SHUF(t0,t1,I2_B);
  t0 = PERM(t2,t3,P1_B);
  t1 = PERM(t2,t3,P2_B);
  STORE(a[0], t1);
  STORE(a[4], t0);

  vpass_srl3(a, d16, d32, 4);//R(x^8-1) and 3 x C(x^4-1)

  
}



void v64(register real *a)
{

  v32(a);
  us16(a + 32);
  
  vpass_sr(a, d64, 8);
}

void v128(register real *a)
{
  v32(a);
  us16(a + 32);
  us16(a + 64);
  us16(a + 96);

  vpass_srl3(a, d64, d128, 16);  
}



void v256(register real *a)
{
  v64(a);
  us32(a + 64);
  us32(a + 128);
  us32(a + 192);

  vpass_srl3(a, d128, d256, 32);
}


void v512(register real *a)
{
  v128(a);
  us64(a + 128);
  us64(a + 256);
  us64(a + 384);

  vpass_srl3(a, d256, d512, 64);
}
