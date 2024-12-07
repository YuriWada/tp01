#include "include/ordind.hpp"
#include "include/ordalg.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    OrdInd ordind(argv);
    ordind.ReadFile();

    OrdAlg ordalg(ordind.GetElements(), ordind.GetLines());

    // Heapsort
    ordalg.Heapsort(ordalg.CompareByName);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Heapsort(ordalg.CompareByID);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Heapsort(ordalg.CompareByEnd);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    // Quicksort
    ordalg.Quicksort(0, ordind.GetLines() - 1, ordalg.CompareByName);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Quicksort(0, ordind.GetLines() - 1, ordalg.CompareByID);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Quicksort(0, ordind.GetLines() - 1, ordalg.CompareByEnd);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    //Bubblesort
    // ordalg.Bubblesort(ordalg.CompareByName);
    // ordind.SortedPrint();

    // ordalg.Bubblesort(ordalg.CompareByID);
    // ordind.SortedPrint();

    // ordalg.Bubblesort(ordalg.CompareByEnd);
    // ordind.SortedPrint(); 

    // Mergesort
    ordalg.Mergesort(0, ordind.GetLines() - 1, ordalg.CompareByName);
    ordind.SortedPrint();

    ordalg.Mergesort(0, ordind.GetLines() - 1, ordalg.CompareByID);
    ordind.SortedPrint();

    ordalg.Mergesort(0, ordind.GetLines() - 1, ordalg.CompareByEnd);
    ordind.SortedPrint();

    return 0;
}