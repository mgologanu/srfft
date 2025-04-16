#include "pre8_V4.h"

#include "i.h"

/* 
   FFT4V - 4*V complex numbers

   V <= 4

   a: 4*V complex = 8*V values  interleaved V-packed format  - V real parts, V imag parts, etc.


   transpose and apply FFT4 using vertical vectorization

   Input:
    -C4-     -C4-    -C4-   -C4-
   x0 y0   x1 y1   x2 y2   x3 y3 
    0  V   2V 3V   4V 5V   6V 7V 

    - transpose(x0, x1, x2, x3)

    - transpose(y0, y1, y2, y3)

    - Apply C4 to x and y


    Output order: 0 2 3 1, see freq.c

    Note: the partially split format, given by the output of rad4 or
    rad8 (twice) is precisely the same - there is no need for a cs4_vert function.

*/
void c4_vert(real *a)
{

  real_packed x0, y0, x1, y1, x2, y2, x3, y3, t02, t13, s02, s13;
  real_packed Ar, Br, Ai, Bi,  AipBr, AimBr, ArpBi, ArmBi, t0, t1, t2, t3;


  x0 = LOAD(a[0*V]);
  y0 = LOAD(a[1*V]);

  x1 = LOAD(a[2*V]);
  y1 = LOAD(a[3*V]);

  x2 = LOAD(a[4*V]);
  y2 = LOAD(a[5*V]);

  x3 = LOAD(a[6*V]);
  y3 = LOAD(a[7*V]);

# if V==4
  real_packed s0, s1, s2, s3;
  TRANSPOSE4(x0,x1,x2,x3);
  TRANSPOSE4(y0,y1,y2,y3);
#endif

  C4_REG_MEM(x0, y0, x1, y1, x2, y2, x3, y3, a[0*V], a[1*V], a[2*V], a[3*V], a[4*V], a[5*V], a[6*V], a[7*V]);

}

