/** @file Cjt_estaciones.cc
    @brief Código de la clase Cjt_estaciones.
*/

#include "Cjt_estaciones.hh"
/*Funciones Privadas*/

Cjt_estaciones::Cjt_estaciones() {
	size_libre = 0;
}


int Cjt_estaciones::consultar_espacio_estacion(const string& IDest)
{
    map<string,Estacion>::iterator it = MapEst.find(IDest);
	return it->second.consultar_espacio();
}

int Cjt_estaciones::alta_bici(const string& IDest, const string& IDbici)
{
	map<string,Estacion>::iterator it = MapEst.find(IDest);
	//no existe estacion
	if (it == MapEst.end())
		return 1;
	//no cabe bici
	else if (it->second.consultar_espacio() < 1)
		return 2;
	else {
	//Agregamos la bicicleta a la estacion dicha
	it->second.agregar_bicicleta(IDbici);
	size_libre--;
	//Agregamos la bicicleta tambien al mapa global de bicicletas
	return 0;
	}
}

int Cjt_estaciones::mover_bici_est(const string &IDbici, const string &IDdest,Cjt_bicicletas &Bicis)
{
	map<string,Estacion>::iterator it = MapEst.find(IDdest);
	string IDest = Bicis.consultar_estacion(IDbici);
	if (it == MapEst.end()){
		return 1;
	}
	else if (IDest == IDdest){
		return 2;
	}
	else if (it->second.consultar_espacio() < 1){
		return 3;
	}
	else {
		map<string,Estacion>::iterator it2 = MapEst.find(IDest);
		it2->second.quitar_bici(IDbici);
		it->second.agregar_bicicleta(IDbici);
		Bicis.actualizar_bicicleta(IDbici,IDdest);
		return 0;
	}
}

void Cjt_estaciones::baja_bici_est(const string &IDest,const string &IDbici)
{	
	map<string,Estacion>::iterator it = MapEst.find(IDest);
	it->second.quitar_bici(IDbici);
	++size_libre;
}

void Cjt_estaciones::agregar_estacion(const string& ID, const Estacion& est)
{
	MapEst.insert(pair<string, Estacion>(ID, est));

}

int Cjt_estaciones::bicis_estacion(const string& IDestacion)
{
	map<string,Estacion>::iterator it = MapEst.find(IDestacion);
	if (it == MapEst.end()){
		return 1;
	}
	else {
	it->second.escribir_bicics();
	return 0;
	}
}

int Cjt_estaciones::modificar_capacidad(const string &IDestacion,const int &newsize)
{
	map<string,Estacion>::iterator it = MapEst.find(IDestacion);
	if (it == MapEst.end()){
		
		return 1;
	}
	else if (newsize < it->second.cuantas_bicis()){
		return 2;
	}
	else {
		int capacidad = it->second.consultar_capacidad();
		if (newsize < capacidad)
			size_libre -= (capacidad - newsize);
		else if (newsize > capacidad)
			size_libre += (newsize-capacidad);

		it->second.mod_capacidad(newsize);
		return 0;
	}

}

int Cjt_estaciones::plazas_libres()
{
    return size_libre;
}

void Cjt_estaciones::subir_bici(Cjt_bicicletas& Bicicletas)
{
	subir_bici_aux(ArbEst,Bicicletas);	
}

void Cjt_estaciones::reducir_pl()
{
	size_libre--;
}

void Cjt_estaciones::agregar_bicicleta(const string &IDest, const string &IDbici)
{
	map<string,Estacion>::iterator it = MapEst.find(IDest);
	//if (it == MapEst.end())
	//	cout << "Error raro en Cjt-estaciones agregar_bicicleta" << endl;
	it->second.agregar_bicicleta(IDbici);
}

void Cjt_estaciones::subir_bici_aux(const BinTree<string> &a,Cjt_bicicletas& Bicicletas)
{
	//Encontramos nuestro nexo
	if (!a.empty()){
		map<string,Estacion>::iterator it = MapEst.find(a.value());
		//numero de bicicletas a mover
		int nllevar = it->second.consultar_espacio();
		//si no es hoja tiene dos hijos
		//no es necesario mirar a.right().empty()
		if (!a.left().empty()){
			map<string,Estacion>::iterator itizq = MapEst.find(a.left().value());
			map<string,Estacion>::iterator itder = MapEst.find(a.right().value());
			int sizq = itizq->second.cuantas_bicis();
			int sder = itder->second.cuantas_bicis();
			//si tenemos suficientes bicis para llenar el nexo
			int bicishijo = sizq + sder;
			if (bicishijo > nllevar){
				for (int i = 0; i < nllevar; ++i){
					
					//sacamos de izq
					if (sizq > sder){
						string menor_bici = itizq->second.first_member();
						it->second.agregar_bicicleta(menor_bici);
						itizq->second.quitar_bici(menor_bici);
						Bicicletas.modificar_estacion(menor_bici,it->first);
						--sizq;
					}

					else if (sizq < sder){
						string menor_bici = itder->second.first_member();
						it->second.agregar_bicicleta(menor_bici);
						itder->second.quitar_bici(menor_bici);
						Bicicletas.modificar_estacion(menor_bici,it->first);
						--sder;
					}

					//en caso de empate escogemos el de menor id
					else{
						string menor_izq = itizq->second.first_member();
						string menor_der = itder->second.first_member();
						if (menor_izq > menor_der){
							it->second.agregar_bicicleta(menor_der);
							itder->second.quitar_bici(menor_der);
							Bicicletas.modificar_estacion(menor_der,it->first);
							--sder;
						}
						else if (menor_izq < menor_der){
							it->second.agregar_bicicleta(menor_izq);
							itizq->second.quitar_bici(menor_izq);
							Bicicletas.modificar_estacion(menor_izq,it->first);
							--sizq;
						}
					}
				}
			}
			//si no tenemos suficientes bicis para llenar el nexo o exactamente para llenarlo
			// subimos todas las bicis de los hijos 
			else {
				if (nllevar != 0){
				//si tenemos bicics a subir las subimos todas de los hijos
				subir_todas_las_bicis(it->second,itizq->second,Bicicletas);
				subir_todas_las_bicis(it->second,itder->second,Bicicletas);
				}
			}
			subir_bici_aux(a.left(),Bicicletas);
			subir_bici_aux(a.right(),Bicicletas);
		}
	}
}

void Cjt_estaciones::subir_todas_las_bicis(Estacion &DEst, Estacion &Est,Cjt_bicicletas& Bicicletas)
{	
	int n = Est.cuantas_bicis();
	for (int i = 0; i < n; ++i){
		string bici = Est.first_member();
		DEst.agregar_bicicleta(bici);
		Est.quitar_bici(bici);
		Bicicletas.modificar_estacion(bici,DEst.consultar_nombre());
	}
}

void Cjt_estaciones::mod_arbol(const BinTree<string> &a)
{
	ArbEst = a;
}

void Cjt_estaciones::mod_mapa(const map<string, Estacion> &map)
{
	MapEst = map;
}

void Cjt_estaciones::leer_estaciones(BinTree<string> &a, map<string, Estacion> &b)
{
	string id;
	cin >> id;
	if (id != "#"){
		int c;
		cin >> c;
		size_libre += c;
		//actualizamos map
		Estacion estacion;
		estacion.agregar_nombre(id);
		estacion.agregar_tam(c);
		b.insert(pair<string,Estacion>(id,estacion));
		//completamos arbol
		BinTree<string> ai;
		leer_estaciones(ai,b);
		BinTree<string> ad;
		leer_estaciones(ad,b);
		
		a = BinTree<string> (id,ai,ad);
	}
}

string Cjt_estaciones::asignar_estacion()
{
    pair<double,string> cf;
	double pl = 0,div = 0;
	asignar_estacion_aux(ArbEst,pl,div,cf);
	return cf.second;
}

void Cjt_estaciones::asignar_estacion_aux(const BinTree<string> &a, double &pl, double &div, pair<double, string> &cf)
{
    // Si es hoja
    if (a.left().empty())
    {
        double Hpl = MapEst[a.value()].consultar_espacio();

		if (Hpl > cf.first){
			cf.first = Hpl;	
			cf.second = a.value();
		}
		else if (Hpl == cf.first){
			if (a.value() < cf.second)
				cf.second = a.value();
		}
		pl += Hpl;
		div += 1;
    }
    // Si no es hoja
    else
    {
		double plizq = 0,plder = 0;
		double divizq = 0,divder = 0;
		asignar_estacion_aux(a.left(),plizq,divizq,cf);
		asignar_estacion_aux(a.right(),plder,divder,cf);

		pl = plizq + plder + MapEst[a.value()].consultar_espacio();
		div = divizq + divder + 1;
		double newcf = pl / div;

		//comprovacion maximo
		if (newcf > cf.first){
			cf.first = newcf;
			cf.second = a.value();
		}
		else if (newcf == cf.first)
			if (a.value() < cf.second)
				cf.second = a.value();
    }
}
