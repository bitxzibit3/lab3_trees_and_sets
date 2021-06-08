//
// Created by Timur on 08.06.2021.
//

#include "menu.h"
#include <time.h>

template<class T>
T mult7 (T value)
{
    return value * 7;
}

template<class T>
bool foo20 (T t)
{
    return (t < 20);
}

template<class T>
T sum (T a, T b)
{
    return a + b;
}

int stoi (char *str)
{
    int ans = 0, i = 0;
    int sign = (str[0] == '-') ? -1: (((str[0] >= '0') && (str[0] <= '9')) ? 1: 0);
    if (sign == 0)
        return -1;
    while (str[i] != '\0')
    {
        if ((str[i] <= '9') && (str[i] >= '0'))
            ans = 10 * ans + str[i] - '0';
        else
            return -1;
        i++;
    }
    return sign * ans;
}

int variable_choise()
{
    while (1)
    {
        std::cout << "What type of data do you wanna use?" << std::endl << "1. Integer" << std::endl << "2. Float" << std::endl;
        char *c = new char (100);
        std::cin >> c;
        int ans = stoi (c);
        delete c;
        if ((ans > 0) && (ans < 3))
            return ans;
        else
            std::cout << "You entered a wrong number, please, try again!" << std::endl;
    }
}

int choise_()
{
    while (1) {
        char *ch = new char (100);
        std::cout << "What do you wanna do?" << std::endl;
        for (size_t i = 0; i < MSGS_SIZE; i++)
            std::cout << MSGS[i] << std::endl;
        std::cin >> ch;
        int choise = stoi(ch);
        delete ch;
        if ((choise >= 0) && (choise < MSGS_SIZE))
            return choise;
        else
            std::cout << "You entered a wrong number, please, try again!" << std::endl;
    }
}


template <class T>
int dialog()
{
    int choise = choise_();
    while (1)
        switch (choise)
        {
            case(0):
            {
                std::cout << "Good Bye!" << std::endl;
                return 0;
            }
            case(1):
            {
                mySet<T> *first = EnterSet<T>();
                mySet<T> *second = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                std::cout << "You entered B: ";
                second->Print();
                std::cout << "Merge of A and B: ";
                mySet<T> *ans = merge(first, second);
                ans->Print();
                first->DeleteSet();
                second->DeleteSet();
                ans->DeleteSet();
                choise = choise_();
                break;
            }
            case(2):
            {
                mySet<T> *first = EnterSet<T>();
                mySet<T> *second = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                std::cout << "You entered B: ";
                second->Print();
                std::cout << "Intersection of sets A and B: ";
                mySet<T> *ans = intersect(first, second);
                ans->Print();
                first->DeleteSet();
                second->DeleteSet();
                ans->DeleteSet();
                choise = choise_();
                break;
            }
            case(3):
            {
                mySet<T> *first = EnterSet<T>();
                mySet<T> *second = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                std::cout << "You entered B: ";
                second->Print();
                std::cout << "Subtraction of sets A and B: ";
                mySet<T> *ans = subtraction(first, second);
                ans->Print();
                first->DeleteSet();
                second->DeleteSet();
                ans->DeleteSet();
                choise = choise_();
                break;
            }
            case(4):
            {
                mySet<T> *first = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                cout << "All elements will be product on 7" << endl;
                mySet<T> *ans = map(first, mult7);
                ans->Print();
                first->DeleteSet();
                ans->DeleteSet();
                choise = choise_();
                break;
            }
            case(5):
            {
                mySet<T> *first = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                cout << "Elements that lower then 20:" << endl;
                mySet<T> *ans = where(first, foo20);
                ans->Print();
                first->DeleteSet();
                ans->DeleteSet();
                choise = choise_();
                break;
            }
            case(6):
            {
                mySet<T> *first = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                cout << "Sum of elements:" << reduce (first, sum, (T)0.) << endl;
                first->DeleteSet();
                choise = choise_();
                break;
            }
            case(7):
            {
                mySet<T> *first = EnterSet<T>();
                mySet<T> *second = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                std::cout << "You entered B: ";
                second->Print();
                if (first->IsSubSet(second))
                    cout << "Set A contain set B" << endl;
                else
                    cout << "Set A doesnt contain set B" << endl;
                first->DeleteSet();
                second->DeleteSet();
                choise = choise_();
                break;
            }
            case(8):
            {
                mySet<T> *first = EnterSet<T>();
                T value;
                cout << "Enter value for check:";
                cin >> value;
                if (first->ElemIn(value))
                    cout << "Set A has element " << value << endl;
                else
                    cout << "Set A has not element " << value << endl;
                first->DeleteSet();
                choise = choise_();
                break;
            }
            case (10):
            {
                return variable_choise();
            }
            case (9):
            {
                mySet<T> *first = EnterSet<T>();
                mySet<T> *second = EnterSet<T>();
                std::cout << "You entered A: ";
                first->Print();
                std::cout << "You entered B: ";
                second->Print();
                if (first->IsEqual(second))
                    cout << "A == B" << endl;
                else
                    cout << "A != B" << endl;
                first->DeleteSet();
                second->DeleteSet();
                choise = choise_();
                break;
            }
        }
}


template <class T>
mySet<T> *EnterSet ()
{
    while (1) 
    {
        cout << "Enter set dimension:";
        char *str = new char(100);
        cin >> str;
        int dim = stoi(str);
        if (dim < 0)
            cout << "Wrong dimension, try again!" << endl;
        else
        {
            mySet<T> *ans = new mySet<T> ();
            for (int i = 0; i < dim; i++)
            {
                T value;
                cin >> value;
                ans->Insert(value);
            }
            return ans;
        }
    }
}

mySet<int> *GenerateSet (size_t size)
{
    srand (time(NULL));
    mySet<int> *ans = new mySet<int> ();
    for (size_t i = 0; i < size; i++)
    {
        int value = rand() % (2 * size) - size;
        ans->Insert(value);
    }
    return ans;
}