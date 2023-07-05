#include "feedback.hpp"
#include <iostream>

void Comentario::Fazer_comentario(std::string Musica, std::string Usuario){
    std::ofstream arquivo("FeedBack.txt", std::ios::app);
    if (arquivo.is_open()) {
    std::string comentario;
    std::cin.ignore(); 
    //Sem o cin.iginore(), o programas estava achado que o usuario ja tinha deixado o seu comentario
    //então foi nescessario coloca-lo para que a caixa de comentario fosse criada.
    std::cout << "Digite seu comentario: ";
    std::getline(std::cin, comentario);
    
    arquivo << Musica << " , " << Usuario << ":" << comentario << std::endl; // Adiciona o comentário à mesma linha
    arquivo.close();

    std::cout << "Comentario registrado com sucesso!" << std::endl;
    } else {
    std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
    }
}


void Comentario::Ler_comentario(std::string Musica, std::string Usuario) {
    std::ifstream arquivo("FeedBack.txt");
    std::string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {

            std::size_t posMusica = linha.find(Musica);
            
            if (posMusica != std::string::npos) {
                std::size_t separator = linha.find(",");
                if (separator != std::string::npos) {
                    std::string comentario = linha.substr(separator + 2);
                    _comentarios.push_back(comentario);
                }
            }
        }
        arquivo.close();

        // Imprimir os comentários encontrados
        if (!_comentarios.empty()) {
            std::cout << "Comentarios encontrados:" << std::endl;
            for (const auto& comentario : _comentarios) {
                std::cout << comentario << std::endl;
            }
        } else {
            std::cout << "Nenhum comentario encontrado para essa musica e artista." << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}



void Curtida::removerLinha(std::string usuario, std::string musica) {
    std::ifstream arquivoEntrada("Curtidas.txt");
    std::string linha;
    bool linhaRemovida = false;

    if (arquivoEntrada.is_open()) {
        std::vector<std::string> linhasRestantes;

        while (getline(arquivoEntrada, linha)) {
            if (linha.find(musica) != std::string::npos && linha.find(usuario) != std::string::npos) {
                linhaRemovida = true;
            } else {
                linhasRestantes.push_back(linha);
            }
        }

        arquivoEntrada.close();
       

        if (linhaRemovida) {
            std::ofstream arquivoFinal("Curtidas.txt");
            for (const std::string& linha : linhasRestantes) {
                arquivoFinal << linha << std::endl;
            }
            arquivoFinal.close();

        } 
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
        
    }
}

bool Curtida::verificacao_curtidas(std::string Usuario, std::string Musica){
    std:: ifstream arquivo ("Curtidas.txt");
    std:: string linha;
    if(arquivo.is_open()){
        
        while (getline(arquivo, linha)){
            if(linha.find(Musica) != std::string::npos){
                if(linha.find(Usuario)){
                    removerLinha(Usuario, Musica);
                }
            }
        }
        return false;
    }else {
        std:: cout << "Nao foi possivel abrir o arquivo."<< std :: endl;
    }
    return false;
}

void Curtida::like(std::string Musica, std::string Usuario){
     if (verificacao_curtidas(Usuario, Musica) == false) {
        std::ofstream arquivo("Curtidas.txt", std::ios::app);

        if (arquivo.is_open()) {
            arquivo << Musica << ", " << Usuario << ": " << "Like" << std::endl;
            arquivo.close();
            std::cout << "Like registrado com sucesso." << std::endl;
        } else {
            std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        }
    } 
} 

void Curtida::dislike(std::string Musica, std::string Usuario ){
    if (verificacao_curtidas(Usuario, Musica) == false) {
        std::ofstream arquivo("Curtidas.txt", std::ios::app);
        if (arquivo.is_open()) {
            arquivo << Musica << ", " << Usuario << ": " << "Dislike" << std::endl;
            arquivo.close();
            std::cout << "Dislike registrado com sucesso." << std::endl;
        } else {
            std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        }
    } else {
        
    }
} 

void Curtida::ver_quatidade_curtias(std::string Musica ){
    std::ifstream arquivo("Curtidas.txt");
    std::string linha;
    Contl=0;
    Contd=0;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            std::size_t posMusica = linha.find(Musica);
            if (posMusica != std::string::npos) {
                std::size_t separator = linha.find(":");
                if (separator != std::string::npos) {
                    std::string like = linha.substr(separator + 2);
                    if(like == "Like") Contl++;
                    else if(like=="Dislike") Contd++;
                }
            }
        }
        arquivo.close();

        // Imprimir quantidade de like encontrados
       std:: cout <<"Quantidade de likes: "<< Contl << std:: endl;
       std:: cout <<"Quantidade de dislikes: "<< Contd << std:: endl;
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}
