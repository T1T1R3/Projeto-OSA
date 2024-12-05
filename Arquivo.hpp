#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <vector>
#include "Registro.hpp"

using namespace std;

class Arquivo
{
    private:
    string nomeDoArquivo;

    public:
    Arquivo(string nome);

    vector<Registro> lerRegistroCSV();
    void adicionarRegistroFixo();
    vector<Registro> lerRegistroFixo();

};


#endif