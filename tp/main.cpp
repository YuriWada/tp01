#include "src/ordind.cpp"

#include <iostream>

int main()
{
    OrdInd ordind;
    ordind.ReadFile();
    ordind.Quicksort(0, ordind.GetLines() - 1, ordind.CompareByName);
    ordind.SortedPrint();

    printf("\n");

    ordind.Quicksort(0, ordind.GetLines() - 1, ordind.CompareByCPF);
    ordind.SortedPrint();

    printf("\n");

    ordind.Quicksort(0, ordind.GetLines() - 1, ordind.CompareByEnd);
    ordind.SortedPrint();

    printf("\n");

    return 0;
}