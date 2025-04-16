#include "pre8_V4.h"
#include "i.h"
 
void c1024(register real *a)
{
  cpass_srl3(a, d512, d1024, 128);
  c256(a);
  c128(a + 512);
  c128(a + 768);
  c128(a + 1024);
  c128(a + 1280);
  c128(a + 1536);
  c128(a + 1792);
}
