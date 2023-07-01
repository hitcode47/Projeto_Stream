#pragma once
#include "pesquisa.hpp"
#include "cadastrousuario.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <functional>

bool avança=false;
std::string nomedeacesso;

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

                if (hashSenha(senha) == testesenha) {
                    std::cout << "LOGIN BEM SUCEDIDO!" << std::endl;
                    std::cout << std::endl;
                    loginBemSucedido = true;
                    nomedeacesso=usuario;
                    avança=true;
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

    // Verifica se o campo do nome de usuário está vazio
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

        // Solicita outro nome de usuário
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

    // Verifica se o campo de senha está vazio
    while (senha.empty()) {
        std::cout << "Campo de senha vazio!" << std::endl;
        std::cout << "Digite a senha novamente: ";
        getline(std::cin, senha);
        std::cout << std::endl;
    }

    std::cout << "Digite novamente para confirmar a senha: ";
    getline(std::cin, senhac);
    std::cout << std::endl;

    // Verifica se o campo de confirmação de senha está vazio
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

    std::cout << "Digite o nome de usuário atual: ";
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
                std::cout << "Digite o novo nome de usuário: ";
                getline(std::cin, novoUsuario);
                std::cout << std::endl;

                while (std::find(usuarios.begin(), usuarios.end(), novoUsuario) != usuarios.end()) {
                    std::cout << "O nome de usuário escolhido já está em uso!" << std::endl;
                    std::cout << "Digite outro novo nome de usuário: ";
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

                    std::cout << "Nome de usuário alterado com sucesso!" << std::endl;
                } else {
                    std::cout << "Erro ao abrir o arquivo de usuários!" << std::endl;
                }
            } else {
                std::cout << "Senha incorreta!" << std::endl;
            }
        } else {
            std::cout << "Nome de usuário não encontrado!" << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo de usuários!" << std::endl;
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
    
while(!avança){
    
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




Pesquisa::Pesquisar::Pesquisar(std::string palavra) : _palavra(palavra){}

bool Pesquisa::Pesquisar::Encontrar() {
    
    if(!_palavra.empty()){
        _palavra[0] = std::toupper(_palavra[0]);
        for(int i=1; i < _palavra.size(); i++){
            if (_palavra[i-1] == ' ') {
            _palavra[i] = std::toupper(_palavra[i]);
            }else{
            _palavra[i] = std::tolower(_palavra[i]);
            }

        }
    }// Converte pra minuscula e as iniciais em maiusculo

    std::ifstream Musica_Exemplo("Musica_Exemplo.txt");
    std::string linha;

    if (Musica_Exemplo.is_open()) {
    }
    else {
        std::cout << "O nome do arquivo.txt deve estar diferente do meu código." << std::endl;
    
    }//abrindo o arquivo.
    




   while (getline(Musica_Exemplo, linha)) {
        std::size_t pos = linha.find(",");
        if (pos != std::string::npos) {
            std::string titulo = linha.substr(0, pos);
            
            std::vector<std::string> palavras_subdivididas;
            std::string palavra;
            std::istringstream iss(_palavra);

            while (iss >> palavra) {
                palavras_subdivididas.push_back(palavra);
            }
            int contador_de_palavras=0;
            int i=0;

            while (i < palavras_subdivididas.size()){

                if (titulo.find(palavras_subdivididas[i]) != std::string::npos) {
                    contador_de_palavras++;
                }

            i++;    
            }
            _resultados.insert(std::make_pair(contador_de_palavras, titulo));
        }
        
    }

    //1° obtenho cada linha e guardo em linha, depois encntro a 1 ocorrencia que seria no caso de copiar toda a string
    //antes do link(ou seja a substring), pois não quero exibir isso para o usuario. Logo após eu encontro dentro dessa substring
    //a palavra "_palavra" e assim guardo em _resultados.
    for (auto& pair : _resultados) {
        std::string& value = pair.second;
        if (!value.empty()) {
            value[0] = std::toupper(value[0]);
            for (size_t i = 1; i < value.size(); i++) {
                if (value[i - 1] == ' ') {
                    value[i] = std::toupper(value[i]);
                }
            }
        }
    }
    //converto tudo que esta depois do espaço para letra maiuscula.

    bool encontrouResultados = false;
    for (const auto& pair : _resultados) {
        if (pair.first > 0) {
            encontrouResultados = true;
            break;
        }
    }

    if (!encontrouResultados) {
        std::cout << "Nenhum resultado encontrado para: " << _palavra << std::endl;
        return false;
    }else{
            std::cout << "Voce deseja: " << std::endl;
            int count = 1;
            for (auto it = _resultados.rbegin(); it != _resultados.rend(); ++it) {
                if(it->first != 0){                
                    std::cout << "(" << count << ") " << it->second << std::endl;
                    _encontrado[count] = it->second;
                    count++;
                    if (count == 4) {
                        break;
                    }
                }
            }
        }

        
    int opcao;
    bool encontrado = false;

    std::cout << "Digite o numero desejado" << std::endl;
    while(encontrado == false){
        std::string opcao_string;
        std::getline(std::cin, opcao_string); // lê a string.

        // Verificar se a entrada é um número inteiro
        try {
            opcao = std::stoi(opcao_string);
        } 
    
        catch (...) {
            std::cout << "Entrada invalida. Digite o numero desejado." << std::endl;
            continue;
        }
        for (auto it = _encontrado.begin(); it != _encontrado.end(); it++){
            if(opcao == it->first){
                std::cout << "Voce escolheu: " << it->second << std::endl;
                
                encontrado = true;
                break;
            }
        
        }

    }

return true;
}





int main(){
    
    Iniciar app;
    
    app.run();
    
    std::cout<<"BEM VINDO "<<nomedeacesso<<std::endl;
    std::cout<<std::endl;
    
    std::string palavra;
    std::cout << "Digite sua musica/Artista: " << std::endl;
    std::getline(std::cin, palavra);
    Pesquisa::Pesquisar Busca(palavra);
    Busca.Encontrar();
    
    return 0;
}
