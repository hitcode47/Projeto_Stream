#include <iostream>
#include <string>
#include "pesquisa.hpp"

int main(){
    bool a = true;
    while(a){
    std::string palavra;
    std::cout << "Digite sua musica/Artista: " << std::endl;
    std::getline(std::cin, palavra);
    Pesquisa::Pesquisar Busca(palavra);
    if(Busca.Encontrar()){
        a=false;
    };
    }
return 0;

}