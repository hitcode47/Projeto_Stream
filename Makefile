all: cadastrousuario.o feedback.o musicas.o pesquisa.o reproducao.o main.o
	g++ -o main cadastrousuario.o feedback.o musicas.o pesquisa.o reproducao.o main.o

cadastrousuario.o: cadastrousuario.cpp cadastrousuario.hpp
	g++ -c cadastrousuario.cpp

feedback.o: feedback.cpp feedback.hpp
	g++ -c feedback.cpp

musicas.o: musicas.cpp musicas.hpp
	g++ -c musicas.cpp

reproducao.o: reproducao.cpp reproducao.hpp
	g++ -c reproducao.cpp

pesquisa.o: pesquisa.cpp pesquisa.hpp
	g++ -c pesquisa.cpp

main.o: main.cpp cadastrousuario.hpp feedback.hpp musicas.hpp reproducao.hpp pesquisa.hpp
	g++ -c main.cpp

teste.o: testes.cpp
	g++ testes.cpp -o teste

run_teste:
	./teste

clean:
	del *.o

run:
	./main
