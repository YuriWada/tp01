#include "../include/ordind.hpp"
#include "pessoa.cpp"

OrdInd::~OrdInd()
{
    if (_elements) {
        for (size_t i = 0; i < _fileLines; ++i) {
            delete[] _elements[i];
        }
        delete[] _elements;
    }
    
    delete[] _columns;
}


int OrdInd::my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    // return the difference between the chars (zero if equals)
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void OrdInd::ReadFile()
{
    std::ifstream file(this->_fileName);
    if (!file.is_open())
    {
        std::cerr << "Erro na leitura do arquivo: " << this->_fileName << std::endl;
        return;
    }

    std::string line;

    // Contar linhas do arquivo (excluindo cabeçalho)
    while (std::getline(file, line))
    {
        ++_fileLines;
    }

    if (_fileLines == 0)
    {
        std::cerr << "O arquivo está vazio ou não contém dados válidos." << std::endl;
        return;
    }

    _fileLines--; // Excluir a linha do cabeçalho

    // Reiniciar o stream para voltar ao início do arquivo
    file.clear();
    file.seekg(0, std::ios::beg);

    // Extrair colunas (cabeçalhos)
    if (std::getline(file, line))
    {
         for (size_t i = 0; i < line.length(); ++i)
        {
            if (line[i] == ',') _keys++;
        }

        int k = 0;
        std::string temp = "";
        _columns = new std::string[_keys];
        for (size_t j = 0; j < line.length() - 1; ++j)
        {
            if (line[j] == ',')
            {
                _columns[k] = temp;
                temp = "";
                k++;
            }
            else temp += line[j];
        }
        _columns[k] = temp; // Add the last column
    }

    // Alocar memória para os elementos
    _elements = new std::string*[_fileLines];
    for (size_t l = 0; l < _fileLines; ++l)
    {
        _elements[l] = new std::string[_keys];
    }

    // Salvar os elementos das linhas
    size_t w = 0;
    while (std::getline(file, line))
    {
        size_t k = 0;
        std::string temp;
        for (char c : line)
        {
            if (c == ',')
            {
                _elements[w][k++] = temp;
                temp.clear();
            }
            else
            {
                temp += c;
            }
        }
        _elements[w][k] = temp; // Última coluna
        ++w;
    }

    file.close();
}


void OrdInd::find_index()
{
    for (size_t i = 0; i < _keys; i++)
    {
        if(my_strcmp(_columns[i].c_str(), "Nome") == 0) _namei = i;
        else if(my_strcmp(_columns[i].c_str(), "CPF") == 0) _cpfi = i;
        else if(my_strcmp(_columns[i].c_str(), "End") == 0) _endi = i;
    }
}

template <typename T>
void OrdInd::Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int OrdInd::Partition(int low, int high, int columnIndex)
{
    std::string* pivot = _elements[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (_elements[j][columnIndex] < pivot[columnIndex]) // Index-based comparison
        {
            ++i;
            Swap(_elements[i], _elements[j]);
        }
    }

    Swap(_elements[i + 1], _elements[high]);
    return i + 1;
}


void OrdInd::Quicksort(int low, int high, int columnIndex)
{
    if (low < high)
    {
        int pivotIndex = Partition(low, high, columnIndex);
        Quicksort(low, pivotIndex - 1, columnIndex);
        Quicksort(pivotIndex + 1, high, columnIndex);
    }
}


void OrdInd::Bubblesort(int columnIndex)
{
    for (int i = 0; i < _fileLines - 1; ++i)
    {
        for (int j = 0; j < _fileLines - i - 1; ++j)
        {
            if (_elements[j][columnIndex] > _elements[j + 1][columnIndex]) // Index-based comparison
            {
                Swap(_elements[j], _elements[j + 1]);
            }
        }
    }
}


void OrdInd::Merge(int left, int mid, int right, int columnIndex)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temp arrays
    std::string** leftArray = new std::string*[n1];
    std::string** rightArray = new std::string*[n2];

    // Copy the temp arrays
    for (int i = 0; i < n1; ++i)
        leftArray[i] = _elements[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = _elements[mid + 1 + j];

    // Merge temp arrays to original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i][columnIndex] <= rightArray[j][columnIndex]) // Index-based comparison
        {
            _elements[k] = leftArray[i];
            i++;
        }
        else
        {
            _elements[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        _elements[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        _elements[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


void OrdInd::Mergesort(int left, int right, int columnIndex)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        Mergesort(left, mid, columnIndex);
        Mergesort(mid + 1, right, columnIndex);

        // Mesclar os subarrays ordenados
        Merge(left, mid, right, columnIndex);
    }
}


void OrdInd::SortedPrint() const
{
    for (int i = 0; i < _fileLines; ++i)
    {
        for (int j = 0; j < _keys; ++j)
        {
            std::cout << _elements[i][j];
            if (j < _keys - 1) 
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
