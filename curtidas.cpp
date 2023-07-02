#include "curtidas.hpp"
#include <iostream>

void Curtida::like(std::string Artista, std::string Musica, std:: string Usuario){
    std:: ofstream arquivo ("Curtidas.txt", std::ios::app);
    if(arquivo.is_open()){
        arquivo << Artista<<"-"<< Musica << ", "<< Usuario << ": "<<"Like"<< std:: endl;

        arquivo.close();            
        std::cout << "Like registrado com sucesso.";
    }else {
        std:: cout << "Nao foi possivel abrir o arquivo."<< std :: endl;
    }
}

void Curtida::dislike(std::string Artista, std::string Musica, std::string Usuario ){
    std:: ofstream arquivo ("Curtidas.txt", std::ios::app);
    if(arquivo.is_open()){
        arquivo << Artista<<"-"<< Musica << ","<< Usuario << ": "<<"Dislike"<< std:: endl;
        arquivo.close();

        std::cout << "Dislike registrado com sucesso.";
    }else {
        std:: cout << "Nao foi possivel abrir o arquivo."<< std :: endl;
    }
}

void Curtida::ver_quatidade_curtias(std::string Musica ){
    std::ifstream arquivo("Curtidas.txt");
    std::string linha;
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
