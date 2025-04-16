#include "pre8_V4.h"

#include "i.h"


/* 
   Extended split radix (or level 3) pass for x^8n-1 - 8n complex numbers 

   a: 8n complex = 16n values = interleaved V-packed format  - V real parts, V imag parts, etc.

   w: n complex numbers or 2n values = [0...2n-1] in interleaved V-packed format - 1/4th of roots of order 4n

   w2: n complex numbers or 2n values = [0...2n-1] in interleaved V-packed format - 1/8th of roots of order 8n

   No mirroring for w!

*/
void cpass_srl3(real *a, const real *w, const real *w2, size_t n)
{

  real_packed x0, x1, x2, x3, x4, x5, x6, x7;
  real_packed y0, y1, y2, y3, y4, y5, y6, y7;
  real_packed xp04, xp26, xp15, xp37, yp04, yp26, yp15, yp37; 
  real_packed c, s, c2, s2, c3, s3;
  real_packed Ar, Br, Ai, Bi, AipBr, AimBr, ArpBi, ArmBi;
  real_packed t0, t1, t2, t3, q2;
  real_packed Er, Ei, Fr, Fi;
  real_packed ar,br,cr,dr,ai,bi,ci,di;

  size_t k, n2;
    
  real *a1;
  real *a2;
  real *a3;
  real *a4;
  real *a5;
  real *a6;
  real *a7;
  
  n2 = n << 1; //2n
    
  a1 = a  + n2;
  a2 = a1 + n2;
  a3 = a2 + n2;
  a4 = a3 + n2;
  a5 = a4 + n2;
  a6 = a5 + n2;
  a7 = a6 + n2;
  
  k = n >> VPOW;  //n/V

  do {
    
    x0 = LOAD(a[0]);
    x1 = LOAD(a1[0]);
    x2 = LOAD(a2[0]);
    x3 = LOAD(a3[0]);
    x4 = LOAD(a4[0]);
    x5 = LOAD(a5[0]);
    x6 = LOAD(a6[0]);
    x7 = LOAD(a7[0]);
    
    y0 = LOAD(a[V]);
    y1 = LOAD(a1[V]);
    y2 = LOAD(a2[V]);
    y3 = LOAD(a3[V]);
    y4 = LOAD(a4[V]);
    y5 = LOAD(a5[V]);
    y6 = LOAD(a6[V]);
    y7 = LOAD(a7[V]);
    
    xp04 = ADD(x0, x4);
    ar   = SUB(x0, x4);
    
    xp26 = ADD(x2, x6);
    br   = SUB(x2, x6);

    xp15 = ADD(x1, x5);
    cr   = SUB(x1, x5);
    
    xp37 = ADD(x3, x7);
    dr   = SUB(x3, x7);

    t0 = ADD(xp04, xp26); //X 0+4+2+6 = X0
    Ar = SUB(xp04, xp26); //X 0+4-2-6
    STORE(a[0], t0);

    t0 = ADD(xp15, xp37); //X 1+5+3+7 = X1
    Br = SUB(xp15, xp37); //X 1+5-3-7
    STORE(a1[0], t0);
    
    yp04 = ADD(y0, y4);
    ai   = SUB(y0, y4);
    
    yp26 = ADD(y2, y6);
    bi   = SUB(y2, y6);

    yp15 = ADD(y1, y5);
    ci   = SUB(y1, y5);
    
    yp37 = ADD(y3, y7);
    di   = SUB(y3, y7);

    t0 = ADD(yp04, yp26); //Y 0+4+2+6 = Y0
    Ai = SUB(yp04, yp26); //Y 0+4-2-6
    STORE(a[V], t0);

    t0 = ADD(yp15, yp37); //Y 1+5+3+7 = Y1
    Bi = SUB(yp15, yp37); //Y 1+5-3-7
    STORE(a1[V], t0);

    c = LOAD(w[0]);
    s = LOAD(w[V]);

    TWISTED(Ar,Ai,Br,Bi,c,s,a2[0],a2[V],a3[0],a3[V]);
 
    q2 = BROADCAST(sq2[0]);

    cr = MUL(q2, cr);
    dr = MUL(q2, dr);
    ci = MUL(q2, ci);
    di = MUL(q2, di);

    t0 = ADD(cr, dr); //cr + dr
    t1 = SUB(cr, dr); //cr - dr

    Ar = ADD(ar, t1); //ar +  cr - dr
    Er = SUB(ar, t1); //ar - (cr - dr)
    
    Br = ADD(br, t0); // br + cr + dr
    Fr = SUB(t0, br); //-br + cr + dr
    
    t0 = ADD(ci, di); //ci + di
    t1 = SUB(ci, di); //ci - di

    Ai = ADD(ai, t1); //ai +  ci - di
    Ei = SUB(ai, t1); //ai - (ci - di)

    Bi = ADD(bi, t0); // bi + ci + di
    Fi = SUB(t0, bi); //-bi + ci + di

    c2 = LOAD(w2[0]);
    s2 = LOAD(w2[V]);

    TWISTED(Ar,Ai,Br,Bi,c2,s2, a4[0], a4[V], a7[0], a7[V]);

    //c3 + i s3 = (c + i s) (c2 + i s2)
    t0 = MUL(c, c2);
    t1 = MUL(s, s2);
    t2 = MUL(c, s2);
    t3 = MUL(s, c2);

    c3 = SUB(t0, t1);
    s3 = ADD(t2, t3);

    TWISTED(Er,Ei,Fr,Fi,c3,s3, a6[0], a6[V], a5[0], a5[V]);

    a  += V2;
    a1 += V2;
    a2 += V2;
    a3 += V2;
    a4 += V2;
    a5 += V2;
    a6 += V2;
    a7 += V2;

    w  += V2;
    w2 += V2;
    
  }  while (k -= 1);
}


