#include "../include/ordind.hpp"
#include "../include/pessoa.hpp"

/**
 * Reads data from a file and initializes the internal data structure.
 */
void OrdInd::ReadFile()
{
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

    // Temporary array to hold row data during parsing
    std::string* elements_lines = new std::string[_keys];

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
    // Print the number of columns (keys)
    std::cout << _keys << std::endl;

    // Print each column name followed by ",s"
    for (int j = 0; j < _keys; j++)
    {
        std::cout << _columns[j] << ",s" << std::endl;
    }

    // Print the number of data rows
    std::cout << _fileLines << std::endl;

    // Print each data row in the stored order
    for (int i = 0; i < _fileLines; ++i)
    {
        std::cout << _elements[i].GetName() << ","
                  << _elements[i].GetID() << ","
                  << _elements[i].GetEnd() << ","
                  << _elements[i].GetOthers()
                  << std::endl;
    }
}
