#ifndef VEC_ADDER_DRIVER_H
#define VEC_ADDER_DRIVER_H

#include "xil_types.h"
struct vec_adder;

void vec_adder_add(struct vec_adder *adder, u32 source1[], u32 source2[], u32 dest[], u32 len);

#endif // AXI_ADDER_H
