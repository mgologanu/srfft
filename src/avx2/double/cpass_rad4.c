#include "pre8_V4.h"

#include "i.h"

/* 
   Radix 4 pass for x^8n-1 - 8n complex numbers 

   a: 8n complex = 16n values = interleaved V-packed format  - V real parts, V imag parts, etc.

   w = w0, w
   w0: 1/2th roots of order 4n
   w:  1/4th roots of order 8n



*/
void cpass_rad4(real *a,  const real *w,  size_t n)
{

  real_packed x0, x1, x2, x3, y0, y1, y2, y3;
  real_packed c, s, t02, t13, s02, s13, Ar, Br, Ai, Bi, AipBr, AimBr, ArpBi, ArmBi, t0, t1, t2, t3;
  real_packed Xm01, Ym01;
  
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
    
    x0 = LOAD(a[0]);
    x1 = LOAD(a1[0]);
    x2 = LOAD(a2[0]);
    x3 = LOAD(a3[0]);
    
    y0 = LOAD(a[V]);
    y1 = LOAD(a1[V]);
    y2 = LOAD(a2[V]);
    y3 = LOAD(a3[V]);

    t02 = ADD(x0, x2);
    Ar  = SUB(x0, x2);
    
    t13 = ADD(x1, x3);
    Br  = SUB(x1, x3);
    
    s02 = ADD(y0, y2);
    Ai  = SUB(y0, y2);
    
    s13 = ADD(y1, y3);
    Bi  = SUB(y1, y3);

    t0 = ADD(t02, t13); //X 0+2+1+3
    t1 = ADD(s02, s13); //Y 0+2+1+3

    STORE(a[0], t0);
    STORE(a[V], t1);
    
    Xm01 = SUB(t02, t13); //X 0+2-1-3
    Ym01=  SUB(s02, s13); //Y 0+2-1-3

    //(Xm01 + i * Ym01) * (C0 + i * S0)
    c = LOAD(w[0]);//C0
    s = LOAD(w[V]);//S0

    t0 = MUL(c, Xm01);
    t1 = MUL(s, Ym01);
    t2 = MUL(c, Ym01);
    t3 = MUL(s, Xm01);

    t0 = SUB(t0, t1);
    t2 = ADD(t2, t3);

    STORE(a1[0], t0);
    STORE(a1[V], t2);
    
    c = LOAD(w[2*V]);//C
    s = LOAD(w[3*V]);//S
    
    TWISTED(Ar, Ai, Br, Bi, c, s, a2[0], a2[V], a3[0], a3[V]);
      
    a  += V2;
    a1 += V2;
    a2 += V2;
    a3 += V2;

    w  += (V<<2); //4V - 2(cos, sin) = w0, w
    
  }  while (k -= 1);
}



