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

        void SortedPrint() const;
};

#endif /* ORDIND_H */