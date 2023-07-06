#ifndef PESQUISA_HPP
#define PESQUISA_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>
#include <sstream>
#include "reproducao.hpp"

namespace Pesquisa{
    class Pesquisar {
    public:
        /// @brief Construtor da classe Pesquisar. 
        ///
        /// @param palavra A palavra, música ou artista a ser pesquisada.
        Pesquisar(std::string palavra);
        /// @brief Realiza a pesquisa no arquivo, música ou artista.
        ///
        /// Realiza a pesquisa através do arquivo "Musica_Exemplo.txt" com a
        /// finalidade de encontrar a maior ocorrencia da palavra passada e
        /// assim retornar um boleano para a continuação do código.
        ///
        /// @return Verdadeiro se a pesquisa foi um sucesso, Falso caso contrário.
        bool Encontrar();
        /// @brief Retorna a música e o artista pesquisado.
        /// @return A música e o artista.
        std::string Retorno_Pesquisa();
        ///
        /// Instância da classe reprodução para que a musica_escolhida possa ser
        /// reproduzida.
        ///
        reproducao repro;
        
    private:
    std::string _palavra;  
    std::multimap<int, std::string> _resultados;
    std::map<double, std::string> _encontrado;
    std::string _musica_escolhida;
    };  
}

#endif