#include "pre8_V4.h"

#include "i.h"

void u4_vert(real *a)
{

  real_packed x0, y0, x1, y1, x2, y2, x3, y3, t02, t13, s02, s13;
  real_packed Ar, Br, Ai, Bi,  AipBr, AimBr, ArpBi, ArmBi, t0, t1, t2, t3;


  U4_REG_MEM(a[0*V], a[1*V], a[2*V], a[3*V], a[4*V], a[5*V], a[6*V], a[7*V], x0, y0, x1, y1, x2, y2, x3, y3);

# if V==4
  real_packed s0, s1, s2, s3;
  TRANSPOSE4(x0,x1,x2,x3);
  TRANSPOSE4(y0,y1,y2,y3);
#endif

  STORE(a[0*V], x0);		
  STORE(a[1*V], y0);		
  STORE(a[2*V], x1);		
  STORE(a[3*V], y1);		
  STORE(a[4*V], x2);		
  STORE(a[5*V], y2);		
  STORE(a[6*V], x3);		
  STORE(a[7*V], y3);		
  
}
