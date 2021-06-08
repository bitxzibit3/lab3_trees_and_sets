//
// Created by Timur on 07.06.2021.
//

#ifndef LAB3_MYSET_H
#define LAB3_MYSET_H

#include "Tree and Nodes.h"


template <class T>
class mySet
{
private:
    BinaryTree<T> *tree;
public:
    mySet();
    mySet (BinaryTree<T> *);
    mySet (mySet<T> *);
    bool ElemIn (T);
    void Insert (T);
    void Print ();
    void Delete (T);
    void DeleteSet();
    BinaryTree<T> *GetTree ();
    Node<T> *GetTreeRoot ();
    bool IsSubSet (mySet<T> *);
    size_t Capacity ();
    bool IsEqual (mySet <T> *);
};

template<class T>
mySet<T> *merge (mySet<T> *, mySet<T> *);

template<class T>
mySet<T> *intersect (mySet<T> *, mySet<T> *);

template<class T>
mySet<T> *subtraction (mySet<T> *, mySet<T> *);

template<class T>
mySet<T> *map (mySet<T> *, T(*)(T));

template<class T>
mySet<T> *where (mySet<T> *, bool (*)(T));

template<class T>
T reduce (mySet<T> *, T(*)(T, T), T);

#endif //LAB3_MYSET_H
