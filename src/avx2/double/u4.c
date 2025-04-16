#include "pre8_V4.h"
#include "i.h"

void u4096(register real *a)
{
  u1024(a);
  u512(a + 2048);
  u512(a + 3072);
  u512(a + 4096);
  u512(a + 5120);
  u512(a + 6144);
  u512(a + 7168);
  upass_srl3(a, d2048, d4096, 512);
}
