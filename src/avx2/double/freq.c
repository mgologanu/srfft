#include <stdio.h>
#include <stdlib.h>

const unsigned int freq8_V4_c16_vert[16] = {0, 8, 12, 4, 14, 6, 2, 10, 15, 7, 3, 11, 13, 5, 1, 9};

const unsigned int freq8_V4_c8_vert[8] = {0, 4, 6, 2, 7, 3, 5, 1};

const unsigned int freq8_V4_c4_vert[4] = {0, 2, 3, 1};


//const unsigned int freq8_4_32_r[] = {0, 30, 31, 27, 8, 14, 15, 11, 12, 22, 23, 19, 4, 6, 7, 3};
  const unsigned int freq8_4_32_r[] = {0, 30, 31, 29, 8, 14, 15, 13, 12, 22, 23, 21, 4, 6, 7, 5};


unsigned int freq8_V4_c(unsigned int ind, unsigned int n);


unsigned int freq8_V4_r(unsigned int ind, unsigned int n)
{
  unsigned int m, r, tr, tc, a, c;

  if (n == 32)
    {
      return freq8_4_32_r[ind];
    }

  else if (n == 64)
    {
      //ind = 0..31

      c = n >> 2; //c = n/4 = 16
      
      r = ind/c;  //r=0..1
      m = ind%c;  //m=0..15


      tr = freq8_4_32_r[m]   << 1;
      tc = freq8_V4_c(m, c)  << 2; 
      switch(r)
	{
	case 0:
	  a = tr;                         break;
	case 1:
	  a = (tc - 1) & (n - 1);      	  break;
	default:
	  a = -1;

	}
      return a;
    }

  else
    {
      /*
	Generic n = 8c

	Split radix level 3 - R(x^8c-1) -> R(x^2c -1) and 3 x C(x^c-1), 
	with the other 3 complex being their conjugates

	ind = 0..n/2-1 as the other half is the conjugate

      */

      c = n >> 2; //c = n/4

      r = ind/c;  //r=0..1  due to ind<n/2 -> r <  (n/2) / (n/4) = 4/2 = 2
      m = ind%c;  //m = 0..c-1

      tr = freq8_V4_r(m, c) << 2;

      
      c = n >> 3; //c = n/8 

      r = ind/c;  //r=0..3  due to ind<n/2 -> r <  (n/2) / (n/8) = 8/2 = 4
      m = ind%c;  //m=0..c-1

      tc = freq8_V4_c(m, c) << 3;

      switch(r)
	{
	case 0:
	  a = tr;                         break;  //8k and 8k-4 for the next real transform
	case 1:
	  a = (tc - 2) & (n - 1);	  break;  //8k-2 (with case 8k+2 the conjugate) 
	case 2:
	  a = (tc - 1) & (n - 1); 	  break;  //8k-1 (with case 8k+1 the conjugate)
	case 3:
	  a = (tc - 3) & (n - 1);	  break;  //8k-3 (with case 8k+3 the conjugate)
	default:
	  a = -1;
	}
      return a;
    }
}

  
unsigned int freq8_V4_c(unsigned int ind, unsigned int n)
{
  unsigned int m, r, t, a, c, i, j;

  //  printf("c: i = %u n = %u\n", i, n);

   
  if (n == 16)
    {
      //take transpose into account: from 4x4 back to 4x4
      c = ind%16; //c=0..15

      //(i,j) = 4x4
      
      j = c/4;  //j=0..3
      i = c%4;  //i=0..3

      //(j,i) = 4x4
      
      ind = 4*i+j;

      r = ind/4;  //r=0..3

      m = ind%4;  //m=0..3

      t = freq8_V4_c4_vert[m] << 2;

      switch(r)
	{
	case 0: 
	  a = t;	                  break;
	case 1:
	  a = (t - 2) & (n - 1);	  break;
	case 2:
	  a =  (t - 1) & (n - 1);      	  break;
	case 3:
	  a = (t + 1);          	  break;
	}
      return a;
    }

  
  if (n == 32)
    {
      //take transpose into account: from 4x4 back to 4x4, twice
      r = ind/16; //r=0..1
      c = ind%16; //c=0..15

      //(i,j) = 4x4
      
      j = c/4;  //j=0..3
      i = c%4;  //i=0..3

      //(j,i) = 4x4
      
      ind = 4*i+j;

      ind = ind + r * 16;

      r = ind/4;  //r=0..7

      m = ind%4;  //m=0..3

      t = freq8_V4_c4_vert[m] << 3;

      switch(r)
	{
	case 0: 
	  a = t;	                  break;
	case 1:
	  a = (t - 4) & (n - 1);          break;
	case 2:
	  a = (t - 2) & (n - 1);	  break;
	case 3:
	  a = t + 2;             	  break;
	case 4:
	  a =  (t - 1) & (n - 1); 	  break;
	case 5:
	  a = (t + 3);          	  break;
	case 6:
	  a = (t - 3) & (n - 1);	  break;
	case 7:
	  a = (t + 1);          	  break;
	}
      return a;
    }

  else if (n == 64)
    {
      //take transpose into account: from 4x8 back to 8x4, twice
      r = ind/32; //r=0..1
      c = ind%32; //c=0..31

      //(i,j) = 4x8
      
      j = c/4;  //j=0..7
      i = c%4;  //i=0..3

      //(j,i) = 8x4
      
      ind = 8*i+j;

      ind = ind + r * 32;

      r = ind/8;  //r=0..7

      m = ind%8;  //m=0..7

      t = freq8_V4_c8_vert[m] << 3;

      switch(r)
	{
	case 0: 
	  a = t;	                  break;
	case 1:
	  a = (t - 4) & (n - 1);          break;
	case 2:
	  a = (t - 2) & (n - 1);	  break;
	case 3:
	  a = t + 2;             	  break;
	case 4:
	  a =  (t - 1) & (n - 1); 	  break;
	case 5:
	  a = (t + 3);          	  break;
	case 6:
	  a = (t - 3) & (n - 1);	  break;
	case 7:
	  a = (t + 1);          	  break;
	}
      return a;

      
    }
  else if (n == 128)
    {

      //take transpose into account: from 4x16 back to 16x4, twice

      r = ind/64; //r=0..1
      c = ind%64; //c=0..63

      //(i,j) = 4x16
      
      j = c/4;  //j=0..15
      i = c%4;  //i=0..3

      //(j,i) = 16x4
      
      ind = 16 * i + j;

      ind = ind + r * 64;
      
      //      printf("complex: ind = %u c = %u r = %u a = %u t = %u\n", ind, c, r, a, t);
      // return 999;
      
      r = ind/16;  //r=0..7

      m = ind%16;  //m=0..15

      t = freq8_V4_c16_vert[m] << 3;

      // printf("c: i = %u r = %u  m = %u t = %u --- ", i, r, m, t);
      switch(r)
	{
	case 0: 
	  a = t;	                  break;
	case 1:
	  a = (t - 4) & (n - 1);          break;
	case 2:
	  a = (t - 2) & (n - 1);	  break;
	case 3:
	  a = t + 2;             	  break;
	case 4:
	  a =  (t - 1) & (n - 1); 	  break;
	case 5:
	  a = (t + 3);          	  break;
	case 6:
	  a = (t - 3) & (n - 1);	  break;
	case 7:
	  a = (t + 1);          	  break;
	}
      return a;
      
    }
  else
    {

      c = n >> 2; //n/4
      
      r = ind/c;  //r=0..3
      m = ind%c;  //m=0..c-1

      if (r == 0)
	{
	  return (freq8_V4_c(m, c) << 2);  //8k and 8k-4
	}
      
      c = n >> 3; //n/8
      
      r = ind/c;  //r=2..7 ; r=0 and r=1 have been treated above
      m = ind%c;  //m=0..c-1

      t = freq8_V4_c(m, c) << 3;

      switch(r)
	{
	  /* 
	     switching a root of unity and its conjugate in order to
	     obtain the "correct" direct FFT using twiddle factors
	     with exp(-2 pi k/N) having a minus sign
	   */
	case 2:
	  a = (t - 2) & (n - 1);	  break;  //8k-2 
	case 3:
	  a = t + 2;             	  break;  //8k+2
	case 4:
	  a =  (t - 1) & (n - 1); 	  break;  //8k-1
	case 5:
	  a = (t + 3);          	  break;  //8k+3
	case 6:
	  a = (t - 3) & (n - 1);	  break;  //8k-3
	case 7:
	  a = (t + 1);          	  break;  //8k+1
	default:
           ;
	  //will NOT execute because r=0 and r=1 have been treated before
	}
      return a;
    }
  
  return 999;
}
  /*     return freq8_4_16_c[i]; */
  /* else if (n == 32) */
  /*   return freq8_4_32_c[i]; */

  /* m = n >> 1; */
  /* if (i < m) return freq8_4_c(i,m) << 1; */
  
  /* i -= m; */
  /* m >>= 1; */
  /* if (i < m) return ((freq8_4_c(i,m) << 2) - 1) & (n - 1); */
  /* i -= m; */
  /* return (freq8_4_c(i,m) << 2) + 1; */

  /*
    Our complex split radix pass is equivalent to:
    
    2k, N-(4k+1), 4k+1. 

    Note the reversal compared to djbfft:

    2k, 4k+1, N-(4k+1)

    Maybe it would be better to use djbfft convention. However, the
    final recursion steps (c16 and c32) are shuffling supplementary
    the order, so that the original djbfft order is not preserved.

    For convolution, it does not matter. Also, the frequency tables
    defined here apply to the new 
   */
  
/* } */


/* unsigned int freq8_4_r(unsigned int i, unsigned int n) */
/* { */
/*   unsigned int m; */
  
/*   if (n == 32) */
/*     return freq8_4_32_r[i]; */

  
/*   m = n >> 1; */
/*   if (i < m/2) return freq8_4_r(i,m) << 1; */
  
/*   i -= m/2; */
/*   m >>= 1; */
/*   return ((freq8_4_c(i,m) << 2) - 1) & (n - 1); */
/*   //  return (freq8_4_c(i,m) << 2) + 1; */

/* } */

/* int main() { */

/*  unsigned int n = 256u; */

/*  unsigned int i; */

/*   for (i=0; i<n; i++) */
/*     { */
/*       printf("%u, ",freq8_V4_c(i,n)); */
/*     } */
/*   printf("\n"); */
  
/* } */
