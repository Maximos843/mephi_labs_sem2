//
//  Double_Vector.c
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "Double_Vector.h"

//void* str_toint(char*);
 
void* double_new(void* ptr){
    double* ans = malloc(sizeof(double));
    *ans = *(double*) ptr;
    return (void*) ans;
}

void* double_mult(void* el1, void* el2){
    double* ans = malloc(sizeof(double));
    *ans = (*(double*) el1) * (*(double*) el2);
    return (void*) ans;
}

void* double_sum(void* el1, void* el2){
    double* ans = malloc(sizeof(double));
    *ans = *(double*) el1 + *(double*) el2;
    return (void*) ans;
}

char* double_tostr(void* v){
    char* ans = calloc(1, 20);
    double* i = (double*)v;
    snprintf(ans, 20, "%.6g", *i);
    return ans;
}

void* str_todouble(char* s){
    char* ptr = NULL;
    double ans = strtod(s, &ptr);
    if (ptr == NULL || *ptr != '\0'){
        return NULL;
    }
    double tmp = (double) ans;
    return double_new((void*) &tmp);
}
