#include "pre8_V4.h"

#include "i.h"


//#include <stdio.h>

//double out[4];

#define PR(x, str) {					\
  printf("%s: ", str);					\
  STORE(out[0], x);					\
  for (int i = 0; i<4; i++) printf("%g ", out[i]);	\
  printf("\n");						\
}



void vpass_srl3(real *a, const real *w, const real *w2, size_t n)
{


  
  real_packed x0, x1, x2, x3, x4, x5, x6, x7;
  real_packed c, s, c2, s2, c3, s3;
  real_packed Ar, Br, A0r, B0r;
  real_packed t0, t1, t2, t3, t4, t5, q2;
  real_packed Er, Fr;
  real_packed ar,br,cr,dr;

  
  size_t k;
    
  real *a1;
  real *a2;
  real *a3;
  real *a4;
  real *a5;
  real *a6;
  real *a7;
  
   
  a1 = a  + n;
  a2 = a1 + n;
  a3 = a2 + n;
  a4 = a3 + n;
  a5 = a4 + n;
  a6 = a5 + n;
  a7 = a6 + n;
  
  k = n >> VPOW;  //n/V

  do {

    c2 = LOAD(w2[0]);
    s2 = LOAD(w2[V]);

    REAL_UNTWISTED(Ar,Br,c2,s2,a4[0],a5[0]);


    c = LOAD(w[0]);
    s = LOAD(w[V]);
    
    t0 = MUL(c, c2);
    t1 = MUL(s, s2);
    t2 = MUL(c, s2);
    t3 = MUL(s, c2);

    c3 = SUB(t0, t1);
    s3 = ADD(t2, t3);

    REAL_UNTWISTED(Er,Fr,c3,s3,a6[0],a7[0]);

 
    

    ar = ADD(Ar, Er); //A + E = a             X 0-4
    t1 = SUB(Ar, Er); //A - E = c_bar

    t2 = ADD(Br, Fr); //B + F = d_bar
    br = SUB(Br, Fr); //B - F = b             X 2-6

    t4 = ADD(t1, t2); //c_bar + d_bar = c     X 1-5
    t5 = SUB(t2, t1); //d_bar - c_bar = d     X 3-7

   
    q2 = BROADCAST(sq2[0]);

    cr = MUL(q2, t4); //X 1-5
    dr = MUL(q2, t5); //X 3-7

    REAL_UNTWISTED(A0r,B0r,c,s,a2[0],a3[0]);
    
    t0 = LOAD(a[0]); // X 0+4+2+6
    t1 = LOAD(a1[0]); // X 1+5+3+7

    t2 = ADD(t0, A0r); //X 0+4
    t3 = SUB(t0, A0r); //X 2+6

    x0 = ADD(t2, ar);
    x4 = SUB(t2, ar);
    STORE(a[0],  x0);
    STORE(a4[0], x4);
 

    x2 = ADD(t3, br);
    x6 = SUB(t3, br);
    STORE(a2[0], x2);    
    STORE(a6[0], x6);


    t2 = ADD(t1, B0r); //X 1+5
    t3 = SUB(t1, B0r); //X 3+7
    
    x1 = ADD(t2, cr);
    x5 = SUB(t2, cr);
    STORE(a1[0], x1);    
    STORE(a5[0], x5);
   
    x3 = ADD(t3, dr);
    x7 = SUB(t3, dr);
    STORE(a3[0], x3);
    STORE(a7[0], x7);

    a  += V;
    a1 += V;
    a2 += V;
    a3 += V;
    a4 += V;
    a5 += V;
    a6 += V;
    a7 += V;

    w  += V2;
    w2 += V2;
    
  }  while (k -= 1);
}
