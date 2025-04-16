#include "pre8_V4.h"

#include "i.h"


void upass_sr(real *a,  const real *w,  size_t n)
{

  real_packed x0, x1, x2, x3, y0, y1, y2, y3;
  real_packed c, s, t02, t13, s02, s13, Ar, Br, Ai, Bi, z0r, z0i, z1r, z1i,  t0r, t1r, t0i, mt1i, t0, t1;

  size_t k, n4;
  
  
  real *a1;
  real *a2;
  real *a3;

  n4 = n << 2; //4n
  
  a1 = a  + n4;
  a2 = a1 + n4;
  a3 = a2 + n4;

  k = n >> (VPOW-1);  //2n/V

  do {
    
    c = LOAD(w[0]);
    s = LOAD(w[V]);
    
    UNTWISTED(Ar, Ai, Br, Bi, c, s, a2[0], a2[V], a3[0], a3[V]);

    t02 = LOAD(a[0]);
    s02 = LOAD(a[V]);
 
    x0 = ADD(t02, Ar);
    x2 = SUB(t02, Ar);

    y0 = ADD(s02, Ai);
    y2 = SUB(s02, Ai);

    STORE(a[0], x0);
    STORE(a[V], y0);

    t13 = LOAD(a1[0]);
    s13 = LOAD(a1[V]);
    
    x1 = ADD(t13, Br);
    x3 = SUB(t13, Br);
    
    y1 = ADD(s13, Bi);
    y3 = SUB(s13, Bi);

    STORE(a1[0], x1);
    STORE(a1[V], y1);

    STORE(a2[0], x2);
    STORE(a2[V], y2);

    STORE(a3[0], x3);
    STORE(a3[V], y3);
    
    a  += V2;
    a1 += V2;
    a2 += V2;
    a3 += V2;

    w  += V2;
    
  }  while (k -= 1);
}

