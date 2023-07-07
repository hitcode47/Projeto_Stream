#include "cadastrousuario.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <map>
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
                getline(confirma, testesenha);  /*Descarta a linha da senha correspondente*/
            }

            if (usuarioEncontrado) {
                std::cout << "Digite aqui a senha: ";
                getline(std::cin, senha);
                std::cout << std::endl;

                if (hashSenha(senha) == testesenha) {
                    std::cout << "LOGIN BEM SUCEDIDO!" << std::endl;
                    std::cout << std::endl;
                    loginBemSucedido = true;
                    _nomedeusuario=usuario;
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

    /*Verifica se o campo do nome de usuário está vazio*/ 
    while (usuario.empty()) {
        std::cout << "Campo de nome de usuario vazio!" << std::endl;
        std::cout << "Digite o nome de usuario novamente: ";
        getline(std::cin, usuario);
        std::cout << std::endl;
    }

    std::ifstream usuariosarq1("usuariosenha.txt");
    if (usuariosarq1.is_open()) {
        std::string teste;
        bool usuarioExistente = false;

        while (getline(usuariosarq1, teste)) {
            if (teste == usuario) {
                usuarioExistente = true;
                break;
            }
        }
        usuariosarq1.close();

        /*Solicita outro nome de usuário*/ 
        while (usuarioExistente) {
            std::cout << "Usuario ja existente!" << std::endl;
            std::cout << "Digite outro nome de usuario: ";
            getline(std::cin, usuario);
            std::cout << std::endl;

            usuariosarq1.open("usuariosenha.txt");
            usuarioExistente = false;

            while (getline(usuariosarq1, teste)) {
                if (teste == usuario) {
                    usuarioExistente = true;
                    break;
                }
            }
            usuariosarq1.close();
        }
    }

    std::cout << "Digite aqui a senha: ";
    getline(std::cin, senha);
    std::cout << std::endl;

    /*Verifica se o campo de senha está vazio*/ 
    while (senha.empty()) {
        std::cout << "Campo de senha vazio!" << std::endl;
        std::cout << "Digite a senha novamente: ";
        getline(std::cin, senha);
        std::cout << std::endl;
    }

    std::cout << "Digite novamente para confirmar a senha: ";
    getline(std::cin, senhac);
    std::cout << std::endl;

    /*Verifica se o campo de confirmação de senha está vazio*/
    while (senhac.empty()) {
        std::cout << "Campo de confirmacao de senha vazio!" << std::endl;
        std::cout << "Digite novamente para confirmar a senha: ";
        getline(std::cin, senhac);
        std::cout << std::endl;
    }

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
}




/*Permite que o usuário altere o nome de usuário. 
Solicita o nome de usuário atual e a senha atual, verifica se as credenciais estão corretas, 
solicita o novo nome de usuário e atualiza as informações no arquivo "usuariosenha.txt".*/


void ChangeUsername::change_username() {
    std::string usuario, senha, novoUsuario;

    std::cout << "Digite o nome de usuario atual: ";
    getline(std::cin, usuario);
    std::cout << std::endl;

    std::cout << "Digite a senha: ";
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
        auto itSenha = itUsuario;  /*Atualiza para itUsuario*/

        if (itUsuario != usuarios.end() && itSenha != usuarios.end()) {
            ++itSenha;  /*Avança para a próxima linha (senha)*/

            if (*(itSenha) == hashSenha(senha)) {  /*Verifica a senha original*/
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


void DeleteAccount::delete_account() {
    std::string usuario, senha;

    std::cout << "Digite o nome de usuario: ";
    getline(std::cin, usuario);
    std::cout << std::endl;

    std::cout << "Digite a senha: ";
    getline(std::cin, senha);
    std::cout << std::endl;

    if (verificar_credenciais(usuario, senha)) {
        if (verificar_existencia_usuario(usuario)) {
            delete_account(usuario);
        } else {
            std::cout << "A conta que deseja excluir nao existe." << std::endl;
        }
    } else {
        std::cout << "Credenciais invalidas. Nao foi possivel apagar a conta." << std::endl;
    }
}



bool DeleteAccount::verificar_credenciais(const std::string& usuario, const std::string& senha) {
    std::ifstream usuariosArquivo("usuariosenha.txt");
    if (usuariosArquivo.is_open()) {
        std::string testeusuario, testesenha;

        while (getline(usuariosArquivo, testeusuario)) {
            if (usuario == testeusuario) {
                getline(usuariosArquivo, testesenha);
                break;
            }
            getline(usuariosArquivo, testesenha);  /*Descarta a linha da senha correspondente*/
        }

        usuariosArquivo.close();

        /*Verifica se o usuário foi encontrado e se a senha corresponde*/
        if (!testesenha.empty() && hashSenha(senha) == testesenha) {
            return true;
        }
    }

    return false;
}


void DeleteAccount::delete_account(const std::string& usuario) {
    std::ifstream usuariosArquivo("usuariosenha.txt");
    if (usuariosArquivo.is_open()) {
        std::string linha;
        std::vector<std::string> usuarios;

        while (getline(usuariosArquivo, linha)) {
            if (linha == usuario) {
                getline(usuariosArquivo, linha); 
            } else {
                usuarios.push_back(linha);
            }
        }

        usuariosArquivo.close();

        std::ofstream usuariosArquivoOut("usuariosenha.txt", std::ios::trunc);
        if (usuariosArquivoOut.is_open()) {
            for (const std::string& u : usuarios) {
                usuariosArquivoOut << u << '\n';
            }
            usuariosArquivoOut.close();

            std::cout << "Conta do usuario " << usuario << " apagada com sucesso!" << std::endl;
            return; /*Retornar após a exclusão bem-sucedida*/
        } else {
            std::cout << "Erro ao abrir o arquivo de usuarios!" << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo de usuários!" << std::endl;
    }
}


bool DeleteAccount::verificar_existencia_usuario(const std::string& usuario) {
    std::ifstream usuariosArquivo("usuariosenha.txt");
    if (usuariosArquivo.is_open()) {
        std::string testeusuario;

        while (getline(usuariosArquivo, testeusuario)) {
            if (usuario == testeusuario) {
                usuariosArquivo.close();
                return true;
            }
            getline(usuariosArquivo, testeusuario);  /*Descarta a linha da senha correspondente*/
        }

        usuariosArquivo.close();
    }

    return false;
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

std::string  Login::getternomedeusuario(){
    return _nomedeusuario;
}



/*Este método exibe um menu para o usuário, 
onde ele pode escolher entre fazer o login (utilizando a classe Login) 
ou realizar o cadastro (utilizando a classe Signup).*/

std::string Iniciar::menu() {

while(true){
    std::cout << "Entre agora no melhor app de musica" << std::endl;
    std::cout << std::endl;
    std::cout << "Digite 1, 2, 3 ou 4 para escolher uma opcao: " << std::endl;
    std::cout << "1. Sign_up" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Trocar nome de usuario" << std::endl;
    std::cout << "4. Apagar conta de usuario" << std::endl;
   

   

   int opcao = 0;
    while (true) {
        if (!(std::cin >> opcao) || (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)) {
            std::cout << "Opcao invalida!!"<< std::endl;
            std::cout << "Digite (1) para sign_up, (2) para login, (3) para mudar o nome de usuario ou (4) para apagar conta de usuario: "<< std::endl;

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
        std::string retorno;
        Login fazer;
        fazer.login();
        retorno = fazer.getternomedeusuario();
        return retorno;
        break;
    }
    else if (opcao == 3) {
        ChangeUsername fazer;
        fazer.change_username();
    }
    else if (opcao == 4) {
        DeleteAccount fazer;
        fazer.delete_account();
    }
}
};





