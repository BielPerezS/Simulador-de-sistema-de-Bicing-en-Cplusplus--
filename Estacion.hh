/** @file Estacion.hh
    @brief Especificación de la clase Estacion
*/

#ifndef EST_HH
#define EST_HH


#ifndef NO_DIAGRAM
#include <set>
#include <string>
using namespace std;
#include <iostream>
#endif

/*
 * Clase Estacion
 */

/** @class Estacion
    @brief Representa una Estacion con nombre, capacidad y un set de identificadores de bicicletas.
    
    Sus operaciones permiten consultar la bicicleta con identificador menor, consultar el identificador de la estacion,consultar la capacidad de la estacion,
    consultar el espacio ocupado de la estacion,modificar la capacidad, agregar y quitar una bicicleta, agregar un nombre y una capacidad a la estacion,
    y escribir las bicicletas de la estacion.
    */


class Estacion {
    // Descripción: Contiene un identificador/nombre de estacion, una capacidad y un set de identificadores de bicicletas 
private:
    /* La Estacion se forma por el identificador/nombre de la estacion, la capacidad de esta,
    y un set de identificadores de bicicletas para escribir las bicicletas por orden de identificador. */

    /*     Variables privadas     */
    /** @brief Identificador de la estacion.*/
    string nombre_estacion;
    /** @brief Capacidad maxima de bicicletas de la estacion.*/
    int size;
    /** @brief Set que contiene el identificador de las bicicletas de la estacion ordenadas de menor a mayor.*/
    set<string> Bicis;

public:
         /*     Constructoras     */
    /** @brief Constructora vacía.
        \pre Cierto.
        \post Crea una estacion vacia.
    */
    Estacion();

                /*     Consultoras     */
    /** @brief Devuelve el primer miembro de Bicis
        \pre Cierto.
        \post Devuelve el primer identificador de bicicleta del set Bicis.
        */
    string first_member();
    /** @brief Devueluve el nombre de la estacion
        \pre Cierto.
        \post Devuelve el identificador de estacion nombre_estacion.
        */
    string consultar_nombre();
    
    
    
    //FUNCIONES REPETIDAS
    
    
    /** @brief Devuelve la capacidad 
        \pre Cierto.
        \post Devuelve la capacidad de bicicletas de la estacion size.
        */

    
    int consultar_capacidad();
    /** @brief Devuelve el numero de bicicletas
        \pre Cierto.
        \post Devuelve el numero de bicicletas en la estacion.
        */
    //int espacio_ocupado();
    int cuantas_bicis();

    /** @brief Devuelve el espacio libre
        \pre Cierto.
        \post Devuelve de espacio libre para bicicletas de la estacion.
        */
    int consultar_espacio();





    


                /*     Modificadoras     */
    /** @brief Modifica el tamaño de la estacion
        \pre newsize es positivo.
        \post El nuevo tamaño de la estacion pasa a ser newsize.
        */
    void mod_capacidad(const int& newsize);
    /** @brief Agrega una bicicleta a la estacion
        \pre Cierto.
        \post El identificador de bicicleta ID pasa a estar en Bicis.
        */
    void agregar_bicicleta(const string& ID);
    /** @brief Quita la Bicicleta de la estacion
        \pre IDbici existe en la estacion.
        \post El Identificador de bicicleta IDbici es removido de la estacion.
        */
    void quitar_bici(const string& IDbici);

    /** @brief Modifica el nombre de la estacion
        \pre Cierto.
        \post El nuevo nombre_estacion de la estacion pasa a ser name.
        */
    void agregar_nombre(const string& name);

    /** @brief Modifica el tamaño de la estacion
        \pre Cierto.
        \post El nuevo size de la estacion pasa a ser tam.
        */
    void agregar_tam(const int& tam);
    
   
                /*     Lectura y Escriptura     */
    /** @brief Imprime las bicicletas de la estacion.
        \pre Cierto.
        \post Imprime las todos los identificadores de las bicicletas de la estacion.
        */
    void escribir_bicics();


};

#endif
