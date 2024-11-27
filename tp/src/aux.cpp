#include "../include/aux.hpp"

int Aux::StringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

int Aux::CustomMin(int a, int b) {
    return (a < b) ? a : b;
}