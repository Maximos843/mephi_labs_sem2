//
//  Vector.c
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Vector.h"
#include "RingInfo.h"

struct Vector* sum(struct Vector* v1, struct Vector* v2, struct RingInfo* ring){
    struct Vector* v3 = malloc(sizeof(struct Vector));
    v3->x = ring->sum(v1->x, v2->x);
    v3->y = ring->sum(v1->y, v2->y);
    v3->z = ring->sum(v1->z, v2->z);
    return v3;
}

struct Vector* mult(struct Vector* v1, struct Vector* v2, struct RingInfo* ri){
    struct Vector* v3 = malloc(sizeof(struct Vector));
    v3->x = ri->mult(v1->x, v2->x);
    v3->y = ri->mult(v1->y, v2->y);
    v3->z = ri->mult(v1->z, v2->z);
    void* res = ri->sum(v3->x, v3->y);
    res = ri->sum(res, v3->z);
    return res;
}

void print_one(struct Vector* v1, struct RingInfo* ring){
    if (v1 == NULL){
        return;
    }
    char* coor1 = ring->tostr(v1->x);
    char* coor2 = ring->tostr(v1->y);
    char* coor3 = ring->tostr(v1->z);
    printf("%s %s %s\n", coor1, coor2, coor3);
    free(coor1);
    free(coor2);
    free(coor3);
}

void print_all(struct Vectors* v){
    if (v == NULL){
        return;
    }
    for (int i = 0; i < v->len; ++i){
        print_one(v->vectors[i], v->ringinfo);
    }
}

struct Vectors* console_reader(struct Vectors* v, struct RingInfo* ri){
    struct Vector* v_new = NULL;
    printf("Input your Vector coordinates:\n");
    char x[20];
    char y[20];
    char z[20];
    if (scanf("%s%s%s", x, y, z) != 3){
        printf("Input in correct format\n");
        return NULL;
    }
    void* v_x = ri->readval(x);
    void* v_y = ri->readval(y);
    void* v_z = ri->readval(z);
    if (v_x == NULL || v_y == NULL || v_z == NULL){
        printf("Invalid format\n");
        return NULL;
    }
    v->len += 1;
    v->vectors = realloc(v->vectors, v->len * sizeof(void*));
    v_new = malloc(sizeof(struct Vector));
    v_new->x = v_x;
    v_new->y = v_y;
    v_new->z = v_z;
    v->vectors[v->len - 1] = v_new;
    return 0;
}


struct Vectors* file_reader(char* name, struct Vectors* v, struct RingInfo* ri){
    struct Vector* v_new = NULL;
    FILE *file = fopen(name, "r");
    char x[20];
    char y[20];
    char z[20];
    while(1){
        if (feof(file)){
            return 0;
        }
        if (fscanf(file, "%s%s%s", x, y, z) != 3){
            printf("Invalid format\n");
            return 0;
        }
        void* v_x = ri->readval(x);
        void* v_y = ri->readval(y);
        void* v_z = ri->readval(z);
        if (v_x == NULL || v_y == NULL || v_z == NULL){
            printf("Invalid format\n");
            return NULL;
        }
        v->len += 1;
        v->vectors = realloc(v->vectors, v->len * sizeof(void*));
        v_new = malloc(sizeof(struct Vector));
        v_new->x = v_x;
        v_new->y = v_y;
        v_new->z = v_z;
        v->vectors[v->len - 1] = v_new;
    }
    return 0;
}
