#include "pesquisa.hpp"

Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}

Pesquisa::Pesquisar::Pesquisar(){}

bool Pesquisa::Pesquisar::Encontrar() {
    
    if(!_palavra.empty()){
        _palavra[0] = std::toupper(_palavra[0]);
        for(int i=1; i < _palavra.size(); i++){
            if (_palavra[i-1] == ' ') {
            _palavra[i] = std::toupper(_palavra[i]);
            }else{
            _palavra[i] = std::tolower(_palavra[i]);
            }

        }
    }// Converte pra minuscula e as iniciais em maiusculo

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
            
            std::vector<std::string> palavras_subdivididas;
            std::string palavra;
            std::istringstream iss(_palavra);

            while (iss >> palavra) {
                palavras_subdivididas.push_back(palavra);
            }
            int contador_de_palavras=0;
            int i=0;

            while (i < palavras_subdivididas.size()){

                if (titulo.find(palavras_subdivididas[i]) != std::string::npos) {
                    contador_de_palavras++;
                }

            i++;    
            }
            _resultados.insert(std::make_pair(contador_de_palavras, titulo));
        }
        
    }

    //1° obtenho cada linha e guardo em linha, depois encntro a 1 ocorrencia que seria no caso de copiar toda a string
    //antes do link(ou seja a substring), pois não quero exibir isso para o usuario. Logo após eu encontro dentro dessa substring
    //a palavra "_palavra" e assim guardo em _resultados.
    for (auto& pair : _resultados) {
        std::string& value = pair.second;
        if (!value.empty()) {
            value[0] = std::toupper(value[0]);
            for (size_t i = 1; i < value.size(); i++) {
                if (value[i - 1] == ' ') {
                    value[i] = std::toupper(value[i]);
                }
            }
        }
    }
    //converto tudo que esta depois do espaço para letra maiuscula.

    bool encontrouResultados = false;
    for (const auto& pair : _resultados) {
        if (pair.first > 0) {
            encontrouResultados = true;
            break;
        }
    }

    if (!encontrouResultados) {
        std::cout << "Nenhum resultado encontrado para: " << _palavra << std::endl;
        return false;
    }

    else{
        std::cout << "Voce deseja: " << std::endl;
            int count = 1;
            for (auto it = _resultados.rbegin(); it != _resultados.rend(); ++it) {
                if(it->first != 0){                
                    std::cout << "(" << count << ") " << it->second << std::endl;
                    _encontrado[count] = it->second;
                    count++;
                    if (count == 4) {
                        break;
                    }
                }
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
                _musica_escolhida = it->second;
                repo.Executar("Musica_Exemplo.txt", _musica_escolhida);
                break;
            }
        
        }

    }

return true;
}

std::string Pesquisa::Pesquisar::Retorno_Pesquisa(){
    return _musica_escolhida;
}