/** @mainpage

        El programa principal se encuentra en el módulo program.cc.
        Atendiendo a los tipos de datos sugeridos en el enunciado,
        necesitaremos un módulo para representar el conjunto de estaciones,
        formado por un arbol de identififcadores de estaciones un map de identificadores de estaciones 
		y su respectiva estacion y una variable size_libre que nos dira el tamaño libre que hay, 
		y otro para el conjunto de bicicletas el cual es formado por un mapa
		de identificadores de bicicletas y su respectiva bicicleta.
 */

/** @file program.cc
    @brief Programa princial.

    Suponemos que los datos leídos son siempre correctos, ya que no
    incluimos combrobaciones al respecto.  Para acceder a las opciones
    disponibles usaremos comandos.
*/


#include "Cjt_bicicletas.hh"
#include "Cjt_estaciones.hh"


#ifndef NO_DIAGRAM        //No aparece en el diagrama
#include <iostream>
//#include "BinTree.hh"
using namespace std;
#endif

int main() {
	string comando;

	Cjt_estaciones est;
	
	BinTree<string> arbolEst;
	map<string, Estacion> mapaEst;
	
	est.leer_estaciones(arbolEst, mapaEst);
	
	est.mod_arbol(arbolEst);
	est.mod_mapa(mapaEst);

	Cjt_bicicletas Bicicletas;

	cin >> comando;
	while (comando != "fin") {

		if (comando == "alta_bici" || comando == "ab") {
			string IDbici, IDestacion;
			cin >> IDbici >> IDestacion;
			cout << "#ab " << IDbici << " " << IDestacion << endl;
			if (!Bicicletas.existe_bici(IDbici)){
				int ret = est.alta_bici(IDestacion,IDbici);
				if (ret != 0){
					if (ret == 1)
						cout << "error: la estacion no existe" << endl;
					else if (ret == 2)
						cout << "error: la bici no cabe" << endl;
				}
				else {
					Bicicletas.agregar_bicicleta(IDbici,IDestacion);
				}
			}
			else {
				cout << "error: la bici ya existe" << endl;
			}
		}

		if (comando == "baja_bici" || comando == "bb"){
			string IDbici;
			cin >> IDbici;
			string ret = Bicicletas.baja_bici(IDbici);
			cout << "#bb " << IDbici << endl;
			if (ret == "Nobici")
				cout << "error: la bici no existe" << endl;
			else {
				est.baja_bici_est(ret,IDbici);
			}
		}

		if (comando == "estacion_bici" || comando == "eb"){
			string IDbici;
			cin >> IDbici;
			string ret = Bicicletas.estacion_bici(IDbici);
			cout << "#eb " << IDbici << endl;
			if (ret == "Nobici")
				cout << "error: la bici no existe"<< endl;
			else 
				cout << ret << endl;
		}

		if (comando == "viajes_bici" || comando == "vb"){
			string IDbici;
			cin >> IDbici;
			cout << "#vb " << IDbici << endl;
			int ret = Bicicletas.viajes_bici(IDbici);
			if (ret == 1)
				cout << "error: la bici no existe" << endl;
		}
		
		if (comando == "mover_bici" || comando == "mb"){
			string IDbici,IDdest;
			cin >> IDbici >> IDdest;
			cout << "#mb " << IDbici << " " << IDdest << endl;
			if (Bicicletas.existe_bici(IDbici)){
				int ret = est.mover_bici_est(IDbici,IDdest,Bicicletas);
				if (ret == 1){
					cout << "error: la estacion no existe" << endl;
				}
				else if (ret == 2){
					cout << "error: la bici ya esta en el sitio"<< endl;
				}
				else if (ret == 3){
					cout << "error: la bici no cabe" << endl;
				}
			}
			else {
				cout << "error: la bici no existe" << endl;
			}
		}
		
		if (comando == "bicis_estacion" || comando == "be"){
			string IDest;
			cin >> IDest;
			cout << "#be " << IDest << endl;
			int ret = est.bicis_estacion(IDest);
			if (ret == 1){
				cout << "error: la estacion no existe" << endl;
			}
		}
		
		if (comando == "modificar_capacidad" || comando == "mc"){
			string IDest;
			int n;
			cin >> IDest >> n;
			cout << "#mc " << IDest << " " << n << endl;
			int ret = est.modificar_capacidad(IDest,n);
			if (ret == 1)
				cout << "error: la estacion no existe" << endl;
			else if (ret == 2)
				cout << "error: capacidad insuficiente" << endl;
		}
		
		if (comando == "plazas_libres" || comando == "pl"){
			cout << "#pl" << endl;
			cout << est.plazas_libres() << endl;
		}
		
		if (comando == "subir_bicis" || comando == "sb"){
			cout << "#sb" << endl;
			est.subir_bici(Bicicletas);
		}
		
		if (comando == "asignar_estacion" || comando == "ae"){
			string IDbici;
			cin >> IDbici;
			cout << "#ae " << IDbici << endl;

			if (Bicicletas.existe_bici(IDbici)){
				cout << "error: la bici ya existe" << endl;
			}
			else if (est.plazas_libres() == 0){
				cout << "error: no hay plazas libres" << endl;
			}
			else {
			string estacion_asignar = est.asignar_estacion();
			
			cout << estacion_asignar << endl;
			
			Bicicletas.agregar_bicicleta(IDbici,estacion_asignar);
			est.agregar_bicicleta(estacion_asignar,IDbici);
			est.reducir_pl();
			}
		}
		cin >> comando;
	}
}