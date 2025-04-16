#include "pre8_V4.h"

#include "i.h"

/* 
   Radix 8  pass for x^8n-1 - 8n complex numbers 

   a: 8n complex = 16n values in split real and imag arrays, but contiguous

   w: 4n complex numbers or 8n values: 1/2th roots of 2n, 1/4th roots
   of order 4n, 1/8th roots of order 8n, 1/8th roots of order 8n at power 3
      
   w = w0, w, w2, w3
*/
void cspass_rad8(real *a,  const real *w, size_t n)
{

  real_packed x0, x1, x2, x3, x4, x5, x6, x7;
  real_packed y0, y1, y2, y3, y4, y5, y6, y7;
  real_packed xp04, xp26, xp15, xp37, yp04, yp26, yp15, yp37; 
  real_packed c, s, Ar, Br, Ai, Bi, AipBr, AimBr, ArpBi, ArmBi, t0, t1, t2, t3, q2;
  real_packed Er, Ei, Fr, Fi;
  real_packed ar,br,cr,dr,ai,bi,ci,di;
  real_packed X0,X1,Y0,Y1, Xm01, Ym01;

  size_t k;
  
  real *a1 = a  + n;
  real *a2 = a1 + n;
  real *a3 = a2 + n;
  real *a4 = a3 + n;
  real *a5 = a4 + n;
  real *a6 = a5 + n;
  real *a7 = a6 + n;
  
  real *b  = a  + (n<<3);
  
  real *b1 = b  + n;
  real *b2 = b1 + n;
  real *b3 = b2 + n;
  real *b4 = b3 + n;
  real *b5 = b4 + n;
  real *b6 = b5 + n;
  real *b7 = b6 + n;
  
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
      
    y0 = LOAD(b[0]);
    y1 = LOAD(b1[0]);
    y2 = LOAD(b2[0]);
    y3 = LOAD(b3[0]);
    y4 = LOAD(b4[0]);
    y5 = LOAD(b5[0]);
    y6 = LOAD(b6[0]);
    y7 = LOAD(b7[0]);
    
    xp04 = ADD(x0, x4);
    ar   = SUB(x0, x4);
    
    xp26 = ADD(x2, x6);
    br   = SUB(x2, x6);

    xp15 = ADD(x1, x5);
    cr   = SUB(x1, x5);
    
    xp37 = ADD(x3, x7);
    dr   = SUB(x3, x7);

    X0 = ADD(xp04, xp26);
    Ar = SUB(xp04, xp26);
 

    X1 = ADD(xp15, xp37);
    Br = SUB(xp15, xp37);

    t0 = ADD(X0, X1); //X 0+4+2+6+1+5+3+7 
    STORE(a[0], t0);  //X0

    Xm01 = SUB(X0, X1);  //X 0+4+2+6-(1+5+3+7 )

    yp04 = ADD(y0, y4);
    ai   = SUB(y0, y4);
    
    yp26 = ADD(y2, y6);
    bi   = SUB(y2, y6);

    yp15 = ADD(y1, y5);
    ci   = SUB(y1, y5);
    
    yp37 = ADD(y3, y7);
    di   = SUB(y3, y7);

    Y0 = ADD(yp04, yp26);
    Ai = SUB(yp04, yp26);


    Y1 = ADD(yp15, yp37); //Y 0+4+2+6+1+5+3+7 
    Bi = SUB(yp15, yp37);

    t0 = ADD(Y0, Y1);
    STORE(a1[0], t0);  //Y0

    Ym01 = SUB(Y0, Y1); //Y 0+4+2+6-(1+5+3+7 )

    //(Xm01 + i * Ym01) * (C0 + i * S0)
    c = LOAD(w[0]);//C0
    s = LOAD(w[V]);//S0
    
    t0 = MUL(c, Xm01);
    t1 = MUL(s, Ym01);
    t2 = MUL(c, Ym01);
    t3 = MUL(s, Xm01);

    t0 = SUB(t0, t1);
    t2 = ADD(t2, t3);

    STORE(a2[0], t0);//X1
    STORE(a3[0], t2);//Y1
    
    c = LOAD(w[2*V]);//C
    s = LOAD(w[3*V]);//S

    TWISTED(Ar,Ai,Br,Bi,c,s,a4[0],a5[0],a6[0],a7[0]);
    
    q2 = BROADCAST(sq2[0]);

    cr = MUL(q2, cr);
    dr = MUL(q2, dr);
    ci = MUL(q2, ci);
    di = MUL(q2, di);

    t0 = ADD(cr, dr);
    t1 = SUB(cr, dr);

    Ar = ADD(ar, t1);
    Er = SUB(ar, t1);
    
    Br = ADD(br, t0);
    Fr = SUB(t0, br);
    
    t0 = ADD(ci, di);
    t1 = SUB(ci, di);

    Ai = ADD(ai, t1);
    Ei = SUB(ai, t1);

    
    Bi = ADD(bi, t0);
    Fi = SUB(t0, bi);

    c = LOAD(w[4*V]);//C2
    s = LOAD(w[5*V]);//S2

    TWISTED(Ar,Ai,Br,Bi,c,s,b[0],b1[0],b6[0],b7[0]);

    c = LOAD(w[6*V]);//C3
    s = LOAD(w[7*V]);//S3

    TWISTED(Er,Ei,Fr,Fi,c,s,b4[0],b5[0],b2[0],b3[0]);
    
    a  += V;
    a1 += V;
    a2 += V;
    a3 += V;
    a4 += V;
    a5 += V;
    a6 += V;
    a7 += V;

    b  += V;
    b1 += V;
    b2 += V;
    b3 += V;
    b4 += V;
    b5 += V;
    b6 += V;
    b7 += V;

    w  += (V<<3);  //8V - 4 (cos, sin) = w0, w, w2, w3
    
  }  while (k -= 1);
}

