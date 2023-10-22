#include "mallocz/mallocz.h"


uint8_t **malloc2D(int jmax, int imax)
{
   // first allocate a block of memory for the row pointers and the 2D array
   uint8_t **x = (uint8_t **)malloc(jmax*sizeof(uint8_t *) + jmax*imax*sizeof(uint8_t));

   // Now assign the start of the block of memory for the 2D array after the row pointers
   x[0] = (uint8_t *)(x + jmax);

   // Last, assign the memory location to point to for each row pointer
   for (int j = 1; j < jmax; j++) {
      x[j] = x[j-1] + imax;
   }

   return(x);
}
