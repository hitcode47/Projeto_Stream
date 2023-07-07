Projeto_Stream
================================================

Projeto final relacionado à disciplina de Programação de Desenvolvimento de Software(PDS)II.

Colaboradores: 
 * Bruno Dos Santos Lopes: Responsável pela introdução do método música e reprodução;
 * Nicolas Silva de Paula Gonçalves: Responsável pela introdução do método pesquisa;
 * Diego Felipe Machado Silva: Responsável pela introdução do método feedback;
 * Breno Ribeiro Rodrigues: Responsável pela documentação e solução de bugs;
 * Dantom Dimitri Guedes: Responsável pela introdução do método cadastro.

Documentação Aplicativo Pancadão:

*OBSERVAÇÕES*

* Ao rodar o programa, recomenda-se fechar todas as guias consideradas importantes do seu navegador. Tal erro é facilmente solucionado, porém, por conta de um calendário curto,
 o grupo optou por não modificar o programa;
* Um documento teste foi implementado no programa, porém não foi possível conciliá-lo ao código. Embora a construção lógica esteja conforme o esperado, uma grande dificuldade
  de implementação foi encontrado. Recomenda-se rodar o programa desconsiderando o DocTest e analisar somente a lógica formulada;


A música é uma das principais ferramentas de expressão que está presente na vida de muitas pessoas. Nessse sentido, o grupo empenhou-se em desenvolver um aplicativo de música
chamado "Pancadão". Dessa forma, buscamos construir um programa simples com uma interface intuitiva e sugestiva para qualquer tipo de usuário. Assim, o aplicativo permite que 
o usuário crie sua conta e, a partir disso, crie playlists, reaja por meio de "likes" ou "deslikes" em uma música, faça comentários e até mesmo usufrua de um pesquisador inte-
ligente, o qual dará recomendações de canções a partir da semelhança sintática das palavras de entrada. Ademais, funções básicas como pular, retroceder e pausar uma música 
também estão presentes. Por fim, o usuário terá a escolha de fazer login, trocar o nome de usuário, deletar uma conta existente e encerrar o aplicativo ao fim do seu uso.

Inicialmente, o grupo dedicou-se em criar as funções de cadastro e login do usuário. Assim, tal sistema apresentou diversas dificuldades durante sua implementação. Optou-se,
primeiramente, por utilizar "arquivos" como banco de dados devido à sua capacidade de manter os dados salvos mesmo após o encerramento do programa e desligamento do computa-
dor, apesar das limitações inerentes a essa abordagem. Além disso, identificar falhas de segurança mostrou-se como a parte mais desafiadora do processo. Mesmo ao acreditar 
que todas as possíveis entradas do usuário haviam sido consideradas, novas situações surgiam durante os testes, exigindo um constante aprimoramento do sistema. Ademais, a ta 
tarefa de adicionar novas linhas de código ao sistema já existente revelou-se complexa, pois era necessário garantir que todas as partes se integrassem perfeitamente.
Diante desses obstáculos, foi necessário adotar uma abordagem mais formal e meticulosa, seguindo os princípios de POO, com o intuito de assegurar a eficiência e a segurança
do sistema como um todo.

Após isso, novos diálogos tiveram início à respeito das músicas e como as reproduções seriam feitas. Assim, ficamos encarregados de criar funcionalidades que permitissem 
adicionar, remover e reproduzir faixas musicais no youtube, de modo que fosse garantido a leitura e escrita adequadas dos dados (das músicas) em arquivos, bem como a manipulação correta das estruturas de dados. No entanto, ao longo do caminho foram identificados alguns empecilhos. Alguma delas foram, lidar com a manipulação de arquivos, abrir e fechar os 
arquivos corretamente e lidar com possíveis erros de escrita e leitura. Além disso, a manipulação dos mapas (map) para armazenar as músicas e seus links correspondentes também se mostrou um obstáculo a ser enfrentado. Outra dificuldade encontrada foi interagir com o sistema operacional para reproduzir as músicas em interfaces de navegação web. 
Foi necessário aprender sobre funções como ShellExecute e descobrir como abrir os links de música e controlar a reprodução de forma adequada.

Já a parte de desenvolver a pesquisa não deu muito trabalho durante a implementação. Optou-se por utilizar o "arquivo" onde será armazenado o nome do cantor, música e o link do YouTube. A classe "Pesquisa" ficarou responsável por receber do usuário qual artista/música ele deseja, retornando-os para que a classe Musica consiga buscar o link do YouTube através do que o usuário solicitar. Dessa maneira, realizar a pesquisa pelo arquivo através da entrada do usuário, tornou-se a parte mais desafiadora do processo. Teve-se que 
avaliar as possíveis entradas do usuário e corrigi-las manualmente, uma vez que caso o usuário pesquise por um determinado artista com letras minúsculas, precisa-se transformar 
para o tipo de letra adequado com o "arquivo.txt" onde estava armazenado as informações, para que assim pudesse estar encontrando. Além disso, foi escolhido deixar que o usuário fosse o mais livre possível nas entradas, ou seja, é possível que o usuário entrasse com qualquer coisa, até mesmo números, onde caso não exista, retornava um texto subjetivo informando "Não foi possível localizar a música/artista desejado.", assim como ocorre nas pesquisas do Google Chrome. Por fim, seguindo a mesma ideia, o programa foi elaborado 
para realizar pesquisas inteligentes, onde surgirão sugestões de pesquisa com base na semelhança da sintaxe.

Dessa forma, pensando em como enriquecer nosso código, foram desenvolvidos métodos para a criação de comentários e reações em uma determinada música. Assim, criaram-se funcionalidades que permitissem o usuário dar sua avaliação sobre a musica reproduzida. O principal problema encontrado estava na manipulação de arquivos, bem como abrir e fechar 
os arquivos corretamente, lidar com possíveis erros de escrita, sobre escrever partes já escritas no meio do texto se mostrou ser um grande desfio.

Por fim, a última etapa do trabalho foi padronizar as linhas de código como um todo. Assim, padronização de comentários nos arquivos cpp, número máximo de colunas a serem usadas e
implementação de boas práticas foram algumas das  preocupações finais do grupo. Isso tudo foi pensado em função da documentação a ser gerada, de modo a tornar o programa algo
didático e que se encaixasse nos padrões adotados durante as aulas. Logo, após finalizado, adotamos as normas estabelecidas pelo Doxygen para gerar formalmente toda documentação do
aplicativo. Os principais problemas identificados neste processo foi entender o comportamento do DoxyGen e identificar um padrão de escrita do código, uma vez que, após finalização
do código, um processo de padronização foi iniciado. Além disso, no estágio final, identificaram-se alguns problemas de escrita no código, o que foi facilmente solucionado.

Professor: Luigi




**Dados do Projeto:**

O que é?: 
 * software gerenciador de reprodutor de músicas. 

Qual seu status?: 
 * Elaboração conceitual do projeto e divisão de demandas

Tecnologias utilizadas: 
 * Visual Stúdio Code;
 * Github;

Como usar: ...

Comentários: ...

User Stories:  

- Como o usuário deseja construir uma playlist de músicas que ele mais gosta, desejo criar uma lista de músicas adicioná-las e retirá-las, para que ele possa salvar os títulos do seu agrado e escutá-las posteriormente. 

  

       * As músicas ficarem salvas; 

       * Incluir músicas na playlist; 

       * Excluir músicas na playlist; 

       * Nomear a playlist;

  

- Como o usuário deseja pesquisar por músicas, quero criar uma barra de pesquisa, para que seja possível achar rapidamente o título procurado. 

  

       * Espaço destinado para o usuário digitar o nome da música a qual será feita a pesquisa; 

       * A barra de pesquisa deve ser testada quanto à usabilidade e facilidade, para garantir que seja simples de usar e entender para o usuário final; 

       * O usuário deve poder reproduzir a música que aparecer após a pesquisa; 

        

- Como o usuário deseja dar um feedback sobre a música a qual ele escutou, quero que seja possível curtir ou descurtir o título em questão. 

 	 

       * Curtir ou descurtir a música; 

       * Contar os números de curtidas; 

       * Contar os números de “dislikes”; 

       * Criar caixas de diálogos;  

  

* Como o usuário deseja criar e/ou logar em uma conta, quero criar um banco de dados com o perfil de cada usuário, para seja possível aprimorar a organização da plataforma. 

  

       * Criar login; 

       * Criar senha; 

       * O usuário deve informar um e-mail; 

       * Cadastrar usuário; 

       * Enviar uma mensagem de confirmação para o e-mail informado; 

  

* Como o usuário deve realizar operações básicas na plataforma, deve haver uma interface de ações interativas, para que ele possa pular ou voltar músicas, além de ver informações (gênero da música).  

  

       * Reproduzir as músicas escolhidas; 

       * Pular para próxima música; 

       * Pular para música anterior; 

       * Acessar informações; 

 * Classes Obtitas:

<<<<<<< HEAD
       * Usuário;
       * Música;
       * Playlist;
       * Curtida;
       * Comentario;
       * Cadastro;
=======
       * Login;
       * SingUp;
       * ChangeUsername;
       * DeleteAccount;
       * Iniciar;
>>>>>>> origin/master


