#include "../include/ordind.hpp"
#include "pessoa.cpp"

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

    // Count columns (keys) of file
    if (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string column;

        while (std::getline(ss, column, ','))
        {
            _keys++;
        }
    }

    // alocate memory
    _elements = new Pessoa[_fileLines];

    // go back to file begining
    file.clear();
    file.seekg(0, std::ios::beg);

    int i=0;
    while(std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string name, cpf, end, others;

        std::getline(ss, name, ',');
        std::getline(ss, cpf, ',');
        std::getline(ss, end, ',');
        std::getline(ss, others, ',');

        Pessoa pessoa(name, cpf, end, others);
        _elements[i++] = pessoa;
    }

    file.close();
}

void OrdInd::SortedPrint() const
{
    int i;
    for (i = 0; i < _fileLines; ++i)
    {
        std::cout << _elements[i].GetName() << " "
                  << _elements[i].GetCPF() << " "
                  << _elements[i].GetEnd() << " "
                  << _elements[i].GetOthers()
                  << std::endl;
    }
}