#include "pre8_V4.h"
#include "i.h"

void u8192(register real *a)
{
  u2048(a);
  u1024(a + 4096);
  u1024(a + 6144);
  u1024(a + 8192);
  u1024(a + 10240);
  u1024(a + 12288);
  u1024(a + 14336);
  upass_srl3(a, d4096, d8192, 1024);
}
