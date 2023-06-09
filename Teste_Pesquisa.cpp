#include <iostream>
#include <string>
#include "pesquisa.hpp"

int main(){
    std::string palavra;
    std::getline(std::cin, palavra);
    Pesquisa::Pesquisar Busca(palavra);
    Busca.Encontrar();

return 0;

}