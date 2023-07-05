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

bool Curtida::sobreescrever(std::string Usuario,std::streampos& posicao ){
    std::ifstream arquivo("Curtidas.txt");
    std::string linha;
    if (arquivo.is_open()) {
        std::streampos pos = arquivo.tellg();  // Posição atual do arquivo

        while (getline(arquivo, linha)) {
            std::size_t posUsuario = linha.find(Usuario);
            posicao = pos;  // Armazena a posição da linha
            arquivo.close();
             return true;
            pos = arquivo.tellg();  // Atualiza a posição do arquivo
        }

        arquivo.close();
    } else {
        std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
    }

    return false;
}

bool Curtida::verificacao_curtidas(std::string Usuario){
    std:: ifstream arquivo ("Curtidas.txt");
    std:: string linha;
    if(arquivo.is_open()){
        
        while (getline(arquivo, linha)){
            std::size_t posUsuario = linha.find(Usuario);
            if (posUsuario != std::string::npos){
                std::size_t separator = linha.find(":");
                if (separator !=std::string::npos){
                    std::string verificacao = linha.substr(separator + 2);
                    if(verificacao == "Like"){
                        return true;
                    }else if (verificacao == "Dislike"){
                        return true;
                    }
                }
            }else {
                return false;
            }
        }
        
    }else {
        std:: cout << "Nao foi possivel abrir o arquivo."<< std :: endl;
    }
}

void Curtida::like(std::string Musica, std::string Usuario){
     if (verificacao_curtidas(Usuario) == false) {
        std::ofstream arquivo("Curtidas.txt", std::ios::app);

        if (arquivo.is_open()) {
            arquivo << Musica << ", " << Usuario << ": " << "Like" << std::endl;
            arquivo.close();
            std::cout << "Like registrado com sucesso." << std::endl;
        } else {
            std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        }
    } else {
        std::streampos posicao;
        if (sobreescrever(Usuario, posicao)) {
            std::fstream arquivo("Curtidas.txt", std::ios::in | std::ios::out);
            if (arquivo.is_open()) {
                arquivo.seekp(posicao);  // Posiciona o ponteiro do arquivo na posição da linha
                arquivo << Musica << ", " << Usuario << ": " << "Like" << std::endl;
                arquivo.close();
                std::cout << "Reacao atualizada com sucesso." << std::endl;
            } else {
                std::cout << "Nao foi possível abrir o arquivo." << std::endl;
            }
        }
    }
} 

void Curtida::dislike(std::string Musica, std::string Usuario ){
    if (verificacao_curtidas(Usuario) == false) {
        std::ofstream arquivo("Curtidas.txt", std::ios::app);
        if (arquivo.is_open()) {
            arquivo << Musica << ", " << Usuario << ": " << "Dislike" << std::endl;
            arquivo.close();
            std::cout << "Dislike registrado com sucesso." << std::endl;
        } else {
            std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        }
    } else {
        std::streampos posicao;
        if (sobreescrever(Usuario, posicao)) {
            std::fstream arquivo("Curtidas.txt", std::ios::in | std::ios::out);
            if (arquivo.is_open()) {
                arquivo.seekp(posicao);  // Posiciona o ponteiro do arquivo na posição da linha
                arquivo << Musica << ", " << Usuario << ": " << "Dislike" << std::endl;
                arquivo.close();
                std::cout << "Reacao atualizada com sucesso." << std::endl;
            } else {
                std::cout << "Nao foi possível abrir o arquivo." << std::endl;
            }
        } 
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
