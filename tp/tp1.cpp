#include "include/ordind.hpp"
#include "include/ordalg.hpp"
#include "include/aux.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    OrdInd ordind(argv);
    ordind.ReadFile();

    OrdAlg ordalg(ordind.GetElements(), ordind.GetLines());

    // Heapsort
    ordalg.Heapsort(Aux::CompareByName);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Heapsort(Aux::CompareByID);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Heapsort(Aux::CompareByEnd);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    // Quicksort
    ordalg.Quicksort(0, ordind.GetLines() - 1, Aux::CompareByName);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Quicksort(0, ordind.GetLines() - 1, Aux::CompareByID);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    ordalg.Quicksort(0, ordind.GetLines() - 1, Aux::CompareByEnd);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    //Bubblesort
    // ordalg.Bubblesort(Aux::CompareByName);
    // ordind.SortedPrint();

    // ordalg.Bubblesort(Aux::CompareByID);
    // ordind.SortedPrint();

    // ordalg.Bubblesort(Aux::CompareByEnd);
    // ordind.SortedPrint(); 

    // Mergesort
    ordalg.Mergesort(0, ordind.GetLines() - 1, Aux::CompareByName);
    ordind.SortedPrint();

    ordalg.Mergesort(0, ordind.GetLines() - 1, Aux::CompareByID);
    ordind.SortedPrint();

    ordalg.Mergesort(0, ordind.GetLines() - 1, Aux::CompareByEnd);
    ordind.SortedPrint();

    return 0;
}