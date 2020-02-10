#include "readcount.h"
#include "types.h"
#include "defs.h"
#include "spinlock.h"

int count = 0;
struct spinlock lock;

void
rc_increment(void)
{
  acquire(&lock);
  count++;
  release(&lock);
}

int
rc_count(void)
{
  return count;
}
