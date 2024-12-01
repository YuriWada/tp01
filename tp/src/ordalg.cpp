#include "../include/ordalg.hpp"

/**
 * Custom compare string is a customized
 * strcmp() that takes 2 strings and 
 * compare them char by char
 */
bool OrdAlg::CustomCompareStrings(const char* str1, const char* str2)
{
    int len1 = Aux::StringLength(str1);
    int len2 = Aux::StringLength(str2);
    int minLen = Aux::CustomMin(len1, len2);

    for (int i = 0; i < minLen; ++i) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        }
    }

    // Se todos os caracteres são iguais, a string menor é a menor
    return len1 < len2;
}

// Compare functions 
bool OrdAlg::CompareByName(const Pessoa& a, const Pessoa& b)
{
    return CustomCompareStrings(a.GetName().c_str(), b.GetName().c_str());
}

bool OrdAlg::CompareByID(const Pessoa& a, const Pessoa& b)
{
    return CustomCompareStrings(a.GetID().c_str(), b.GetID().c_str());
}

bool OrdAlg::CompareByEnd(const Pessoa& a, const Pessoa& b)
{
    return CustomCompareStrings(a.GetEnd().c_str(), b.GetEnd().c_str());
}

/**
 * Simples swap function that takes
 * two objects of 'Pessoa' type
 * and swap their places
 */
void OrdAlg::Swap(Pessoa& a, Pessoa& b)
{
    Pessoa temp = a;
    a = b;
    b = temp;
}

void OrdAlg::Partition(int low, int high, int* i, int* j, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    Pessoa pivot = _elements[(low + high) / 2]; // Pivot no meio do intervalo
    *i = low;
    *j = high;

    do 
    {
        // Avança o ponteiro esquerdo enquanto o elemento for menor que o pivot
        while (compare(_elements[*i], pivot)) 
        {
            ++(*i);
        }

        // Regride o ponteiro direito enquanto o elemento for maior que o pivot
        while (compare(pivot, _elements[*j])) 
        {
            --(*j);
        }

        // Troca elementos fora de lugar e ajusta índices
        if (*i <= *j) 
        {
            Swap(_elements[*i], _elements[*j]);
            ++(*i);
            --(*j);
        }

    } while (*i <= *j);
}

void OrdAlg::Quicksort(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    int i, j;
    Partition(low, high, &i, &j, compare); // Ajustado para retornar índices por referência

    // Recursivamente ordena os sub-arrays
    if (low < j) 
    {
        Quicksort(low, j, compare);
    }

    if (i < high) 
    {
        Quicksort(i, high, compare);
    }
}

void OrdAlg::Bubblesort(bool (*compare)(const Pessoa&, const Pessoa&))
{
    for (int i = 0; i < _fileLines - 1; ++i) 
    {
        for (int j = 1; j < _fileLines - i; ++j) 
        {
            if (compare(_elements[j], _elements[j - 1])) 
            {
                Swap(_elements[j - 1], _elements[j]);
            }
        }
    }
}

void OrdAlg::Merge(int left, int mid, int right, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Alocar arrays temporários
    Pessoa* leftArray = new Pessoa[n1];
    Pessoa* rightArray = new Pessoa[n2];

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; ++i) 
    {
        leftArray[i] = _elements[left + i];
    }
    for (int j = 0; j < n2; ++j) 
    {
        rightArray[j] = _elements[mid + 1 + j];
    }

    // Combinar os arrays temporários no array original
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        if (compare(leftArray[i], rightArray[j])) 
        {
            _elements[k++] = leftArray[i++];
        } 
        else 
        {
            _elements[k++] = rightArray[j++];
        }
    }

    // Se ainda houver elementos restantes
    while (i < n1) 
    {
        _elements[k++] = leftArray[i++];
    }
    while (j < n2) 
    {
        _elements[k++] = rightArray[j++];
    }

    // Liberar memória dos arrays temporários
    delete[] leftArray;
    delete[] rightArray;
}

void OrdAlg::Mergesort(int left, int right, bool (*compare)(const Pessoa&, const Pessoa&))
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // Realizar chamadas recursivas
        OrdAlg::Mergesort(left, mid, compare);
        OrdAlg::Mergesort(mid + 1, right, compare);

        // Mesclar subarrays ordenados
        OrdAlg::Merge(left, mid, right, compare);

    }
}


void OrdAlg::Heapify(int n, int i, bool (*compare)(const Pessoa&, const Pessoa&))
{
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    
    int right = 2 * i + 2;   

    if (left < n && !compare(_elements[left], _elements[largest]))
        largest = left;

    if (right < n && !compare(_elements[right], _elements[largest]))
        largest = right;


    if (largest != i)
    {
        Swap(_elements[i], _elements[largest]);

        Heapify(n, largest, compare);
    }
}

void OrdAlg::Heapsort(bool (*compare)(const Pessoa&, const Pessoa&))
{
    int n = _fileLines;

    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(n, i, compare);

    for (int i = n - 1; i > 0; --i)
    {
        Swap(_elements[0], _elements[i]);

        Heapify(i, 0, compare);
    }
}
