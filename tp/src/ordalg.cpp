#include "../include/ordalg.hpp"

/**
 * CustomCompareStrings:
 * A custom string comparison function that compares two strings character by character.
 * It returns true if the first string is lexicographically smaller than the second one.
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

    // If all characters are equal, the shorter string is considered smaller.
    return len1 < len2;
}

/**
 * Comparison functions:
 * Used to compare 'Pessoa' objects based on different fields.
 */
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
 * Swap:
 * Swaps the values of two 'Pessoa' objects.
 */
void OrdAlg::Swap(Pessoa& a, Pessoa& b)
{
    Pessoa temp = a;
    a = b;
    b = temp;
}

/**
 * Partition:
 * Partitions the array around a pivot element for the QuickSort algorithm.
 * Adjusts indices to split the array into two subarrays.
 */
void OrdAlg::Partition(int low, int high, int* i, int* j, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    Pessoa pivot = _elements[(low + high) / 2];
    *i = low;
    *j = high;

    do 
    {
        // Move the left pointer until an element greater than or equal to the pivot is found
        while (compare(_elements[*i], pivot)) 
        {
            ++(*i);
        }

        // Move the right pointer until an element less than or equal to the pivot is found
        while (compare(pivot, _elements[*j])) 
        {
            --(*j);
        }

        // Swap elements if the pointers have not crossed
        if (*i <= *j) 
        {
            Swap(_elements[*i], _elements[*j]);
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
 * Implements the Bubble Sort algorithm by repeatedly swapping adjacent elements
 * that are in the wrong order.
 */
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

/**
 * Merge:
 * Merges two sorted subarrays into a single sorted subarray.
 */
void OrdAlg::Merge(int left, int mid, int right, bool (*compare)(const Pessoa&, const Pessoa&)) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Allocate temporary arrays
    Pessoa* leftArray = new Pessoa[n1];
    Pessoa* rightArray = new Pessoa[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i) 
    {
        leftArray[i] = _elements[left + i];
    }
    for (int j = 0; j < n2; ++j) 
    {
        rightArray[j] = _elements[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back into the original array
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

    while (i < n1) 
    {
        _elements[k++] = leftArray[i++];
    }
    while (j < n2) 
    {
        _elements[k++] = rightArray[j++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

/**
 * Mergesort:
 * Implements the Merge Sort algorithm using a divide-and-conquer approach.
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

/**
 * Heapsort:
 * Implements the Heap Sort algorithm by building a heap and repeatedly extracting
 * the largest element.
 */
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
