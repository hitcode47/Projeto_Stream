#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "cadastrousuario.hpp"
#include "feedback.hpp"
#include "reproducao.hpp"
#include "musicas.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "doctest.h"
#include "pesquisa.hpp"

TEST_CASE("hashSenha gerando hash corretamente") {
    std::string password = "password123";
    std::string expectedHash = "123456789"; 
    
    std::string actualHash = hashSenha(password);

    CHECK(actualHash == expectedHash);
}


TEST_CASE("Login bem sucedido") {
    
    Login login;

  
    std::ofstream testFile("usuariosenha.txt");
    testFile << "username\n" << hashSenha("password") << "\n";
    testFile.close();

    
    std::istringstream input("username\npassword\n");

    
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf());

  
    login.login();

    
    std::cin.rdbuf(oldCinBuffer);

   
    CHECK(login.getternomedeusuario() == "username");
}



TEST_CASE("Signup criando novo usuário") {
 
    Signup signup;

    std::istringstream input("newuser\npassword\npassword\n");

   
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf());

  
    signup.sign_up();

    
    std::cin.rdbuf(oldCinBuffer);

  
    std::ifstream userFile("usuariosenha.txt");
    std::string username, password;

    bool userExists = false;
    while (getline(userFile, username) && getline(userFile, password)) {
        if (username == "newuser" && password == hashSenha("password")) {
            userExists = true;
            break;
        }
    }

    CHECK(userExists);
}



TEST_CASE("ChangeUsername trocando nome") {

    ChangeUsername changeUsername;

    
    std::ofstream testFile("usuariosenha.txt");
    testFile << "currentuser\n" << hashSenha("password") << "\n";
    testFile.close();

    
    std::istringstream input("currentuser\npassword\nnewuser\n");

 
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf());

    
    changeUsername.change_username();

    
    std::cin.rdbuf(oldCinBuffer);

    
    std::ifstream userFile("usuariosenha.txt");
    std::string username, password;

    bool usernameUpdated = false;
    while (getline(userFile, username) && getline(userFile, password)) {
        if (username == "newuser") {
            usernameUpdated = true;
            break;
        }
    }

    CHECK(usernameUpdated);
}


TEST_CASE("DeleteAccount apagando conta") {
    
    DeleteAccount deleteAccount;

    
    std::ofstream testFile("usuariosenha.txt");
    testFile << "existinguser\n" << hashSenha("password") << "\n";
    testFile.close();

    
    std::istringstream input("existinguser\npassword\n");
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf());

    
    deleteAccount.delete_account();

    
    std::cin.rdbuf(oldCinBuffer);

  
    std::ifstream userFile("usuariosenha.txt");
    std::string username, password;

    bool userExists = false;
    while (getline(userFile, username) && getline(userFile, password)) {
        if (username == "existinguser" && password == hashSenha("password")) {
            userExists = true;
            break;
        }
    }

    CHECK(!userExists);
}




TEST_CASE("Teste da classe Comentario") {

    Comentario comentario;
    std::string musica = "Nome da Musica";
    std::string usuario = "Nome do Usuario";

    SUBCASE("Teste do método Fazer_comentario") {

        comentario.Fazer_comentario(musica, usuario);
        // Verifique se o arquivo "FeedBack.txt" foi criado e se o comentário foi registrado corretamente
        std::ifstream arquivo("FeedBack.txt");
        std::string linha;
        bool comentarioEncontrado = false;
        while (getline(arquivo, linha)) {
            if (linha.find(musica) != std::string::npos && linha.find(usuario) != std::string::npos) {
                comentarioEncontrado = true;
                break;
            }
        }
        arquivo.close();
        CHECK(comentarioEncontrado);
    }

    SUBCASE("Teste do método Ler_comentario") {
        
        comentario.Ler_comentario(musica, usuario);
        // Verifique se os comentários são lidoscorretamente do arquivo "FeedBack.txt"
        // Para testar isso usando a biblioteca doctest, você pode usar capturar a saída do cout e verificar se ela contém os comentários esperados
        // Aqui está um exemplo simplificado:
        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf()); // Redireciona a saída do cout para o stringstream
        comentario.Ler_comentario(musica, usuario);
        std::cout.rdbuf(coutBuffer); // Restaura o buffer de saída padrão

        // Verifique se a saída contém os comentários esperados
        std::string outputStr = output.str();
        CHECK(outputStr.find("Comentarios encontrados:") != std::string::npos);
        CHECK(outputStr.find("Nome do Comentario") != std::string::npos);
    }
}

TEST_CASE("Teste da classe Curtida") {

    Curtida curtida;
    std::string musica = "Nome da Musica";
    std::string usuario = "Nome do Usuario";

    SUBCASE("Teste do método like") {

        curtida.like(musica, usuario);
        // Verifique se o arquivo "Curtidas.txt" foi criado e se o like foi registrado corretamente
        std::ifstream arquivo("Curtidas.txt");
        std::string linha;
        bool likeEncontrado = false;
        while (getline(arquivo, linha)) {
            if (linha.find(musica) != std::string::npos && linha.find(usuario) != std::string::npos && linha.find("Like") != std::string::npos) {
                likeEncontrado = true;
                break;
            }
        }
        arquivo.close();
        CHECK(likeEncontrado);
    }

    SUBCASE("Teste do método dislike") {

        curtida.dislike(musica, usuario);
        // Verifique se o arquivo "Curtidas.txt" foi criado e se o dislike foi registrado corretamente
        std::ifstream arquivo("Curtidas.txt");
        std::string linha;
        bool dislikeEncontrado = false;
        while (getline(arquivo, linha)) {
            if (linha.find(musica) != std::string::npos && linha.find(usuario) != std::string::npos && linha.find("Dislike") != std::string::npos) {
                dislikeEncontrado = true;
                break;
            }
        }
        arquivo.close();
        CHECK(dislikeEncontrado);
    }

    SUBCASE("Teste do método ver_quatidade_curtias"){

        curtida.ver_quatidade_curtias(musica);
        // Verifique se a quantidade de likes e dislikes é exibida corretamente
        // Para testar isso usando a biblioteca doctest, você pode usar capturar a saída do cout e verificar se ela contém as informações esperadas
        // Aqui está um exemplo simplificado:
        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf()); // Redireciona a saída do cout para o stringstream
        curtida.ver_quatidade_curtias(musica);
        std::cout.rdbuf(coutBuffer); // Restaura o buffer de saída padrão

        // Verifique se a saída contém as informações esperadas
        std::string outputStr = output.str();
        CHECK(outputStr.find("Quantidade de likes:") != std::string::npos);
        CHECK(outputStr.find("Quantidade de dislikes:") != std::string::npos);
    }
}

TEST_CASE("Pesquisa::Pesquisar") {
    SUBCASE("Encontrar") {
        Pesquisa::Pesquisar busca("musica");
        bool resultado = busca.Encontrar();
        CHECK(resultado == true);
        std::string musicaEscolhida = busca.Retorno_Pesquisa();
        CHECK(!musicaEscolhida.empty());
    }

    SUBCASE("Não Encontrar"){
        Pesquisa::Pesquisar busca("xyz");
        bool resultado = busca.Encontrar();
        CHECK(resultado == false);
        std::string musicaEscolhida = busca.Retorno_Pesquisa();
        CHECK(musicaEscolhida.empty());
    }
}
TEST_CASE("Teste da classe reproducao") {

    reproducao player;

    SUBCASE("Teste do método Executar") {

        std::string nomeArquivo = "Musica_Exemplo.txt";
        std::string nomeMusica = "Eagles - Hotel California";

        player.Executar(nomeArquivo, nomeMusica);
        CHECK(player.Retornar_nome() == nomeMusica);
    }

    SUBCASE("Teste do método Pular_p_frente") {

        std::string nomeArquivo = "Musica_Exemplo.txt";
        Sleep(5000);
        player.Pular_p_frente(nomeArquivo);

    }

    SUBCASE("Teste do método Pular_p_tras") {

        std::string nomeArquivo = "Musica_Exemplo.txt";
        Sleep(5000);
        player.Pular_p_tras(nomeArquivo);
        
    }
}
