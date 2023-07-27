//
//  func_context.c
//  MemoryFunc
//
//  Created by janezhuang on 2023/7/27.
//

#include "func_context.h"

#if defined(__arm64__) || defined(__aarch64__)

void im_makecontext(func_ucontext_t *ctx, void *func, void *arg, void *stackTop) {
    ctx->GR.__fp = (uintptr_t)stackTop;
    ctx->GR.__sp = (uintptr_t)stackTop;
    ctx->GR.__x[0] = (uintptr_t)arg;
    ctx->GR.__pc = (uintptr_t)func;
}

#endif
