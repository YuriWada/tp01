#include "../include/pessoa.hpp"

Pessoa::Pessoa(std::string name, std::string cpf, std::string end) : _name(name), _cpf(cpf), _end(end) {}

std::string Pessoa::GetName() const { return _name; }
std::string Pessoa::GetCPF() const { return _cpf; }
std::string Pessoa::GetEnd() const { return _end; }