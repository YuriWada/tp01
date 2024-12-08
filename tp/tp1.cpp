#include "include/ordind.hpp"
#include "include/ordalg.hpp"
#include "include/aux.hpp"
#include "include/memlog.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    // Inicializa o memlog e define o arquivo de saída
    iniciaMemLog("/tmp/memlog.out");
    ativaMemLog();

    // Lê os dados do arquivo
    OrdInd ordind(argv);
    ordind.ReadFile();

    // Cria o objeto para manipulação dos algoritmos de ordenação
    OrdAlg ordalg(ordind.GetElements(), ordind.GetLines());

    // Heapsort por Nome
    defineFaseMemLog(0); // Fase 1: Heapsort por Nome
    ordalg.Heapsort(Aux::CompareByName);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    // Heapsort por ID
    defineFaseMemLog(1); // Fase 2: Heapsort por ID
    ordalg.Heapsort(Aux::CompareByID);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    // Heapsort por Endereço
    defineFaseMemLog(2); // Fase 3: Heapsort por Endereço
    ordalg.Heapsort(Aux::CompareByEnd);
    ordind.SetElements(ordalg.GetElements());
    ordind.SortedPrint();

    // // Quicksort
    // defineFaseMemLog(4); // Fase 4: Quicksort por Nome
    // ordalg.Quicksort(0, ordind.GetLines() - 1, Aux::CompareByName);
    // ordind.SetElements(ordalg.GetElements());
    // ordind.SortedPrint();

    // defineFaseMemLog(5); // Fase 5: Quicksort por ID
    // ordalg.Quicksort(0, ordind.GetLines() - 1, Aux::CompareByID);
    // ordind.SetElements(ordalg.GetElements());
    // ordind.SortedPrint();

    // defineFaseMemLog(6); // Fase 6: Quicksort por Endereço
    // ordalg.Quicksort(0, ordind.GetLines() - 1, Aux::CompareByEnd);
    // ordind.SetElements(ordalg.GetElements());
    // ordind.SortedPrint();

    // // Bubblesort
    // defineFaseMemLog(7); // Fase 7: Bubblesort por Nome
    // ordalg.Bubblesort(Aux::CompareByName);
    // ordind.SortedPrint();

    // defineFaseMemLog(8); // Fase 8: Bubblesort por ID
    // ordalg.Bubblesort(Aux::CompareByID);
    // ordind.SortedPrint();

    // defineFaseMemLog(9); // Fase 9: Bubblesort por Endereço
    // ordalg.Bubblesort(Aux::CompareByEnd);
    // ordind.SortedPrint();

    // // Mergesort
    // defineFaseMemLog(10); // Fase 10: Mergesort por Nome
    // ordalg.Mergesort(0, ordind.GetLines() - 1, Aux::CompareByName);
    // ordind.SortedPrint();

    // defineFaseMemLog(11); // Fase 11: Mergesort por ID
    // ordalg.Mergesort(0, ordind.GetLines() - 1, Aux::CompareByID);
    // ordind.SortedPrint();

    // defineFaseMemLog(12); // Fase 12: Mergesort por Endereço
    // ordalg.Mergesort(0, ordind.GetLines() - 1, Aux::CompareByEnd);
    // ordind.SortedPrint();

    // Finaliza o memlog
    finalizaMemLog();

    return 0;
}
