#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

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

#endif