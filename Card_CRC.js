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
        ""
      ],
      "collaborators": [
        "playlist",
        "músicas",
        "Cadastro",
        ""
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
      "superclasses": "",
      "subclasses": "",
      "type": 1,
      "responsibilities": [
        "Colher informações para contato e acesso",
        "Realizar processo de confirmação por email",
        "Abrir guia de login",
        ""
      ],
      "collaborators": [
        ""
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
        "Cadastro",
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
      "Velocidade "
    ],
    "collaborators": [
      "Musicas "
    ]
  }
]
