//
//  memory_func.h
//  MemoryFunc
//
//  Created by janezhuang on 2023/7/27.
//

#ifndef memory_func_h
#define memory_func_h

#include <stdio.h>

void call_memory_func(void(*func)(void *userdata), void *userdata);

#endif /* memory_func_h */
