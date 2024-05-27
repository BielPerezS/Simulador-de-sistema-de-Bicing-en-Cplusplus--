/** @file Cjt_bicicletas.cc
    @brief Código de la clase Cjt_bicicletas.
*/
#include "Cjt_bicicletas.hh"

Cjt_bicicletas::Cjt_bicicletas()
{
}

string Cjt_bicicletas::baja_bici(const string &IDbici)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
    if (it == MapBic.end()){
        return "Nobici";
    } 
    else {
    string estacion = it->second.consultar_estacion();
    MapBic.erase(it);
    return estacion;
    }
}

string Cjt_bicicletas::estacion_bici(const string& IDbici)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
    if (it == MapBic.end())
        return "Nobici";
    return it->second.consultar_estacion();
}

int Cjt_bicicletas::viajes_bici(const string& IDbici)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
    if (it == MapBic.end()){
        return 1;
    }
    else {
    it->second.escribir_viajes();
    return 0;
    }
}

bool Cjt_bicicletas::existe_bici(const string &IDbici)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
    if (it == MapBic.end())
        return false;
    else 
        return true;
}

void Cjt_bicicletas::agregar_bicicleta(const string &ID, const string& IDestacion)
{
    Bicicleta Bici;
    Bici.agregar_nombre(ID);
	Bici.mod_estacion_asignada(IDestacion);
    MapBic.insert(pair<string,Bicicleta>(ID,Bici));
}

string Cjt_bicicletas::consultar_estacion(const string &IDbici)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
    return it->second.consultar_estacion();
}

void Cjt_bicicletas::actualizar_bicicleta(const string &IDbici, const string &IDdest)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
        it->second.agregar_viaje(IDdest);
        it->second.mod_estacion_asignada(IDdest);
}

void Cjt_bicicletas::modificar_estacion(const string &IDbici, const string &IDdest)
{
    map<string,Bicicleta>::iterator it = MapBic.find(IDbici);
    it->second.mod_estacion_asignada(IDdest);
}
