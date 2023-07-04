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

void Curtida::sobreescrever(){
    
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
    if(verificacao_curtidas(Usuario)==false){
        std:: ofstream arquivo ("Curtidas.txt", std::ios::app);

        if(arquivo.is_open()){
            arquivo << Musica << ", "<< Usuario << ": "<<"Like"<< std:: endl;

            arquivo.close();            
            std::cout << "Like registrado com sucesso."<< std:: endl;
        }else {
            std:: cout << "Nao foi possivel abrir o arquivo."<< std :: endl;
        }
    }else {
        bool encerrar = true;
        bool encerrar2 = true;
        while(encerrar){
            int indeciso;
            std:: cout << "***O usuario ja regiu a essa musica.***"<< std:: endl;
            std:: cout << "O usuario deseja reagir novamente?"<< std:: endl<<std:: endl;
            std:: cout << "Digite:"<< std:: endl;
            std:: cout << "(1)Para sim"<< std:: endl;
            std:: cout << "(2)Para nao"<< std:: endl;
            std:: cin >> indeciso;
            std::cin.ignore();

            switch (indeciso){
            case (1):
                
                while(encerrar2){
                    int troca;
                    std:: cout << "Digite:"<< std:: endl;
                    std:: cout << "(1)Para like"<< std:: endl;
                    std:: cout << "(2)Para dislike"<< std:: endl;
                    std:: cout << "(3)Para nao fazer alteracao na sua curtida."<< std:: endl;
                    std:: cin >> troca;
                    switch (troca){
                    case (1):
                        
                        encerrar2= false;
                        encerrar=false;
                        break;
                    case (2):
                        encerrar2= false;
                        encerrar=false;
                        break;
                    case(3):
                        encerrar2=false;
                        encerrar=false;
                        break;
                    default:
                        std::cout << "Opcao nao encontrada. Tente Novamente" << std::endl << std::endl;
                        continue;
                        encerrar2=false;
                        break;    
                    }
                }
                break;
            case (2): 
                encerrar=false;
                break;
            default:
                std::cout << "Opcao nao encontrada. Tente Novamente" << std::endl << std::endl;
                continue;
                encerrar=false;
                break;
            }
        }
    }
}

void Curtida::dislike(std::string Musica, std::string Usuario ){
    if(verificacao_curtidas(Usuario)== false ){
        std:: ofstream arquivo ("Curtidas.txt", std::ios::app);
        if(arquivo.is_open()){
            arquivo << Musica << ","<< Usuario << ": "<<"Dislike"<< std:: endl;
            arquivo.close();    

            std::cout << "Dislike registrado com sucesso."<< std:: endl;
        }else {
            std:: cout << "Nao foi possivel abrir o arquivo."<< std :: endl;
        }
    }else{
        bool encerrar = true;
        bool encerrar2 = true;
        while(encerrar){
            int indeciso;
            std:: cout << "***O usuario ja regiu a essa musica.***"<< std:: endl;
            std:: cout << "O usuario deseja reagir novamente?"<< std:: endl<<std:: endl;
            std:: cout << "Digite:"<< std:: endl;
            std:: cout << "(1)Para sim"<< std:: endl;
            std:: cout << "(2)Para nao"<< std:: endl;
            std:: cin >> indeciso;
            std::cin.ignore();
            switch (indeciso){
            case (1):
                
                while(encerrar2){
                    int troca;
                    std:: cout << "Digite:"<< std:: endl;
                    std:: cout << "(1)Para like"<< std:: endl;
                    std:: cout << "(2)Para dislike"<< std:: endl;
                    std:: cout << "(3)Para nao fazer alteracao na sua curtida."<< std:: endl;
                    std:: cin >> troca;
                    switch (troca){
                    case (1):
                       
                        encerrar2= false;
                        encerrar=false;
                        break;
                    case (2):
                        encerrar2= false;
                        encerrar=false;
                        break;
                    case(3):
                        encerrar2= false;
                        encerrar=false;
                        break;
                    default:
                        std::cout << "**Opcao nao encontrada. Tente Novamente**" << std::endl<<std:: endl;
                        continue;
                        encerrar2=false;
                        break;
                    }
                }
                break;
            case (2): 
                encerrar = true;
                break;
            default:
                std::cout << "Opcao nao encontrada. Tente Novamente" << std::endl<<std:: endl;
                continue;
                encerrar=false;
                break;
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
