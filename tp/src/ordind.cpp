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

int OrdInd::Partition(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&))
{
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

void OrdInd::Quicksort(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&))
{
    if (low < high) {
        int pivotIndex = Partition(low, high, compare);
        Quicksort(low, pivotIndex - 1, compare);
        Quicksort(pivotIndex + 1, high, compare);
    }
}

void OrdInd::Bubblesort(bool (*compare)(const Pessoa&, const Pessoa&))
{
    for (int i = 0; i < _fileLines - 1; ++i) {
        for (int j = 0; j < _fileLines - i - 1; ++j) {
            if (!compare(_elements[j], _elements[j + 1])) {
                Swap(_elements[j], _elements[j + 1]);
            }
        }
    }
}

void OrdInd::Merge(int left, int mid, int right, bool (*compare)(const Pessoa&, const Pessoa&))
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temp arrays
    Pessoa* leftArray = new Pessoa[n1];
    Pessoa* rightArray = new Pessoa[n2];

    // copy data to temp array
    for (int i = 0; i < n1; ++i)
        leftArray[i] = _elements[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = _elements[mid + 1 + j];

    // merge temp arrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(leftArray[i], rightArray[j])) {
            _elements[k] = leftArray[i];
            i++;
        } else {
            _elements[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // copy remain elements
    while (i < n1) {
        _elements[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        _elements[k] = rightArray[j];
        j++;
        k++;
    }

    // free
    delete[] leftArray;
    delete[] rightArray;
}

void OrdInd::Mergesort(int left, int right, bool (*compare)(const Pessoa&, const Pessoa&))
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        OrdInd::Mergesort(left, mid, compare);
        OrdInd::Mergesort(mid + 1, right, compare);

        // merge sorted subarrays
        OrdInd::Merge(left, mid, right, compare);
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