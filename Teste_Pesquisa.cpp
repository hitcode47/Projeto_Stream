#include <iostream>
#include <string>
#include "pesquisa.hpp"

int main(){
    std::string palavra;
    std::cout << "Digite sua musica/Artista: " << std::endl;
    std::getline(std::cin, palavra);
    Pesquisa::Pesquisar Busca(palavra);
    Busca.Encontrar();

return 0;

}