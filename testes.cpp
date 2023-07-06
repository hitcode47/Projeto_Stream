#include "doctest.h"
#include "cadastrousuario.hpp"

DOCTEST_TEST_CASE("Testando a função hashSenha") {
    CHECK(hashSenha("123456") == "126381531049624");
    CHECK(hashSenha("abcdef") == "1099511627776");
    CHECK(hashSenha("senha") == "1099511627776");
}

DOCTEST_TEST_CASE("Testando a função login") {
  
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq << "admin\n";
    usuariosarq << hashSenha("admin") << "\n";
    usuariosarq << "user\n";
    usuariosarq << hashSenha("user") << "\n";
    usuariosarq.close();

    Login l;

    SUBCASE("Login com credenciais corretas") {
     
        std::istringstream input("admin\nadmin\n");
        std::ostringstream output;
        l.login(input, output);
        CHECK(output.str() == "LOGIN BEM SUCEDIDO!\n\n");
    }

    SUBCASE("Login com senha incorreta") {
        
        std::istringstream input("admin\nwrongpassword\n");
        std::ostringstream output;
        l.login(input, output);
        CHECK(output.str() == "Senha incorreta!\n");
    }

    SUBCASE("Login com usuário inexistente") {
        
        std::istringstream input("nonexistentuser\npassword\n");
        std::ostringstream output;
        l.login(input, output);
        CHECK(output.str() == "Nome de usuario nao encontrado!\n");
    }
}

DOCTEST_TEST_CASE("Testando a função sign_up") {
    // Create an empty test file
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq.close();

    Signup s;

    SUBCASE("Cadastro com nome de usuário válido") {
        // Provide a valid username and password
        std::istringstream input("newuser\npassword\npassword\n");
        std::ostringstream output;
        s.sign_up(input, output);
        CHECK(output.str() == "USUARIO CRIADO COM SUCESSO!\n\n");
    }

    SUBCASE("Cadastro com nome de usuário já existente") {
       
        std::istringstream input("admin\npassword\npassword\n");
        std::ostringstream output;
        s.sign_up(input, output);
        CHECK(output.str() == "Usuario ja existente!\n");
    }

    SUBCASE("Cadastro com campo de senha vazio") {
        
        std::istringstream input("newuser\n\npassword\n");
        std::ostringstream output;
        s.sign_up(input, output);
        CHECK(output.str() == "Campo de senha vazio!\n");
    }
}

DOCTEST_TEST_CASE("Testando a função change_username") {
    
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq << "admin\n";
    usuariosarq << hashSenha("admin") << "\n";
    usuariosarq << "user\n";
    usuariosarq << hashSenha("user") << "\n";
    usuariosarq.close();

    ChangeUsername cu;

    SUBCASE("Alteração de nome de usuário com credenciais corretas") {
       
        std::istringstream input("admin\nadmin\nnewadmin\n");
        std::ostringstream output;
        cu.change_username(input, output);
        CHECK(output.str() == "Nome de usuario alterado com sucesso!\n");
    }

    SUBCASE("Alteração de nome de usuário com senha incorreta") {
        
        std::istringstream input("admin\nwrongpassword\nnewadmin\n");
        std::ostringstream output;
        cu.change_username(input, output);
        CHECK(output.str() == "Senha incorreta!\n");
    }

    SUBCASE("Alteração de nome de usuário com usuário inexistente") {
        
        std::istringstream input("nonexistentuser\npassword\nnewuser\n");
        std::ostringstream output;
        cu.change_username(input, output);
        CHECK(output.str() == "Nome de usuario nao encontrado!\n");
    }
}

DOCTEST_TEST_CASE("Testando a função delete_account") {
   
    std::ofstream usuariosarq("usuariosenha.txt");
    usuariosarq << "admin\n";
    usuariosarq << hashSenha("admin") << "\n";
    usuariosarq << "user\n";
    usuariosarq << hashSenha("user") << "\n";
    usuariosarq.close();

    DeleteAccount da;

    SUBCASE("Exclusão de conta com credenciais corretas") {
 
        std::istringstream input("admin\nadmin\n");
        std::ostringstream output;
        da.delete_account(input, output);
        CHECK(output.str() == ""); 
    }

    SUBCASE("Exclusão de conta com senha incorreta") {
        
        std::istringstream input("admin\nwrongpassword\n");
        std::ostringstream output;
        da.delete_account(input, output);
        CHECK(output.str() == "Credenciais invalidas. Nao foi possivel apagar a conta.\n");
    }

    SUBCASE("Exclusão de conta com usuário inexistente") {
       
        std::istringstream input("nonexistentuser\npassword\n");
        std::ostringstream output;
        da.delete_account(input, output);
        CHECK(output.str() == "A conta que deseja excluir nao existe.\n");
    }
}
