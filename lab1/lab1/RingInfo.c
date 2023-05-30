//
//  RingInfo.c
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//

#include "RingInfo.h"
#include <stdlib.h>

struct RingInfo* Create(size_t size, void* (*sum)(void*, void*), void* (*mult)(void*, void*), void* (*readval)(char*), void* (*new)(void*), char* (*tostr)(void*)){
    struct RingInfo* Ringinfo = malloc(sizeof(struct RingInfo));
    Ringinfo->size = size;
    Ringinfo->sum = sum;
    Ringinfo->mult = mult;
    Ringinfo->readval = readval;
    Ringinfo->new = new;
    Ringinfo->tostr = tostr;
    return Ringinfo;
};
