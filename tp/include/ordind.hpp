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
        std::string * _columns;
        Pessoa * _elements;

    public:
        // Constructor
        OrdInd(): _fileName("cad.r1000.p1000.xcsv"), _fileLines(0), _keys(0), _columns(nullptr), _elements(nullptr) {};

        // Destructor
        ~OrdInd() { if(_elements) delete[] _elements; if(_columns) delete[] _columns; };

        void ReadFile();

        // Compare functions
        static bool CompareByName(const Pessoa& a, const Pessoa& b);
        static bool CompareByID(const Pessoa& a, const Pessoa& b);
        static bool CompareByEnd(const Pessoa& a, const Pessoa& b);

        // Swap function
        void Swap(Pessoa& a, Pessoa& b);

        // Quicksort functions
        int Partition(int low, int high, bool(*compare)(const Pessoa&, const Pessoa&));
        void Quicksort(int low, int high, bool(*compare)(const Pessoa&, const Pessoa&));

        // Bubblesort function
        void Bubblesort(bool (*compare)(const Pessoa&, const Pessoa&));

        // Mergesort functions
        void Merge(int left, int mid, int right, bool (*compare)(const Pessoa&, const Pessoa&));
        void Mergesort(int left, int right, bool (*compare)(const Pessoa&, const Pessoa&));

        int GetLines() { return _fileLines; };

        // Print the sorted table
        void SortedPrint() const;
};

#endif /* ORDIND_H */