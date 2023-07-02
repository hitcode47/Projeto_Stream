#include <iostream>
#include <string>
#include "feedback.hpp"
#include "curtidas.hpp"

int main(){
int a1, al, ac;
    std::string Musica;
    std::string Artista;
    std::string Usuario;

    Curtida execucao1;
    Feed execucao2;

    std::cout << "Digite:" << std::endl;
    std::cout << "(1) Para curtir." << std::endl;
    std::cout << "(2) Para comentario" << std::endl;
    std::cin >> a1;
    
    if (a1==1){
        std::cout << "Digite:" << std::endl;
        std::cout << "(1) Para ver quantidade de curtidas." << std::endl;
        std::cout << "(2) Para like." << std::endl;
        std::cout << "(3) Para dislike." << std::endl;
        std::cin >> al;

        if (al == 1){

            std::cin.ignore(); // Limpa o caractere de nova linha pendente
            std::cout << "Digite sua musica: " << std:: endl;
            std::getline(std::cin, Musica);
            
            execucao1.ver_quatidade_curtias(Musica);
        }else if(al == 2){

            std::cin.ignore(); // Limpa o caractere de nova linha pendente
            std::cout << "Digite seu Artista: " << std::endl;
            std::getline(std::cin, Artista);

            std::cout << "Digite sua musica: " << std:: endl;
            std::getline(std::cin, Musica);

            std::cout << "Digite seu nome de usuario: " << std:: endl;
            std::getline(std::cin, Usuario);
            // Ter verificação de usuario.*****

            execucao1.like(Artista, Musica, Usuario);

        }else if (al == 3){
            
            std::cin.ignore(); // Limpa o caractere de nova linha pendente
            std::cout << "Digite seu Artista: " << std::endl;
            std::getline(std::cin, Artista);

            std::cout << "Digite sua musica: " << std:: endl;
            std::getline(std::cin, Musica);

            std::cout << "Digite seu nome de usuario: " << std:: endl;
            std::getline(std::cin, Usuario);
            // Ter verificação de usuario.*****

            execucao1.dislike(Artista,Musica,Usuario);

        }else {
            std::cout << "Acao nao encontrada." << std::endl;
            return 0;
        }

    }else if (a1==2){
        std::cout << "Digite:" << std::endl;
        std::cout << "(1) Para ler comentarios." << std::endl;
        std::cout << "(2) Para fazer comentarios." << std::endl;
        std::cin >> ac;

        if(ac == 1){
            
            std::cin.ignore(); // Limpa o caractere de nova linha pendente
            std::cout << "Digite seu Artista: " << std::endl;
            std::getline(std::cin, Artista);

            std::cout << "Digite sua musica: " << std:: endl;
            std::getline(std::cin, Musica);

            std::cout << "Digite seu nome de usuario: " << std:: endl;
            std::getline(std::cin, Usuario);
            // Ter verificação de usuario.*****

            execucao2.Ler_Comentario(Artista, Musica, Usuario);

        }else if (ac == 2){

            std::cin.ignore(); // Limpa o caractere de nova linha pendente
            std::cout << "Digite seu Artista: " << std::endl;
            std::getline(std::cin, Artista);

            std::cout << "Digite sua musica: " << std:: endl;
            std::getline(std::cin, Musica);

            std::cout << "Digite seu nome de usuario: " << std:: endl;
            std::getline(std::cin, Usuario);
            // Ter verificação de usuario.*****

            execucao2.Fazer_comentario(Artista, Musica, Usuario);

        }else {
            std::cout << "Acao nao encontrada." << std::endl;
            return 0;
        }

    }else {
        std::cout << "Acao nao encontrada." << std::endl;
        return 0;
    }
}