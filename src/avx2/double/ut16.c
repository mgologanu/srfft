#include "pre8_V4.h"

#include "i.h"



/* 
   Inverse transform for t16_V4

   Recall t16_V4:

   Transpose 16 x V complex numbers to V x 16 appropriate as input for vertical C16

   V-packed interleaved format

      --------- C16 ----------  --------- C16 ----------  ------------- C16 ----------  ------------- C16 -------------- 
      x0 y0 x1 y1 x2 y2 x3 y3   x4 y4 x5 y5 x6 y6 x7 y7   x8 y8 x9 y9 x10 y10 x11 y11   x12 y12 x13 y13 x14 y14 x15 y15  
   
   V * 0  1  2  3  4  5  6  7   8  9 10  11 12 13 14 15   16 17 18  19  20 21  22  23   24  25  26  27   28  29  30  31  

   x:
   V2* 0     1     2     3      4     5     6      7       8     9      10     11       12      13       14      15

   y: 
   V+V2*  0     1     2     3      4     5     6      7       8     9      10     11       12      13       14      15

   Note that each x and y is a packed array with V values


   Algorithm:

   transpose(x0 x4  x8 x12) -> save in x0   x1  x2  x3
   transpose(x1 x5  x9 x13) -> save in x4   x5  x6  x7
   transpose(x2 x6 x10 x14) -> save in x8   x9 x10 x11
   transpose(x3 x7 x11 x15) -> save in x12 x13 x14 x15

   Repeat for y


   INVERSE:

   transpose( x0  x1  x2  x3)  -> save in x0 x4  x8 x12
   transpose( x4  x5  x6  x7)  -> save in x1 x5  x9 x13
   transpose( x8  x9 x10 x11)  -> save in x2 x6 x10 x14
   transpose(x12 x13 x14 x15)  -> save in x3 x7 x11 x15
   
   Repeat for y

*/



void ut16_V4(real *a)
{
  real_packed t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
  real_packed s0, s1, s2, s3;

  t0 =  LOAD(a[0]);
  t1 =  LOAD(a[V2]);
  t2 =  LOAD(a[2*V2]);
  t3 =  LOAD(a[3*V2]);

  TRANSPOSE4(t0,t1,t2,t3);

  STORE(a[0],     t0);
  
  t4 =  LOAD(a[4*V2]);
  t5 =  LOAD(a[5*V2]);
  t6 =  LOAD(a[6*V2]);
  t7 =  LOAD(a[7*V2]);

  TRANSPOSE4(t4,t5,t6,t7);

  STORE(a[4*V2],  t1);
  
  t8 =  LOAD(a[8*V2]);
  t9 =  LOAD(a[9*V2]);
  t10 =  LOAD(a[10*V2]);
  t11 =  LOAD(a[11*V2]);

  TRANSPOSE4(t8,t9,t10,t11);

  STORE(a[8*V2],  t2);

  t12 =  LOAD(a[12*V2]);
  t13 =  LOAD(a[13*V2]);
  t14 =  LOAD(a[14*V2]);
  t15 =  LOAD(a[15*V2]);

  TRANSPOSE4(t12,t13,t14,t15);

  STORE(a[12*V2], t3);
  STORE(a[1*V2],  t4);
  STORE(a[5*V2],  t5);
  STORE(a[9*V2],  t6);
  STORE(a[13*V2], t7);
  STORE(a[2*V2],  t8);
  STORE(a[6*V2],  t9);
  STORE(a[10*V2], t10);
  STORE(a[14*V2], t11);
  STORE(a[3*V2],  t12);
  STORE(a[7*V2],  t13);
  STORE(a[11*V2], t14);
  STORE(a[15*V2], t15);

  //Same for y
  a += V;
  t0 =  LOAD(a[0]);
  t1 =  LOAD(a[V2]);
  t2 =  LOAD(a[2*V2]);
  t3 =  LOAD(a[3*V2]);

  TRANSPOSE4(t0,t1,t2,t3);

  STORE(a[0],     t0);
  
  t4 =  LOAD(a[4*V2]);
  t5 =  LOAD(a[5*V2]);
  t6 =  LOAD(a[6*V2]);
  t7 =  LOAD(a[7*V2]);

  TRANSPOSE4(t4,t5,t6,t7);

  STORE(a[4*V2],  t1);
  
  t8  = LOAD(a[8*V2]);
  t9  = LOAD(a[9*V2]);
  t10 = LOAD(a[10*V2]);
  t11 = LOAD(a[11*V2]);

  TRANSPOSE4(t8,t9,t10,t11);

  STORE(a[8*V2],  t2);

  t12 = LOAD(a[12*V2]);
  t13 = LOAD(a[13*V2]);
  t14 = LOAD(a[14*V2]);
  t15 = LOAD(a[15*V2]);

  TRANSPOSE4(t12,t13,t14,t15);

  STORE(a[12*V2], t3);
  STORE(a[1*V2],  t4);
  STORE(a[5*V2],  t5);
  STORE(a[9*V2],  t6);
  STORE(a[13*V2], t7);
  STORE(a[2*V2],  t8);
  STORE(a[6*V2],  t9);
  STORE(a[10*V2], t10);
  STORE(a[14*V2], t11);
  STORE(a[3*V2],  t12);
  STORE(a[7*V2],  t13);
  STORE(a[11*V2], t14);
  STORE(a[15*V2], t15);
}
