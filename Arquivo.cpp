#include "Arquivo.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include "Registro.hpp"

using namespace std;

Arquivo::Arquivo(string nome){
        this->nomeDoArquivo = "./CSV/" + nome;
}

vector<Registro> Arquivo::lerRegistroCSV(){
    ifstream arquivoNomes(this->nomeDoArquivo);
    vector<Registro> Usuarios;
    string linha;
    int count = 0;

    while(getline(arquivoNomes, linha)){
        stringstream ss(linha);
        string item;
        vector<string> usuarioTemp;

        while(getline(ss, item, ',')){
            count++;
            if(count > 2)
                usuarioTemp.push_back(item);
        }
        if(count > 2){
            Registro novo(usuarioTemp[0], stoi(usuarioTemp[1]));
            Usuarios.push_back(novo);
        }
    }

    return Usuarios;
}

