//
//  tests.c
//  lab1
//
//  Created by Максим Шелестов on 15.05.2023.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Vector.h"
#include "Int_Vector.h"
#include "Double_Vector.h"
#include "tests.h"

// int tests
struct v_test_int{
    int x;
    int y;
    int z;
};

struct vects_sum_int{
    struct v_test_int a;
    struct v_test_int b;
    struct v_test_int c;
};

struct vects_sum_int test_sum_int[] = {
    {{1, 2, 3}, {0, -1, 2}, {1, 1, 5}},
    {{-1, 0, -12}, {1, 42, 32}, {0, 42, 20}},
    {{-1, -2, -3}, {1, 2, 3}, {0, 0, 0}},
    {{-987, -12, 345}, {123, 421, 26}, {-864, 409, 371}},
};

struct vects_mult_int{
    struct v_test_int a;
    struct v_test_int b;
    int res;
};

struct vects_mult_int test_mult_int[] = {
    {{-1, 2, 3}, {-3, 0, 1}, 6},
    {{912, -12, -134}, {11, 2345, -156}, 2796},
    {{0, -1, -1}, {1, 1, 1}, -2},
    {{0, 0, 0}, {1, 2, -3}, 0},
};

int tests_sum_int(struct RingInfo* ri){
    struct Vector a, b;
    for (int i = 0; i < 4; ++i){
        a.x = &test_sum_int[i].a.x;
        a.y = &test_sum_int[i].a.y;
        a.z = &test_sum_int[i].a.z;
        b.x = &test_sum_int[i].b.x;
        b.y = &test_sum_int[i].b.y;
        b.z = &test_sum_int[i].b.z;
        struct Vector *ans = sum(&a, &b, ri);
        if (*(int*) ans->x != test_sum_int[i].c.x || *(int*) ans->y != test_sum_int[i].c.y || *(int*) ans->z != test_sum_int[i].c.z){
            printf("Test sum int %d failed", i);
            exit(1);
        }
    }
    printf("All sum int tests passed\n");
    return 0;
};

int tests_mult_int(struct RingInfo* ri){
    struct Vector a, b;
    for (int i = 0; i < 4; ++i){
        a.x = &test_mult_int[i].a.x;
        a.y = &test_mult_int[i].a.y;
        a.z = &test_mult_int[i].a.z;
        b.x = &test_mult_int[i].b.x;
        b.y = &test_mult_int[i].b.y;
        b.z = &test_mult_int[i].b.z;
        void* ans = mult(&a, &b, ri);
        if (*(int*) ans != test_mult_int[i].res){
            printf("Test mult int %d failed", i);
            exit(1);
        }
    }
    printf("All mult int tests passed\n");
    return 0;
}

//double tests
struct v_test_double{
    double x;
    double y;
    double z;
};

struct vects_sum_double{
    struct v_test_double a;
    struct v_test_double b;
    struct v_test_double c;
};

struct vects_sum_double test_sum_double[] = {
    {{1.23, -1.11, 0.9}, {2.3, 4.126, -0.34}, {3.53, 3.016, 0.56}},
    {{12.8392, 1.2, 0.11}, {-0.876, 0.2, 1}, {11.9632, 1.4, 1.11}},
    {{1.2, 3.3, 0}, {0, 0, 1.23}, {1.2, 3.3, 1.23}},
    {{-3.5, 1.2, 2}, {2, 3, 4}, {-1.5, 4.2, 6}},
};

struct vects_mult_double{
    struct v_test_double a;
    struct v_test_double b;
    double res;
};

struct vects_mult_double test_mult_double[] = {
    {{-1.12, 2.1, 3.8}, {-3.01, 0.9, 1}, 9.0612},
    {{1.21, 0, 0}, {0.1, 1, -2}, 0.121},
    {{0.9, 0, 0.1}, {1, 1, 1}, 1},
    {{0.3, 0.1, 1}, {1.23, 1.2, 3.4}, 3.889},
};

int tests_sum_double(struct RingInfo* ri){
    struct Vector a, b;
    for (int i = 0; i < 4; ++i){
        a.x = &test_sum_double[i].a.x;
        a.y = &test_sum_double[i].a.y;
        a.z = &test_sum_double[i].a.z;
        b.x = &test_sum_double[i].b.x;
        b.y = &test_sum_double[i].b.y;
        b.z = &test_sum_double[i].b.z;
        struct Vector *ans = sum(&a, &b, ri);
        if (*(double*) ans->x != test_sum_double[i].c.x || *(double*) ans->y != test_sum_double[i].c.y || *(double*) ans->z != test_sum_double[i].c.z){
            printf("Test sum double %d failed\n", i);
            exit(1);
        }
    }
    printf("All sum double tests passed\n");
    return 0;
};

int tests_mult_double(struct RingInfo* ri){
    struct Vector a, b;
    for (int i = 0; i < 4; ++i){
        a.x = &test_mult_double[i].a.x;
        a.y = &test_mult_double[i].a.y;
        a.z = &test_mult_double[i].a.z;
        b.x = &test_mult_double[i].b.x;
        b.y = &test_mult_double[i].b.y;
        b.z = &test_mult_double[i].b.z;
        void* ans = mult(&a, &b, ri);
        //printf("%.6f\n", *(double*) ans);
        //printf("%.6f\n", test_mult_double[i].res);
        if (*(double*) ans != test_mult_double[i].res){
            printf("Test mult double %d failed\n", i);
            exit(1);
        }
    }
    printf("All mult double tests passed\n");
    return 0;
}
