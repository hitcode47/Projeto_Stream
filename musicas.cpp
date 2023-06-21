#include "musicas.hpp"

musicas::musicas()
{
    
}
void musicas::adicionar_musica(const std::string& nomeArquivo) {
    std::map<std::string, std::string> mapa = lerArquivoParaMap(nomeArquivo);

    std::string musica;
    std::string link;

    std::cout << "Digite o nome da música: ";
    std::getline(std::cin, musica);

    std::cout << "Digite o link da música: ";
    std::getline(std::cin, link);

    mapa[musica] = link;

    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const auto& par : mapa) {
            arquivo << par.first << "," << par.second << std::endl;
        }
        arquivo.close();
        std::cout << "Dados salvos no arquivo." << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo para escrita." << std::endl;
    }
}

void musicas::Remove_musica(const std::string& nomeArquivo){
    std::map<std::string, std::string> mapa = lerArquivoParaMap(nomeArquivo);

    std::string musica;

    std::cout << "Digite o nome da música a ser apagada: ";
    std::getline(std::cin, musica);

    auto it = mapa.find(musica);
    if (it != mapa.end()) {
        mapa.erase(it);
        salvarMapEmArquivo(nomeArquivo, mapa);
        std::cout << "Música removida com sucesso." << std::endl;
    } else {
        std::cout << "Música não encontrada." << std::endl;
    }
}

std::map<std::string, std::string> musicas::lerArquivoParaMap(const std::string& nomeArquivo) {
    std::map<std::string, std::string> mapa;

    std::ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            size_t pos = linha.find(',');
            if (pos != std::string::npos) {
                std::string musica = linha.substr(0, pos);
                std::string link = linha.substr(pos + 1);
                mapa[musica] = link;
            }
        }
        arquivo.close();
        std::cout << "Dados lidos com sucesso do arquivo." << std::endl;
    } else {
        std::cout << "Arquivo não encontrado. Será criado um novo arquivo." << std::endl;
    }

    return mapa;
}

void musicas::salvarMapEmArquivo(const std::string& nomeArquivo, const std::map<std::string, std::string>& mapa) {
    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const auto& par : mapa) {
            arquivo << par.first << "," << par.second << std::endl;
        }
        arquivo.close();
        std::cout << "Dados salvos no arquivo." << std::endl;
    } else {
        std::cout << "Não foi possível abrir o arquivo para escrita." << std::endl;
    }
}