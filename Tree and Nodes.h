//
// Created by Timur on 03.06.2021.
//

#ifndef LAB3_TREE_AND_NODES_H
#define LAB3_TREE_AND_NODES_H
#include "Array/ArrSeq.h"
#include <queue>

using namespace std;

template <class T>
class Node
{
private:
    T value;
    size_t height;
    Node<T> *left, *right;
public:
    void SetLeft(Node<T> *);
    void SetRight(Node<T> *);
    void SetValue (T);
    Node(T);
    Node (T, size_t);
    size_t Capacity (Node<T> *);
    T GetValue ();
    void DeleteNode();
    Node<T> *GetLeft ();
    Node<T> *GetRight();
    size_t GetHeight();
    void SetHeight(size_t);
    bool IsEqualNode (Node<T> *);
    Node<T> *GetParent (T);
};

template<class T>
class BinaryTree
{
private:
    Node<T> *root;
    Node<T> *Find (T, Node<T> *);
    void Insert (T, Node<T> *, size_t);
    void PrintKRL (Node<T> *);
    void PrintLRK (Node<T> *);
    void PrintLKR (Node<T> *);
    void PrintRKL (Node<T> *);
    void PrintRLK (Node<T> *);
public:
    BinaryTree();
    Node<T> *GetRoot ();
    BinaryTree (Node<T> *);
    Node<T> *CopyNode (Node<T> *, size_t);
    Node<T> *Find (T);
    bool HasElem (T);
    void Insert (T);
    void Delete (T);
    void DeleteTree ();
    size_t Capacity ();
    bool IsSubTree (BinaryTree<T> *);
    void PrintKLR (Node<T> *);
    BinaryTree<T> *CopyTree ();
    BinaryTree<T> *GetSubTree (T);
    void FixPrint ();
    Node<T> *GetParent (T);
};

template <class P, class T>
BinaryTree<T> *map (BinaryTree<T> *, T(*)(T));

template <class T>
BinaryTree<T> *where (BinaryTree<T> *, bool (*)(T));

template <class T>
T reduce (BinaryTree<T> *, T(*)(T, T), T);

#endif //LAB3_TREE_AND_NODES_H
