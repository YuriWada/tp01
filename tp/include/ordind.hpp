#ifndef ORDIND_H
#define ORDIND_H

#include <iostream>
#include <string>
#include <fstream>

class OrdInd
{
    private:
        std::string _fileName;
        int _fileLines;
        std::string * _elements;

    public:
        // Constructor
        OrdInd(): _fileName("teste.csv"), _fileLines(0), _elements(nullptr) {};

        // Destructor
        ~OrdInd() { if(_elements) delete[] _elements; };

        void ReadFile();

        void SortedPrint() const;
};

#endif /* ORDIND_H */