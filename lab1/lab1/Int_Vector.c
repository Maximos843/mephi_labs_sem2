//
//  Int_Vector.c
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "Int_Vector.h"

//void* str_toint(char*);
 
void* int_new(void* ptr){
    int* ans = malloc(sizeof(int));
    *ans = *(int*) ptr;
    return (void*) ans;
}

void* int_mult(void* el1, void* el2){
    int* ans = malloc(sizeof(int));
    *ans = (*(int*) el1) * (*(int*) el2);
    return (void*) ans;
}

void* int_sum(void* el1, void* el2){
    int* ans = malloc(sizeof(int));
    *ans = *(int*) el1 + *(int*) el2;
    return (void*) ans;
}

char* int_tostr(void* elem){
    char* ans = calloc(1, 20);
    int* i = (int*) elem;
    snprintf(ans, 20, "%d", *i);
    return ans;
}

void* str_toint(char* s){
    char* ptr = NULL;
    long ans = strtol(s, &ptr, 10);
    if (ptr == NULL || *ptr != '\0'){
        return NULL;
    }
    int tmp = (int) ans;
    return int_new((void*)&tmp);
}
