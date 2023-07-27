//
//  memory_func.c
//  MemoryFunc
//
//  Created by janezhuang on 2023/7/27.
//

#include "memory_func.h"
#include "func_context.h"
#include <malloc/_malloc.h>

#define STACK_SIZE (512 * 1024)

typedef struct memory_func {
    func_ucontext_t *pre_context;
    func_ucontext_t *context;
    void(*func)(void *userdata);
    void *userdata;
} memory_func_t;

static void entry(memory_func_t *memory_func) {
    memory_func->func(memory_func->userdata);
    im_setcontext(memory_func->pre_context);
}

void call_memory_func(void(*func)(void *userdata), void *userdata) {
    char *stack = malloc(STACK_SIZE);
    memory_func_t *memory_func = malloc(sizeof(memory_func_t));
    memory_func->pre_context = malloc(sizeof(func_ucontext_t));
    memory_func->context = malloc(sizeof(func_ucontext_t));
    memory_func->func = func;
    memory_func->userdata = userdata;
    
    im_getcontext(memory_func->pre_context);
    im_makecontext(memory_func->context, entry, memory_func, stack + STACK_SIZE);
    im_callFunc(memory_func->context, memory_func->pre_context);
    
    free(memory_func->context);
    free(memory_func->pre_context);
    free(memory_func);
    free(stack);
}
