#include "pesquisa.hpp"
#include "cadastrousuario.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <functional>

std::string nomedeacesso;


int main(){
    
    Iniciar app;
    
    app.exibirlogo();
    nomedeacesso = app.menu();
    
    std::cout<<"BEM VINDO "<<nomedeacesso<<std::endl;
    std::cout<<std::endl;
    
    std::string palavra;
    std::cout << "Digite sua musica/Artista: " << std::endl;
    std::getline(std::cin, palavra);
    Pesquisa::Pesquisar Busca(palavra);
    Busca.Encontrar();
    
    return 0;
}
