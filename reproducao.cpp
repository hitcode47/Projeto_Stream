#include "reproducao.hpp"

reproducao::reproducao(): posicaoAtual(-1)
{

}
//Acessa uma posição no map gerado a partir do arquivo e executa uma música
void reproducao::Executar(const std::string& nomeArquivo){
    std::map<std::string, std::string> mapa2 = ler_arquivo_em_map(nomeArquivo);

    std::string musica;

    std::cout << "Digite o nome da música a ser buscada: ";
    std::getline(std::cin, musica);

    auto it = mapa2.find(musica);
    if (it != mapa2.end()) {
        std::string link = it->second;
        std::cout << "Abrindo link da música: " << link << std::endl;

        // Converter a string para o tipo LPCWSTR
        std::wstring linkWide(link.begin(), link.end());
        LPCWSTR linkLpcwstr = linkWide.c_str();

        // Abrir o link da música usando o ShellExecute
        ShellExecute(NULL, L"open", linkLpcwstr, NULL, NULL, SW_SHOWNORMAL);

        // Atualizar a posição atual para a posição do link executado
        posicaoAtual = std::distance(mapa2.begin(), it);

    } else {
        std::cout << "Música não encontrada." << std::endl;
    }
}
void reproducao::Parar_Executar(){
    pressionar(VK_MEDIA_PLAY_PAUSE);
    soltar(VK_MEDIA_PLAY_PAUSE);
}
// A variável posicaoAtual avança para o índice posterior e executa a chave da posição(link).
void reproducao::Pular_p_frente(const std::string& nomeArquivo) {
    // Fechar o navegador
    Encerrar();
    std::map<std::string, std::string> mapa2 = ler_arquivo_em_map(nomeArquivo);

    if (posicaoAtual > 0 && posicaoAtual < mapa2.size()) {
        auto it = mapa2.begin();
        std::advance(it, posicaoAtual + 1);
        std::string link = it->second;
        std::cout << "Pulando para o link anterior: " << link << std::endl;

        Sleep(5000);

        // Converter a string para o tipo LPCWSTR
        std::wstring linkWide(link.begin(), link.end());
        LPCWSTR linkLpcwstr = linkWide.c_str();

        // Abrir o link da música usando o ShellExecuteEx
        SHELLEXECUTEINFO sei;
        ZeroMemory(&sei, sizeof(sei));
        sei.cbSize = sizeof(sei);
        sei.fMask = SEE_MASK_FLAG_DDEWAIT | SEE_MASK_FLAG_NO_UI;
        sei.lpVerb = L"open";
        sei.lpFile = linkLpcwstr;
        sei.nShow = SW_SHOWNORMAL;

        if (ShellExecuteEx(&sei)) {
            // Atualizar a posição atual para a posição do link anterior
            posicaoAtual++;
        } else {
            std::cout << "Não foi possível abrir o link." << std::endl;
        }
    } else {
        std::cout << "Não há link anterior disponível." << std::endl;
    }
}
// A variável posicaoAtual retrocede para o índice anterior e executa a chave da posição(link).
void reproducao::Pular_p_tras(const std::string& nomeArquivo) {
    // Fechar o navegador
    Encerrar();

    std::map<std::string, std::string> mapa2 = ler_arquivo_em_map(nomeArquivo);

    if (posicaoAtual >= 0 && posicaoAtual < mapa2.size() - 1) {
        auto it = mapa2.begin();
        std::advance(it, posicaoAtual - 1);
        std::string link = it->second;
        std::cout << "Pulando para o link posterior: " << link << std::endl;
        
        Sleep(5000);
        
        // Converter a string para o tipo LPCWSTR
        std::wstring linkWide(link.begin(), link.end());
        LPCWSTR linkLpcwstr = linkWide.c_str();

        // Abrir o link da música anterior usando o ShellExecuteEx
        SHELLEXECUTEINFO sei;
        ZeroMemory(&sei, sizeof(sei));
        sei.cbSize = sizeof(sei);
        sei.fMask = SEE_MASK_FLAG_DDEWAIT | SEE_MASK_FLAG_NO_UI;
        sei.lpVerb = L"open";
        sei.lpFile = linkLpcwstr;
        sei.nShow = SW_SHOWNORMAL;

        if (ShellExecuteEx(&sei)) {
            // Atualizar a posição atual para a posição do link posterior
            posicaoAtual--;
        } else {
            std::cout << "Não foi possível abrir o link." << std::endl;
        }
    } else {
        std::cout << "Não há link posterior disponível." << std::endl;
    }
}
//Recebe um arquivo de texto e armazena em um map.
std::map<std::string, std::string> reproducao::ler_arquivo_em_map(const std::string& nomeArquivo) {
    std::map<std::string, std::string> mapa2;
    std::ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            size_t pos = linha.find(',');
            if (pos != std::string::npos) {
                std::string musica = linha.substr(0, pos);
                std::string link = linha.substr(pos + 1);
                mapa2[musica] = link;
            }
        }
        arquivo.close();
        std::cout << "Dados lidos com sucesso do arquivo." << std::endl;
    } else {
        std::cout << "Arquivo não encontrado. Será criado um novo arquivo." << std::endl;
    }

    return mapa2;
}
BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lParam)
{
    // Verificar se a janela pertence a um navegador
    TCHAR className[256];
    if (GetClassName(hWnd, className, 256))
    {
        if (_tcscmp(className, _T("Chrome_WidgetWin_1")) == 0 || 
            _tcscmp(className, _T("MozillaWindowClass")) == 0 || 
            _tcscmp(className, _T("IEFrame")) == 0 ||
            _tcscmp(className, _T("ApplicationFrameWindow")) == 0 ||
            _tcscmp(className, _T("MicrosoftEdgeWindowClass")) == 0)
        {
            // Verificar se o título da janela corresponde ao Visual Studio Code
            TCHAR windowTitle[256];
            if (GetWindowText(hWnd, windowTitle, 256) > 0)
            {
                if (_tcsstr(windowTitle, _T("Visual Studio Code")) != nullptr)
                {
                    // Pular esta janela e continuar para a próxima
                    return TRUE;
                }
            }

            // Enviar mensagem de fechamento para a janela
            SendMessage(hWnd, WM_CLOSE, 0, 0);
        }
    }

    return TRUE;
}
void reproducao::Encerrar()
{
     // Enumerar todas as janelas abertas
    EnumWindows(EnumWindowsCallback, 0);
}

void reproducao::pressionar(WORD keyCode) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}

void reproducao::soltar(WORD keyCode) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}