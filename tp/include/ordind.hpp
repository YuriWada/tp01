#ifndef ORDIND_H
#define ORDIND_H

#include "pessoa.hpp"
#include "aux.hpp"

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
        OrdInd(char **argv) : _fileName((argv[1] != nullptr) ? argv[1] : ""), _fileLines(0), _keys(0), _columns(nullptr), _elements(nullptr) {}

        // Destructor
        ~OrdInd() { if(_elements) delete[] _elements; if(_columns) delete[] _columns; };

        void ReadFile();

        int GetLines() { return _fileLines; };
        Pessoa * GetElements() { return _elements; };

        void SetElements(Pessoa * elements) { _elements = elements; };

        // Print the sorted table
        void SortedPrint() const;
};

#endif /* ORDIND_H */