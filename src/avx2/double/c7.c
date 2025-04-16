#include "pre8_V4.h"
#include "i.h"
 
void c32768(register real *a)
{
  cpass_srl3(a, d16384, d32768, 4096);
  c8192(a);
  c4096(a + 16384);
  c4096(a + 24576);
  c4096(a + 32768);
  c4096(a + 40960);
  c4096(a + 49152);
  c4096(a + 57344);
}
