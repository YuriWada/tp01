#include "../include/ordalg.hpp"
#include "../include/memlog.hpp"

/**
 * Partition:
 * Partitions the array around a pivot element for the QuickSort algorithm.
 */
void OrdAlg::Partition(int low, int high, int* i, int* j, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    Pessoa pivot = _elements[(low + high) / 2];
    LEMEMLOG((long)&_elements[(low + high) / 2], sizeof(Pessoa), 1);

    *i = low;
    *j = high;

    do 
    {
        while (compare(_elements[*i], pivot)) 
        {
            LEMEMLOG((long)&_elements[*i], sizeof(Pessoa), 1);
            ++(*i);
        }

        while (compare(pivot, _elements[*j])) 
        {
            LEMEMLOG((long)&_elements[*j], sizeof(Pessoa), 1);
            --(*j);
        }

        if (*i <= *j) 
        {
            ESCREVEMEMLOG((long)&_elements[*i], sizeof(Pessoa), 1);
            ESCREVEMEMLOG((long)&_elements[*j], sizeof(Pessoa), 1);
            Aux::Swap(_elements[*i], _elements[*j]);
            ++(*i);
            --(*j);
        }

    } while (*i <= *j);
}

/**
 * Quicksort:
 * Implements the QuickSort algorithm using recursion to sort the elements.
 */
void OrdAlg::Quicksort(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    int i, j;
    Partition(low, high, &i, &j, compare);

    if (low < j) 
    {
        Quicksort(low, j, compare);
    }

    if (i < high) 
    {
        Quicksort(i, high, compare);
    }
}

/**
 * Bubblesort:
 * Implements the Bubble Sort algorithm.
 */
void OrdAlg::Bubblesort(bool (*compare)(const Pessoa&, const Pessoa&))
{
    for (int i = 0; i < _fileLines - 1; ++i) 
    {
        for (int j = 1; j < _fileLines - i; ++j) 
        {
            LEMEMLOG((long)&_elements[j], sizeof(Pessoa), 1);
            LEMEMLOG((long)&_elements[j - 1], sizeof(Pessoa), 1);
            if (compare(_elements[j], _elements[j - 1])) 
            {
                ESCREVEMEMLOG((long)&_elements[j], sizeof(Pessoa), 1);
                ESCREVEMEMLOG((long)&_elements[j - 1], sizeof(Pessoa), 1);
                Aux::Swap(_elements[j - 1], _elements[j]);
            }
        }
    }
}

/**
 * Merge:
 * Merges two sorted subarrays into a single sorted subarray.
 */
void OrdAlg::Merge(int left, int mid, int right, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pessoa* leftArray = new Pessoa[n1];
    Pessoa* rightArray = new Pessoa[n2];

    ESCREVEMEMLOG((long)leftArray, sizeof(Pessoa) * n1, 3);
    ESCREVEMEMLOG((long)rightArray, sizeof(Pessoa) * n2, 3);

    for (int i = 0; i < n1; ++i) 
    {
        leftArray[i] = _elements[left + i];
        LEMEMLOG((long)&_elements[left + i], sizeof(Pessoa), 1);
        ESCREVEMEMLOG((long)&leftArray[i], sizeof(Pessoa), 3);
    }

    for (int j = 0; j < n2; ++j) 
    {
        rightArray[j] = _elements[mid + 1 + j];
        LEMEMLOG((long)&_elements[mid + 1 + j], sizeof(Pessoa), 1);
        ESCREVEMEMLOG((long)&rightArray[j], sizeof(Pessoa), 3);
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        LEMEMLOG((long)&leftArray[i], sizeof(Pessoa), 3);
        LEMEMLOG((long)&rightArray[j], sizeof(Pessoa), 3);
        ESCREVEMEMLOG((long)&_elements[k], sizeof(Pessoa), 1);
        if (compare(leftArray[i], rightArray[j])) 
        {
            _elements[k++] = leftArray[i++];
        } 
        else 
        {
            _elements[k++] = rightArray[j++];
        }
    }

    while (i < n1) 
    {
        LEMEMLOG((long)&leftArray[i], sizeof(Pessoa), 3);
        ESCREVEMEMLOG((long)&_elements[k], sizeof(Pessoa), 1);
        _elements[k++] = leftArray[i++];
    }

    while (j < n2) 
    {
        LEMEMLOG((long)&rightArray[j], sizeof(Pessoa), 3);
        ESCREVEMEMLOG((long)&_elements[k], sizeof(Pessoa), 1);
        _elements[k++] = rightArray[j++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

/**
 * Mergesort:
 * Implements the Merge Sort algorithm.
 */
void OrdAlg::Mergesort(int left, int right, bool (*compare)(const Pessoa&, const Pessoa&))
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        Mergesort(left, mid, compare);
        Mergesort(mid + 1, right, compare);
        Merge(left, mid, right, compare);
    }
}

/**
 * Heapify:
 * Ensures that a subtree rooted at index 'i' satisfies the max-heap property.
 */
void OrdAlg::Heapify(int n, int i, bool (*compare)(const Pessoa&, const Pessoa&))
{
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) 
    {
        LEMEMLOG((long)&_elements[left], sizeof(Pessoa), 1);
        LEMEMLOG((long)&_elements[largest], sizeof(Pessoa), 1);
        if (!compare(_elements[left], _elements[largest]))
            largest = left;
    }

    if (right < n) 
    {
        LEMEMLOG((long)&_elements[right], sizeof(Pessoa), 1);
        LEMEMLOG((long)&_elements[largest], sizeof(Pessoa), 1);
        if (!compare(_elements[right], _elements[largest]))
            largest = right;
    }

    if (largest != i)
    {
        ESCREVEMEMLOG((long)&_elements[i], sizeof(Pessoa), 1);
        ESCREVEMEMLOG((long)&_elements[largest], sizeof(Pessoa), 1);
        Aux::Swap(_elements[i], _elements[largest]);
        Heapify(n, largest, compare);
    }
}

/**
 * Heapsort:
 * Implements the Heap Sort algorithm.
 */
void OrdAlg::Heapsort(bool (*compare)(const Pessoa&, const Pessoa&))
{
    int n = _fileLines;

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        Heapify(n, i, compare);
    }

    for (int i = n - 1; i > 0; --i)
    {
        ESCREVEMEMLOG((long)&_elements[0], sizeof(Pessoa), 1);
        ESCREVEMEMLOG((long)&_elements[i], sizeof(Pessoa), 1);
        Aux::Swap(_elements[0], _elements[i]);
        Heapify(i, 0, compare);
    }
}
