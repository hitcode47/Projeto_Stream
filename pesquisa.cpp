#include "pesquisa.hpp"

Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}

void Pesquisa::Pesquisar::Encontrar() {
    auto _copia = _palavra;


    if(!_copia.empty()){
        _copia[0] = std::toupper(_copia[0]);
        for(int i=1; i < _copia.size(); i++){
        if (_copia[i-1] == ' ') {
            _copia[i] = std::toupper(_copia[i]);
        }else{
            _copia[i] = std::tolower(_copia[i]);
        }

    }}// Converte pra minuscula.

    std::ifstream Musica_Exemplo("Musica_Exemplo.txt");
    std::string linha;

    if (Musica_Exemplo.is_open()) {
    }
    else {
        std::cout << "O nome do arquivo.txt deve estar diferente do meu código." << std::endl;
    
    }//abrindo o arquivo.
    
    while (getline(Musica_Exemplo, _linha)) {
        if (_linha.find(_copia) != std::string::npos) {
            _resultados.push_back(_linha);
        }
    }//1° obtenho cada linha e guardo em _linha, depois encontro a _palavra == _copia e guardo a linha inteira em _resultados

    for(int i=0; i < _resultados.size(); i++){
        if (i == 0 || _resultados[i-1][0] == ' ') {
            _resultados[i][0] = std::toupper(_resultados[i][0]);
        }
    }//converto tudo que esta depois do espaço para letra maiuscula.

     if (_resultados.empty()) {
        std::cout << "Nenhum resultado encontrado para: " << _copia << std::endl;
    }
    else{
        std::cout << "Voce deseja:" << std::endl;
         for (auto resultado : _resultados) {
            std::cout << resultado << std::endl;
        }
    }
}