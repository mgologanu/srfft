#include "pre8_V4.h"
#include "i.h"
 
void c2048(register real *a)
{
  cpass_srl3(a, d1024, d2048, 256);
  c512(a);
  c256(a + 1024);
  c256(a + 1536);
  c256(a + 2048);
  c256(a + 2560);
  c256(a + 3072);
  c256(a + 3584);
}
