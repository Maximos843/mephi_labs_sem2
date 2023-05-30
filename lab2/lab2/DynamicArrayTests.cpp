//
//  DynamicArrayTests.cpp
//  lab2
//
//  Created by Максим Шелестов on 23.05.2023.
//

#include <iostream>
#include "Sequence.h"
#include "DynamicArray.h"
#include "DynamicArrayTests.h"

void Get_test(){
    int a[] = {1, 2, 3, 4, 5};
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    for (int i = 0; i < 5; ++i){
        if (tmp->Get(i) != a[i]){
            printf("Test %d Get failed\n", i);
            return;
        }
    }
    printf("All test with Get passed\n");
    return;
}

void GetSize_test(){
    int a[] = {1, 1, 1, 1, 1};
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    if (tmp->GetSize() != 5){
        printf("Test with Length failed\n");
        return;
    }
    printf("Test with Length passed\n");
    return;
}

void Set_test(){
    int a[] = {1, 2, 3, 4, 5};
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    for (int i = 0; i < 5; ++i){
        tmp->Set(5 - i, i);
    }
    for (int i = 0; i < 5; ++i){
        if (tmp->Get(i) != 5 - i){
            printf("Test %d with Set falied\n", i);
            return;
        }
    }
    printf("All Tests with Set passed\n");
    return;
}

void Resize_test(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 10);
    tmp->Resize(4);
    if (tmp->GetSize() != 4){
        printf("Test with Resize ans Size failed\n");
        return;
    }
    for (int i = 0; i < 4; ++i){
        if (tmp->Get(i) != i + 1){
            printf("Test with Resize and Get failed\n");
            return;
        }
    }
    tmp->Resize(6);
    if (tmp->GetSize() != 6){
        printf("Test with Resize ans Size failed\n");
        return;
    }
    for (int i = 0; i < 4; ++i){
        if (tmp->Get(i) != i + 1){
            printf("Test with Resize and Get failed\n");
            return;
        }
    }
    printf("All Tests with Resize passed\n");
    return;
}

void checker1(){
    printf("Get\n");
    Get_test();
    printf("Resize\n");
    Resize_test();
    printf("Set\n");
    Set_test();
    printf("GetSize\n");
    GetSize_test();
    return;
}
