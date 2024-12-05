#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

using namespace std;

class Registro{
    private:
    string nome;
    int idade;

    public:
    Registro();
    Registro(string nome, int idade);
    string getNome();
    int getIdade();
    void imprimeUsuario();
    string packFixed();
    void unpackFixed(const string& input);
};



#endif