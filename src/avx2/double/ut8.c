#include "pre8_V4.h"

#include "i.h"



/* 
   Transpose 8*V complex numbers as input for vertical C16

        ---C8 -----  ---C8 -----  ---C8 ----- ---C8 ----- 
	x0 y0 x1 y1  x2 y2 x3 y3  x4 y4 x5 y5  x6 y6 x7 y7 
    (V*) 0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15
     
     transpose(x0 x2 x4 x6) -> t0 t1 t2 t3 
     
     transpose(x1 x3 x5 x7) -> t4 t5 t6 t7
     
     save in place in increasing order of ti

     Same for y

*/


void ut8_V4(real *a)
{
  real_packed t0, t1, t2, t3, t4, t5, t6, t7;
  real_packed s0, s1, s2, s3;


  t0 = LOAD(a[0]);
  t1 = LOAD(a[2*V]);
  t2 = LOAD(a[4*V]);
  t3 = LOAD(a[6*V]);

  TRANSPOSE4(t0,t1,t2,t3);

  STORE(a[0], t0);
  
  t4 = LOAD(a[8*V]);
  t5 = LOAD(a[10*V]);
  t6 = LOAD(a[12*V]);
  t7 = LOAD(a[14*V]);
    
  TRANSPOSE4(t4,t5,t6,t7);


  STORE(a[4*V], t1);
  STORE(a[8*V], t2);
  STORE(a[12*V], t3);
  STORE(a[2*V], t4);
  STORE(a[6*V], t5);
  STORE(a[10*V], t6);
  STORE(a[14*V], t7);


  a += V;

  t0 = LOAD(a[0]);
  t1 = LOAD(a[2*V]);
  t2 = LOAD(a[4*V]);
  t3 = LOAD(a[6*V]);

  TRANSPOSE4(t0,t1,t2,t3);

  STORE(a[0], t0);
  
  t4 = LOAD(a[8*V]);
  t5 = LOAD(a[10*V]);
  t6 = LOAD(a[12*V]);
  t7 = LOAD(a[14*V]);
    
  TRANSPOSE4(t4,t5,t6,t7);


  STORE(a[4*V], t1);
  STORE(a[8*V], t2);
  STORE(a[12*V], t3);
  STORE(a[2*V], t4);
  STORE(a[6*V], t5);
  STORE(a[10*V], t6);
  STORE(a[14*V], t7);

  
}


