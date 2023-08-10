/***************************** Include Files *******************************/
#include "xil_cache.h"
#include "axi_adder.h"

/************************** Function Definitions ***************************/
/***************************** Include Files *******************************/

struct request {
    u32 *vec1; // Pointer to vector 1
    u32 *vec2; // Pointer to vector 2
    u32 *result; // Pointer to result vector
    u32 len; // Length of vectors
};


struct vec_adder {
  struct request *base;
  volatile u32 ready;
};

void vec_adder_add(struct vec_adder *adder, u32 source1[], u32 source2[], u32 dest[], u32 len)
{
  struct request req = {.vec1 = source1, .vec2 = source2, .result = dest, .len = len};
  Xil_DCacheFlushRange(source1, len * sizeof(source1[0]));
  Xil_DCacheFlushRange(source2, len * sizeof(source2[0]));
  Xil_DCacheFlushRange(&req, sizeof(req));
  adder->base = &req;
  while (!adder->ready);
  Xil_DCacheFlushRange(req.result, len * sizeof(dest[0]));
}

