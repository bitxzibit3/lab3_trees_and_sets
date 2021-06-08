//
// Created by Timur on 08.06.2021.
//

#ifndef LAB3_MENU_H
#define LAB3_MENU_H
#include "mySet.h"

int variable_choise();

const char *MSGS[] = {"0. Quit", "1. Merge sets", "2. Intersect sets", "3. Set subtraction", "4. Map",
                      "5. Where", "6. Reduce", "7. Check subset", "8. Check element",
                      "9. Equation of two sets"};

const size_t MSGS_SIZE = (sizeof(MSGS) / sizeof(MSGS[0]));

template<class T>
T mult7 (T);

template <class T>
T sum (T, T);

template <class T>
bool foo20 (T);

int stoi (char *);

int choise();

void dialog (int);

template <class T>
mySet<T> *EnterSet ();

mySet<int> *GenerateSet (size_t);

#endif //LAB3_MENU_H
