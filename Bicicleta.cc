/** @file Bicicleta.cc
    @brief Código de la clase Bicicleta.
*/

#include "Bicicleta.hh"
/*Funciones Privadas*/
Bicicleta::Bicicleta() {
}

string Bicicleta::consultar_estacion()
{
    return estacio_asignada;
}

void Bicicleta::agregar_viaje(const string &IDdest)
{
    Historial.push_back(pair<string,string>(estacio_asignada,IDdest));
}

void Bicicleta::agregar_nombre(const string &ID)
{
    nom = ID;
}

void Bicicleta::mod_estacion_asignada(const string &Est)
{
    estacio_asignada = Est;
}

void Bicicleta::escribir_viajes()
{
   for (list<pair<string,string>>::iterator it = Historial.begin(); it != Historial.end(); ++it){
        cout << it->first << " " << it->second << endl;
   }
}
