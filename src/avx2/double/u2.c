#include "pre8_V4.h"
#include "i.h"

void u1024(register real *a)
{
  u256(a);
  u128(a + 512);
  u128(a + 768);
  u128(a + 1024);
  u128(a + 1280);
  u128(a + 1536);
  u128(a + 1792);
  upass_srl3(a, d512, d1024, 128);
}
