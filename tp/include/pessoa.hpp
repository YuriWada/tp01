#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{
    private:
        std::string _name;
        std::string _cpf;
        std::string _end;

    public:
        Pessoa(std::string name, 
               std::string cpf, 
               std::string end);

        std::string GetName() const;
        std::string GetCPF() const;
        std::string GetEnd() const;
};

#endif /* PESSOA_H */