//
//  RingInfo.h
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef RingInfo_h
#define RingInfo_h

struct RingInfo{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*mult)(void*, void*);
    void* (*readval)(char*);
    void* (*new)(void*);
    char* (*tostr)(void*);
};

struct RingInfo* Create(
    size_t size,
    void* (*sum)(void*, void*),
    void* (*mult)(void*, void*),
    void* (*readval)(char*),
    void* (*new)(void*),
    char* (*tostr)(void*)
);

#endif /* RingInfo_h */
