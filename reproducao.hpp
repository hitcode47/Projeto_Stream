#pragma once
#define UNICODE
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <map>
#include <tlhelp32.h>
#include <cstdlib>
#include <tchar.h>

/// @brief Classe responsável pela reprodução das músicas.
class reproducao
{
private:
    int posicaoAtual;

public:
    reproducao();
    /// @brief Inicia a reprodução de uma música.
    ///
    /// @param nomeArquivo "Musica_Exemplo.txt" onde há o map das músicas e links.
    /// @param nome_musica Nome da música a ser reproduzida.
    void Executar(const std::string& nomeArquivo, std::string nome_musica);
    /// @brief Interrompe a música em execução.
    void Parar_Executar();
    /// @brief Pula a música atual para a próxima.
    ///
    /// @param nomeArquivo Arquivo "Musica_Exemplo.txt".
    void Pular_p_frente(const std::string& nomeArquivo);
    /// @brief Pula a música atual para a anterior.
    ///
    /// @param nomeArquivo Arquivo "Musica_Exemplo.txt".
    void Pular_p_tras(const std::string& nomeArquivo);
    /// @brief Encerra a repodução.
    void Encerrar();
    /// @brief Retorna o nome da música em reprodução.
    ///
    /// @return Nome da música escolhida.
    std::string Retornar_nome();

private:
    /// @brief Efetua a leitura do "Musica_Exemplo.txt" e armazena o conteúdo em um map.
    ///
    /// @param nomeArquivo "Musica_Exemplo.txt".
    /// @return Map contendo as informações do arquivo.
    static std::map<std::string, std::string> ler_arquivo_em_map(const std::string& nomeArquivo);
    /// @brief Pressiona uma tecla do teclado.
    ///
    /// @param keyCode Código da tecla a ser pressionada.
    static void pressionar(WORD keyCode);
    /// @brief Solta uma tecla do teclado.
    ///
    /// @param keyCode Código da tecla a ser solta.
    static void soltar(WORD keyCode);
    /// @brief A música escolhida para reprodução.
    std::string _musica_escolhida;
};