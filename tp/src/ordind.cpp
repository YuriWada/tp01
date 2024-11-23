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

    // Primeira linha: número de colunas
    std::getline(file, line);
    _keys = std::stoi(line);

    std::string temp = "";
    _columns = new std::string[_keys];
    for (size_t i = 0; i < _keys; ++i)
    {
        std::getline(file, line);
        for (size_t j = 0; j < line.length(); ++j)
        {
            if (line[j] == ',')
            {
                _columns[i] = temp;
                temp = "";
                break;
            }
            else temp += line[j];
        }
    }

    // Sexta linha: número de linhas de dados
    std::getline(file, line);
    _fileLines = std::stoi(line);

    // Alocar memória para os dados
    _elements = new Pessoa[_fileLines];

    // Linhas de dados (a partir da 7ª linha)
    for (int i = 0; i < _fileLines; ++i)
    {
        std::getline(file, line);
        std::stringstream ss(line);

        std::string name, id, address, payload;
        std::getline(ss, name, ',');
        std::getline(ss, id, ',');
        std::getline(ss, address, ',');
        std::getline(ss, payload, ',');

        _elements[i] = Pessoa(name, id, address, payload);
    }

    file.close();
}

void OrdInd::SortedPrint() const
{
    int i;
    for (i = 0; i < _fileLines; ++i)
    {
        std::cout << _elements[i].GetName() << ","
                  << _elements[i].GetID() << ","
                  << _elements[i].GetEnd() << ","
                  << _elements[i].GetOthers()
                  << std::endl;
    }
}