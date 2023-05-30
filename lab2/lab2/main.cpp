//
//  main.cpp
//  lab2
//
//  Created by Максим Шелестов on 15.05.2023.
//

#include <iostream>

#include "DynamicArrayTests.h"
#include "LinkedListTests.hpp"
#include "ArraySequenceTests.hpp"
#include "LinkedListSequenceTests.hpp"

#include "Sequence.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"

int main() {
    printf("Dynamic Array Tests\n");
    printf("\n");
    checker1();
    printf("---------------------\n");
    printf("Linked List Tests\n");
    printf("\n");
    checker2();
    printf("---------------------\n");
    printf("ArraySequence Tests\n");
    printf("\n");
    checker3();
    printf("---------------------\n");
    printf("LinkedListSequence Tests\n");
    printf("\n");
    checker4();
    printf("\n");
    return 0;
}
