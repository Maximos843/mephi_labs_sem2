//
//  Vector.h
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//

#ifndef Vector_h
#define Vector_h

#include <stdio.h>
#include <stdlib.h>
#include "RingInfo.h"

struct Vector{
    void* x;
    void* y;
    void* z;
};

struct Vectors{
    struct RingInfo* ringinfo;
    size_t len;
    struct Vector** vectors;
};

void print_all(struct Vectors*);
void print_one(struct Vector*, struct RingInfo*);
struct Vector* mult(struct Vector*, struct Vector*, struct RingInfo*);
struct Vector* sum(struct Vector*, struct Vector*, struct RingInfo*);
struct Vectors* console_reader(struct Vectors*, struct RingInfo*);
struct Vectors* file_reader(char* , struct Vectors*, struct RingInfo*);

#endif /* Vector_h */
