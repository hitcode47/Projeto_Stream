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

    void Fazer_comentario(std::string, std::string);
    
    void Ler_comentario(std::string, std::string);

    private:
    std::list<std::string> _comentarios;
};

class Curtida {
    public:
    void like(std::string, std::string);

    void dislike( std::string, std::string);

    void ver_quatidade_curtias(std:: string);
    
    bool verificacao_curtidas (std::string, std::string);

    void removerLinha(std::string usuario, std::string musica);

    private:
    int Contl;
    int Contd;
    
   
    
};


#endif