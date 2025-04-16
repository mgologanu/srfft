#include "pre8_V4.h"
#include "i.h"


/* TODO:
   c16 (via cpass_rad4) - DONE
   and also c8, c4, c2 without avx
*/

void  c16(register real *a)
{

  /*
    the first half of rad8_32: w0, w, w2, w3

    (with n = 32/8 = 4)

    w0 = 1/2 of roots of order 2n = 8  and  
    w  = 1/4 of roots of order 4n = 16


    are precisely the roots needed for rad4_16:

    (with n = 16/8 = 2)
  
    w0 =  1/2 of roots of order 4n = 8
    w  =  1/4 of roots of order 8n = 16
 
  */

  
  cpass_rad4(a, rad8_d32, 2); 
  
  c4_vert(a);   //Note that c4_vert also contains the transpose part

}


void  c32(register real *a)
{
  cpass_rad8(a, rad8_d32, 4);

  c4_vert(a);   //Note that c4_vert also contains the transpose part

  c4_vert(a+32);

}


void  c64(register real *a)
{
  cpass_rad8(a, rad8_d64, 8);

  //  t8_V4  (a);
  c8_vert(a); //Note that c8_vert also contains the transpose part

  //  t8_V4  (a+64);
  c8_vert(a+64);
}



void  c128(register real *a)
{
  cpass_rad8(a, rad8_d128, 16);

  t16_V4  (a);
  c16_vert(a);

  t16_V4  (a+128);
  c16_vert(a+128);
}



void c256(register real *a)
{
  cpass_srl3(a, d128, d256, 32);
  c64(a);
  c32(a + 128);
  c32(a + 192);
  c32(a + 256);
  c32(a + 320);
  c32(a + 384);
  c32(a + 448);
}


void c512(register real *a)
{
  cpass_srl3(a, d256, d512, 64);
  c128(a);
  c64(a + 256);
  c64(a + 384);
  c64(a + 512);
  c64(a + 640);
  c64(a + 768);
  c64(a + 896);
}
