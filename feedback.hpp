#ifndef FEEDBACK_CPP
#define FEEDBACK_CPP
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Comentario{
    public:
    /// @brief Permite fazer um comentário em uma música. 
    ///
    /// O arquivo "Feedback.txt" é aberto e o usuário tem a possibilidade de 
    /// fazer um comentário. Após isso, o arquivo armazenará toda informação
    /// adicionada.
    ///
    /// @param musica String do nome da música.
    /// @param usuario String do nome do usuário.
    void Fazer_comentario(std::string, std::string);
    /// @brief Permite que um usuário leia um comentário em uma música.
    ///
    /// O arquivo "Feedback.txt" é aberto em modo leitura. Feito isso, linha por
    /// linha é percorrida com a finalidade de encontrar a música e o usuário
    /// especificado. Após isso, toda informação é armazenada no vetor 
    /// "_comentarios" e imprime a mensagem encontrada.
    /// 
    /// @param musica String do nome da música. 
    /// @param usuario String do nome do usuário. 
    void Ler_comentario(std::string, std::string);

    private:
    std::list<std::string> _comentarios;
};

class Curtida {
    public:
    /// @brief Adiciona um "Like" à música escolhida
    ///
    /// @param musica String do nome da música. 
    /// @param usuario String do nome do usuário. 
    void like(std::string, std::string);

    void dislike( std::string, std::string);
    /// @brief Conta o número de "Likes" e "Deslikes"
    ///
    /// @param Musica String do nome da música.  
    void ver_quatidade_curtias(std:: string);
    /// @brief Verifica se um usúario já deu ou não alguma reação em uma música.
    ///
    /// @param  usuario String do nome do usuário.
    /// @param  musica String do nome da música.
    /// @return Verdadeiro se encontrar o usuário, Falso caso contrário.
    bool verificacao_curtidas (std::string, std::string);
    /// @brief Remove uma linha de arquivo de curtidas
    ///
    /// @param usuario String do nome do usuário.
    /// @param musica String do nome da música.
    void removerLinha(std::string usuario, std::string musica);

    private:
    int Contl;
    int Contd;    
};

#endif