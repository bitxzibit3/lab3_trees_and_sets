//
// Created by Timur on 30.03.2021.
//

#ifndef LAB2_VECTOR_DYNARRAY_H
#define LAB2_VECTOR_DYNARRAY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

template <class T> class DArray
{
protected:
    T *data = NULL;
    size_t size;
public:
    DArray ();
    DArray (T*, size_t);
    DArray (DArray<T> *);
    void append(T);
    void prepend (T);
    void insert (T, size_t);
    T get_i (size_t);
    void set_i (size_t, T);
    size_t get_size();
    void resize(size_t);
    DArray<T> *CopyDArray ();
    void printArr ();
    DArray<T> *GetSubArray (size_t, size_t);
    DArray<T> *concat (DArray<T> *, DArray<T> *);
    ~DArray();
    void Delete();
};


#endif //LAB2_VECTOR_DYNARRAY_H
