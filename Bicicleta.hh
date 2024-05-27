/** @file Bicicleta.hh
    @brief Especificación de la clase Bicicleta
*/

#ifndef BIC_HH
#define BIC_HH
#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/*
 * Clase Bicicleta
 */

/** @class Bicicleta
    @brief Representa una Bicicleta con nombre, estacion asignada y un historial de viajes.
    
    Sus operaciones permiten Consultar su estacion asignada, agregar viajes, agrega un nombre, modificar la estacion 
    de residencia y escribir su historial de viajes
*/

class Bicicleta {
    // Descripción: Contiene un nombre, estacion asignada y un Historial de viajes.
private:
    /* Una Bicicleta es formada por su nombre/Identificador, el nombre/Identificador de la estacion donde reside actualmente
    y una lista de pairs para almazenar sus viajes. */

    /*     Variables privadas     */
    /** @brief Identificador de la bicicleta.*/
    string nom;
    /** @brief Identificador de la estacion en la que reside la bicicleta.*/
    string estacio_asignada;
    /** @brief Lista de los viajes de la bicicleta organizada en pairs de string que representan la estacion de salida y la de llegada respectivamente.*/
    list<pair<string,string>> Historial;

public:
         /*     Constructoras     */
    /** @brief Constructora vacía.
        \pre Cierto.
        \post Crea una bicicleta vacia.
    */
    Bicicleta();

                /*     Consultoras     */
    /** @brief Devuelve la estacion de la bicicleta
        \pre Cierto.
        \post Devuelve el identificador de estacion de la bicicleta estacio_asignada.
        */
    string consultar_estacion();


                /*     Modificadoras     */
    /** @brief Agrega un viaje a la bicicleta
        \pre IDdest es una estacion existente.
        \post Historial pasa a tener un nuevo viaje y estacio_asignada pasa a ser IDdest.
        */
    void agregar_viaje(const string& IDdest);
    /** @brief Modifica el de la nombre bicicleta
        \pre El identificador de estacion IDdest existe en el Cjt_estaciones.
        \post nom pasa a ser ID.
        */
    void agregar_nombre(const string& ID);
    /** @brief Modifica la estacion asignada
        \pre El identificador de estacion ID existe en el Cjt_estaciones.
        \post estacio_asignada pasa a ser Est.
        */
    void mod_estacion_asignada(const string& Est);

                /*     Lectura y Escriptura     */
    /** @brief Imprime los viajes de la estacion.
        \pre Cierto.
        \post Imprime todos los viajes de la estacion, guardados en Historial por de mas viejos a mas recientes.
        */
    void escribir_viajes();

};

#endif