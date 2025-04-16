#include "pre8_V4.h"

#include "i.h"

void vpass_sr(real *a, const real *w, size_t n)
{

  real_packed x0, x1, x2, x3;
  real_packed c, s, t02, t13, Ar, Br, t0, t1, t2, t3;

  size_t k, n2;
  
  
  real *a1;
  real *a2;
  real *a3;

  n2 = n << 1; //2n
  
  a1 = a  + n2;
  a2 = a1 + n2;
  a3 = a2 + n2;

  k = n >> (VPOW-1);  //2n/V
  
  do {
    
    c = LOAD(w[0]);
    s = LOAD(w[V]);

    REAL_UNTWISTED(Ar, Br, c, s, a2[0], a3[0]);

    t02 = LOAD(a[0]); 
    t13 = LOAD(a1[0]);

    x0 = ADD(t02, Ar);
    x2 = SUB(t02, Ar);
    STORE(a[0],  x0);
    STORE(a2[0], x2);

    x1 = ADD(t13, Br);
    x3 = SUB(t13, Br);
    STORE(a1[0], x1);
    STORE(a3[0], x3);

    a  += V;
    a1 += V;
    a2 += V;
    a3 += V;

    w  += V2;
    
  }  while (k -= 1);

    
}
