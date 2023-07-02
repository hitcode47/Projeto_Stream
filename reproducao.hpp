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


class reproducao
{
private:
    int posicaoAtual;

public:
    reproducao();
    void Executar(const std::string& nomeArquivo, std::string nome_musica);
    void Parar_Executar();
    void Pular_p_frente(const std::string& nomeArquivo);
    void Pular_p_tras(const std::string& nomeArquivo);
    void Encerrar();
private:
    static std::map<std::string, std::string> ler_arquivo_em_map(const std::string& nomeArquivo);
    static void pressionar(WORD keyCode);
    static void soltar(WORD keyCode);
};