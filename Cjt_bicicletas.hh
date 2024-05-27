/** @file Cjt_bicicletas.hh
    @brief Especificación de la clase Cjt_bicicletas
*/
#ifndef CJT_BICICLETAS_HH
#define CJT_BICICLETAS_HH
#include "Bicicleta.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <set>
#include <string>
#endif

/*
 * Clase Cjt_bicicletas
 */

/** @class Cjt_bicicletas
    @brief Representa un Conjunto de bicicletas ordenadas por identificador y guardadas en un mapa
    
    Sus operaciones permiten quitar y agregar una bicicleta al conjunto,actualizar la estacion asignada de una bicicleta y añadirle viajes,
    consultar si una bicicleta existe o no en el conjunto, consultar la estacion asignada de una bicicleta y imprimir los viajes de una bicicleta.
*/
class Cjt_bicicletas {
    // Descripción: contiene un conjunto de bicicletas en forma ordenada por identificador de estas
private:
    /* El conjunto de bicicletas se guarda en un map ordenado por 
       identificador para facilitar la búsquedas y la impresión de las 
       bicicletas. */

    /*     Variables privadas     */
    /** @brief Mapa que contiene todas las bicicletas ordenadas por identificador.*/
    map<string, Bicicleta> MapBic;

public:
         /*     Constructoras     */
    /** @brief Constructora vacía.
        \pre Cierto.
        \post Crea un conjunto de bicicletas vacío.
    */
    Cjt_bicicletas();


                /*     Modificadoras     */
    /** @brief Quita una bicicleta del conjunto de Bicicletas
        \pre Cierto.
        \post El identificador de la bicicleta es removido y devuelve el identificador de su estacion, si la bicicleta no exsitia devuelve "Nobici".
        */
    string baja_bici(const string& IDbici);
    
    /** @brief Argega una bicicleta al conjunto
        \pre La bicicleta no existe en el conjunto, la estacion existe en cjt_estaciones y la bicicleta cabe en la estacion.
        \post  La bicicleta con identificador ID y estacion asignada IDestacion es agregada al conjunto de bicicletas.
         */
    void agregar_bicicleta(const string& ID, const string& IDestacion);
    
    /** @brief Actualiza la estacion y los viajes de una bicicleta.
        \pre  IDdest es una estacion existente en Cjt_estaciones, IDdest no es igual a la estacion asignada de la bicicleta y hay espacio para la bicicleta en IDdest.
        \post  La bicicleta IDbici pasa a estar localizada en IDdest y se le agrega el viaje correspondiente.
         */
    void actualizar_bicicleta(const string& IDbici, const string& IDdest);
    
    /** @brief Modifica la estacion asignada de la bicicleta
        \pre La estacion existe en Cjt_estaciones y hay hueco para la bicicleta.
        \post La estacion asignada de la bicicleta pasa a ser IDdest.
        */
    void modificar_estacion(const string& IDbici,const string& IDdest);

                /*     Consultoras     */
    /** @brief Consulta la estacion de una bicicleta
        \pre Cierto.
        \post Si la bicicleta existe devuelve su estacion asignada, de otro modo si la bicicleta no exisitia devuelve "Nobici".
        */
    string estacion_bici(const string& IDbici);
    
    /** @brief Consulta la existencia de una bicicleta
        \pre Cierto.
        \post Devuelve true si la bicicleta existe, false en caso contrario.
        */
    bool existe_bici(const string& IDbici);
    
    /** @brief Devuelve la estacion de la bicicleta IDbici
        \pre La bicicleta existe en el conjunto.
        \post Devuelve la estacion de la bicicleta IDbici.
        */
    string consultar_estacion(const string& IDbici);

                /*      Lectura y Escritura     */
    /** @brief Escribe los viajes de una bicicleta
        \pre Cierto.
        \post Si la bicicleta existe imprime sus viajes, de otro modo si la bicicleta no exisitia devuelve 1.
        */    
    int viajes_bici(const string& IDbici);
};

#endif