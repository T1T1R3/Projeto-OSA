#include "Registro.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Registro::Registro(){}

Registro::Registro(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}

void Registro::imprimeUsuario(){
    cout << "Nome: " << this->nome << endl;
    cout << "Idade: " << this->idade << endl;
}

string Registro::getNome(){
    return this->nome;
}

int Registro::getIdade(){
    return this->idade;
}

string Registro::packFixed(){
    string saida(100 + sizeof(int), '\0');
    copy(nome.begin(), nome.end(), saida.begin());

    memcpy(&saida[100], &idade, sizeof(int));
    return saida;
}

void Registro::unpackFixed(const string& entrada){
    nome = string(entrada.begin(), find(entrada.begin(), entrada.begin() + 100, '\0'));
    memcpy(&idade, &entrada[100], sizeof(int));
}