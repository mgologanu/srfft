#include "pre8_V4.h"
#include "i.h"

void u2048(register real *a)
{
  u512(a);
  u256(a + 1024);
  u256(a + 1536);
  u256(a + 2048);
  u256(a + 2560);
  u256(a + 3072);
  u256(a + 3584);
  upass_srl3(a, d1024, d2048, 256);
}
