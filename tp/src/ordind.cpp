#include "../include/ordind.hpp"

void OrdInd::ReadFile()
{
    std::ifstream file(this->_fileName);
    if (!file.is_open())
    {
        std::cerr << "Erro na leitura do arquivo: " << this->_fileName << std::endl;
        return;
    }

    std::string line;
    // Count lines of file
    while (std::getline(file, line))
    {
        ++this->_fileLines;
    }

    // alocate memory
    _elements = new std::string[_fileLines];

    // go back to file begining
    file.clear();
    file.seekg(0, std::ios::beg);

    int i=0;
    while(std::getline(file, line))
    {
        _elements[i++] = line;
    }

    file.close();
}

void OrdInd::SortedPrint() const
{
    int i;
    for (i = 0; i < _fileLines; ++i)
    {
        std::cout << _elements[i] << std::endl;
    }
}