
extern const double sq2[];

extern const double sq2_u[];

extern const double c_16[];

extern const double s_16[];


extern const real rad8_d32[];
extern const real rad8_d64[];
extern const real rad8_d128[];
extern const real d16[];
extern const real d32[];
extern const real d64[];
extern const real d128[];
extern const real d256[];
extern const real d512[];
extern const real d1024[];
extern const real d2048[];
extern const real d4096[];
extern const real d8192[];
extern const real d16384[];
extern const real d32768[];
extern const real d65536[];
extern const real d131072[];
extern const real d262144[];
extern const real d524288[];
extern const real d1048576[];
extern const real d2097152[];
extern const real d4194304[];
extern const real d8388608[];

extern unsigned int freq8_V4_r(unsigned int ind, unsigned int n);
extern unsigned int freq8_V4_c(unsigned int ind, unsigned int n);

extern void c16_vert(real *a);
extern void c8_vert(real *a);
extern void c4_vert(real *a);

extern void t8_V4(real *a);
extern void t16_V4(real *a);

extern void cpass_rad4(real *a,  const real *w, size_t n);
extern void cpass_rad8(real *a,  const real *w, size_t n);
extern void cpass_srl3(real *a,  const real *w,  const real *w2, size_t n);
extern void cpass_sr(real *a,  const real *w,  size_t n);

extern void upass_srl3(real *a, const real *w, const real *w2, size_t n);
extern void upass_rad8(real *a,  const real *w, size_t n);
extern void upass_sr(real *a,  const real *w,  size_t n);

extern void u4_vert(real *a);
extern void u8_vert(real *a);
extern void u16_vert(real *a);
extern void ut8_V4(real *a);
extern void ut16_V4(real *a);


extern void c16(real *a);
extern void c32(real *a);
extern void c64(real *a);
extern void c128(real *a);
extern void c256(real *a);
extern void c512(real *a);
extern  void c1024(real *a);
extern  void c2048(real *a);
extern  void c4096(real *a);
extern  void c8192(real *a);
extern  void c16384(real *a);
extern  void c32768(real *a);
extern  void c65536(real *a);
extern  void c131072(real *a);
extern  void c262144(real *a);
extern  void c524288(real *a);
extern void c1048576(real *a);
extern void c2097152(real *a);
extern void c4194304(real *a);
extern void c8388608(real *a);

extern void u32(real *a);
extern void u64(real *a);
extern void u128(real *a);
extern void u256(real *a);
extern void u512(real *a);
extern  void u1024(real *a);
extern  void u2048(real *a);
extern  void u4096(real *a);
extern  void u8192(real *a);
extern  void u16384(real *a);
extern  void u32768(real *a);
extern  void u65536(real *a);
extern  void u131072(real *a);
extern  void u262144(real *a);
extern  void u524288(real *a);
extern  void u1048576(real *a);

extern void cs16_vert(real *a);
extern void cs8_vert(real *a);

extern void ts8_V4(real *a);
extern void ts16_V4(real *a);

extern void cspass_rad4(real *a,  const real *w,  size_t n);
extern void cspass_rad8(real *a,  const real *w, size_t n);
extern void cspass_srl3(real *a,  const real *w,  const real *w2, size_t n);
extern void cspass_sr(real *a,  const real *w,  size_t n);

extern void uspass_sr(real *a,  const real *w,  size_t n);
extern void uspass_srl3(real *a, const real *w, const real *w2, size_t n);
extern void uspass_rad8(real *a,  const real *w, size_t n);
extern void uspass_rad4(real *a,  const real *w,  size_t n);

extern void us8_vert(real *a);
extern void us16_vert(real *a);

extern void uts8_V4(real *a);
extern void uts16_V4(real *a);


extern void cs16(real *a);
extern void cs32(real *a);
extern void cs64(real *a);
extern void cs128(real *a);
extern void cs256(real *a);
extern void cs512(real *a);
extern void cs1024(real *a);
extern void cs2048(real *a);
extern void cs4096(real *a);
extern void cs8192(real *a);
extern void cs16384(real *a);
extern void cs32768(real *a);
extern void cs65536(real *a);
extern void cs131072(real *a);
extern void cs262144(real *a);
extern void cs524288(real *a);
extern void cs1048576(real *a);

extern void us16(real *a);
extern void us32(real *a);
extern void us64(real *a);
extern void us128(real *a);
extern void us256(real *a);
extern void us512(real *a);
extern  void us1024(real *a);
extern  void us2048(real *a);
extern  void us4096(real *a);
extern  void us8192(real *a);
extern  void us16384(real *a);
extern  void us32768(real *a);
extern  void us65536(real *a);
extern  void us131072(real *a);
extern  void us262144(real *a);
extern  void us524288(real *a);
extern  void us1048576(real *a);

extern void rpass_srl3(real *a,  const real *w,  const real *w2, size_t n);
extern void rpass_sr(real *a,  const real *w,  size_t n);


extern void r32(real *a);
extern void r64(real *a);
extern void r128(real *a);
extern void r256(real *a);
extern void r512(real *a);
extern void r1024(real *a);
extern void r2048(real *a);
extern void r4096(real *a);
extern void r8192(real *a);
extern void r16384(real *a);
extern void r32768(real *a);
extern void r65536(real *a);
extern void r131072(real *a);
extern void r262144(real *a);
extern void r524288(real *a);
extern void r1048576(real *a);

extern void vpass_srl3(real *a,  const real *w,  const real *w2, size_t n);
extern void vpass_sr(real *a,  const real *w,  size_t n);



extern void v32(real *a);
extern void v64(real *a);
extern void v128(real *a);
extern void v256(real *a);
extern void v512(real *a);
extern void v1024(real *a);
extern void v2048(real *a);
extern void v4096(real *a);
extern void v8192(real *a);
extern void v16384(real *a);
extern void v32768(real *a);
extern void v65536(real *a);
extern void v131072(real *a);
extern void v262144(real *a);
extern void v524288(real *a);
extern void v1048576(real *a);


/*

  Calculates and saves twisted coefficients defined by:

  z1 = (A+Bj)*(c+js)
  z2 = (A-Bj)*(c+js)

  where A and B are complex:
  
  A = Ar + j Ai
  B = Br + j Bi


  The output is given by:
  
  z1 = S0 + j S1
  z2 = S2 + j S3

  with: 

  z1 = [Ar + j Ai + j( Br + j Bi)] (c+js)
     = [Ar - Bi + j(Ai + Br)] (c+js)
     = (Ar - Bi)c - (Ai + Br)s + j[ (Ar - Bi)s + (Ai + Br)c] 
     =              S0         + j            S1


  z2 = [Ar + j Ai - j( Br + j Bi)] (c-js)
     = [Ar + Bi + j(Ai - Br)] (c-js)
     = (Ar + Bi)c + (Ai - Br)s + j[-(Ar + Bi)s + (Ai - Br)c] 
     =              S2         + j            S3

*/

#define TWISTED(Ar,Ai,Br,Bi,c,s,S0,S1,S2,S3) {	\
  AipBr = ADD(Ai, Br);				\
  AimBr = SUB(Ai, Br);				\
  ArpBi = ADD(Ar, Bi);				\
  ArmBi = SUB(Ar, Bi);				\
  t0 = MUL(c, ArmBi);				\
  t1 = MUL(s, AipBr);				\
  t2 = SUB(t0, t1);				\
  STORE(S0, t2);				\
  t0 = MUL(c, AipBr);				\
  t1 = MUL(s, ArmBi);				\
  t2 = ADD(t0, t1);				\
  STORE(S1, t2);				\
  t0 = MUL(c, ArpBi);				\
  t1 = MUL(s, AimBr);				\
  t2 = ADD(t0, t1);				\
  STORE(S2, t2);				\
  t0 = MUL(c, AimBr);				\
  t1 = MUL(s, ArpBi);				\
  t2 = SUB(t0, t1);				\
  STORE(S3, t2);				\
  }



#define C2_REG_MEM(x0, y0, x1, y1, X0, Y0, X1, Y1) {  \
    t0 = ADD(x0, x1);				     \
    t2 = SUB(x0, x1);				     \
    t1 = ADD(y0, y1);				     \
    t3 = SUB(y0, y1);				     \
    STORE(X0, t0);				     \
    STORE(Y0, t1);				     \
    STORE(X1, t2);				     \
    STORE(Y1, t3);				     \
  }


#define C4_REG_MEM(x0, y0, x1, y1, x2, y2, x3, y3, X0, Y0, X1, Y1, X2, Y2, X3, Y3) { \
    t02 = ADD(x0, x2);		/* x 0+2 */				\
    Ar  = SUB(x0, x2);		/* x 0-2 */				\
    t13 = ADD(x1, x3);		/* x 1+3 */				\
    Br  = SUB(x1, x3);		/* x 1-3 */				\
    s02 = ADD(y0, y2);		/* y 0+2 */				\
    Ai  = SUB(y0, y2);		/* y 0-2 */				\
    s13 = ADD(y1, y3);		/* y 1+3 */				\
    Bi  = SUB(y1, y3);		/* y 1-3 */				\
    t0 = ADD(t02, t13);		/* x 0+2+1+3 */				\
    t1 = ADD(s02, s13);		/* y 0+2+1+3 */				\
    t2 = SUB(t02, t13);		/* x 0+2-1-3 */				\
    t3 = SUB(s02, s13);		/* y 0+2-1-3 */				\
    AipBr = ADD(Ai, Br);        /* y 0-2 + x 1-3 */			\
    AimBr = SUB(Ai, Br);	/* y 0-2 - x 1-3 */			\
    ArpBi = ADD(Ar, Bi);	/* x 0-2 + y 1-3 */			\
    ArmBi = SUB(Ar, Bi);	/* x 0-2 - y 1-3 */			\
    STORE(X0, t0);							\
    STORE(Y0, t1);							\
    STORE(X1, t2);							\
    STORE(Y1, t3);							\
    STORE(X2, ArmBi);							\
    STORE(Y2, AipBr);							\
    STORE(X3, ArpBi);							\
    STORE(Y3, AimBr);							\
  }

#define TRANSPOSE4(x0,x1,x2,x3) {				  \
    s0 = SHUF(x0,x1,I1_F) ;					  \
    s1 = SHUF(x0,x1,I2_F) ;					  \
    s2 = SHUF(x2,x3,I1_F) ;					  \
    s3 = SHUF(x2,x3,I2_F) ;					  \
    x0 = PERM(s0,s2,P1_F) ;					  \
    x2 = PERM(s0,s2,P2_F) ;					  \
    x1 = PERM(s1,s3,P1_F) ;					  \
    x3 = PERM(s1,s3,P2_F) ;					  \
  }





/*

  Inverse of TWISTED: from (z0, z1) to (A, B):


  z0 = (A+Bj)*(c+js) = Ac - Bs + j(As + Bc)
  z1 = (A-Bj)*(c-js)

  where A and B are complex:
  
  A = Ar + j Ai
  B = Br + j Bi

  and z0 and z1 are given by:


  z0 = S0 + j S1
  z1 = S2 + j S3


  Multiply by c+/-js:

  z0*(c-js) = A+B*j
  z1*(c+js) = A-B*j


  (z0+z1)*c + j*(z1-z0)*s = 2A (forget the 2!) = Ar + jAi
  (z0-z1)*c - j*(z0+z1)*s = 2*B*j (forget the 2) = (Br + jBi)*j = -Bi + jBr

  Multiply last eq by j:

  j*(z0-z1)*c - j^2 * (z0+z1)*s = -j*Bi + j^2 Br

  j*(z0-z1)*c  +  (z0+z1)*s = -j*Bi + - Br
  
  and again by -1:

  -(z0+z1)*s + j*(z1-z0)*c = Br + j Bi = B!!

  Final eqs:
  
  (z0+z1)*c + j*(z1-z0)*s = A
 -(z0+z1)*s + j*(z1-z0)*c = B
  
  
  

*/


#define UNTWISTED(Ar,Ai,Br,Bi,c,s,S0,S1,S2,S3) {		\
  z0r = LOAD(S0);						\
  z0i = LOAD(S1);						\
  z1r = LOAD(S2);						\
  z1i = LOAD(S3);						\
  t0r = ADD(z0r, z1r);						\
  t0i = ADD(z0i, z1i);						\
  t1r = SUB(z1r, z0r);						\
  mt1i= SUB(z0i, z1i);						\
  t0  = MUL(t0r,c);						\
  t1  = MUL(mt1i,s);						\
  Ar  = ADD(t0,t1);						\
  t0  = MUL(t0i,c);						\
  t1  = MUL(t1r,s);						\
  Ai  = ADD(t0, t1);						\
  t0  = MUL(mt1i,c);						\
  t1  = MUL(t0r,s);						\
  Br  = SUB(t0,t1);						\
  t0  = MUL(t1r,c);						\
  t1  = MUL(t0i,s);						\
  Bi  = SUB(t0,t1);						\
  }

  
 

#define U4_REG_MEM(X0, Y0, X1, Y1, X2, Y2, X3, Y3, x0, y0, x1, y1, x2, y2, x3, y3) { \
  t0 = LOAD(X0);							\
  t1 = LOAD(Y0);							\
  t2 = LOAD(X1);							\
  t3 = LOAD(Y1);							\
  ArmBi = LOAD(X2);							\
  AipBr = LOAD(Y2);							\
  ArpBi = LOAD(X3);							\
  AimBr = LOAD(Y3);							\
  Ai  = ADD(AipBr, AimBr);	/* y 0-2 */				\
  Br  = SUB(AipBr, AimBr);	/* x 1-3 */				\
  Ar  = ADD(ArpBi, ArmBi);	/* x 0-2 */				\
  Bi  = SUB(ArpBi, ArmBi);	/* y 1-3 */				\
  t02 = ADD(t0, t2);            /* x 0+2 */				\
  t13 = SUB(t0, t2);            /* x 1+3 */				\
  s02 = ADD(t1, t3);            /* y 0+2 */				\
  s13 = SUB(t1, t3);            /* y 1+3 */				\
  x0  = ADD(t02, Ar);							\
  x2  = SUB(t02, Ar);							\
  x1  = ADD(t13, Br);							\
  x3  = SUB(t13, Br);							\
  y0  = ADD(s02, Ai);							\
  y2  = SUB(s02, Ai);							\
  y1  = ADD(s13, Bi);							\
  y3  = SUB(s13, Bi);							\
  }





#define U2_REG_MEM(X0, Y0, X1, Y1, x0, y0, x1, y1) {  \
  t0 = LOAD(X0);				      \
  t1 = LOAD(Y0);				      \
  t2 = LOAD(X1);				      \
  t3 = LOAD(Y1);				      \
  x0 = ADD(t0, t2);				      \
  x1 = SUB(t0, t2);				      \
  y0 = ADD(t1, t3);				      \
  y1 = SUB(t1, t3);				      \
}



#define UNTWISTED_REG(Ar,Ai,Br,Bi,c,s,z0r, z0i, z1r, z1i) {	\
  t0r = ADD(z0r, z1r);						\
  t0i = ADD(z0i, z1i);						\
  t1r = SUB(z1r, z0r);						\
  mt1i= SUB(z0i, z1i);						\
  t0  = MUL(t0r,c);						\
  t1  = MUL(mt1i,s);						\
  Ar  = ADD(t0,t1);						\
  t0  = MUL(t0i,c);						\
  t1  = MUL(t1r,s);						\
  Ai  = ADD(t0, t1);						\
  t0  = MUL(mt1i,c);						\
  t1  = MUL(t0r,s);						\
  Br  = SUB(t0,t1);						\
  t0  = MUL(t1r,c);						\
  t1  = MUL(t0i,s);						\
  Bi  = SUB(t0,t1);						\
  }



#define REAL_TWISTED(Ar,Br,c,s,S0,S1) {		\
    t0 = MUL(c, Ar);				\
    t1 = MUL(s, Br);				\
    t2 = SUB(t0, t1);				\
    STORE(S0, t2);				\
    t0 = MUL(c, Br);				\
    t1 = MUL(s, Ar);				\
    t2 = ADD(t0, t1);				\
    STORE(S1, t2);				\
  }



#define REAL_UNTWISTED(Ar,Br,c,s,S0,S1) {	\
    t0 = LOAD(S0);				\
    t1 = LOAD(S1);				\
    t2 = MUL(c,t0);				\
    t3 = MUL(s,t1);				\
    Ar = ADD(t2,t3);				\
    t2 = MUL(s,t0);				\
    t3 = MUL(c,t1);				\
    Br = SUB(t3,t2);				\
  }

