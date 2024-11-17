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

bool OrdInd::CompareByName(const Pessoa& a, const Pessoa& b)
{
    return a.GetName() < b.GetName();
}

bool OrdInd::CompareByCPF(const Pessoa& a, const Pessoa& b)
{
    return a.GetCPF() < b.GetCPF();
}

bool OrdInd::CompareByEnd(const Pessoa& a, const Pessoa& b)
{
    return a.GetEnd() < b.GetEnd();
}

void OrdInd::Swap(Pessoa& a, Pessoa& b)
{
    Pessoa temp = a;
    a = b;
    b = temp;
}

int OrdInd::Partition(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&)) {
    Pessoa pivot = _elements[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (compare(_elements[j], pivot)) {
            ++i;
            Swap(_elements[i], _elements[j]);
        }
    }

    Swap(_elements[i + 1], _elements[high]);
    return i + 1;
}

void OrdInd::Quicksort(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&)) {
    if (low < high) {
        int pivotIndex = Partition(low, high, compare);
        Quicksort(low, pivotIndex - 1, compare);
        Quicksort(pivotIndex + 1, high, compare);
    }
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