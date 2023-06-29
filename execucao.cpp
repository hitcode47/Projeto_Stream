#include <iostream>
#include <string>
#include "musicas.hpp"
#include "reproducao.hpp"
#include "pesquisa.hpp"
#include "cadastrousuario.hpp"

int main() {
    std::string arquivo = "musica.txt"; // Nome do arquivo a ser usado

    musicas playlist;
    reproducao player;
    Pesquisa::Pesquisar pesquisa("");
    Login login;

    int opcao;
    do {
        std::cout << "============== MENU ==============" << std::endl;
        std::cout << "1. Cadastro de usuário" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Adicionar música" << std::endl;
        std::cout << "4. Remover música" << std::endl;
        std::cout << "5. Executar música" << std::endl;
        std::cout << "6. Parar execução" << std::endl;
        std::cout << "7. Pular para a próxima música" << std::endl;
        std::cout << "8. Voltar para a música anterior" << std::endl;
        std::cout << "9. Pesquisar música" << std::endl;
        std::cout << "10. Encerrar programa" << std::endl;
        std::cout << "Digite a opção desejada: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: {
                std::string nome, senha;
                std::cout << "Digite o nome de usuário: ";
                std::cin >> nome;
                std::cout << "Digite a senha: ";
                std::cin >> senha;
                Login.cadastrarUsuario(nome, senha);
                break;
            }
            case 2: {
                std::string nome, senha;
                std::cout << "Digite o nome de usuário: ";
                std::cin >> nome;
                std::cout << "Digite a senha: ";
                std::cin >> senha;
                if (Login.realizarLogin(nome, senha)) {
                    std::cout << "Login realizado com sucesso!" << std::endl;
                } else {
                    std::cout << "Nome de usuário ou senha incorretos." << std::endl;
                }
                break;
            }
            case 3:
                if (Login.usuarioLogado()) {
                    playlist.adicionar_musica(arquivo);
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 4:
                if (Login.usuarioLogado()) {
                    playlist.Remove_musica(arquivo);
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 5:
                if (Login.usuarioLogado()) {
                    player.Executar(arquivo);
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 6:
                if (Login.usuarioLogado()) {
                    player.Parar_Executar();
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 7:
                if (Login.usuarioLogado()) {
                    player.Pular_p_frente(arquivo);
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 8:
                if (Login.usuarioLogado()) {
                    player.Pular_p_tras(arquivo);
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 9:
                if (Login.usuarioLogado()) {
                    std::string palavra;
                    std::cout << "Digite a palavra-chave para pesquisa: ";
                    std::getline(std::cin, palavra);
                    pesquisa = Pesquisa::Pesquisar(palavra);
                    if (pesquisa.Encontrar()) {
                        std::cout << "Resultados encontrados:" << std::endl;
                        const std::vector<std::string>& resultados = pesquisa.getResultados();
                        for (const auto& resultado : resultados) {
                            std::cout << resultado << std::endl;
                        }
                    } else {
                        std::cout << "Nenhum resultado encontrado." << std::endl;
                    }
                } else {
                    std::cout << "Faça login para realizar esta ação." << std::endl;
                }
                break;
            case 10:
                std::cout << "Encerrando programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Digite um número válido." << std::endl;
        }

        std::cout << std::endl;

    } while (opcao != 10);

    return 0;
}
