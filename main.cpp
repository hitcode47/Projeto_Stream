#include "pesquisa.hpp"
#include "cadastrousuario.hpp"
#include "reproducao.hpp"
#include "musicas.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <functional>
#include <locale.h>
#include <stdio.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    std::string nomedeacesso;
    Iniciar app;
    
    app.exibirlogo();
    nomedeacesso = app.menu();
    
    std::cout<<"BEM VINDO "<<nomedeacesso<<std::endl;
    std::cout<<std::endl;
    inicio:
    std::string palavra;
     
    

    std::cout << "Digite sua musica/Artista: " << std::endl;
    std::getline(std::cin, palavra);

    Pesquisa::Pesquisar Busca(palavra);
    bool resultado_da_busca = Busca.Encontrar();
    

    std::string _musica_escolhida;
    _musica_escolhida = Busca.Retorno_Pesquisa();

    reproducao repro;
    if(resultado_da_busca == true){
        repro.Executar("Musica_Exemplo.txt", _musica_escolhida);
    }

    reproducao reproduz;
    musicas minha_musica;
    bool encerrar = true;
    if(resultado_da_busca){
std::cout << "**********************" << std::endl;
std::cout << "**** REPRODUZINDO ****" << std::endl;
std::cout << "**********************" << std::endl;
std::cout << "(1) - Pausar |(II)" << std::endl;
std::cout << "(2) - Avancar|(>>)" << std::endl;
std::cout << "(3) - Voltar |(<<)" << std::endl;
std::cout << "(4) - Fechar |(X)" << std::endl;
std::cout << "******* OUTROS *******" << std::endl;
std::cout << "(5) - Adicionar Musicas" << std::endl;
std::cout << "(6) - Remover Musicas" << std::endl;
std::cout << "(7) - Fazer uma nova Pesquisa" << std::endl;
    while (encerrar)
    {   
        int opcao;
        std::string operacao;
        std::cin >> operacao;
        try {
            opcao = std::stoi(operacao);
        } 
    
        catch (...) {
            std::cout << "Entrada invalida. Digite o numero desejado." << std::endl;
            continue;
        }

        switch (opcao)
        {
        case(1):
            Busca.repro.Parar_Executar();
            break;
        case(2):
            Busca.repro.Pular_p_frente("Musica_Exemplo.txt");
            break;
        case(3):
            Busca.repro.Pular_p_tras("Musica_Exemplo.txt");
            break;
        case(4):
            std::cout << "Obrigado por usar o app PANCADAO" << std::endl;
            encerrar = false;
            break;
        case(5):
            minha_musica.adicionar_musica("Musica_Exemplo.txt");
            break;
        case(6):
            minha_musica.Remove_musica("Musica_Exemplo.txt");
            break;
        case(7):
        goto ibusca;
        break;

        default:
            std::cout << "Opcao nao encontrada. Tente Novamente" << std::endl;
            continue;
            encerrar = false;
            break;
        }
    }
}
    else{
        ibusca:
        bool continuar = true;
        while (continuar)
        {
        std::cout << "Deseja fazer uma nova busca?" << std::endl;
        std::cout << "1 - sim" << std::endl;
        std::cout << "2 - nao" << std::endl;
        int valor = 0;
        std::cin >> valor;
        switch (valor){
            case(1):
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto inicio;
              break;
            case(2):
              continuar = false;
              break;
            default:
            continue;
              break;
          }
        }
        
    }
    
    
    return 0;
}
