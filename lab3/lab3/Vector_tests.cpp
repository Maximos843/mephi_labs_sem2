//
//  Vector_tests.cpp
//  lab3
//
//  Created by Максим Шелестов on 28.05.2023.
//

#include "Vector.h"
#include "Vector_tests.h"
#include "ArraySequence.h"
#include <iostream>

void addVector_test(){
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    Vector<int> vector1 = Vector<int>(a, 3);
    Vector<int> vector2 = Vector<int>(b, 3);
    Vector<int>* vector3 = vector2.sumVectors(vector1);
    if (vector3->Get_elem(0) != 5 || vector3->Get_elem(1) != 7 || vector3->Get_elem(2) != 9){
        std::cout << "Test with addVectors failed\n";
        return;
    }
    std::cout << "Test with addVectors passed\n";
    return;
}

void multVectors_test(){
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    Vector<int> vector1 = Vector<int>(a, 3);
    Vector<int> vector2 = Vector<int>(b, 3);
    Vector<int>* vector3 = vector2.multVectors(vector1);
    if (vector3->Get_elem(0) != 4 || vector3->Get_elem(1) != 10 || vector3->Get_elem(2) != 18){
        std::cout << "Test with multVectors failed\n";
        return;
    }
    std::cout << "Test with multVectors passed\n";
    return;
}

void Scalarmult_test(){
    int a[] = {1, 2, 3};
    Vector<int> vector1 = Vector<int>(a, 3);
    Vector<int>* vector2 = vector1.Scalarmult(7);
    if (vector2->Get_elem(0) != 7 || vector2->Get_elem(1) != 14 || vector2->Get_elem(2) != 21){
        std::cout << "Test with ScalarMult failed\n";
        return;
    }
    std::cout << "Test with ScalarMult passed\n";
    return;
}

void GetNorm_test(){
    int a[] = {4, 2, 4};
    Vector<int> vector1 = Vector<int>(a, 3);
    double res = vector1.GetNorm();
    //std::cout << res << "\n";
    if (res != 6){
        std::cout << "Test with GetNorm failed\n";
        return;
    }
    std::cout << "Test with GetNorm passed\n";
    return;
}

void checker(){
    std::cout << "AddVectors\n";
    addVector_test();
    std::cout << "MultVectors\n";
    multVectors_test();
    std::cout << "ScalarMult\n";
    Scalarmult_test();
    std::cout << "GetNorm\n";
    GetNorm_test();
    return;
}
