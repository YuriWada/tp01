#include "../include/ordind.hpp"
#include "../include/pessoa.hpp"

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
    for (int i = 0; i < _keys; ++i)
    {
        std::getline(file, line);
        for (int j = 0; j < Aux::StringLength(line.c_str()); ++j)
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

    std::string * elements_lines = new std::string[_keys];
    for (int i = 0; i < _fileLines; ++i)
    {
        std::string aux = "";
        int k = 0;
        std::getline(file, line);
        for (int j = 0; j < Aux::StringLength(line.c_str()); ++j)
        {
            if (line[j] == ',')
            {
                elements_lines[k] = aux;
                aux = "";
                k++;
            }
            else aux += line[j];
        }
        elements_lines[k] = aux;

        std::string name = elements_lines[0];
        std::string id = elements_lines[1];
        std::string address = elements_lines[2];
        std::string payload = elements_lines[3];

        _elements[i] = Pessoa(name, id, address, payload);

        // Reset string array
        for (int t = 0; t < _keys; t++)
        {
            elements_lines[t] = "";
        }
    }

    delete[] elements_lines;

    file.close();
}

void OrdInd::SortedPrint() const
{
    std::cout << _keys << std::endl;
    
    int j;
    for (j = 0; j < _keys; j++)
    {
        std::cout << _columns[j] << ",s" << std::endl;
    }
    
    std::cout << _fileLines << std::endl;

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