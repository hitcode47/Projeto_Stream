#include "pesquisa.hpp"

Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}



void Pesquisa::Pesquisar::Encontrar() {
    std::ifstream Musica_Exemplo("Musica.txt");
    std::string linha;
    if (Musica_Exemplo.is_open()) {
    }
    else {
        std::cout << "Erro no código, tente novamente!" << std::endl;
    }
    while (getline(Musica_Exemplo, linha)) {
        if (linha.find(_palavra) != std::string::npos) {
            std::cout << "Musica encontrada: " << _palavra << std::endl;
        }
    }
}