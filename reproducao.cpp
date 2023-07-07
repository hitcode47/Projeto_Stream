#include "reproducao.hpp"

reproducao::reproducao() : posicaoAtual(-1)
{

}

void reproducao::Executar(const std::string& nomeArquivo, std::string nome_musica)
{
    std::map<std::string, std::string> mapa2 = ler_arquivo_em_map(nomeArquivo);

    std::string musica;

    std::cout << "sua musica esta sendo buscada" << std::endl;
    Sleep(5000);

    auto it = mapa2.find(nome_musica);
    if (it != mapa2.end())
    {
        std::string link = it->second;
        std::string musica = it->first;
        _musica_escolhida = musica;
        std::cout << "Abrindo musica: " << musica << std::endl;

        /*Converter a string para o tipo LPCWSTR*/
        std::wstring linkWide(link.begin(), link.end());
        LPCWSTR linkLpcwstr = linkWide.c_str();

        /*Abrir o link da musica usando o ShellExecute*/
        ShellExecute(NULL, L"open", linkLpcwstr, NULL, NULL, SW_SHOWNORMAL);

        /*Atualizar a posicao atual para a posicao do link executado*/
        posicaoAtual = std::distance(mapa2.begin(), it);
    }
    else
    {
        std::cout << "Musica nao encontrada." << std::endl;
    }
}

void reproducao::Parar_Executar()
{
    pressionar(VK_MEDIA_PLAY_PAUSE);
    soltar(VK_MEDIA_PLAY_PAUSE);
}

std::string reproducao::Retornar_nome(){
    return _musica_escolhida;
}
void reproducao::Pular_p_frente(const std::string& nomeArquivo) {

    /*Fechar o navegador*/
    Encerrar();

    std::map<std::string, std::string> mapa2 = ler_arquivo_em_map(nomeArquivo);

    if (posicaoAtual >= 0 && posicaoAtual < mapa2.size() - 1) {
        auto it = mapa2.begin();
        std::advance(it, posicaoAtual + 1);
        std::string link = it->second;
        _musica_escolhida = it->first;
        std::cout << "Pulando para o musica posterior: " << it->first << std::endl;

        Sleep(5000);

        /*Converter a string para o tipo LPCWSTR*/
        std::wstring linkWide(link.begin(), link.end());
        LPCWSTR linkLpcwstr = linkWide.c_str();

        /*Abrir o link da musica usando o ShellExecuteEx*/
        SHELLEXECUTEINFO sei;
        ZeroMemory(&sei, sizeof(sei));
        sei.cbSize = sizeof(sei);
        sei.fMask = SEE_MASK_FLAG_DDEWAIT | SEE_MASK_FLAG_NO_UI;
        sei.lpVerb = L"open";
        sei.lpFile = linkLpcwstr;
        sei.nShow = SW_SHOWNORMAL;

        if (ShellExecuteEx(&sei)) {
            /*Atualizar a posicao atual para a posicao do link posterior*/
            posicaoAtual = std::distance(mapa2.begin(), it);
        } else {
            std::cout << "Nao foi possivel abrir o link." << std::endl;
        }
    } else {
        std::cout << "Nao ha link posterior disponivel." << std::endl;
    }
}

void reproducao::Pular_p_tras(const std::string& nomeArquivo) {

    /*Fechar o navegador*/
    Encerrar();
    std::map<std::string, std::string> mapa2 = ler_arquivo_em_map(nomeArquivo);

    if (posicaoAtual > 0 && posicaoAtual < mapa2.size()) {
        auto it = mapa2.begin();
        std::advance(it, posicaoAtual - 1);
        std::string link = it->second;
        std::string musica = it->first;
        std::cout << "Pulando para o muscia anterior: " << musica << std::endl;
        _musica_escolhida = it->first;
        Sleep(5000);

        /*Converter a string para o tipo LPCWSTR*/
        std::wstring linkWide(link.begin(), link.end());
        LPCWSTR linkLpcwstr = linkWide.c_str();

        /*Abrir o link da musica anterior usando o ShellExecuteEx*/
        SHELLEXECUTEINFO sei;
        ZeroMemory(&sei, sizeof(sei));
        sei.cbSize = sizeof(sei);
        sei.fMask = SEE_MASK_FLAG_DDEWAIT | SEE_MASK_FLAG_NO_UI;
        sei.lpVerb = L"open";
        sei.lpFile = linkLpcwstr;
        sei.nShow = SW_SHOWNORMAL;

        if (ShellExecuteEx(&sei)) {
            /*Atualizar a posicao atual para a posicao do link anterior*/
            posicaoAtual = std::distance(mapa2.begin(), it);
        } else {
            std::cout << "Nao foi possivel abrir o link." << std::endl;
        }
    } else {
        std::cout << "Nao ha link anterior disponivel." << std::endl;
    }
}


std::map<std::string, std::string> reproducao::ler_arquivo_em_map(const std::string& nomeArquivo)
{
    std::map<std::string, std::string> mapa2;
    std::ifstream arquivo(nomeArquivo);
    if (arquivo.is_open())
    {
        std::string linha;
        while (std::getline(arquivo, linha))
        {
            if(!linha.empty()){
                linha[0] = std::toupper(linha[0]);
                for(int i=1; i < linha.size(); i++){

                    if(linha[i] == ','){
                        break;
                    }
                    else{
                        if (linha[i-1] == ' ') {
                            linha[i] = std::toupper(linha[i]);
                        }else{
                            linha[i] = std::tolower(linha[i]);
                        }
                    }
                }   
            }
            //converte as letras após o espaço para maiuscula.
            size_t pos = linha.find(',');
            if (pos != std::string::npos)
            {
                std::string musica = linha.substr(0, pos);
                std::string link = linha.substr(pos + 1);
                mapa2[musica] = link;
            }
        }
        arquivo.close();
        std::cout << "Dados lidos com sucesso do arquivo." << std::endl;
    }
    else
    {
        std::cout << "Arquivo nao encontrado. Sera criado um novo arquivo." << std::endl;
    }

    return mapa2;
}

BOOL CALLBACK EnumWindowsCallback(HWND hWnd, LPARAM lParam)
{
    /*Verificar se a janela pertence a um navegador*/
    TCHAR className[256];
    if (GetClassName(hWnd, className, 256))
    {
        if (_tcscmp(className, _T("Chrome_WidgetWin_1")) == 0 ||
            _tcscmp(className, _T("MozillaWindowClass")) == 0 ||
            _tcscmp(className, _T("IEFrame")) == 0 ||
            _tcscmp(className, _T("ApplicationFrameWindow")) == 0 ||
            _tcscmp(className, _T("MicrosoftEdgeWindowClass")) == 0)
        {
            /*Verificar se o titulo da janela corresponde ao Visual Studio Code*/
            TCHAR windowTitle[256];
            if (GetWindowText(hWnd, windowTitle, 256) > 0)
            {
                if (_tcsstr(windowTitle, _T("Visual Studio Code")) != nullptr)
                {
                    /*Pular esta janela e continuar para a proxima*/
                    return TRUE;
                }
            }

            /*Enviar mensagem de fechamento para a janela*/
            SendMessage(hWnd, WM_CLOSE, 0, 0);
        }
    }

    return TRUE;
}

void reproducao::Encerrar()
{
    /*Enumerar todas as janelas abertas*/
    EnumWindows(EnumWindowsCallback, 0);
}

void reproducao::pressionar(WORD keyCode)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}

void reproducao::soltar(WORD keyCode)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}
