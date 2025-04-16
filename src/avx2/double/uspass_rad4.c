#include "pre8_V4.h"

#include "i.h"

/* 
   Radix 4 pass for x^8n-1 - 8n complex numbers 

   a: 8n complex = 16n values = split real and imag arrays

   w = w0, w
   w0: 1/2th roots of order 4n
   w:  1/4th roots of order 8n



*/
void uspass_rad4(real *a,  const real *w,  size_t n)
{

  real_packed x0, x1, x2, x3, y0, y1, y2, y3;
  real_packed c, s, t02, t13, s02, s13, Ar, Br, Ai, Bi, t0, t1, t2, t3;
  real_packed z0r, z0i, z1r, z1i, t0r, t0i, t1r, mt1i;
  real_packed Xm01, Ym01;
  
  size_t k, n2;
  
  
  real *a1;
  real *a2;
  real *a3;

  real *b0;
  real *b1;
  real *b2;
  real *b3;
  

  n2 = n << 1; //2n
  
  a1 = a  + n2;
  a2 = a1 + n2;
  a3 = a2 + n2;

  b0 = a3 + n2;
  b1 = b0 + n2;
  b2 = b1 + n2;
  b3 = b2 + n2;
  
  

  k = n >> (VPOW-1);  //2n/V
  
  do {
    c = LOAD(w[2*V]);//C
    s = LOAD(w[3*V]);//S
    
    UNTWISTED(Ar, Ai, Br, Bi, c, s, b0[0], b1[0], b2[0], b3[0]);

    c = LOAD(w[0]);//C0
    s = LOAD(w[V]);//S0

    t0 = LOAD(a2[0]);
    t1 = LOAD(a3[0]);

    t2 = MUL(c, t0);
    t3 = MUL(s, t1);
    t1 = MUL(c, t1);
    t0 = MUL(s, t0);

    Xm01 = ADD(t2,t3);
    Ym01 = SUB(t1,t0);

    t0 = LOAD(a[0]);
    t1 = LOAD(a1[0]);

    t02 = ADD(t0, Xm01);
    t13 = SUB(t0, Xm01);

    s02 = ADD(t1, Ym01);
    s13 = SUB(t1, Ym01);

    x0 = ADD(t02, Ar);
    x2 = SUB(t02, Ar);

    y0 = ADD(s02, Ai);
    y2 = SUB(s02, Ai);

    x1 = ADD(t13, Br);
    x3 = SUB(t13, Br);

    y1 = ADD(s13, Bi);
    y3 = SUB(s13, Bi);
    
    STORE(a[0], x0);
    STORE(a1[0], x1);
    STORE(a2[0], x2);
    STORE(a3[0], x3);

    STORE(b0[0], y0);
    STORE(b1[0], y1);
    STORE(b2[0], y2);
    STORE(b3[0], y3); 

    
    
    a  += V;
    a1 += V;
    a2 += V;
    a3 += V;

    b0 += V;
    b1 += V;
    b2 += V;
    b3 += V;

    w  += (V<<2); //4V - 2(cos, sin) = w0, w
    
  }  while (k -= 1);
}
     
