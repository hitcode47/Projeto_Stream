#include "feedback.hpp"



void Feed::Fazer_comentario(std::string Musica, std::string Usuario){
    std::ofstream arquivo("FeedBack.txt", std::ios::app);
    if (arquivo.is_open()) {
    std::string comentario;
    std::cin.ignore();
    std::cout << "Digite seu comentario: ";
    std::getline(std::cin, comentario);
    
    arquivo << Musica << " , " << Usuario << ":" << comentario << std::endl; // Adiciona o comentário à mesma linha
    arquivo.close();

    std::cout << "Comentario registrado com sucesso!" << std::endl;
    } else {
    std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
    }
}


void Feed::Ler_Comentario(std::string Musica, std::string Usuario) {
    std::ifstream arquivo("FeedBack.txt");
    std::string linha;
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {

            std::size_t posMusica = linha.find(Musica);
            if (posMusica != std::string::npos) {
                std::size_t separator = linha.find(",");
                if (separator != std::string::npos) {
                    std::string comentario = linha.substr(separator + 2);
                    _comentarios.push_back(comentario);
                }
            }
        }
        arquivo.close();

        // Imprimir os comentários encontrados
        if (!_comentarios.empty()) {
            std::cout << "Comentarios encontrados:" << std::endl;
            for (const auto& comentario : _comentarios) {
                std::cout << comentario << std::endl;
            }
        } else {
            std::cout << "Nenhum comentario encontrado para essa musica e artista." << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}
