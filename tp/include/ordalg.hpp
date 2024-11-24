#ifndef ORDALG_H
#define ORDALG_H

#include "pessoa.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class OrdAlg
{
    private:
        Pessoa * _elements;
        int _fileLines;

    public:
        // Constructor
        OrdAlg(Pessoa * elements, int fileLines) : _elements(elements), _fileLines(fileLines) {}

        // Destructor
        //~OrdAlg() { if(_elements) delete[] _elements; }

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

        // Heapsort functions
        void Heapify(int n, int i, bool (*compare)(const Pessoa&, const Pessoa&));
        void Heapsort(bool (*compare)(const Pessoa&, const Pessoa&));


        Pessoa * GetElements() { return _elements; }
};

#endif /* ORDALG_H */