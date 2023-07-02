#include "musicas.hpp"
#include <limits>
musicas::musicas()
{
    
}
std::string musicas::Tratamento_de_Palavras(std::string musica_ou_artista){
    if(musica_ou_artista!=""){
        musica_ou_artista[0] = std::toupper(musica_ou_artista[0]);
        for(int i=1; i < musica_ou_artista.size(); i++){
            if (musica_ou_artista[i-1] == ' ') {
            musica_ou_artista[i] = std::toupper(musica_ou_artista[i]);
            }else{
            musica_ou_artista[i] = std::tolower(musica_ou_artista[i]);
            }

        }
    }
    return musica_ou_artista;
}

void musicas::adicionar_musica(const std::string& nomeArquivo) {
    std::map<std::string, std::string> mapa = lerArquivoParaMap(nomeArquivo);

    std::string artista;
    std::string musica;
    std::string link;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Digite o nome do Artista: ";
    std::getline(std::cin, artista);

    std::cout << "Digite o nome da música: ";
    std::getline(std::cin, musica);
    
    std::cout << "Digite o link da música: ";
    std::getline(std::cin, link);

    artista = Tratamento_de_Palavras(artista); //trata as palavras. Se o usuario entrar com "bruno mars" (por exemplo), ele transforma pra "Bruno Mars"
    musica = Tratamento_de_Palavras(musica);

    mapa.insert(std::make_pair(artista + " - " + musica, link));

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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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