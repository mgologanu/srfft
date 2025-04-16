#include "pre8_V4.h"
#include "i.h"
 
void c16384(register real *a)
{
  cpass_srl3(a, d8192, d16384, 2048);
  c4096(a);
  c2048(a + 8192);
  c2048(a + 12288);
  c2048(a + 16384);
  c2048(a + 20480);
  c2048(a + 24576);
  c2048(a + 28672);
}
