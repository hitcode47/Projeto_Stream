#ifndef cadastrousuario_hpp
#define cadastrousuario_hpp

/**
 * @file cadastrousuario.hpp
 * @brief Arquivo de cabeçalho contendo as definições das classes relacionadas ao cadastro de usuários.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

/**
 * @brief Função de hash básica para criptografar as senhas.
 * @param senha A senha a ser criptografada.
 * @return A senha criptografada.
 */
std::string hashSenha(const std::string& senha);

/**
 * @brief Classe responsável por realizar o login de um usuário.
 */
class Login {
public:
    /**
     * @brief Realiza o login de um usuário.
     * Solicita o nome de usuário e a senha, lê as informações do arquivo "usuariosenha.txt" e verifica se as credenciais estão corretas.
     */
   void login();
   std::string getternomedeusuario();

private:
   std::string _nomedeusuario;
   

};

/**
 * @brief Classe responsável pelo cadastro de novos usuários.
 */
class Signup {
public:
    /**
     * @brief Cria uma nova conta de usuário.
     * Solicita um nome de usuário e uma senha, verifica se o usuário já existe no arquivo "usuariosenha.txt" e, em seguida, armazena as informações no arquivo, caso sejam válidas.
     */
    void sign_up();
};

/**
 * @brief Classe responsável por alterar o nome de usuário.
 */
class ChangeUsername {
public:
    /**
     * @brief Altera o nome de usuário.
     * Solicita o nome de usuário atual e a senha atual, verifica se as credenciais estão corretas, solicita o novo nome de usuário e atualiza as informações no arquivo "usuariosenha.txt".
     */
    void change_username();
};


class DeleteAccount {
public:
    void delete_account();
    bool verificar_existencia_usuario(const std::string& usuario);

private:
    bool verificar_credenciais(const std::string& usuario, const std::string& senha);
    void delete_account(const std::string& usuario);
};



/**
 * @brief Classe responsável por iniciar o aplicativo.
 */
class Iniciar {
public:
    /**
     * @brief Exibe o logotipo do aplicativo.
     */
    void exibirlogo();

    /**
     * @brief Exibe o menu principal do aplicativo.
     * O usuário pode escolher entre fazer o login, realizar o cadastro ou trocar o nome de usuário.
     */
    std::string menu();

    
};

#endif
