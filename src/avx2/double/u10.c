#include "pre8_V4.h"
#include "i.h"

void u262144(register real *a)
{
  u65536(a);
  u32768(a + 131072);
  u32768(a + 196608);
  u32768(a + 262144);
  u32768(a + 327680);
  u32768(a + 393216);
  u32768(a + 458752);
  upass_srl3(a, d131072, d262144, 32768);
}
