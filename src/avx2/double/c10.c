#include "pre8_V4.h"
#include "i.h"
 
void c262144(register real *a)
{
  cpass_srl3(a, d131072, d262144, 32768);
  c65536(a);
  c32768(a + 131072);
  c32768(a + 196608);
  c32768(a + 262144);
  c32768(a + 327680);
  c32768(a + 393216);
  c32768(a + 458752);
}
