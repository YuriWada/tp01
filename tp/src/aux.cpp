#include "../include/aux.hpp"

int Aux::StringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0') {
        // Calculates without the last element '\0'
        ++length;
    }
    return length;
}

int Aux::CustomMin(int a, int b) {
    // Return simple comparison
    return (a < b) ? a : b;
}

/**
 * CustomCompareStrings:
 * A custom string comparison function that compares two strings character by character.
 * It returns true if the first string is lexicographically smaller than the second one.
 */
bool Aux::CustomCompareStrings(const char* str1, const char* str2)
{
    int len1 = Aux::StringLength(str1);
    int len2 = Aux::StringLength(str2);
    int minLen = Aux::CustomMin(len1, len2);

    for (int i = 0; i < minLen; ++i) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        }
    }

    // If all characters are equal, the shorter string is considered smaller.
    return len1 < len2;
}

/**
 * Comparison functions:
 * Used to compare 'Pessoa' objects based on different fields.
 */
bool Aux::CompareByName(const Pessoa& a, const Pessoa& b)
{
    return CustomCompareStrings(a.GetName().c_str(), b.GetName().c_str());
}

bool Aux::CompareByID(const Pessoa& a, const Pessoa& b)
{
    return CustomCompareStrings(a.GetID().c_str(), b.GetID().c_str());
}

bool Aux::CompareByEnd(const Pessoa& a, const Pessoa& b)
{
    return CustomCompareStrings(a.GetEnd().c_str(), b.GetEnd().c_str());
}

/**
 * Swap:
 * Swaps the values of two 'Pessoa' objects.
 */
void Aux::Swap(Pessoa& a, Pessoa& b)
{
    Pessoa temp = a;
    a = b;
    b = temp;
}