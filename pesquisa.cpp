#include "pesquisa.hpp"

Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}

bool Pesquisa::Pesquisar::Encontrar() {
    
    if(!_palavra.empty()){
        _palavra[0] = std::toupper(_palavra[0]);
        for(int i=1; i < _palavra.size(); i++){
        if (_palavra[i-1] == ' ') {
            _palavra[i] = std::toupper(_palavra[i]);
        }else{
            _palavra[i] = std::tolower(_palavra[i]);
        }

    }}// Converte pra minuscula.

    std::ifstream Musica_Exemplo("Musica_Exemplo.txt");
    std::string linha;

    if (Musica_Exemplo.is_open()) {
    }
    else {
        std::cout << "O nome do arquivo.txt deve estar diferente do meu código." << std::endl;
    
    }//abrindo o arquivo.
    
   while (getline(Musica_Exemplo, linha)) {
        std::size_t pos = linha.find(",");
        if (pos != std::string::npos) {
            std::string titulo = linha.substr(0, pos);
            if (titulo.find(_palavra) != std::string::npos) {
            _resultados.push_back(titulo);
            }
        }
        
    }//1° obtenho cada linha e guardo em linha, depois encntro a 1 ocorrencia que seria no caso de copiar toda a string
    //antes do link(ou seja a substring), pois não quero exibir isso para o usuario. Logo após eu encontro dentro dessa substring
    //a palavra "_palavra" e assim guardo em _resultados.
     
    for(int i=0; i < _resultados.size(); i++){
        if (i == 0 || _resultados[i-1][0] == ' ') {
            _resultados[i][0] = std::toupper(_resultados[i][0]);
        }
    }//converto tudo que esta depois do espaço para letra maiuscula.

     if (_resultados.empty()) {
        std::cout << "Nenhum resultado encontrado para: " << _palavra << std::endl;
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