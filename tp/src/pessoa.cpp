#include "../include/pessoa.hpp"

Pessoa::Pessoa(std::string name, std::string id, std::string end, std::string others) : 
    _name(name), 
    _id(id), 
    _end(end), 
    _others(others) 
    {}

std::string Pessoa::GetName() const { return _name; }
std::string Pessoa::GetID() const { return _id; }
std::string Pessoa::GetEnd() const { return _end; }
std::string Pessoa::GetOthers() const { return _others; }