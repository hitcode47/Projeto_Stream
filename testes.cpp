#include "cadastrousuario.hpp"
#include "feedback.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "doctest.h"


DOCTEST_TEST_CASE("Testando a função hashSenha") {
    CHECK(hashSenha("123456") == "126381531049624");
    CHECK(hashSenha("abcdef") == "1099511627776");
    CHECK(hashSenha("senha") == "1099511627776");
}

DOCTEST_TEST_CASE("Testando a função login") {
  
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq << "admin\n";
    usuariosarq << hashSenha("admin") << "\n";
    usuariosarq << "user\n";
    usuariosarq << hashSenha("user") << "\n";
    usuariosarq.close();

    Login l;

    SUBCASE("Login com credenciais corretas") {
     
        std::istringstream input("admin\nadmin\n");
        std::ostringstream output;
        l.login(input, output);
        CHECK(output.str() == "LOGIN BEM SUCEDIDO!\n\n");
    }

    SUBCASE("Login com senha incorreta") {
        
        std::istringstream input("admin\nwrongpassword\n");
        std::ostringstream output;
        l.login(input, output);
        CHECK(output.str() == "Senha incorreta!\n");
    }

    SUBCASE("Login com usuário inexistente") {
        
        std::istringstream input("nonexistentuser\npassword\n");
        std::ostringstream output;
        l.login(input, output);
        CHECK(output.str() == "Nome de usuario nao encontrado!\n");
    }
}

DOCTEST_TEST_CASE("Testando a função sign_up") {
    // Create an empty test file
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq.close();

    Signup s;

    SUBCASE("Cadastro com nome de usuário válido") {
        // Provide a valid username and password
        std::istringstream input("newuser\npassword\npassword\n");
        std::ostringstream output;
        s.sign_up(input, output);
        CHECK(output.str() == "USUARIO CRIADO COM SUCESSO!\n\n");
    }

    SUBCASE("Cadastro com nome de usuário já existente") {
       
        std::istringstream input("admin\npassword\npassword\n");
        std::ostringstream output;
        s.sign_up(input, output);
        CHECK(output.str() == "Usuario ja existente!\n");
    }

    SUBCASE("Cadastro com campo de senha vazio") {
        
        std::istringstream input("newuser\n\npassword\n");
        std::ostringstream output;
        s.sign_up(input, output);
        CHECK(output.str() == "Campo de senha vazio!\n");
    }
}

DOCTEST_TEST_CASE("Testando a função change_username") {
    
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq << "admin\n";
    usuariosarq << hashSenha("admin") << "\n";
    usuariosarq << "user\n";
    usuariosarq << hashSenha("user") << "\n";
    usuariosarq.close();

    ChangeUsername cu;

    SUBCASE("Alteração de nome de usuário com credenciais corretas") {
       
        std::istringstream input("admin\nadmin\nnewadmin\n");
        std::ostringstream output;
        cu.change_username(input, output);
        CHECK(output.str() == "Nome de usuario alterado com sucesso!\n");
    }

    SUBCASE("Alteração de nome de usuário com senha incorreta") {
        
        std::istringstream input("admin\nwrongpassword\nnewadmin\n");
        std::ostringstream output;
        cu.change_username(input, output);
        CHECK(output.str() == "Senha incorreta!\n");
    }

    SUBCASE("Alteração de nome de usuário com usuário inexistente") {
        
        std::istringstream input("nonexistentuser\npassword\nnewuser\n");
        std::ostringstream output;
        cu.change_username(input, output);
        CHECK(output.str() == "Nome de usuario nao encontrado!\n");
    }
}

DOCTEST_TEST_CASE("Testando a função delete_account") {
   
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq << "admin\n";
    usuariosarq << hashSenha("admin") << "\n";
    usuariosarq << "user\n";
    usuariosarq << hashSenha("user") << "\n";
    usuariosarq.close();

    DeleteAccount da;

    SUBCASE("Exclusão de conta com credenciais corretas") {
 
        std::istringstream input("admin\nadmin\n");
        std::ostringstream output;
        da.delete_account(input, output);
        CHECK(output.str() == ""); 
    }

    SUBCASE("Exclusão de conta com senha incorreta") {
        
        std::istringstream input("admin\nwrongpassword\n");
        std::ostringstream output;
        da.delete_account(input, output);
        CHECK(output.str() == "Credenciais invalidas. Nao foi possivel apagar a conta.\n");
    }

    SUBCASE("Exclusão de conta com usuário inexistente") {
       
        std::istringstream input("nonexistentuser\npassword\n");
        std::ostringstream output;
        da.delete_account(input, output);
        CHECK(output.str() == "A conta que deseja excluir nao existe.\n");
    }
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

    SUBCASE("Teste do método ver_quatidade_curtias") {

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