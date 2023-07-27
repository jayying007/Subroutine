//
//  main.c
//  MemoryFunc
//
//  Created by janezhuang on 2023/7/27.
//

#include <stdio.h>
#include "memory_func.h"

int sum(int a, int b) {
    return a + b;
}

int total(int arg1, int arg2, int arg3, int arg4) {
    int t1 = sum(arg1, arg2);
    int t2 = sum(arg3, arg4);
    return t1 + t2;
}

void testFunc(void *userdata) {
    char *str = userdata;
    printf("%s\n", str);
    printf("%d\n", total(1, 2, 3, 4));
}

int main(int argc, const char * argv[]) {
    printf("Start\n");
    call_memory_func(testFunc, "call memory function success!");
    printf("End\n");
    
    return 0;
}
