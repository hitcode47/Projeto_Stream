#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "cadastrousuario.hpp"
#include "feedback.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "doctest.h"




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