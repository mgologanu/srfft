#include "pre8_V4.h"

#include "i.h"




void upass_srl3(real *a, const real *w, const real *w2, size_t n)
{

  size_t k, n2;
    
  real *a1;
  real *a2;
  real *a3;
  real *a4;
  real *a5;
  real *a6;
  real *a7;

  
  real_packed x0, x1, x2, x3, x4, x5, x6, x7;
  real_packed y0, y1, y2, y3, y4, y5, y6, y7;

  real_packed A0r, B0r, A0i, B0i;
  real_packed Ar, Br, Ai, Bi;
  real_packed Er, Ei, Fr, Fi;

  real_packed ar,br,cr,dr,ai,bi,ci,di;
  real_packed z0r, z0i, z1r, z1i, t0r, t0i, t1r, mt1i;

  real_packed t0, t1, t2, t3, t4, t5;
  real_packed s0, s1, s2, s3, s4, s5;
  real_packed c, s, cc2, ss2, cc3, ss3;
  real_packed q2;
  
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

    cc2 = LOAD(w2[0]);
    ss2 = LOAD(w2[V]);

    UNTWISTED(Ar, Ai, Br, Bi, cc2, ss2, a4[0], a4[V], a7[0], a7[V]);

    c = LOAD(w[0]);
    s = LOAD(w[V]);
    
    t0 = MUL(c, cc2);
    t1 = MUL(s, ss2);
    t2 = MUL(c, ss2);
    t3 = MUL(s, cc2);

    cc3 = SUB(t0, t1);
    ss3 = ADD(t2, t3);

    UNTWISTED(Er, Ei, Fr, Fi, cc3, ss3, a6[0], a6[V], a5[0], a5[V]);
    
    ar = ADD(Ar, Er); //A + E = a             X 0-4
    t1 = SUB(Ar, Er); //A - E = c_bar

    t2 = ADD(Br, Fr); //B + F = d_bar
    br = SUB(Br, Fr); //B - F = b             X 2-6

    t4 = ADD(t1, t2); //c_bar + d_bar = c     X 1-5
    t5 = SUB(t2, t1); //d_bar - c_bar = d     X 3-7

    ai = ADD(Ai, Ei); //A + E = a             Y 0-4
    s1 = SUB(Ai, Ei); //A - E = c_bar

    s2 = ADD(Bi, Fi); //B + F = d_bar
    bi = SUB(Bi, Fi); //B - F = b             Y 2-6

    s4 = ADD(s1, s2); //c_bar + d_bar = c     Y 1-5
    s5 = SUB(s2, s1); //d_bar - c_bar = d     Y 3-7
    

    q2 = BROADCAST(sq2[0]);

    cr = MUL(q2, t4); //X 1-5
    dr = MUL(q2, t5); //X 3-7
    ci = MUL(q2, s4); //Y 1-5
    di = MUL(q2, s5); //Y 3-7

    
    UNTWISTED(A0r, A0i, B0r, B0i, c, s, a2[0], a2[V], a3[0], a3[V]); //0+4-2(2+6) real and imag and 1+5-(3+7) real and imag
      

    t0 = LOAD(a[0]); // X 0+4+2+6
    s0 = LOAD(a[V]); // Y 0+4+2+6
    
    t1 = LOAD(a1[0]); // X 1+5+3+7
    s1 = LOAD(a1[V]); // Y 1+5+3+7


    
    t2 = ADD(t0, A0r); //X 0+4
    t3 = SUB(t0, A0r); //X 2+6

    s2 = ADD(s0, A0i); //Y 0+4
    s3 = SUB(s0, A0i); //Y 2+6

    x0 = ADD(t2, ar);
    x4 = SUB(t2, ar);

    y0 = ADD(s2, ai);
    y4 = SUB(s2, ai);

    STORE(a[0], x0);
    STORE(a[V], y0);
    
    STORE(a4[0], x4);
    STORE(a4[V], y4);

    x2 = ADD(t3, br);
    x6 = SUB(t3, br);

    y2 = ADD(s3, bi);
    y6 = SUB(s3, bi);

    STORE(a2[0], x2);
    STORE(a2[V], y2);
    
    STORE(a6[0], x6);
    STORE(a6[V], y6);

    
    t2 = ADD(t1, B0r); //X 1+5
    t3 = SUB(t1, B0r); //X 3+7

    s2 = ADD(s1, B0i); //Y 1+5
    s3 = SUB(s1, B0i); //Y 3+7
       
    x1 = ADD(t2, cr);
    x5 = SUB(t2, cr);

    y1 = ADD(s2, ci);
    y5 = SUB(s2, ci);

    STORE(a1[0], x1);
    STORE(a1[V], y1);
    
    STORE(a5[0], x5);
    STORE(a5[V], y5);

   
    x3 = ADD(t3, dr);
    x7 = SUB(t3, dr);

    y3 = ADD(s3, di);
    y7 = SUB(s3, di);

    STORE(a3[0], x3);
    STORE(a3[V], y3);
    
    STORE(a7[0], x7);
    STORE(a7[V], y7);


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
