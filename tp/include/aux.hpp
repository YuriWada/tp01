#ifndef AUX_H
#define AUX_H

#include "pessoa.hpp"
#include <string>

class Aux
{
    public:
        // Calculates the string length
        static int StringLength(const char* str);

        static int CustomMin(int a, int b);

        static bool CustomCompareStrings(const char* str1, const char* str2);

        // Compare functions
        static bool CompareByName(const Pessoa& a, const Pessoa& b);
        static bool CompareByID(const Pessoa& a, const Pessoa& b);
        static bool CompareByEnd(const Pessoa& a, const Pessoa& b);

        // Swap function
        static void Swap(Pessoa& a, Pessoa& b);
};

#endif /* AUX_H */