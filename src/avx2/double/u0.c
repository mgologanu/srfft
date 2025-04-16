#include "pre8_V4.h"
#include "i.h"

void  u32(register real *a)
{
  u4_vert(a);   //Note that c4_vert also contains the transpose part

  u4_vert(a+32);

  upass_rad8(a, rad8_d32, 4);

}


void  u64(register real *a)
{
  u8_vert(a); //Note that c8_vert also contains the transpose part
  //  t8_V4  (a);

  u8_vert(a+64);
  //  t8_V4  (a+64);
  
  upass_rad8(a, rad8_d64, 8);
}

void  u128(register real *a)
{
  u16_vert(a);
  ut16_V4  (a);

  u16_vert(a+128);
  ut16_V4  (a+128);

  upass_rad8(a, rad8_d128, 16);
}

void u256(register real *a)
{
  u64(a);
  u32(a + 128);
  u32(a + 192);
  u32(a + 256);
  u32(a + 320);
  u32(a + 384);
  u32(a + 448);
  upass_srl3(a, d128, d256, 32);
}

void u512(register real *a)
{
  u128(a);
  u64(a + 256);
  u64(a + 384);
  u64(a + 512);
  u64(a + 640);
  u64(a + 768);
  u64(a + 896);
  upass_srl3(a, d256, d512, 64);
}
