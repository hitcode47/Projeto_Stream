

[
  {
    "name": "Login",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Solicitar nome do usuário e senha",
      "Verificar se as credenciais estão certas"
    ],
    "collaborators": [
      "Singnup",
      "Iniciar "
    ]
  },
  {
    "name": "Signup",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Cadastrar novo usuário",
      "Verificar se o usuário já existe ",
      "Armazenar as informações de novos usuarios"
    ],
    "collaborators": [
      "Iniciar"
    ]
  },
  {
    "name": "ChangeUsername ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Atualiza o cadastro do usuário",
      "Solicita as novas informações do usuário"
    ],
    "collaborators": [
      "Signup",
      "Iniciar"
    ]
  },
  {
    "name": "DeleteAccount",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Exclui a conta de um usuário "
    ],
    "collaborators": [
      "Iniciar"
    ]
  },
  {
    "name": "Iniciar ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Inicia o programa "
    ],
    "collaborators": [
      ""
    ]
  },
  {
    "name": "Comentário",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Registrar comentários",
      "Exibir comentários feitos por outros usuários  "
    ],
    "collaborators": [
      "Reprodução",
      "Login",
      "musica "
    ]
  },
  {
    "name": "Curtida",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Registar curtidas ",
      "Realizar a contagem de reações feitas em uma musica"
    ],
    "collaborators": [
      "Reprodução",
      "Login",
      "musica "
    ]
  },
  {
    "name": "Musica",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Adicionar musicas",
      "Remover musicas "
    ],
    "collaborators": [
      "Pesquisa"
    ]
  },
  {
    "name": "Pesquisa ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Procurar musicas",
      ""
    ],
    "collaborators": [
      "Musica"
    ]
  },
  {
    "name": "Reprodução ",
    "superclasses": "",
    "subclasses": "",
    "type": 1,
    "responsibilities": [
      "Executar ",
      "Parar ",
      "Pular para outra musica",
      "Voltar para musica anterior ",
      "Encerrar programa "
    ],
    "collaborators": [
      "Musica ",
      "Pesquisa "
    ]
  }
]
