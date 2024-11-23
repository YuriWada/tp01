#include "../include/ordalg.hpp"

bool OrdAlg::CompareByName(const Pessoa& a, const Pessoa& b)
{
    return a.GetName() < b.GetName();
}

bool OrdAlg::CompareByID(const Pessoa& a, const Pessoa& b)
{
    return a.GetID() < b.GetID();
}

bool OrdAlg::CompareByEnd(const Pessoa& a, const Pessoa& b)
{
    return a.GetEnd() < b.GetEnd();
}

void OrdAlg::Swap(Pessoa& a, Pessoa& b)
{
    Pessoa temp = a;
    a = b;
    b = temp;
}

int OrdAlg::Partition(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&))
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

void OrdAlg::Quicksort(int low, int high, bool (*compare)(const Pessoa&, const Pessoa&))
{
    if (low < high) {
        int pivotIndex = Partition(low, high, compare);
        Quicksort(low, pivotIndex - 1, compare);
        Quicksort(pivotIndex + 1, high, compare);
    }
}

void OrdAlg::Bubblesort(bool (*compare)(const Pessoa&, const Pessoa&))
{
    for (int i = 0; i < _fileLines - 1; ++i) {
        for (int j = 0; j < _fileLines - i - 1; ++j) {
            if (!compare(_elements[j], _elements[j + 1])) {
                Swap(_elements[j], _elements[j + 1]);
            }
        }
    }
}

void OrdAlg::Merge(int left, int mid, int right, bool (*compare)(const Pessoa&, const Pessoa&))
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

void OrdAlg::Mergesort(int left, int right, bool (*compare)(const Pessoa&, const Pessoa&))
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        OrdAlg::Mergesort(left, mid, compare);
        OrdAlg::Mergesort(mid + 1, right, compare);

        // merge sorted subarrays
        OrdAlg::Merge(left, mid, right, compare);
    }
}