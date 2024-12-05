#include "Buffer.hpp"
#include "Registro.hpp"
#include <iostream>

using namespace std;

Buffer::Buffer(){}


void Buffer::escreverRegistro(Registro reg, ofstream& saida){
    string serial = reg.packFixed();
    saida.write(serial.c_str(), serial.size());
}

Registro Buffer::lerRegistroFixo(ifstream& entrada){
    string buffer(100 + sizeof(int), '\0');
    if(entrada.read(&buffer[0], buffer.size())){
        Registro reg;
        reg.unpackFixed(buffer);
        return reg;
    }
    else{
        return Registro();
    }
}