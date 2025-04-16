#include "pre8_V4.h"

#include "i.h"

/* 
   Radix 4 pass for x^8n-1 - 8n complex numbers 

   a: 8n complex = 16n values = split real and imag arrays

   w = w0, w
   w0: 1/2th roots of order 4n
   w:  1/4th roots of order 8n



*/
void cspass_rad4(real *a,  const real *w,  size_t n)
{

  real_packed x0, x1, x2, x3, y0, y1, y2, y3;
  real_packed c, s, t02, t13, s02, s13, Ar, Br, Ai, Bi, AipBr, AimBr, ArpBi, ArmBi, t0, t1, t2, t3;
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
    
    x0 = LOAD(a[0]);
    x1 = LOAD(a1[0]);
    x2 = LOAD(a2[0]);
    x3 = LOAD(a3[0]);
    
    y0 = LOAD(b0[0]);
    y1 = LOAD(b1[0]);
    y2 = LOAD(b2[0]);
    y3 = LOAD(b3[0]);

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
    STORE(a1[0], t1);
    
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

    STORE(a2[0], t0);
    STORE(a3[0], t2);
    
    c = LOAD(w[2*V]);//C
    s = LOAD(w[3*V]);//S
    
    TWISTED(Ar, Ai, Br, Bi, c, s, b0[0], b1[0], b2[0], b3[0]);
      
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



