#ifndef PESQUISA_H
#define PESQUISA_H

#include <string>
#include <iostream>
#include <fstream>

namespace Pesquisa {
    class Pesquisar {
    public:
        Pesquisar(std::string palavra);
        void Encontrar();
    private:
    std::string _palavra;  
    };
    
}

#endif