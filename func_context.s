#if defined(__arm64__) || defined(__aarch64__)

.text
.align 2

.global _im_getcontext
_im_getcontext:
    str    x29,    [x0, #0x0E8]    // 保存call_memory_func函数的FP
    mov    x9,     sp
    str    x9,     [x0, #0x0F8]    // 保存call_memory_func函数的SP
    ret

.global _im_callFunc
_im_callFunc:
    str    x30,    [x1, #0x100]    // 保存call_memory_func中im_callFunc的下一条指令地址到pre_context的PC中
    ldr    x29,    [x0, #0x0E8]    // 设置entry函数的FP
    ldr    x1,     [x0, #0x0F8]
    mov    sp,     x1              // 设置entry函数的SP
    ldr    x30,    [x0, #0x100]
    ldr    x0,     [x0, #0x000]    // 设置entry的参数
    ret    x30                     // 跳转到x9（entry函数）

.global _im_setcontext
_im_setcontext:
    ldr    x29,    [x0, #0x0E8]    // 恢复call_memory_func函数的FP
    ldr    x1,     [x0, #0x0F8]
    mov    sp,     x1              // 恢复call_memory_func函数的SP
    ldr    x30,    [x0, #0x100]    // LR = call_memory_func中im_callFunc的下一条指令地址
    ret x30

#endif
