#include "pre8_V4.h"
#include "i.h"
 
void c131072(register real *a)
{
  cpass_srl3(a, d65536, d131072, 16384);
  c32768(a);
  c16384(a + 65536);
  c16384(a + 98304);
  c16384(a + 131072);
  c16384(a + 163840);
  c16384(a + 196608);
  c16384(a + 229376);
}
