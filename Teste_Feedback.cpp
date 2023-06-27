#include <iostream>
#include <string>
#include "feedback.hpp"

int main(){
int a;
    std::string Musica;
    std::string Artista;
    feed teste;
    std::cout << "Digite:" << std::endl;
    std::cout << "(1) Para ler comentarios." << std::endl;
    std::cout << "(2) Para fazer comentarios." << std::endl;
    std::cin >> a;
    std::cin.ignore(); // Limpa o caractere de nova linha pendente

    std::cout << "Digite sua musica/Artista: " << std::endl;
    std::getline(std::cin, Artista);
    std::getline(std::cin, Musica);

    if (a == 1) {
        teste.Ler_Comentario(Artista, Musica);
    } else {
        teste.Fazer_comentario(Artista, Musica);
    }
    
    return 0;
}



