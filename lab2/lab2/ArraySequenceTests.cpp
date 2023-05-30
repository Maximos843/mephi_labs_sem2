//
//  ArraySequenceTests.cpp
//  lab2
//
//  Created by Максим Шелестов on 23.05.2023.
//

#include "ArraySequenceTests.hpp"
#include "ArraySequence.h"
#include <iostream>

//insert at

void ArrGetFirst_test(){
    int a[] = {1, 2, 3, 4, 5};
    ArraySequence<int> tmp = ArraySequence<int>(a, 5);
    if (tmp.GetFirst() != 1){
        printf("Test with GetFirst failed\n");
        return;
    }
    printf("All Test with GetFirst passed\n");
    return;
}

void ArrGetLast_test(){
    int a[] = {1, 2, 3, 4, 5};
    ArraySequence<int> tmp = ArraySequence<int>(a, 5);
    if (tmp.GetLast() != 5){
        printf("Test with GetLast failed\n");
        return;
    }
    printf("All Test with GetLast passed\n");
    return;
}

void ArrGet_test(){
    int a[] = {1, 2, 3, 4, 5};
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    for (int i = 0; i < 5; ++i){
        if (tmp->Get(i) != i + 1){
            printf("Test %d with Get failed\n", i);
            return;
        }
    }
    printf("All Tests with Get passed\n");
    return;
}

void ArrAppend_test(){
    int a[] = {1, 2, 3, 4, 5};
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    tmp->Append(6);
    tmp->Append(7);
    if (tmp->GetLength() != 7){
        printf("Test with Append failed\n");
        return;
    }
    for (int i = 0; i < 7; ++i){
        if (tmp->Get(i) != i + 1){
            printf("Test %d with Append failed\n", i);
            return;
        }
    }
    printf("All Tests with Append passed\n");
    return;
}

void ArrPrepend_test(){
    int a[] = {2, 3, 4, 5, 6};
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    tmp->Prepend(1);
    tmp->Prepend(0);
    if (tmp->GetLength() != 7){
        printf("Test with Prepend failed\n");
        return;
    }
    for (int i = 0; i < 7; ++i){
        if (tmp->Get(i) != i){
            printf("Test %d with Prepend failed\n", i);
            return;
        }
    }
    printf("All Tests with Append passed\n");
    return;
}

void ArrInsertAt_test(){
    int a[] = {2, 3, 4, 5, 6};
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    tmp->InsertAt(7, 3);
    if (tmp->Get(3) != 7){
        printf("Test with InsertAt failed\n");
        return;
    }
    printf("Test with InsertAt passed\n");
    return;
}

void checker3(){
    printf("Get\n");
    ArrGet_test();
    printf("GetFirst\n");
    ArrGetFirst_test();
    printf("GetLast\n");
    ArrGetLast_test();
    printf("InsertAt\n");
    ArrInsertAt_test();
    printf("Append\n");
    ArrAppend_test();
    printf("Prepend\n");
    ArrPrepend_test();
}
