// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)

    {

    ofstream mi_archivo(nombre_archivo.c_str(),ios::in | ios::binary);

   mi_archivo.seekp( posicion*10);
   mi_archivo.write(mascota->nombre.c_str(),6);
   mi_archivo.write((char *) &mascota->edad,4);
   mi_archivo.close();

}


//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
    Mascota *msco;
    ifstream mi_archivo(nombre_archivo.c_str());
    mi_archivo.seekg(posicion*10);

    char nombre[6];
    int edad;

    mi_archivo.read(nombre,6);
    mi_archivo.read((char*)&edad,4);
    msco=  new Mascota(edad,nombre);
    return msco;

}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{

    vector<Mascota*>respuesta;
    Mascota *msco ;
    ifstream mi_archivo(nombre_archivo.c_str());
    mi_archivo.seekg(0,mi_archivo.end);
    int tama = mi_archivo.tellg()/10;
    mi_archivo.seekg(0,mi_archivo.beg);

    for(int i =0 ; i< tama; i++)
    {
        char nombre[6];
        int edad;
       mi_archivo.read(nombre,6);
        mi_archivo.read((char*)&edad,4);
        msco = new Mascota(edad,nombre);
        respuesta.push_back(msco);
    }
    return respuesta;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
