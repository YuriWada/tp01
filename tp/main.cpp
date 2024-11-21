#include "src/ordind.cpp"

#include <iostream>

int main()
{
    OrdInd ordind;
    ordind.ReadFile();
    ordind.find_index();
    

    printf("---QUICKSORT---\n");
    ordind.Quicksort(0, ordind.GetLines() - 1, ordind.GetNameIndex());
    ordind.SortedPrint();
    printf("\n");

    // ordind.Quicksort(0, ordind.GetLines() - 1, ordind.CompareByCPF);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Quicksort(0, ordind.GetLines() - 1, ordind.CompareByEnd);
    // ordind.SortedPrint();
    // printf("\n"); 

    // printf("---BUBBLESORT---\n");
    // ordind.Bubblesort(ordind.CompareByName);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Bubblesort(ordind.CompareByCPF);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Bubblesort(ordind.CompareByEnd);
    // ordind.SortedPrint(); 
    // printf("\n");

    // printf("---MERGESORT---\n");
    // ordind.Mergesort(0, ordind.GetLines() - 1, ordind.CompareByName);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Mergesort(0, ordind.GetLines() - 1, ordind.CompareByCPF);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Mergesort(0, ordind.GetLines() - 1, ordind.CompareByEnd);
    // ordind.SortedPrint();
    // printf("\n");

    return 0;
}