#include <iostream>
#include "Registro.hpp"
#include "Arquivo.hpp"
#include "Buffer.hpp"

using namespace std;

int main(){
    Arquivo a("Nomes_Idades_2.csv");
    vector<Registro> teste = a.lerRegistroCSV();

    //Serializa a quarta posiçao dos registros
    string serial = teste[3].packFixed();

    //Desserializa o registro anteriormente serializado e imprime o registro
    Registro desserial;
    desserial.unpackFixed(serial);
    cout << "Leitura apos serializar e desserializar: " << endl;
    desserial.imprimeUsuario();

    //Gera buffer e um arquivo binário contendo o registro
    Buffer buffer;

    ofstream saida("Teste1.bin", ios::binary);
    buffer.escreverRegistro(desserial, saida);
    saida.close();

    //Lê o arquivo binario gerado anteriormente e imprime o registro
    ifstream entrada("Teste1.bin", ios::binary);
    Registro regLido = buffer.lerRegistroFixo(entrada);
    cout << endl;
    cout << "Leitura do arquivo binario: " << endl;
    regLido.imprimeUsuario();

    return 0;
}