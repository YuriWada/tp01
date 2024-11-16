#include "../include/pessoa.hpp"

Pessoa::Pessoa(std::string name, std::string cpf, std::string end, std::string others) : _name(name), _cpf(cpf), _end(end), _others(others) {}

std::string Pessoa::GetName() const { return _name; }
std::string Pessoa::GetCPF() const { return _cpf; }
std::string Pessoa::GetEnd() const { return _end; }
std::string Pessoa::GetOthers() const { return _others; }