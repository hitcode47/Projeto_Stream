#include "reproducao.hpp"
#include <fstream>
#include <map>
#include <sstream>
class musicas
{
private:
    reproducao repro;
public:
    musicas();
    void adicionar_musica(const std::string& nomeArquivo);
    void Remove_musica(const std::string& nomeArquivo);
    
private:
    std::map<std::string, std::string> lerArquivoParaMap(const std::string& nomeArquivo);
    void salvarMapEmArquivo(const std::string& nomeArquivo, const std::map<std::string, std::string>& mapa);

    
};