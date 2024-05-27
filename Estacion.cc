/** @file Estacion.cc
    @brief Código de la clase Estacion.
*/

#include "Estacion.hh"

Estacion::Estacion() {
}

string Estacion::first_member()
{
    set<string>::iterator it = Bicis.begin();
    return *it;
}


string Estacion::consultar_nombre()
{
    return nombre_estacion;
}

int Estacion::consultar_capacidad()
{
    return size;
}

void Estacion::mod_capacidad(const int &newsize)
{
    size = newsize;
}

int Estacion::cuantas_bicis()
{
    return Bicis.size();
}

void Estacion::escribir_bicics()
{
    for (set<string>::iterator it = Bicis.begin(); it != Bicis.end(); ++it)
        cout << *it << endl;
}

void Estacion::quitar_bici(const string &IDbici)
{
    Bicis.erase(IDbici);
}

void Estacion::agregar_nombre(const string &name)
{
    nombre_estacion = name;
}

void Estacion::agregar_tam(const int& tam) {
	size = tam;
}

int Estacion::consultar_espacio()
{
    int espacio = size - Bicis.size();
    return espacio;
}

void Estacion::agregar_bicicleta(const string &ID)
{
    Bicis.insert(ID);
}
