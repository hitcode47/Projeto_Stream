#include "cadastrousuario.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <functional>

/*Função de hash básica para criptografar as senhas*/
std::string hashSenha(const std::string& senha) {
    std::hash<std::string> hashFunc;
    return std::to_string(hashFunc(senha));
}

/* Este método é responsável por realizar o login de um usuário. 
Ele solicita o nome de usuário e a senha, 
lê as informações do arquivo "usuariosenha.txt" e verifica se as credenciais estão corretas.*/

void Login::login() {
    std::string usuario, senha, testeusuario, testesenha;
    
    std::ifstream confirma("usuariosenha.txt");

    if (confirma.is_open()) {
        bool usuarioEncontrado = false;
        bool loginBemSucedido = false;

        while (!loginBemSucedido) {
            usuarioEncontrado = false;
            std::cout << "Digite aqui o nome de usuario: ";
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

                if (hashSenha(senha) == testesenha) {
                    std::cout << "LOGIN BEM SUCEDIDO!" << std::endl;
                    std::cout << std::endl;
                    loginBemSucedido = true;
                } 
                else {
                    std::cout << "Senha incorreta!" << std::endl;
                }
            }
            else {
                std::cout << "Nome de usuario nao encontrado!" << std::endl;
            }
            confirma.clear();
            confirma.seekg(0, std::ios::beg);
        }

        confirma.close();
    }
    else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
    }
};

/* Este método permite que um novo usuário crie uma conta. 
Ele solicita um nome de usuário e uma senha, 
verifica se o usuário já existe no arquivo "usuariosenha.txt" e, 
em seguida, armazena as informações no arquivo, caso sejam válidas.*/

void Signup::sign_up() {
    std::string usuario, senha, senhac;
    
    std::cout << "Digite aqui o nome de usuario: ";
    getline(std::cin, usuario);
    std::cout << std::endl;
    
    std::ifstream usuariosarq1("usuariosenha.txt");
    if (usuariosarq1.is_open()) {
        std::string teste;
        while (getline(usuariosarq1, teste)) {
            if (teste == usuario) {
                std::cout << "Usuario ja existente!" << std::endl;
                std::cout << "Digite outro nome de usuario: ";
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
    usuariosarq2 << usuario << "\n" << hashSenha(senha) << "\n";
    usuariosarq2.close();
    
    std::cout << "USUARIO CRIADO COM SUCESSO!" << std::endl;
    std::cout << std::endl;
};




/*Permite que o usuário altere o nome de usuário. 
Solicita o nome de usuário atual e a senha atual, verifica se as credenciais estão corretas, 
solicita o novo nome de usuário e atualiza as informações no arquivo "usuariosenha.txt".*/


void ChangeUsername::change_username() {
    std::string usuario, senha, novoUsuario;

    std::cout << "Digite o nome de usuario atual: ";
    getline(std::cin, usuario);
    std::cout << std::endl;

    std::cout << "Digite a senha atual: ";
    getline(std::cin, senha);
    std::cout << std::endl;

    std::ifstream usuariosArquivo("usuariosenha.txt");
    if (usuariosArquivo.is_open()) {
        std::string linha;
        std::vector<std::string> usuarios;

        while (getline(usuariosArquivo, linha)) {
            usuarios.push_back(linha);
        }

        usuariosArquivo.close();

        auto itUsuario = std::find(usuarios.begin(), usuarios.end(), usuario);
        auto itSenha = itUsuario;  // Atualiza para itUsuario

        if (itUsuario != usuarios.end() && itSenha != usuarios.end()) {
            ++itSenha;  // Avança para a próxima linha (senha)

            if (*(itSenha) == hashSenha(senha)) {  // Verifica a senha original
                std::cout << "Digite o novo nome de usuario: ";
                getline(std::cin, novoUsuario);
                std::cout << std::endl;

                while (std::find(usuarios.begin(), usuarios.end(), novoUsuario) != usuarios.end()) {
                    std::cout << "O nome de usuario escolhido ja esta em uso!" << std::endl;
                    std::cout << "Digite outro novo nome de usuario: ";
                    getline(std::cin, novoUsuario);
                    std::cout << std::endl;
                }

                *itUsuario = novoUsuario;

                std::ofstream usuariosArquivo("usuariosenha.txt", std::ios::trunc);
                if (usuariosArquivo.is_open()) {
                    for (const std::string& u : usuarios) {
                        usuariosArquivo << u << '\n';
                    }
                    usuariosArquivo.close();

                    std::cout << "Nome de usuario alterado com sucesso!" << std::endl;
                } else {
                    std::cout << "Erro ao abrir o arquivo de usuarios!" << std::endl;
                }
            } else {
                std::cout << "Senha incorreta!" << std::endl;
            }
        } else {
            std::cout << "Nome de usuario nao encontrado!" << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo de usuarios!" << std::endl;
    }
}




/*Este método inicia o aplicativo. 
Ele chama o método exibirlogo() para exibir o logotipo*/ 

void Iniciar::exibirlogo() {
    std::cout << "===============================" << std::endl;
    std::cout << "           PANCADAO            " << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}


/*Este método exibe um menu para o usuário, 
onde ele pode escolher entre fazer o login (utilizando a classe Login) 
ou realizar o cadastro (utilizando a classe Signup).*/

void Iniciar::menu() {
    std::cout << "Entre agora no melhor app de musica" << std::endl;
    std::cout << std::endl;
    std::cout << "Digite 1, 2 ou 3 para escolher uma opcao: " << std::endl;
    std::cout << "1. Sign_up" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Trocar nome de usuario" << std::endl;
   



   int opcao = 0;
    while (true) {
        if (!(std::cin >> opcao) || (opcao != 1 && opcao != 2 && opcao != 3)) {
            std::cout << "Opcao invalida!!"<< std::endl;
            std::cout << "Digite (1) para sign_up, (2) para login ou (3) para mudar o nome de usuario: "<< std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    std::cin.ignore();


    if (opcao == 1) {
        Signup fazer;
        fazer.sign_up();
    }
    else if (opcao == 2) {
        Login fazer;
        fazer.login();
    }
    else if (opcao == 3) {
        ChangeUsername fazer;
        fazer.change_username();
    }

};






/*Este método inicia o aplicativo. 
Ele chama o método exibirlogo() 
para exibir o logotipo e, em seguida,
chama o método menu() para exibir o menu principal.
*/

void Iniciar::run() {
    exibirlogo();
    menu();
};


int main(){
    
    Iniciar app;
    
    app.run();
    
    return 0;
}

