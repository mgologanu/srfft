#include "pre8_V4.h"
#include "i.h"

void cs16384(register real *a)
{
  cspass_sr(a, d16384, 2048);
  cs8192(a);
  cs4096(a + 16384);
  cs4096(a + 24576);
}
