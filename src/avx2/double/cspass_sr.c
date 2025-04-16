#include "pre8_V4.h"

#include "i.h"


/* 
   Split radix pass for x^8n-1 - 8n complex numbers 

   a: 8n complex = 16n values = split arrays for real and imag

   w: 2n complex numbers or 4n values = [0...4n-1] in interleaved V-packed format

   Uses 1/4 of roots (no mirroring on 45 deg). 

*/
void cspass_sr(real *a,  const real *w,  size_t n)
{

  real_packed x0, x1, x2, x3, y0, y1, y2, y3;
  real_packed c, s, t02, t13, s02, s13, Ar, Br, Ai, Bi, AipBr, AimBr, ArpBi, ArmBi, t0, t1, t2;

  size_t k, n2;
  
  
  real *a1;
  real *a2;
  real *a3;

  real *b;
  real *b1;
  real *b2;
  real *b3;

  n2 = n << 1; //2n
  
  a1 = a  + n2;
  a2 = a1 + n2;
  a3 = a2 + n2;

  b = a + (n<<3);
  b1 = b  + n2;
  b2 = b1 + n2;
  b3 = b2 + n2;
  

  k = n >> (VPOW-1);  //2n/V

  do {
    
    x0 = LOAD(a[0]);
    x1 = LOAD(a1[0]);
    x2 = LOAD(a2[0]);
    x3 = LOAD(a3[0]);
    
    y0 = LOAD(b[0]);
    y1 = LOAD(b1[0]);
    y2 = LOAD(b2[0]);
    y3 = LOAD(b3[0]);

    c = LOAD(w[0]);
    s = LOAD(w[V]);
    
    t02 = ADD(x0, x2); //X0
    Ar  = SUB(x0, x2);
    
    t13 = ADD(x1, x3); //X1
    Br  = SUB(x1, x3);
    
    s02 = ADD(y0, y2); //Y0
    Ai  = SUB(y0, y2);
    
    s13 = ADD(y1, y3); //Y1
    Bi  = SUB(y1, y3);
    
    STORE(a[0], t02);  //X0
    STORE(a1[0], t13);  //X1

    STORE(a2[0], s02); //Y0
    STORE(a3[0], s13); //Y1

    

    TWISTED(Ar, Ai, Br, Bi, c, s, b[0], b1[0], b2[0], b3[0]);
  
    
    a  += V;
    a1 += V;
    a2 += V;
    a3 += V;

    b  += V;
    b1 += V;
    b2 += V;
    b3 += V;

    w  += V2;
    
  }  while (k -= 1);
}

