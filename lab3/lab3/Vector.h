//
//  Vector.h
//  lab3
//
//  Created by Максим Шелестов on 28.05.2023.
//

#ifndef Vector_h
#define Vector_h

#include "ArraySequence.h"
#include "IndexError.h"
#include "math.h"

template <class T>
class Vector {
    int dimension;
    ArraySequence<T>* data;
    size_t elem_size = sizeof(T);
public:
    Vector(){};
    
    Vector(const ArraySequence<T>& array){
        data = new ArraySequence<T>(array);
        dimension = data->GetLength();
    };
    
    Vector(Vector<T>& vector){
        this->data = vector.data;
        this->dimension = vector.data->GetLength();
    };
    
    Vector(T* array, int dim){
        dimension = dim;
        data = new ArraySequence<T>(array, dim);
    };
    
    Vector<T>* sumVectors(Vector<T> vector){
        if (vector.elem_size != this->elem_size){
            return nullptr;
        }
        ArraySequence<T>* tmp;
        T* buf;
        if(vector.dimension <= this->dimension){
            buf = new T[this->dimension];
            for (int i = 0; i < dimension; ++i){
                buf[i] = data->Get(i);
            }
            tmp = new ArraySequence<T>(buf, this->dimension);
        }
        else{
            buf = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i){
                buf[i] = vector.data->Get(i);
            }
            tmp = new ArraySequence<T>(buf, vector.dimension);
        }
        for (int i = 0; i < std::min(this->dimension, vector.dimension); ++i){
            tmp->InsertAt(data->Get(i) + vector.data->Get(i), i);
        }
        Vector<T>* res = new Vector<T>(*tmp);
        return res;
    };
    
    Vector<T>* multVectors(Vector<T> vector){
        if (vector.elem_size != this->elem_size){
            return nullptr;
        }
        ArraySequence<T>* tmp;
        T* buf;
        if(vector.dimension <= this->dimension){
            buf = new T[this->dimension];
            for (int i = 0; i < dimension; ++i){
                buf[i] = data->Get(i);
            }
            tmp = new ArraySequence<T>(buf, this->dimension);
        }
        else{
            buf = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i){
                buf[i] = vector.data->Get(i);
            }
            tmp = new ArraySequence<T>(buf, vector.dimension);
        }
        for (int i = 0; i < std::min(this->dimension, vector.dimension); ++i){
            tmp->InsertAt(data->Get(i) * vector.data->Get(i), i);
        }
        Vector<T>* res = new Vector<T>(*tmp);
        return res;
    };
    
    Vector<T>* Scalarmult(double n){
        T* a = new T[this->dimension];
        ArraySequence<T>* tmp = new ArraySequence<T>(a, dimension);
        for (int i = 0; i < dimension; ++i){
            tmp->InsertAt(data->Get(i) * n, i);
        }
        Vector<T>* vector = new Vector<T>(*tmp);
        return vector;
    };
    
    double GetNorm(){
        double ans = 0;
        for (int i = 0; i < this->dimension; ++i){
            ans += this->data->Get(i) * this->data->Get(i);
        }
        return sqrt(ans);
    };
    
    friend std::ostream& operator<<(std::ostream &out, Vector &vector){
        out<<"{";
        for (int i = 0; i < vector.dimension - 1; ++i) {
            out<<vector.data->Get(i)<<", ";
        }
        out<<vector.data->Get(vector.dimension-1)<<"}"<<std::endl;
        return out;
    };
    
    T Get_elem(int i){
        return data->Get(i);
    };

};


#endif /* Vector_h */
