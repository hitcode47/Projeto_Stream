#ifndef CURTIDA_HPP
#define CURTIDA_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <map>

class Curtida {
    public:
    void like(std::string, std::string, std:: string);

    void dislike(std:: string, std::string, std::string);

    void ver_quatidade_curtias(std:: string);

    private:
    int Contl=0;
    int Contd=0;
    
};

#endif
