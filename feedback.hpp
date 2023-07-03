#ifndef FEEDBACK_HPP
#define FEEDBACK_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <map>

class Feed{
    public:

    void Fazer_comentario(std::string, std::string);
    
    void Ler_Comentario(std::string, std::string);

    private:
    std::list<std::string> _comentarios;
};

#endif