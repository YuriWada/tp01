#include "../include/aux.hpp"
#include "../include/memlog.hpp"

/**
 * StringLength:
 * Calculates the length of a string excluding the null terminator ('\0').
 */
int Aux::StringLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0') {
        // Calculates without the last element '\0'
        ++length;
    }
    return length;
}

/**
 * CustomMin:
 * Returns the smaller of two integers.
 */
int Aux::CustomMin(int a, int b) {
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
 * CompareByName:
 * Compares 'Pessoa' objects based on the 'name' field.
 */
bool Aux::CompareByName(const Pessoa& a, const Pessoa& b)
{
    return a.GetName() < b.GetName();
}

/**
 * CompareByID:
 * Compares 'Pessoa' objects based on the 'ID' field.
 */
bool Aux::CompareByID(const Pessoa& a, const Pessoa& b)
{
    return a.GetID() < b.GetID();
}

/**
 * CompareByEnd:
 * Compares 'Pessoa' objects based on the 'end' field.
 */
bool Aux::CompareByEnd(const Pessoa& a, const Pessoa& b)
{
    return a.GetEnd() < b.GetEnd();
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
