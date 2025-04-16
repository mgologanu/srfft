#include "pre8_V4.h"
#include "i.h"
 
void c65536(register real *a)
{
  cpass_srl3(a, d32768, d65536, 8192);
  c16384(a);
  c8192(a + 32768);
  c8192(a + 49152);
  c8192(a + 65536);
  c8192(a + 81920);
  c8192(a + 98304);
  c8192(a + 114688);
}
