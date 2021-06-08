//
// Created by Timur on 28.04.2021.
//

#ifndef LAB2_VECTOR_ARRSEQ_H
#define LAB2_VECTOR_ARRSEQ_H
#include "../Sequence.h"
#include "DynArray.h"
#include "DynArray.cpp"

template <class T>
class ArrSeq: public Sequence <T>
{
protected:
    DArray<T> *array;
public:
    ArrSeq ();
    ArrSeq (DArray<T> *);
    ArrSeq (ArrSeq<T> *);
    ArrSeq (T *, size_t);
    T GetFirst ();
    T GetLast ();
    T Get (size_t, size_t *);
    T Get (size_t);
    void Set (size_t, T, size_t *);
    void Resize (size_t);
    size_t GetSize ();
    Sequence<T> *GetSubSeq (size_t, size_t, size_t *);
    void Append (T);
    void Prepend (T);
    void Insert (T, size_t, size_t *);
    Sequence<T> *Concat (Sequence<T> *);
    void Print ();
    Sequence<T> *Copy ();
    void Delete ();
};



#endif //LAB2_VECTOR_ARRSEQ_H
