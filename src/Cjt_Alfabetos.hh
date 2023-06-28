/** @file Cjt_Alfabetos.hh
    @brief Especificación de la clase Conjunto de alfabetos
*/

#ifndef _CJT_ALFABETOS_HH_
#define _CJT_ALFABETOS_HH_

#include "Alfabeto.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Alfabetos
    @brief Representa un conjunto de alfabetos
*/
class Cjt_Alfabetos
{
public:
	//Constructoras
	
	/** @brief Creadora por defecto.
      \pre Cierto
      \post El resultado es un conjunto de alfabetos
  	*/
	Cjt_Alfabetos();
	
	//Modificadoras
	
	/** @brief Añadir un alfabeto
      \pre El alfabeto no existe en el conjunto
      \post El conjunto existe el alfabeto "a"
  	*/
	void anadir_alfabeto(const Alfabeto& a);
	
	/** @brief Borrar un alfabeto
      \pre El alfabeto con id "ida" existe en el conjunto
      \post El conjunto ya no existe el alfabeto "a"
  	*/
	void borrar_alfabeto(const string& ida);
	
	/** @brief Incremento del número de mensajes que usa el alfabeto
      \pre Cierto
      \post Devuelve el número de mensajes del alfabeto "ida" más uno
  	*/
	void inc_num_mensajes(const string& ida);

	/** @brief Decremento del número de mensajes que usa el alfabeto
      \pre Cierto
      \post Devuelve el número de mensajes del alfabeto "ida" menos uno
  	*/
	void dec_num_mensajes(const string& ida);
	//consultoras
	

	
	/** @brief Existe
      \pre  El alfabeto con identificador "idm" existe
      \post Devuelve <em>true</em> si está dentro del conjunto, o <em>false</em> si no
  	*/
	bool existe(const string& ida) const;
	
	/** @brief Consultar un alfabeto
      \pre El alfabeto con id "ida" existe en el conjunto
      \post Devuelve el alfabeto con id "ida" del conjunto
  	*/
	Alfabeto consultar(const string& ida) const;
	
	//lectura y escriptura
	
	/** @brief Operación de lectura
      \pre Por el canal estándar de entrada hay un número n seguido de n alfabetos
      \post El contenido de la entrada es guardado en el parámetro implícito
  	*/
	void leer();

	/** @brief Operación de escritura
      \pre  Cierto
      \post Escribe el contenido del parámetro implícito por el canal estándar
            de salida por el orden alfabético
  	*/
	void escribir() const;
	
private:
	map<string,Alfabeto> alfabetos;
	int num;
};
#endif
