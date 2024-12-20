#ifndef ORDALG_H
#define ORDALG_H

#include "pessoa.hpp"
#include "aux.hpp"

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

        // Quicksort functions
        void Partition(int low, int high, int* i, int* j, bool (*compare)(const Pessoa&, const Pessoa&));
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