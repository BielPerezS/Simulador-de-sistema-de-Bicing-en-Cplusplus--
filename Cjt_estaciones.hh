/** @file Cjt_estaciones.hh
    @brief Especificación de la clase Cjt_estaciones
*/
#ifndef CJT_ESTACIONES_HH
#define CJT_ESTACIONES_HH


#include "Cjt_bicicletas.hh"
#include "Estacion.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"   
#include <map>
#include <string.h>
#endif

/*
 * Clase Cjt_estaciones
 */

/** @class Cjt_estaciones
    @brief Representa una Conjunto de estaciones con estructura de arbol binario, un mapa ordenado por identificador de estacion y su espacio libre global
    
    Sus operaciones permiten dar de alta o quitar una bicicleta, moverla de estacion, subir bicicletas, agregar y quitar estaciones,
    modificar sus capacidad, modificar el arbol y el mapa de estaciones, leer una estructura de estaciones, reducir el numero de la plazas libres totales, consultar el espacio
    libre de una estacion, imprimir la bicicletas de una estacion y asignar a una bicicleta una estacion.
*/


class Cjt_estaciones {
    // Descripción: contiene un conjunto de estaciones en forma ordenada y de BinTree y
    //              las plazas libres globaless
private:
    /* El conjunto de estaciones se guarda en un map ordenado por 
       identificador para facilitar la búsquedas y la impresión de las 
       estaciones, el ArbEst nos muestra la estructura de estas estaciones y el tamaño libre
       nos dice cuantas plazas libres quedan entre todas las estaciones juntas. */

    /*     Variables privadas     */
    /** @brief Arbol que contiene la estructura de las estaciones.*/
    BinTree<string> ArbEst;
    /** @brief Tamaño libre de todas las estaciones juntas*/
    int size_libre;
    /** @brief Map de que contiene las estaciones.*/
    map<string, Estacion> MapEst;

public:
         /*     Constructoras     */
    /** @brief Constructora vacía.
        \pre Cierto.
        \post Crea un conjunto de estaciones vacío.
    */
    Cjt_estaciones();



    	       /*     Modificadoras     */
    /** @brief Añade una bicicleta al conjunto.
        \pre Cierto.
        \post si devuelve 0 El identificador de la bicicleta pasa a estar presente en la estacion selecionada, si devuelve 1 la estacion no existe, si devuelve 2 la bicicleta no cabe 
    */
    int alta_bici(const string& IDest, const string& IDbici);

          
    /** @brief Quita una bicicleta del conjunto.
        \pre Cierto.
        \post El identificador de la bicicleta es removido del conjunto y de su respectiva estacion.
    */
    void baja_bici_est(const string& IDest,const string& IDbici);

    /** @brief Mueve una bicicleta a la estacion deseada.
        \pre Cierto.
        \post si devuelve 0 El identificador de la bicicleta es removido de su estacion actual y pasa a estar en la estacion deseada, si devuelve 1 la estacion deseada no existe, si devuelve 2 la estacion deseada es la actual de la bicicleta, si devuelve 3 la bici no cabe.
        */
    int mover_bici_est(const string &IDbici, const string &IDdest, Cjt_bicicletas& IDest);
    
    /** @brief Modifica la capacidad de una estacion del conjunto
        \pre newsize es estrictamente positivo. 
        \post si devuelve 0 la capacidad de la estacion es modificada con dicho size, si devuelve 1 la estacion no existe, si devuelve 2 el tamaño es menor al numero de bicis que tiene la estacion y no se modifica la capacidad. 
        */
    int modificar_capacidad(const string& IDestacion,const int& newsize);
    
    /** @brief Funcion de inmersion en el Arbol de estaciones
        \pre Cierto. 
        \post Llama a subir_bici_aux pasandole el conjunto de bicicletas y el arbol
         */
    void subir_bici(Cjt_bicicletas& Biciceltas);
    
    /** @brief Acerca bicis hacia la primera estación
        \pre Cierto. 
        \post Las bicis son acercadas a la raiz dejandolas lo mas equilibradas posible
         */
    void subir_bici_aux(const BinTree<string>& a,Cjt_bicicletas& Biciceltas);
    
    /** @brief Sube todas las bicis al padre
        \pre Cierto. 
        \post Las bicis de los 2 hijos son subidas al padre
         */
    void subir_todas_las_bicis(Estacion& DEst, Estacion& Est,Cjt_bicicletas& Bicicletas);
    
    /** @brief Agrega una estacion al conjunto.
        \pre Cierto.
        \post MapEst pasa a contener la estacion est con identificador ID.
    */
    void agregar_estacion(const string& ID, const Estacion& est);
    
    /** @brief Reemplaza ArbEst.
        \pre Cierto.
        \post ArbEst pasa a ser el arbol BinTree<string> a.
    */    
    void mod_arbol(const BinTree<string>& a);

    /** @brief Reemplaza MapEst.
        \pre Cierto.
        \post MapEst pasa a ser el map<string,Estacion> map.
    */
    void mod_mapa(const map<string,Estacion>& map);

    /** @brief Lee el arbol a y cf.second pasa a ser la estacion con mayor coeficiente de desocupacion.
        \pre Cierto.
        \post cf.second pasa a ser la estacion con mayor coeficiente de desocupacion.
    */
    void asignar_estacion_aux(const BinTree<string>& a, double& pl, double& div, pair<double,string>& cf);
    
    /** @brief Agrega una bicicleta a la estacion designada.
        \pre La estacion existe en el conjunto y tiene espacio para la bicicleta.
        \post La bicicleta IDbici es agregada a la estacion IDest.
    */
    void agregar_bicicleta(const string& IDest, const string& IDbici);
    
    /** @brief Reduce el numero de plazas libres.
        \pre Cierto.
        \post El elemento privado size_libre se le resta 1.
    */
    void reducir_pl();

                /*     Consultoras   */
    /** @brief Devuelve las plazas libres.
        \pre Cierto.
        \post Devuelve cuantas plazas libres quedan en todo el conjunto.
    */
    int plazas_libres();
    /** @brief Devuelve el espacio libre de una estacion.
        \pre Cierto.
        \post Si devuelve 1 la el identificador de estacion IDest no existia en el conjunto de bicicletas, de otra forma se devuelve el espacio libre de la estacion IDest.
    */
    int consultar_espacio_estacion(const string& IDest);
    
    
                /*     Lectura y Escriptura     */
    /** @brief Imprime las bicicletas de la estacion.
        \pre Cierto.
        \post si devuelve 0 Escribe las bicics de la estacion, si devuelve 1 la estacion no existe.
        */
    int bicis_estacion(const string& IDestacion);
    /** @brief Lee un arbol y un mapa de estaciones.
        \pre Cierto.
        \post a pasa a ser un arbol con los identificadores de las estaciones y b un map con los identificadores y las estaciones.
        */
    void leer_estaciones(BinTree<string>& a, map<string,Estacion>& b);
    
    /** @brief Devuelve la estacion con mayor coeficiente de desocupacion.
        \pre Cierto.
        \post Llama a new_ae_aux y devuelve la estacion con mayor coeficiente de desocupacion.
    */
    string asignar_estacion();
    
    
    
};

#endif