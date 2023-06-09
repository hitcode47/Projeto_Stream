#include "pesquisa.hpp"

Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}

void Pesquisa::Pesquisar::Encontrar() {
    if(!_palavra.empty()){
        _palavra[0] = std::toupper(_palavra[0]);
        for(int i=1; i < _palavra.size(); i++){
            _palavra[i] = std::tolower(_palavra[i]);
        }
    } // Converte pra minuscula.

    std::ifstream Musica_Exemplo("Musica_Exemplo.txt");
    std::string linha;
    if (Musica_Exemplo.is_open()) {
    }
    else {
        std::cout << "O nome do arquivo.txt deve estar diferente do meu código." << std::endl;
    
    }
    while (getline(Musica_Exemplo, linha)) {
        if (linha.find(_palavra) != std::string::npos) {
            _resultados.push_back(linha);
        }
    }
     if (_resultados.empty()) {
        std::cout << "Nenhum resultado encontrado para: " << _palavra << std::endl;
    }
    else{
        std::cout << "Voce deseja:" << std::endl;
         for (const std::string& resultado : _resultados) {
            std::cout << resultado << std::endl;
        }
    }
}