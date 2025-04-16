#include "pre8_V4.h"
#include "i.h"

void u131072(register real *a)
{
  u32768(a);
  u16384(a + 65536);
  u16384(a + 98304);
  u16384(a + 131072);
  u16384(a + 163840);
  u16384(a + 196608);
  u16384(a + 229376);
  upass_srl3(a, d65536, d131072, 16384);
}
