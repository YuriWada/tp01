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
        Pessoa * _elements;

    public:
        // Constructor
        OrdInd(): _fileName("teste.csv"), _fileLines(0), _keys(0), _elements(nullptr) {};

        // Destructor
        ~OrdInd() { if(_elements) delete[] _elements; };

        void ReadFile();

        // Compare functions
        static bool CompareByName(const Pessoa& a, const Pessoa& b);
        static bool CompareByCPF(const Pessoa& a, const Pessoa& b);
        static bool CompareByEnd(const Pessoa& a, const Pessoa& b);

        // Swap function
        void Swap(Pessoa& a, Pessoa& b);

        // Quicksort functions
        int Partition(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&));
        void Quicksort(int low, int high, bool(*compare)(const Pessoa&, const Pessoa&));

        int GetLines() { return _fileLines; };

        // Print the sorted table
        void SortedPrint() const;
};

#endif /* ORDIND_H */