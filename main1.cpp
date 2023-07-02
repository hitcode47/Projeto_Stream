#include <iostream>
#include <string>
#include "feedback.hpp"
#include "curtidas.hpp"

int main(){
    int a, al, ac;


    std::string Musica;
    std::string Artista;
    std::string Usuario;

    Curtida execucao1;
    Feed execucao2;

    std::cout << "Digite seu Artista: " << std::endl;
    std::getline(std::cin, Artista);
    std::cout << "Digite sua musica: " << std:: endl;
    std::getline(std::cin, Musica);
    std::cout << "Digite seu nome de usuario: " << std:: endl;
    std::getline(std::cin, Usuario);

    execucao1.ver_quatidade_curtias(Musica);

    std::cout << "Digite:" << std::endl;
    std::cout << "(1) Para deixar seu like." << std::endl;
    std::cout << "(2) Para comentario" << std::endl;
    std::cin >> a;
    std::cin.ignore();
    
    if (a==1){
        std::cout << "Digite:" << std::endl;
        std::cout << "(2) Para like." << std::endl;
        std::cout << "(3) Para dislike." << std::endl;
        std::cin >> al;
        std::cin.ignore();


        if(al == 2){

            execucao1.like(Artista, Musica, Usuario);

        }else if (al == 3){
            execucao1.dislike(Artista,Musica,Usuario);

        }else {
            std::cout << "Acao nao encontrada." << std::endl;
            
        }

    }else if (a==2){
        std::cout << "Digite:" << std::endl;
        std::cout << "(1) Para ler comentarios." << std::endl;
        std::cout << "(2) Para fazer comentarios." << std::endl;
        std::cin >> ac;

        if(ac == 1){
            execucao2.Ler_Comentario(Artista, Musica, Usuario);

        }else if (ac == 2){
            execucao2.Fazer_comentario(Artista, Musica, Usuario);

        }else {
            std::cout << "Acao nao encontrada." << std::endl;
        
        }

    }else {
        std::cout << "Acao nao encontrada." << std::endl;

    }
}