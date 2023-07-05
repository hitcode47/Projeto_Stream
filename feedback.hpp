#ifndef FEEDBACK_CPP
#define FEEDBACK_CPP

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <map>

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
    

    private:
    int Contl;
    int Contd;
    bool verificacao_curtidas (std::string);
    bool sobreescrever(std::string,std::streampos&);
   
    
};


#endif