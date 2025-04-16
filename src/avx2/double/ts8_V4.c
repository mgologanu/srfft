#include "pre8_V4.h"

#include "i.h"



/* 
   Transpose 8 x V complex numbers to V x 8 appropriate as input for
   vertical C8

   Partially split arrays for real and imaginary, given by cpass_rad8
   applied twice

   ---C8 -----   ---C8 -----   ---C8 -----   ---C8 -----   
   x0 x1  y0 y1  x2 x3  y2 y3  x4 x5  y4 y5  x6 x7  y6 y7 
   0   1  2  3   4  5   6  7   8  9  10  11  12 13  14 15

   transpose(x0 x2 x4 x6)  -> t0 t1 t2 t3 

   transpose(x1 x3 x5 x7)  -> t4 t5 t6 t7

   save in place in increasing order of ti

   The same for y

*/


void ts8_V4(real *a)
{
  real_packed t0, t1, t2, t3, t4, t5, t6, t7;
  real_packed s0, s1, s2, s3;//needed by TRANSPOSE4 macro function

  t0 = LOAD(a[0]);  
  t1 = LOAD(a[4*V]);
  t2 = LOAD(a[8*V]);
  t3 = LOAD(a[12*V]);

  TRANSPOSE4(t0,t1,t2,t3);

  STORE(a[0], t0);

  t4 = LOAD(a[1*V]);
  t5 = LOAD(a[5*V]);
  t6 = LOAD(a[9*V]);
  t7 = LOAD(a[13*V]);
  
  TRANSPOSE4(t4,t5,t6,t7);

  STORE(a[1*V], t1);
  STORE(a[4*V], t2);
  STORE(a[5*V], t3);
  STORE(a[8*V], t4);
  STORE(a[9*V], t5);
  STORE(a[12*V], t6);
  STORE(a[13*V], t7);


  a += V2;

  t0 = LOAD(a[0]);  
  t1 = LOAD(a[4*V]);
  t2 = LOAD(a[8*V]);
  t3 = LOAD(a[12*V]);

  TRANSPOSE4(t0,t1,t2,t3);

  STORE(a[0], t0);

  t4 = LOAD(a[1*V]);
  t5 = LOAD(a[5*V]);
  t6 = LOAD(a[9*V]);
  t7 = LOAD(a[13*V]);
  
  TRANSPOSE4(t4,t5,t6,t7);

  STORE(a[1*V], t1);
  STORE(a[4*V], t2);
  STORE(a[5*V], t3);
  STORE(a[8*V], t4);
  STORE(a[9*V], t5);
  STORE(a[12*V], t6);
  STORE(a[13*V], t7);
}


