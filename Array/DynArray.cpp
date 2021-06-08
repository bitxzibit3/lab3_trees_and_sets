//
// Created by Timur on 30.03.2021.
//

#include <iostream>
#include "DynArray.h"

template<class T>
void DArray<T>::append(T value)
{
    size++;
    data = (T *)realloc (data, size * sizeof(T));
    data[size - 1] = value;
}

template<class T>
T DArray<T>::get_i(size_t index) {
    return *(data + index);
}

template<class T>
size_t DArray<T>::get_size() {
    return size;
}

template<class T>
DArray<T>::DArray(T *d, size_t size1) {
    if (this->size  == 0)
        this->data = (T* )calloc (size1, sizeof (T));
    else
        this->data = (T* )realloc (this->data, size1 * sizeof (T));
    for (size_t i = 0; i < size1; i++)
        *(this->data + i) = *(d + i);
    this->size = size1;
}

template<class T>
DArray<T>::DArray(DArray<T> * Array) {
    size = Array->get_size();
    data = (T *) calloc (size, sizeof(T));
    for (size_t i = 0; i < size; i++)
        data[i] = Array->get_i(i);
}

template<class T>
void DArray<T>::set_i(size_t index, T value) {
    this->data[index] = value;
}

template<class T>
void DArray<T>::resize(size_t new_size) {
    if (this->size != 0)
        this->data = (T *) realloc (this->data, new_size * sizeof (T));
    else
        this->data = (T *) calloc (new_size, sizeof(T));
    this->size = new_size;
}
template<class T>
DArray<T>::~DArray()
{
    free(data);
}

template<class T>
DArray<T> *DArray<T>::CopyDArray() {
    DArray<T> *ans = (DArray *) calloc (1, sizeof(DArray<T>));
    ans->size = this->size;
    ans->data = (T *) calloc (ans->size, sizeof(T));
    for (size_t i = 0; i < ans->size; i++)
        *(ans->data + i) = *(this->data + i);
    return ans;
}

template<class T>
void DArray<T>::prepend(T value)
{
    this->resize (this->size + 1);
    if (this->size == 1)
    {
        *(this->data) = value;
        return;
    }
    for (size_t i = this->size - 1; i > 0; i--)
    {
        *(data + i) = *(data + i - 1);
    }
    *(data) = value;
}

template<class T>
void DArray<T>::insert(T value, size_t index) {
    resize (this->size + 1);
    for (size_t i = this->size - 1; i > index; i--)
    {
        *(data + i) = *(data + i - 1);
    }
    *(data + index) = value;
}

template<class T>
void DArray<T>::printArr() {
    for (size_t i = 0; i < this->size; i++)
        std::cout << *(data + i) << " ";
    std::cout << std::endl;
}

template<class T>
DArray<T> *DArray<T>::concat(DArray<T> *first, DArray<T> *second) {
    DArray<T> *ans = (DArray<T> *) calloc (1, sizeof (DArray<T>));
    ans->resize(first->size + second->size);
    for (size_t i = 0; i < first->size; i++)
        *(ans->data + i) = *(first->data + i);
    for (size_t i = first->size; i < ans->size; i++)
        *(ans->data + i) = *(second->data + i - first->size);
    return ans;
}

template<class T>
DArray<T> *DArray<T>::GetSubArray(size_t begin, size_t end) //TODO Не работает
{
    T *new_data = (T* ) calloc (end - begin + 1, sizeof(T));
    for (size_t i = begin; i <= end; i++)
        *(new_data + i - begin) = this->get_i(i);
    DArray<T> *ans = new DArray<T> (new_data, end - begin + 1);
    free (new_data);
    return ans;
}

template<class T>
DArray<T>::DArray()
{
    this->data = NULL;
    this->size = 0;
}

template<class T>
void DArray<T>::Delete()
{
    free (this->data);
    free (this);
};

