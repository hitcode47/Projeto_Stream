#ifndef cadastrousuario_hpp
#define cadastrousuario_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <map>     
#include <functional>

/// @brief Função de hash básica para criptografar as senhas.
///  
/// @param senha A senha a ser criptografada.
/// @return A senha criptografada.
std::string hashSenha(const std::string& senha);

class Login {
public:
    /// @brief Realiza o login de um usuário.
    ///
    /// Solicita o nome de usuário e a senha, lê as informações do arquivo
    /// "usuariosenha.txt" e verifica se as credenciais estão certas.
    ///
   void login();
   std::string getternomedeusuario();

private:
   std::string _nomedeusuario;
};

class Signup {
public:
    /// @brief Cadastra uma nova conta de usuário.
    ///
    /// Solicita um nome de usuário e uma senha, verifica se o usuário já existe
    /// no arquivo "usuariosenha.txt" e, em seguida, armazena as informações no
    /// próprio arquivo, caso sejam válidas.
    ///    
    void sign_up();
};

class ChangeUsername {
public:
    /// @brief Altera o nome de usuário.
    ///
    /// Solicita o nome de usuário e senha atuais, verifica se as credenciais
    /// estão corretas, solicita o novo nome de usuário e atualiza as informações
    /// no arquivo "usuariosenha.txt".
    ///
    void change_username();
};

class DeleteAccount {
public:
    /// @brief Exclui a conta de um usuário.
    ///
    /// Solcita o nome de usário, bem como sua senha e verifica a veracidade das
    /// informações. Após isso, exclui as informações do usuário no arquivo
    /// "usuariosenha.txt".
    ///
    void delete_account();
    /// @brief Verifica se há um determinado usuário no arquivo "usuariosenha.txt".
    ///
    /// @param usuario Suposto usuário cadastrado.
    /// @return Verdadeiro se o usuário existir, Falso caso contrário.
    bool verificar_existencia_usuario(const std::string& usuario);

private:
    /// @brief Verifica se as crendenciais do usuário estão corretas.
    ///
    /// @param usuario O nome do usuário em verificação. 
    /// @param senha A senha do usuário em verificação.
    /// @return Verdadeiro se as credenciais estão corretas, Falso caso contrário.
    bool verificar_credenciais(const std::string& usuario, const std::string& senha);
    /// @brief Deleta as informações do usuário.
    ///
    /// @param usuario O nome do usuário em verificação.
    void delete_account(const std::string& usuario);
};

class Iniciar {
public:
    /// @brief Exibe a logotipo escolhida para o projeto 
    void exibirlogo();
    /// @brief Exibe o menu principal do aplicativo.
    /// 
    /// O usuário poderá escolher entre fazer o login, realizar o cadastro,
    /// trocar o nome de usuário ou apagar uma conta existente.
    ///
    /// @return O nome do usuário após o login.
    std::string menu(); 
};

#endif
