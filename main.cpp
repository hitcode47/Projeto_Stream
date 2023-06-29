#include "reproducao.hpp"
#include "musicas.hpp"

int main(){

    musicas music;
    
    music.adicionar_musica("musicas_teste.txt");
    music.Remove_musica("musicas_teste.txt");

    return 0;
}