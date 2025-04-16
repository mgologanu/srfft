#include "pre8_V4.h"
#include "i.h"
 
void c524288(register real *a)
{
  cpass_srl3(a, d262144, d524288, 65536);
  c131072(a);
  c65536(a + 262144);
  c65536(a + 393216);
  c65536(a + 524288);
  c65536(a + 655360);
  c65536(a + 786432);
  c65536(a + 917504);
}
