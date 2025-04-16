#include "pre8_V4.h"
#include "i.h"
 
void c4096(register real *a)
{
  cpass_srl3(a, d2048, d4096, 512);
  c1024(a);
  c512(a + 2048);
  c512(a + 3072);
  c512(a + 4096);
  c512(a + 5120);
  c512(a + 6144);
  c512(a + 7168);
}
