//
//  func_context.h
//  MemoryFunc
//
//  Created by janezhuang on 2023/7/27.
//

#ifndef func_context_h
#define func_context_h

#include <stdio.h>

#if defined(__arm64__) || defined(__aarch64__)

typedef struct func_ucontext {
    struct GPRs {
        uint64_t __x[29]; // x0-x28
        uint64_t __fp;    // Frame pointer x29
        uint64_t __lr;    // Link register x30
        uint64_t __sp;    // Stack pointer x31
        uint64_t __pc;    // Program counter
        uint64_t padding; // 16-byte align, for cpsr
    } GR;
    double VR[32];
} func_ucontext_t;

extern void im_getcontext(func_ucontext_t *__ucp);
extern void im_makecontext(func_ucontext_t *__ucp, void *func, void *arg, void *stackPointer);
extern void im_callFunc(func_ucontext_t *__ucp, func_ucontext_t *__ucp2);
extern void im_setcontext(func_ucontext_t *__ucp);

#endif

#endif /* func_context_h */
