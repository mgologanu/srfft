#include "pre8_V4.h"
#include "i.h"

void u32768(register real *a)
{
  u8192(a);
  u4096(a + 16384);
  u4096(a + 24576);
  u4096(a + 32768);
  u4096(a + 40960);
  u4096(a + 49152);
  u4096(a + 57344);
  upass_srl3(a, d16384, d32768, 4096);
}
