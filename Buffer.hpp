#ifndef BUFFER_H
#define BUFFER_H

#include <fstream>
#include "Registro.hpp"

using namespace std;

class Buffer
{
    public:
    Buffer();
    void escreverRegistro(Registro reg, ofstream& saida);
    Registro lerRegistroFixo(ifstream& entrada);
};


#endif