#include "reproducao.hpp"
#include <fstream>
#include <map>
#include <sstream>

/// @brief Classe responsável pelo gerenciamento das músicas.
class Musica
{  
public:
    Musica();
    /// @brief Adiciona uma música ao sitema.
    ///
    /// É solicitado ao usuário o nome do artista, bem como o link da música
    /// a ser inserida. É realizado o tratamento das palavras nos nomes e, por
    /// fim, o arquivo "Musica_Exemplo.txt" é atualizado.
    /// @param nomeArquivo Nome do arquivo da música.
    void adicionar_musica(const std::string& nomeArquivo);
    /// @brief Remove uma música do arquivo.
    ///
    /// É solicitado ao usuário o nome do artista e da música a ser removida
    /// e assim uma busca no arquivo "Musica_Exemplo.txt" é iniciada. Caso
    /// encontrada, a música é excluída e o arquivo atualizado.
    ///
    /// @param nomeArquivo Nome do arquivo da música.
    void Remove_musica(const std::string& nomeArquivo);
    
private:
    /// @brief É realizado o tratamento das palavras de uma música ou artista.
    ///
    /// A primeira letra da string é transformada em maiúscula e as demais em
    /// minúsculas.
    ///
    /// @param musica_ou_artista O nome da música ou artista a ser tratado.
    /// @return A palavra tratada.
    std::string Tratamento_de_Palavras(std::string musica_ou_artista);
    /// @brief Lê os dados do arquivo e retorna um map de músicas.
    /// 
    /// O arquivo "Musica_Exemplo.txt" possui os dados das músicas no formato
    /// "musica, link", de modo que cada linha representa uma canção diferente.
    /// Nesse sentido o nome da música é a chave e o link seu valor.
    ///
    /// @param nomeArquivo Nome do arquivo a ser lido.
    /// @return Um map contendo os dados das músicas.
    std::map<std::string, std::string> lerArquivoParaMap(const std::string& nomeArquivo);
    void salvarMapEmArquivo(const std::string& nomeArquivo, const std::map<std::string, std::string>& mapa);   
};
