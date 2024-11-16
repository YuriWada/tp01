#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{
    private:
        std::string _name;
        std::string _cpf;
        std::string _end;
        std::string _others;

    public:
        Pessoa() {};
        Pessoa(std::string name, 
               std::string cpf, 
               std::string end,
               std::string others);

        std::string GetName() const;
        std::string GetCPF() const;
        std::string GetEnd() const;
        std::string GetOthers() const;
};

#endif /* PESSOA_H */