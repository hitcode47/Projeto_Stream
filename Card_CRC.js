//Cartões CRC:
// Importar os dados a seguir no seguinte link: https://echeung.me/crcmaker/

[
    {
      "name": "usuário",
      "superclasses": "",
      "subclasses": "",
      "type": 1,
      "responsibilities": [
        "Criar Primeira Playlist",
        "Criar Novas Playlists",
        "Incluir e excluir Músicas em um diretório",
        "Gerenciar configurações da conta",
        "Compartilhar playlist com outros usuários"
      ],
      "collaborators": [
        "playlist",
        "músicas",
        "Cadastro",
      
      ]
    },
    {
      "name": "Música",
      "superclasses": "",
      "subclasses": "",
      "type": 1,
      "responsibilities": [
        "Armazenar informações sobre a música",
        "Reproduzir as música escolhida",
        "Pular para próxima música",
        "Pular para música anterior;",
        "Acessar informações;"
      ],
      "collaborators": [
        "Playlist",
        "Usuário",
        ""
      ]
    },
    {
      "name": "Cadastro",
      "superclasses": "Abrir Conta",
      "subclasses": "Cadastro do cliente",
      "type": 1,
      "responsibilities": [
        "Colher informações para contato e acesso",
        "Realizar processo de confirmação por email",
        "Abrir guia de login",
        "Armazenar informações do usuário",
        "Validar dados inseridos"
      ],
      "collaborators": [
        "Usuário"
      ]
    },
    {
      "name": "Feedback",
      "superclasses": "",
      "subclasses": "",
      "type": 1,
      "responsibilities": [
        " Contar os números de curtidas",
        " Contar os números de dislikes",
        " Criar caixas de diálogos",
        "Curtir/descurtir a música",
        "Curtir/ descurtir comentários"
      ],
      "collaborators": [
        "Músicas",
        "Usuário",
        ""
      ]
    }
  ]
[
  {
    "name": "Reprodução ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Play",
      "Pausar ",
      "Pular",
      "Velocidade ",
      "voltar música"
    ],
    "collaborators": [
      "Musicas "
    ]
  }
]
[
  {
    "name": "Pesquisa",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
    "Pesquisar músicas",
    "Pesquisar artistas",
    "Pesquisar playlists",
    "Filtrar resultados de busca",
    "Exibir resultados relevantes"
  ],
    "collaborators": [
    "Usuário",
    "Música",
    "Playlist",
    ]
  }
]
