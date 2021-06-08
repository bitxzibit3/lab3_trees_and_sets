//
// Created by Timur on 07.06.2021.
//

#include "mySet.h"


template<class T>
mySet<T>::mySet()
{
    this->tree = new BinaryTree<T> ();
}

template<class T>
mySet<T>::mySet(BinaryTree<T> *tree)
{
    this->tree = tree->CopyTree();
}

template<class T>
bool mySet<T>::ElemIn(T value)
{
    return this->tree->HasElem(value);
}

template<class T>
void mySet<T>::Insert(T value)
{
    if (!this->ElemIn(value))
        this->tree->Insert(value);
}

template<class T>
void mySet<T>::Print()
{
    if (!this->Capacity())
    {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    this->tree->PrintKLR(this->GetTreeRoot());
    cout << "]" << endl;
}

template<class T>
mySet<T>::mySet(mySet<T> *set)
{
    this->tree = set->tree->CopyTree();
}

template<class T>
Node<T> *mySet<T>::GetTreeRoot() {
    return tree->GetRoot();
}

template<class T>
BinaryTree<T> *mySet<T>::GetTree()
{
    return this->tree;
}

template<class T>
size_t mySet<T>::Capacity()
{
    return this->tree->Capacity();
}

template<class T>
bool mySet<T>::IsSubSet(mySet<T> *set)
{
    if ((!this) && (set))
        return false;
    if (!set)
        return true;
    std::queue<Node<T> *> nodes;
    nodes.push (set->GetTreeRoot());
    while (!nodes.empty())
    {
        Node<T> *last = nodes.front();
        nodes.pop();
        if (last->GetLeft())
            nodes.push (last->GetLeft());
        if (last->GetRight())
            nodes.push (last->GetRight());
        if (!this->ElemIn(last->GetValue()))
            return false;
    }
    return true;
}

template<class T>
bool mySet<T>::IsEqual(mySet<T> *set)
{
    return (this->IsSubSet(set) && set->IsSubSet(this));
}

template<class T>
void mySet<T>::Delete(T value)
{
    this->tree->Delete(value);
}

template<class T>
void mySet<T>::DeleteSet()
{
    this->tree->DeleteTree ();
}


template<class T>
mySet<T> *merge (mySet<T> *first, mySet<T> *second)
{
    if (first->Capacity() == 0)
        return new mySet<T> (second);
    if (second->Capacity() == 0)
        return new mySet<T> (first);
    mySet<T> *ans = new mySet<T> (first);
    std::queue<Node<T> *> nodes;
    nodes.push (second->GetTreeRoot());
    while (!nodes.empty())
    {
        Node<T> *last = nodes.front();
        nodes.pop();
        if (last->GetLeft())
            nodes.push (last->GetLeft());
        if (last->GetRight())
            nodes.push (last->GetRight());
        ans->Insert(last->GetValue());
    }
    return ans;
}

template<class T>
mySet<T> *intersect(mySet<T> *first, mySet<T> *second)
{
    if (first->Capacity() * second->Capacity() == 0)
        return new mySet<T> ();
    mySet<T> *ans = new mySet<T>();
    std::queue<Node<T> *> nodes;
    if (!first)
        return NULL;
    nodes.push(first->GetTreeRoot());
    while (!nodes.empty())
    {
        Node<T> *last = nodes.front();
        nodes.pop();
        if (last->GetLeft())
            nodes.push (last->GetLeft());
        if (last->GetRight())
            nodes.push (last->GetRight());
        if (second->GetTree()->Find(last->GetValue()))
            ans->Insert(last->GetValue());
    }
    return ans;
}

template<class T>
mySet<T> *subtraction(mySet<T> *first, mySet<T> *second)
{
    if (first->Capacity() == 0)
        return new mySet<T> ();
    if (second->Capacity() == 0)
        return new mySet<T> (first);
    mySet<T> *ans = new mySet<T>(first);
    std::queue <Node<T> *> nodes;
    nodes.push(second->GetTreeRoot());
    while (!nodes.empty())
    {
        Node<T> *last = nodes.front();
        nodes.pop();
        if (last->GetLeft())
            nodes.push (last->GetLeft());
        if (last->GetRight())
            nodes.push (last->GetRight());
        if (ans->ElemIn(last->GetValue()))
            ans->Delete(last->GetValue());
    }
    return ans;
}

template<class T>
mySet<T> *map (mySet<T> *set, T(*foo)(T))
{
    return new mySet<T> (map(set->GetTree(), foo));
}

template<class T>
mySet<T> *where (mySet<T> *set, bool (*foo)(T))
{
    return new mySet<T> (where(set->GetTree(), foo));
}

template<class T>
T reduce(mySet<T> *set, T (*foo)(T, T), T first_value)
{
    return reduce (set->GetTree(), foo, first_value);
}
