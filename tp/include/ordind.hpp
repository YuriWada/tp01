#ifndef ORDIND_H
#define ORDIND_H

#include "pessoa.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class OrdInd
{
    private:
        std::string _fileName;
        int _fileLines;
        int _keys;
        std::string ** _elements;
        std::string * _columns;
        int _namei;
        int _cpfi;
        int _endi;

    public:
        // Constructor
        OrdInd(): _fileName("teste.csv"), 
                  _fileLines(0), 
                  _keys(1), 
                  _elements(nullptr), 
                  _columns(nullptr), 
                  _namei(0), 
                  _cpfi(1), 
                  _endi(2) 
                  {};

        // Destructor
        ~OrdInd();

        int my_strcmp(const char *str1, const char *str2);
        void ReadFile();

        void find_index();

        // Compare functions
        int GetNameIndex() { return _namei; };
        int GetCPFIndex() { return _cpfi; };
        int GetEndIndex() { return _endi; };

        // Swap function
        template <typename T>
        void Swap(T& a, T& b);

        // Quicksort functions
        int Partition(int low, int high, int columnIndex);
        void Quicksort(int low, int high, int columnIndex);

        // Bubblesort function
        void Bubblesort(int columnIndex);

        // Mergesort functions
        void Merge(int left, int mid, int right, int columnIndex);
        void Mergesort(int left, int right, int columnIndex);

        int GetLines() { return _fileLines; };

        // Print the sorted table
        void SortedPrint() const;
};

#endif /* ORDIND_H */