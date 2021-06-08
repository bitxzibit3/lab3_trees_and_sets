#include <iostream>
#include "Tree and Nodes.cpp"
#include "../Lab2_vector/Array/ArrSeq.cpp"
#include "mySet.cpp"
#include "menu.cpp"
#include <fstream>

int VAR = variable_choise();

int main()
{
    while (1) {
        switch (VAR) {
            case(0):
            {
                return 0;
            }
            case (1): {
                VAR = dialog<int>();
                break;
            }
            case (2): {
                VAR = dialog<float>();
                break;
            }
        }
    }
}