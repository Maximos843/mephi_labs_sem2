//
//  menu.c
//  lab1
//
//  Created by Максим Шелестов on 09.05.2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RingInfo.h"
#include "Vector.h"
#include "Int_Vector.h"
#include "Double_Vector.h"
#include "Double_Vector.h"
#include "menu.h"


int console(struct RingInfo* ri){
    int mode;
    printf("Choose mode to input your vectors:\n1 - File\n2 - Console input\n");
    scanf("%d", &mode);
    struct Vectors* vects = NULL;
    if (mode == 2){
        vects = calloc(1, sizeof(struct Vector));
        vects->len = 0;
        vects->ringinfo = ri;
        printf("Enter the firct vector\n");
        console_reader(vects, ri);
        printf("Enter the second vector\n");
        console_reader(vects, ri);
    }
    else if (mode == 1){
        vects = calloc(1, sizeof(struct Vector));
        vects->len = 0;
        vects->ringinfo = ri;
        char name[50];
        printf("Enter path to file\n");
        scanf("%s", name);
        file_reader(name, vects, ri);
    }
    while (1){
        printf("\n");
        printf("Choose operation with vectors:\n1 - Scalar_mult\n2 - Sum\n3 - exit\n4 - print_all\n");
        int type;
        scanf("%d", &type);
        void* ans;
        struct Vector* res_vector;
        switch(type){
            case 1:
                ans = mult(vects->vectors[0], vects->vectors[1], ri);
                char* res = ri->tostr(ans);
                printf("%s\n", res);
                free(res);
                free(ans);
                break;
            case 2:
                res_vector = sum(vects->vectors[0], vects->vectors[1], ri);
                print_one(res_vector, ri);
                free(res_vector);
                break;
            case 3:
                //struct RingInfo* ring1;
                //ring1 = Create(sizeof(int), &sum_int, &mult_int,  &new_int,
                  //          &str_to_val_int, &val_to_str_int);
                exit(0);
            case 4:
                print_all(vects);
                break;
            default:
                break;
        }
    }
    return 0;
}
