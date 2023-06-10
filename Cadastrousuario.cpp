#include <iostream>
#include <fstream>
#include <string>

void login() {
    std::string usuario, senha, testeusuario, testesenha;
    
    std::ifstream confirma("usuariosenha.txt");

    if (confirma.is_open()) {
        bool usuarioEncontrado = false;
        bool loginBemSucedido = false;

        while (!loginBemSucedido) {
            std::cout << "Digite aqui o nome de usuário: ";
            getline(std::cin, usuario);
            std::cout << std::endl;

            while (getline(confirma, testeusuario)) {
                if (usuario == testeusuario) {
                    usuarioEncontrado = true;
                    getline(confirma, testesenha);
                    break;
                }
                getline(confirma, testesenha);  // Descarta a linha da senha correspondente
            }

            if (usuarioEncontrado) {
                std::cout << "Digite aqui a senha: ";
                getline(std::cin, senha);
                std::cout << std::endl;

                if (senha == testesenha) {
                    std::cout << "LOGIN BEM SUCEDIDO!" << std::endl;
                    loginBemSucedido = true;
                } 
                else {
                    std::cout << "Senha incorreta!" << std::endl;
                }
            }
            else {
                std::cout << "Nome de usuário não encontrado!" << std::endl;
            }
            confirma.clear();
            confirma.seekg(0, std::ios::beg);
        }

        confirma.close();
    }
    else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
    }
}


void sign_up() {
    std::string usuario, senha, senhac;
    
    std::cout << "Digite aqui o nome de usuário: ";
    getline(std::cin, usuario);
    std::cout << std::endl;
    
    std::ifstream usuariosarq1("usuariosenha.txt");
    if (usuariosarq1.is_open()) {
        std::string teste;
        while (getline(usuariosarq1, teste)) {
            if (teste == usuario) {
                std::cout << "Usuário já existente!" << std::endl;
                std::cout << "Digite outro nome de usuário: ";
                getline(std::cin, usuario);
                std::cout << std::endl;
                
            }
        }
        usuariosarq1.close();
    }
    
    std::cout << "Digite aqui a senha: ";
    getline(std::cin, senha);
    std::cout << std::endl;
    
    std::cout << "Digite novamente para confirmar a senha: ";
    getline(std::cin, senhac);
    std::cout << std::endl;
    
    while (senhac != senha) {
        std::cout << "Senhas diferentes" << std::endl;
        std::cout << "Digite novamente para confirmar a senha: ";
        getline(std::cin, senhac);
        std::cout << std::endl;
    }
    
    std::ofstream usuariosarq2("usuariosenha.txt", std::ios::app);
    usuariosarq2 << usuario << "\n" << senha << "\n";
    usuariosarq2.close();
    
    std::cout << std::endl;
    std::cout << "USUARIO CRIADO COM SUCESSO!" << std::endl;
};





void exibirlogo(){

    std::cout << "===============================" << std::endl;
    std::cout << "           PANCADAO            " << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

};

void menu(){
  
    std::cout<<"Entre agora no melhor app de musica"<<std::endl;
    std::cout << std::endl;
    std::cout<<"Escolha uma opção: "<<std::endl;
    std::cout<<"1. Sign_up: "<<std::endl;
    std::cout<<"2. login: "<<std::endl;

};

int main(){
    
    
    exibirlogo();
    menu();
    int opcao=0;
    std::cin>>opcao;
    std::cin.ignore();

    if(opcao==1)
       sign_up();
    else if(opcao==2)
       login();
    
    
    
    return 0;}


