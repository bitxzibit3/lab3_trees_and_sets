//
// Created by Timur on 03.06.2021.
//

#include "Tree and Nodes.h"

using namespace std;

template<class T>
T Node<T>::GetValue() {
    return this->value;
}

template<class T>
Node<T> *Node<T>::GetLeft() {
    return this->left;
}

template<class T>
Node<T> *Node<T>::GetRight() {
    return this->right;
}

template<class T>
Node<T>::Node(T value)
{
    this->value = value;
    this->height = 0;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
void Node<T>::SetLeft(Node<T> *newleft)
{
    delete this->left;
    this->left = newleft;
}

template<class T>
void Node<T>::SetRight(Node<T> *newright)
{
    delete this->right;
    this->right = newright;
}

template<class T>
size_t Node<T>::GetHeight() {
    return this->height;
}

template<class T>
void Node<T>::SetHeight(size_t new_height)
{
    this->height = new_height;
}

template<class T>
Node<T>::Node(T value, size_t height)
{
    this->value = value;
    this->height = height;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
bool Node<T>::IsEqualNode(Node<T> *target)
{
    bool f = true, s = true;
    if (target == NULL)
        return true;
    if (target->GetValue() != this->GetValue())
        return false;
    if (target->GetLeft())
    {
        if (this->GetLeft())
            f = this->GetLeft()->IsEqualNode(target->GetLeft());
        else
            return false;
    }
    if (target->GetRight())
    {
        if (this->GetRight())
            s = this->GetRight()->IsEqualNode(target->GetRight());
        else
            return false;
    }
    return f && s;
}

template<class T>
Node<T> *BinaryTree<T>::Find(T value, Node<T> *start)
{
    if ((start == NULL) || (start->GetValue() == value))
        return start;
    Node<T> *ans;
    if (value < start->GetValue())
        ans = Find (value, start->GetLeft());
    else
        ans = Find (value, start->GetRight());
    return ans;
}

template<class T>
Node<T> *BinaryTree<T>::Find(T value)
{
    return Find (value, this->root);
}

template<class T>
void BinaryTree<T>::Insert(T value)
{
    if (this->root == NULL)
    {
        this->root = new Node<T> (value, 0);
        return;
    }
    Insert(value, this->root, 0);
}

//template<class T>
//void BinaryTree<T>::Delete(T value)
//{
//    Node<T> *target = Find (value);
//    if (target == NULL)
//        return;
//    if ((target->GetLeft() == NULL) && (target->GetRight() == NULL))
//    {
//        delete target;
//        return;
//    }
//}


template<class T>
BinaryTree<T> *BinaryTree<T>::CopyTree()
{
    return new BinaryTree<T> (CopyNode(this->root, 0));
}

template<class T>
BinaryTree<T> *BinaryTree<T>::GetSubTree(T start_value)
{
    Node<T> *start_node = Find(start_value);
    if (start_node == NULL)
    {
        //May be other exception
        return NULL;
    }
    return new BinaryTree<T> (CopyNode (start_node, start_node->GetHeight()));

}

template<class T>
Node<T> *BinaryTree<T>::CopyNode(Node<T> *target ,size_t level)
{
    if (target == NULL)
        return NULL;
    Node<T> *node = new Node<T> (target->GetValue(), target->GetHeight() - level);
    node->SetLeft (CopyNode (target->GetLeft(), level));
    node->SetRight (CopyNode (target->GetRight(), level));
    return node;
}

template<class T>
BinaryTree<T>::BinaryTree(Node<T> *root)
{
    this->root = root;
}


template<class T>
void BinaryTree<T>::Insert(T value, Node<T> *start, size_t current_height)
{
    if (start->GetValue() == value)
        return;
    if (value < start->GetValue())
    {
        if (start->GetLeft() == NULL)
        {
            start->SetLeft(new Node<T> (value, current_height + 1));
            return;
        }
        Insert (value, start->GetLeft(), current_height + 1);
    }
    else if (value > start->GetValue())
    {
        if (start->GetRight() == NULL)
        {
            start->SetRight(new Node<T> (value, current_height + 1));
            return;
        }
        Insert (value, start->GetRight(), current_height + 1);
    }
}

template<class T>
BinaryTree<T>::BinaryTree()
{
    this->root = NULL;
}

template<class T>
bool BinaryTree<T>::HasElem(T value) {
    if (Find(value) == NULL)
        return false;
    return true;
}

template <class T>
void BinaryTree<T>::PrintKLR (Node <T> *start)
{
    if (start == NULL)
        return;
    cout << start->GetValue() << ";";
    PrintKLR (start->GetLeft());
    PrintKLR (start->GetRight());
}

template <class T>
void BinaryTree<T>::PrintKRL (Node <T> *start)
{
    if (start == NULL)
        return;
    cout << start->GetValue() << ";";
    PrintKRL (start->GetRight());
    PrintKRL (start->GetLeft());
}

template <class T>
void BinaryTree<T>::PrintLRK (Node <T> *start)
{
    if (start == NULL)
        return;
    PrintLRK (start->GetLeft());
    PrintLRK (start->GetRight());
    cout << start->GetValue() << ";";
}

template <class T>
void BinaryTree<T>::PrintLKR (Node <T> *start)
{
    if (start == NULL)
        return;
    PrintLKR (start->GetLeft());
    cout << start->GetValue() << ";";
    PrintLKR (start->GetRight());
}

template <class T>
void BinaryTree<T>::PrintRKL (Node <T> *start)
{
    if (start == NULL)
        return;
    PrintRKL (start->GetRight());
    cout << start->GetValue() << ";";
    PrintRKL (start->GetLeft());
}

template <class T>
void BinaryTree<T>::PrintRLK (Node <T> *start)
{
    if (start == NULL)
        return;
    PrintRLK (start->GetRight());
    PrintRLK (start->GetLeft());
    cout << start->GetValue() << ";";
}

template<class T>
void BinaryTree<T>::FixPrint()
{
    if (this->root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    cout << "Enter traverse order: KLR, KRL, LKP, LRK, RKL, RLK:";
    char *format = new char (10);
    cin >> format;
    switch (format[0]) {
        case ('K'): {
            if ((format[1] == 'L') && (format[2] == 'R'))
                this->PrintKLR(this->root);
            else if ((format[1] == 'R') && (format[2] == 'L'))
                this->PrintKRL(this->root);
            else {
                cout << "Wrong format" << endl;
                return;
            }
            break;
        }
        case ('L'): {
            if ((format[1] == 'K') && (format[2] == 'R'))
                PrintLKR(this->root);
            else if ((format[1] == 'R') && (format[2] == 'K'))
                PrintLRK(this->root);
            else {
                cout << "Wrong format" << endl;
                return;
            }
            break;
        }
        case ('R'): {
            if ((format[1] == 'K') && (format[2] == 'L'))
                PrintRKL(this->root);
            else if ((format[1] == 'L') && (format[2] == 'K'))
                PrintRLK(this->root);
            else {
                cout << "Wrong format" << endl;
                return;
            }
            break;
        }
        default:
        {
            cout << "Wrong format here" << endl;
            return;
        }
    }
    cout << endl;
}

template<class T>
Node<T> *BinaryTree<T>::GetRoot() {
    return this->root;
}

template<class T>
bool BinaryTree<T>::IsSubTree(BinaryTree<T> *sub_tree)
{
    Node<T> *sub_root = this->Find(sub_tree->GetRoot()->GetValue());
    if (!sub_root)
        return false;
    return sub_root->IsEqualNode(sub_tree->GetRoot());
}

template<class T>
size_t BinaryTree<T>::Capacity()
{
    if (!this->root)
        return 0;
    return 1 + this->root->Capacity(this->root);
}

template<class T>
void BinaryTree<T>::Delete(T value)
{
    if (!this->root)
        return;
    if (this->root->GetValue() == value)
    {
        Node<T> *for_delete = this->root;
        if ((!this->root->GetLeft()) && (!this->root->GetRight()))
        {
            this->root = NULL;
            return;
        }
        else if ((!this->root->GetLeft()) && (this->root->GetRight()))
        {
            this->root = this->root->GetRight();
            return;
        }
        else if ((this->root->GetLeft()) && (!this->root->GetRight()))
        {
            this->root = this->root->GetLeft();
            return;
        }
        else
        {
            Node<T> *min = this->root->GetRight();
            while (min->GetLeft())
                min = min->GetLeft();
            T val = min->GetValue();
            this->Delete(min->GetValue());
            this->root->SetValue(val);
            return;
        }
    }
    Node<T> *for_delete = this->Find(value);
    if (!for_delete)
    {
        return;
    }
    Node<T> *parent = this->GetParent(value);
    if ((!for_delete->GetLeft()) && (!for_delete->GetRight()))
    {
        if (parent->GetLeft() == for_delete)
            parent->SetLeft(NULL);
        else
            parent->SetRight(NULL);
        return;
    }
    else if ((!for_delete->GetLeft()) && (for_delete->GetRight()))
    {
        if (parent->GetLeft() == for_delete)
            parent->SetLeft(for_delete->GetRight());
        else
            parent->SetRight(for_delete->GetRight());
        return;
    }
    else if ((for_delete->GetLeft()) && (!for_delete->GetRight()))
    {
        if (parent->GetLeft() == for_delete)
            parent->SetLeft(for_delete->GetLeft());
        else
            parent->SetRight(for_delete->GetLeft());
        return;
    }
    else
    {
        Node<T> *min = for_delete->GetRight();
        while (min->GetLeft())
            min = min->GetLeft();
        T val = min->GetValue();
        this->Delete(min->GetValue());
        for_delete->SetValue(val);
        return;
    }
}

template<class T>
Node<T> *BinaryTree<T>::GetParent(T target)
{
    if (!this->HasElem(target))
        return NULL;
    if (this->root->GetValue() == target)
        return NULL;
    return this->root->GetParent(target);
}

template<class T>
void BinaryTree<T>::DeleteTree()
{
    if (this->root)
        this->root->DeleteNode();
}

template<class T>
size_t Node<T>::Capacity(Node<T> *start)
{
    size_t ans = 0;
    if (start == NULL)
        return 0;
    if (start->GetLeft())
        ans += (1 + Capacity(start->GetLeft()));
    if (start->GetRight())
        ans += (1 + Capacity(start->GetRight()));
    return ans;
}

template<class T>
Node<T> *Node<T>::GetParent(T target)
{
    if ((this->GetLeft()) && (this->GetLeft()->GetValue() == target))
        return this;
    else if ((this->GetRight()) && (this->GetRight()->GetValue() == target))
        return this;
    else if (target > this->GetValue())
    {
        if (this->GetRight() == NULL)
            return NULL;
        return this->GetRight()->GetParent(target);
    }
    else
    {
        if (this->GetLeft() == NULL)
            return NULL;
        return this->GetLeft()->GetParent(target);
    }
}

template<class T>
void Node<T>::SetValue(T value)
{
    if (!this)
        return;
    this->value = value;
}

template<class T>
void Node<T>::DeleteNode()
{
    if (this->GetLeft())
        this->GetLeft()->DeleteNode();
    if (this->GetRight())
        this->GetRight()->DeleteNode();
    delete this;
}


template<class T>
BinaryTree<T> *map(BinaryTree<T> *tree, T (*foo)(T))
{
    if ((tree == NULL) || (tree->GetRoot() == NULL))
        return NULL;
    BinaryTree<T> *ans = new BinaryTree<T> ();
    std::queue <Node<T> *> nodes;
    nodes.push(tree->GetRoot());
    while (!nodes.empty())
    {
        Node<T> *last_elem = nodes.front();
        nodes.pop();
        if (last_elem->GetLeft() != NULL)
            nodes.push (last_elem->GetLeft());
        if (last_elem->GetRight() != NULL)
            nodes.push (last_elem->GetRight());
        ans->Insert(foo(last_elem->GetValue()));
    }
    return ans;
}

template <class T>
BinaryTree<T> *where (BinaryTree<T> *tree, bool (*foo)(T))
{
    if ((tree == NULL) || (tree->GetRoot() == NULL))
        return NULL;
    BinaryTree<T> *ans = new BinaryTree<T> ();
    std::queue <Node<T> *> nodes;
    nodes.push(tree->GetRoot());
    while (!nodes.empty())
    {
        Node<T> *last_elem = nodes.front();
        nodes.pop();
        if (last_elem->GetLeft() != NULL)
            nodes.push (last_elem->GetLeft());
        if (last_elem->GetRight() != NULL)
            nodes.push (last_elem->GetRight());
        if (foo(last_elem->GetValue()))
            ans->Insert(last_elem->GetValue());
    }
    return ans;
}

template <class T>
T reduce (BinaryTree<T> *tree, T (*foo)(T,T), T first_value)
{
    ArrSeq<T> *array = new ArrSeq<T> ();
    std::queue <Node<T> *> nodes;
    nodes.push(tree->GetRoot());
    while (!nodes.empty())
    {
        Node<T> *last_elem = nodes.front();
        nodes.pop();
        if (last_elem->GetLeft() != NULL)
            nodes.push (last_elem->GetLeft());
        if (last_elem->GetRight() != NULL)
            nodes.push (last_elem->GetRight());
        array->Append(last_elem->GetValue());
    }
    T answer = first_value;
    size_t checker = 0;
    for (size_t i = 0; i < array->GetSize(); i++)
        answer = foo (answer, array->Get(i));
    array->Delete();
    return answer;
}