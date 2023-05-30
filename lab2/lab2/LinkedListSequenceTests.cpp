//
//  LinkedListSequenceTests.cpp
//  lab2
//
//  Created by Максим Шелестов on 23.05.2023.
//

#include "LinkedListSequenceTests.hpp"
#include "LinkedListSequence.h"

//getfirst, getlast, get, prepend, append, getlength, insert at

void SeqGetFirst_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 5);
    if (tmp->GetFirst() != 1){
        printf("Test with GetFrist failed\n");
        return;
    }
    printf("Test with GetFirst passed\n");
    return;
}

void SeqGetLast_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 5);
    if (tmp->GetLast() != 5){
        printf("Test with GetLast failed\n");
        return;
    }
    printf("Test with GetLast passed\n");
    return;
}

void SeqGet_test(){
    int a[] = {1, 2, 3, 4, 5};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 5);
    if (tmp->Get(2) != 3 || tmp->Get(4) != 5){
        printf("Test with Get failed\n");
        return;
    }
    printf("Test with Get passed\n");
    return;
}

void SeqPrepend_test(){
    int a[] = {1, 2, 3, 4, 5, 6};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 6);
    tmp->Prepend(7);
    tmp->Prepend(8);
    if (tmp->Get(0) != 8 || tmp->Get(1) != 7){
        printf("Test with Prepend failed\n");
        return;
    }
    printf("Test with Prepend passed\n");
    return;
}

void SeqAppend_test(){
    int a[] = {1, 2, 3, 4, 5, 6};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 6);
    tmp->Append(7);
    tmp->Append(8);
    if (tmp->Get(6) != 7 || tmp->Get(7) != 8){
        printf("Test with Append failed\n");
        return;
    }
    printf("Test with Append passed\n");
    return;
}

void SeqGetLength_test(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 7);
    if (tmp->GetLength() != 7){
        printf("Test with GetLength failed\n");
        return;
    }
    printf("Test with GetLength passed\n");
    return;
}

void SeqInsertAt_test(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    LinkedListSequence<int>* tmp = new LinkedListSequence<int>(a, 7);
    tmp->InsertAt(10, 3);
    if (tmp->Get(4) != 10){
        printf("Test with InsertAt failed\n");
        return;
    }
    printf("Test with InsertAt passed\n");
    return;
}

void checker4(){
    printf("Get\n");
    SeqGet_test();
    printf("GetFirst\n");
    SeqGetFirst_test();
    printf("GetLast\n");
    SeqGetLast_test();
    printf("GetLength\n");
    SeqGetLength_test();
    printf("Append\n");
    SeqAppend_test();
    printf("Prepend\n");
    SeqPrepend_test();
    printf("InsertAt\n");
    SeqInsertAt_test();
    return;
}
