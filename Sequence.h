//
// Created by Timur on 25.04.2021.
//

#ifndef LAB2_VECTOR_SEQUENCE_H
#define LAB2_VECTOR_SEQUENCE_H

#include <stdlib.h>

template <class T>
class Sequence
{
public:
    virtual T GetFirst () = 0;
    virtual T GetLast () = 0;
    virtual T Get (size_t, size_t *) = 0;
    virtual size_t GetSize () = 0;
    virtual Sequence<T> *GetSubSeq (size_t, size_t, size_t *) = 0;
    virtual void Append (T) = 0;
    virtual void Set (size_t, T, size_t *) = 0;
    virtual void Prepend (T) = 0;
    virtual void Resize (size_t) = 0;
    virtual void Insert (T, size_t, size_t *) = 0;
    virtual void Print () = 0;
    virtual Sequence<T> *Concat (Sequence<T> *) = 0;
    virtual void Delete () = 0;
    virtual Sequence<T> *Copy() = 0;
};

#endif //LAB2_VECTOR_SEQUENCE_H
