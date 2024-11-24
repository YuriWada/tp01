#include "include/ordind.hpp"
#include "include/ordalg.hpp"

#include <iostream>

int main()
{
    OrdInd ordind;
    ordind.ReadFile();

    OrdAlg ordalg(ordind.GetElements(), ordind.GetLines());

    printf("---HEAPSORT---\n");
    ordalg.Heapsort(ordalg.CompareByName);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();
    printf("\n");

    ordalg.Heapsort(ordalg.CompareByID);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();
    printf("\n");

    ordalg.Heapsort(ordalg.CompareByEnd);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();
    printf("\n");


    // printf("---QUICKSORT---\n");
    // ordalg.Quicksort(0, ordind.GetLines() - 1, ordalg.CompareByName);
    // ordind.SetElements(ordalg.GetElements());
    // ordind.SortedPrint();
    // printf("\n");

    // ordalg.Quicksort(0, ordind.GetLines() - 1, ordalg.CompareByID);
    // ordind.SetElements(ordalg.GetElements());
    // ordind.SortedPrint();
    // printf("\n");

    // ordalg.Quicksort(0, ordind.GetLines() - 1, ordalg.CompareByEnd);
    // ordind.SetElements(ordalg.GetElements());
    // ordind.SortedPrint();
    // printf("\n"); 

    // printf("---BUBBLESORT---\n");
    // ordind.Bubblesort(ordind.CompareByName);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Bubblesort(ordind.CompareByID);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Bubblesort(ordind.CompareByEnd);
    // ordind.SortedPrint(); 
    // printf("\n");

    // printf("---MERGESORT---\n");
    // ordind.Mergesort(0, ordind.GetLines() - 1, ordind.CompareByName);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Mergesort(0, ordind.GetLines() - 1, ordind.CompareByID);
    // ordind.SortedPrint();
    // printf("\n");

    // ordind.Mergesort(0, ordind.GetLines() - 1, ordind.CompareByEnd);
    // ordind.SortedPrint();
    // printf("\n");

    return 0;
}