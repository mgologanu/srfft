#include "pre8_V4.h"
#include "i.h"

void u65536(register real *a)
{
  u16384(a);
  u8192(a + 32768);
  u8192(a + 49152);
  u8192(a + 65536);
  u8192(a + 81920);
  u8192(a + 98304);
  u8192(a + 114688);
  upass_srl3(a, d32768, d65536, 8192);
}
