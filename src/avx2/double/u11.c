#include "pre8_V4.h"
#include "i.h"

void u524288(register real *a)
{
  u131072(a);
  u65536(a + 262144);
  u65536(a + 393216);
  u65536(a + 524288);
  u65536(a + 655360);
  u65536(a + 786432);
  u65536(a + 917504);
  upass_srl3(a, d262144, d524288, 65536);
}
