#ifndef PESQUISA_HPP
#define PESQUISA_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>
#include <sstream>


namespace Pesquisa {
    class Pesquisar {
    public:
        Pesquisar(std::string palavra);
        bool Encontrar();
        std::string Retorno_Pesquisa();
    private:
    std::string _palavra;  
    std::multimap<int, std::string> _resultados;
    std::map<double, std::string> _encontrado;
    std::string _musica_escolhida;
    };
    
}

#endif