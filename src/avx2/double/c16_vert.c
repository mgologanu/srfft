#include "pre8_V4.h"

#include "i.h"


/* 
   FFT16V - 16*V complex numbers

   
   V <= 16

   a: 16*V complex = 32*V values  interleaved V-packed format  - V real parts, V imag parts, etc.

*/

void c16_vert(real *a)
{

  //n = N/8 = 2

  real_packed x0, x1, x2, x3, x4, x5, x6, x7;
  real_packed y0, y1, y2, y3, y4, y5, y6, y7;
  real_packed xp04, xp26, xp15, xp37, yp04, yp26, yp15, yp37;
  real_packed t02, s02, t13, s13;
  real_packed c, s, Ar, Br, Ai, Bi, AipBr, AimBr, ArpBi, ArmBi, q2;
  real_packed Er, Ei, Fr, Fi;
  real_packed ar,br,cr,dr,ai,bi,ci,di;
  real_packed t0, t1, t2, t3;
  real_packed X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15;
  real_packed Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8, Y9, Y10, Y11, Y12, Y13, Y14, Y15;

  /* z0 z1  z2  z3  z4  z5  z6  z7  z8  z9  z10  z11  z12  z13  z14  z15 */ 
  /*  0 2V  4V  6V  8V 10V 12V 14V 16V 18V  20V  22V  24V  26V  28V  30V */
  /*  0 V2 2V2 3V2 4V2 5V2 6V2 7V2 8V2 9V2 10V2 11V2 12V2 13V2 14V2 15V2 */

  //First srl3 pass, all c,s = 1,0
  
  x0 = LOAD(a[0]);
  x1 = LOAD(a[2*V2]);
  x2 = LOAD(a[4*V2]);
  x3 = LOAD(a[6*V2]);
  x4 = LOAD(a[8*V2]);
  x5 = LOAD(a[10*V2]);
  x6 = LOAD(a[12*V2]);
  x7 = LOAD(a[14*V2]);
  
  y0 = LOAD(a[V]);
  y1 = LOAD(a[2*V2+V]);
  y2 = LOAD(a[4*V2+V]);
  y3 = LOAD(a[6*V2+V]);
  y4 = LOAD(a[8*V2+V]);
  y5 = LOAD(a[10*V2+V]);
  y6 = LOAD(a[12*V2+V]);
  y7 = LOAD(a[14*V2+V]);
  
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
   
  X2 = ADD(xp15, xp37);
  Br = SUB(xp15, xp37);
   
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
   
  Y2 = ADD(yp15, yp37);
  Bi = SUB(yp15, yp37);
   
  // c = 1, s = 0
  
  X4 = SUB(Ar, Bi);
  Y4 = ADD(Ai, Br);
  X6 = ADD(Ar, Bi);
  Y6 = SUB(Ai, Br);
  
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

  
  // c = 1, s=0

  X8  = SUB(Ar, Bi);
  Y8  = ADD(Ai, Br);
  X14 = ADD(Ar, Bi);
  Y14 = SUB(Ai, Br);
    
  //c = 1, s = 0
 
  X12 = SUB(Er, Fi);
  Y12 = ADD(Ei, Fr);
  X10 = ADD(Er, Fi);
  Y10 = SUB(Ei, Fr);

  //second srl3 pass

  x0 = LOAD(a[V2]);
  x1 = LOAD(a[3*V2]);
  x2 = LOAD(a[5*V2]);
  x3 = LOAD(a[7*V2]);
  x4 = LOAD(a[9*V2]);
  x5 = LOAD(a[11*V2]);
  x6 = LOAD(a[13*V2]);
  x7 = LOAD(a[15*V2]);
    
  y0 = LOAD(a[V2+V]);
  y1 = LOAD(a[3*V2+V]);
  y2 = LOAD(a[5*V2+V]);
  y3 = LOAD(a[7*V2+V]);
  y4 = LOAD(a[9*V2+V]);
  y5 = LOAD(a[11*V2+V]);
  y6 = LOAD(a[13*V2+V]);
  y7 = LOAD(a[15*V2+V]);

  xp04 = ADD(x0, x4);
  ar   = SUB(x0, x4);
    
  xp26 = ADD(x2, x6);
  br   = SUB(x2, x6);

  xp15 = ADD(x1, x5);
  cr   = SUB(x1, x5);
    
  xp37 = ADD(x3, x7);
  dr   = SUB(x3, x7);

  X1 = ADD(xp04, xp26);
  Ar = SUB(xp04, xp26);
 
  X3 = ADD(xp15, xp37);
  Br = SUB(xp15, xp37);
  
  yp04 = ADD(y0, y4);
  ai   = SUB(y0, y4);
    
  yp26 = ADD(y2, y6);
  bi   = SUB(y2, y6);

  yp15 = ADD(y1, y5);
  ci   = SUB(y1, y5);
    
  yp37 = ADD(y3, y7);
  di   = SUB(y3, y7);

  Y1 = ADD(yp04, yp26);
  Ai = SUB(yp04, yp26);
 
  Y3 = ADD(yp15, yp37);
  Bi = SUB(yp15, yp37);
  
  //w0=1/sqrt(2)*(1+i), [ c=1, s=1]  then multiplication by sq2
    
  AipBr = ADD(Ai, Br);
  AimBr = SUB(Ai, Br);
    
  ArpBi = ADD(Ar, Bi);
  ArmBi = SUB(Ar, Bi);

        
  AipBr = MUL(q2, AipBr);
  AimBr = MUL(q2, AimBr);
    
  ArpBi = MUL(q2, ArpBi);
  ArmBi = MUL(q2, ArmBi);
    
  X5 = SUB(ArmBi, AipBr);
  Y5 = ADD(AipBr, ArmBi);
  X7 = ADD(ArpBi, AimBr);
  Y7 = SUB(AimBr, ArpBi);
 
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

  //w = exp(2 pi i / 16)

  c = BROADCAST(c_16[0]);
  s = BROADCAST(s_16[0]);

  AipBr = ADD(Ai, Br);				
  AimBr = SUB(Ai, Br);				
  ArpBi = ADD(Ar, Bi);				
  ArmBi = SUB(Ar, Bi);				
  t0 = MUL(c, ArmBi);				
  t1 = MUL(s, AipBr);				
  X9 = SUB(t0, t1);				
 			
  t0 = MUL(c, AipBr);				
  t1 = MUL(s, ArmBi);				
  Y9 = ADD(t0, t1);				
 		
  t0 = MUL(c, ArpBi);				
  t1 = MUL(s, AimBr);				
  X15 = ADD(t0, t1);				
  		
  t0 = MUL(c, AimBr);				
  t1 = MUL(s, ArpBi);				
  Y15 = SUB(t0, t1);				
		

  //w = exp(6 pi i / 16) = (s_16, c_16)

  AipBr = ADD(Ei, Fr);				
  AimBr = SUB(Ei, Fr);				
  ArpBi = ADD(Er, Fi);				
  ArmBi = SUB(Er, Fi);				
  t0 = MUL(s, ArmBi);				
  t1 = MUL(c, AipBr);				
  X13 = SUB(t0, t1);				
  
  t0 = MUL(s, AipBr);				
  t1 = MUL(c, ArmBi);				
  Y13 = ADD(t0, t1);				
  
  t0 = MUL(s, ArpBi);				
  t1 = MUL(c, AimBr);				
  X11 = ADD(t0, t1);				
  
  t0 = MUL(s, AimBr);				
  t1 = MUL(c, ArpBi);				
  Y11 = SUB(t0, t1);				
    

  //C4

  C4_REG_MEM(X0, Y0, X1, Y1, X2, Y2, X3, Y3, a[0], a[V], a[2*V], a[3*V], a[4*V], a[5*V], a[6*V], a[7*V]);


  //C2 - 6 times


  C2_REG_MEM(X4, Y4, X5, Y5, a[8*V], a[9*V], a[10*V], a[11*V]);
 
  C2_REG_MEM(X6, Y6, X7, Y7, a[12*V], a[13*V], a[14*V], a[15*V]);

  C2_REG_MEM(X8, Y8, X9, Y9, a[16*V], a[17*V], a[18*V], a[19*V]);
  
  C2_REG_MEM(X10, Y10, X11, Y11, a[20*V], a[21*V], a[22*V], a[23*V]);
   
  C2_REG_MEM(X12, Y12, X13, Y13, a[24*V], a[25*V], a[26*V], a[27*V]);
    
  C2_REG_MEM(X14, Y14, X15, Y15, a[28*V], a[29*V], a[30*V], a[31*V]);
  
  }
