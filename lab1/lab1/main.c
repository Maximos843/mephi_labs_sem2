//
//  main.c
//  lab1
//
//  Created by Максим Шелестов on 13.04.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "Int_Vector.h"
#include "RingInfo.h"
#include "Vector.h"
#include "Double_Vector.h"
#include "menu.h"
#include "tests.h"

int main() {
    struct RingInfo* ri;
    int x;
    printf("Choose the type:\n1-Integer\n2-Double\n");
    scanf("%d", &x);
    if (x == 1){
        ri = Create(sizeof(int), &int_sum, &int_mult, &str_toint, &int_new, &int_tostr);
        tests_sum_int(ri);
        tests_mult_int(ri);
        console(ri);
    }
    else if (x == 2){
        ri = Create(sizeof(double), &double_sum, &double_mult, &str_todouble, &double_new, &double_tostr);
        tests_mult_double(ri);
        tests_sum_double(ri);
        console(ri);
    }
    else{
        printf("Wrong args\n");
    }
    return 0;
}
