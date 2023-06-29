#ifndef PESQUISA_HPP
#define PESQUISA_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>

namespace Pesquisa {
    class Pesquisar {
    public:
        Pesquisar(std::string palavra);
        bool Encontrar();
        

    private:
    std::string _palavra;  
    std::vector<std::string> _resultados;
    std::map<double, std::string> _encontrado;
    };
    
}

#endif