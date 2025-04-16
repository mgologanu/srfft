#include "pre8_V4.h"
#include "i.h"

void u16384(register real *a)
{
  u4096(a);
  u2048(a + 8192);
  u2048(a + 12288);
  u2048(a + 16384);
  u2048(a + 20480);
  u2048(a + 24576);
  u2048(a + 28672);
  upass_srl3(a, d8192, d16384, 2048);
}
