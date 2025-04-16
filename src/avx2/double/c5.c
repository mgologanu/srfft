#include "pre8_V4.h"
#include "i.h"
 
void c8192(register real *a)
{
  cpass_srl3(a, d4096, d8192, 1024);
  c2048(a);
  c1024(a + 4096);
  c1024(a + 6144);
  c1024(a + 8192);
  c1024(a + 10240);
  c1024(a + 12288);
  c1024(a + 14336);
}
