#include "pesquisa.hpp"

Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}

bool Pesquisa::Pesquisar::Encontrar() {
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
        std::size_t pos = _linha.find(",");
        if (pos != std::string::npos) {
            std::string titulo = _linha.substr(0, pos);
            if (titulo.find(_copia) != std::string::npos) {
            _resultados.push_back(titulo);
            }
        }
        
    }//1° obtenho cada linha e guardo em _linha, depois encntro a 1 ocorrencia que seria no caso de copiar toda a string
    //antes do link(ou seja a substring), pois não quero exibir isso para o usuario. Logo após eu encontro dentro dessa substring
    //a palavra "_copia" e assim guardo em _resultados.
     
    for(int i=0; i < _resultados.size(); i++){
        if (i == 0 || _resultados[i-1][0] == ' ') {
            _resultados[i][0] = std::toupper(_resultados[i][0]);
        }
    }//converto tudo que esta depois do espaço para letra maiuscula.

     if (_resultados.empty()) {
        std::cout << "Nenhum resultado encontrado para: " << _copia << std::endl;
        return false;
    }
    else{
        std::cout << "Voce deseja: " << std::endl;
         for (int i=0; i<_resultados.size(); i++){
            std::cout << "("<< (i+1) << ") " << _resultados[i] << std::endl;

            _encontrado[i+1] = _resultados[i];
         }
    }
    int opcao;
    bool encontrado = false;

std::cout << "Digite o numero desejado" << std::endl;
while(encontrado == false){
    std::string opcao_string;
    std::getline(std::cin, opcao_string); // lê a string.

    // Verificar se a entrada é um número inteiro
    try {
        opcao = std::stoi(opcao_string);
    } 
    
    catch (...) {
        std::cout << "Entrada invalida. Digite o numero desejado." << std::endl;
        continue;
    }
    for (auto it = _encontrado.begin(); it != _encontrado.end(); it++){
        if(opcao == it->first){
            std::cout << "Voce escolheu: " << it->second << std::endl;
            encontrado = true;
            break;
        }
        
    }

    }

return true;
}