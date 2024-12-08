#include "../include/ordind.hpp"
#include "../include/pessoa.hpp"
#include "../include/memlog.hpp"

/**
 * Reads data from a file and initializes the internal data structure.
 */
void OrdInd::ReadFile()
{
    defineFaseMemLog(0); // Fase 1: Leitura do arquivo e inicialização

    // Open the file specified in _fileName
    std::ifstream file(this->_fileName);
    if (!file.is_open())
    {
        std::cerr << "Error reading the file: " << this->_fileName << std::endl;
        return;
    }

    std::string line;

    // First line contains the number of columns (keys)
    std::getline(file, line);
    _keys = std::stoi(line);

    // Allocate memory for column names
    _columns = new std::string[_keys];
    ESCREVEMEMLOG((long)_columns, sizeof(std::string) * _keys, 0); // Log: alocação de _columns

    std::string temp = "";

    // Read each column name from the file
    for (int i = 0; i < _keys; ++i)
    {
        std::getline(file, line);
        for (int j = 0; j < Aux::StringLength(line.c_str()); ++j)
        {
            // Stop at the first comma and save the column name
            if (line[j] == ',')
            {
                _columns[i] = temp;
                ESCREVEMEMLOG((long)&_columns[i], sizeof(std::string), 0); // Log: escrita em _columns[i]
                temp = "";
                break;
            }
            else
            {
                temp += line[j];
            }
        }
    }

    // Sixth line specifies the number of data rows
    std::getline(file, line);
    _fileLines = std::stoi(line);

    // Allocate memory for the data rows
    _elements = new Pessoa[_fileLines];
    ESCREVEMEMLOG((long)_elements, sizeof(Pessoa) * _fileLines, 1); // Log: alocação de _elements

    // Temporary array to hold row data during parsing
    std::string* elements_lines = new std::string[_keys];
    ESCREVEMEMLOG((long)elements_lines, sizeof(std::string) * _keys, 2); // Log: alocação de elements_lines

    // Read and process each data row
    for (int i = 0; i < _fileLines; ++i)
    {
        std::string aux = "";
        int k = 0;
        std::getline(file, line);

        // Parse the row by splitting on commas
        for (int j = 0; j < Aux::StringLength(line.c_str()); ++j)
        {
            if (line[j] == ',')
            {
                elements_lines[k] = aux;
                ESCREVEMEMLOG((long)&elements_lines[k], sizeof(std::string), 2); // Log: escrita em elements_lines[k]
                aux = "";
                k++;
            }
            else
            {
                aux += line[j];
            }
        }
        elements_lines[k] = aux;

        // Assign parsed values to a Pessoa object
        std::string name = elements_lines[0];
        std::string id = elements_lines[1];
        std::string address = elements_lines[2];
        std::string payload = elements_lines[3];

        _elements[i] = Pessoa(name, id, address, payload);
        ESCREVEMEMLOG((long)&_elements[i], sizeof(Pessoa), 1); // Log: escrita em _elements[i]

        // Reset temporary array for the next row
        for (int t = 0; t < _keys; t++)
        {
            elements_lines[t] = "";
        }
    }

    // Free the temporary memory
    delete[] elements_lines;

    // Close the file after reading
    file.close();
}

/**
 * Prints the stored data in a sorted format.
 */
void OrdInd::SortedPrint() const
{
    defineFaseMemLog(1); // Fase 2: Impressão ordenada dos dados

    // Print the number of columns (keys)
    std::cout << _keys << std::endl;

    // Print each column name followed by ",s"
    for (int j = 0; j < _keys; j++)
    {
        LEMEMLOG((long)&_columns[j], sizeof(std::string), 0); // Log: leitura de _columns[j]
        std::cout << _columns[j] << ",s" << std::endl;
    }

    // Print the number of data rows
    std::cout << _fileLines << std::endl;

    // Print each data row in the stored order
    for (int i = 0; i < _fileLines; ++i)
    {
        LEMEMLOG((long)&_elements[i], sizeof(Pessoa), 1); // Log: leitura de _elements[i]
        std::cout << _elements[i].GetName() << ","
                  << _elements[i].GetID() << ","
                  << _elements[i].GetEnd() << ","
                  << _elements[i].GetOthers()
                  << std::endl;
    }
}
