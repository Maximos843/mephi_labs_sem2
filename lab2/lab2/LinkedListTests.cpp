//
//  LinkedListTests.cpp
//  lab2
//
//  Created by Максим Шелестов on 23.05.2023.
//

#include "LinkedListTests.hpp"
#include <iostream>
#include "LinkedList.h"

//SubList

void ListGetFirst_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    if (tmp->GetFirst() != 1){
        printf("Test with GetFirst falied\n");
        return;
    }
    printf("Test with GetFirst passed\n");
    return;
}

void ListGetLast_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    if (tmp->GetLast() != 5){
        printf("Test with GetLast falied\n");
        return;
    }
    printf("Test with GetLast passed\n");
    return;
}

void ListGetLength_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    if (tmp->GetLength() != 5){
        printf("Test with GetLength falied\n");
        return;
    }
    printf("Test with GetLength passed\n");
    return;
}

void ListGet_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    for (int i = 0; i < 5; ++i){
        if (tmp->Get(i) != i + 1){
            printf("Test %d with Get failed\n", i);
            return;
        }
    }
    printf("All Tests with Get passed\n");
    return;
}

void InsertAt_test(){
    int a[] = {1, 2, 3, 4, 5, 6};
    LinkedList<int>* tmp = new LinkedList<int>(a, 6);
    tmp->InsertAt(7, 4);
    if (tmp->Get(5) != 7){
        printf("Test with InsertAt failed\n");
        return;
    }
    printf("All Tests with InsertAt passed\n");
    return;
}

void SubList_test(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList<int>* tmp = new LinkedList<int>(a, 10);
    LinkedList<int>* tmp2 = tmp->GetSubList(2, 5);
    for (int i = 0; i < 3; ++i){
        if (tmp2->Get(i) != i + 3){
            printf("Test %d with SubList failed\n", i);
            return;
        }
    }
    printf("All Tests with SubList passed\n");
    return;
}

void checker2(){
    printf("Get\n");
    ListGet_test();
    printf("GetFirst\n");
    ListGetFirst_test();
    printf("GetLast\n");
    ListGetLast_test();
    printf("InsertAt\n");
    InsertAt_test();
    printf("GetSize\n");
    ListGetLength_test();
    printf("GetSubList\n");
    SubList_test();
}
