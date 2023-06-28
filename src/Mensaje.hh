/** @file Mensaje.hh
    @brief Especificación de la clase Mensaje
*/

#ifndef _MENSAJE_HH_
#define _MENSAJE_HH_

#include "Cjt_Alfabetos.hh"
#include "BinTree.hh"


#ifndef NO_DIAGRAM
#include <string>
#endif

/** @class Mensaje
    @brief Representa un mensaje
*/
class Mensaje
{
public:
	//Constructoras
	
	/** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un mensaje
      \pre Cierto
      \post El resultado es un mensaje
  	*/
	Mensaje();
	
	/** @brief Creadora con valores concretos. 
      \pre Cierto
      \post El resultado es un mensaje con el identificador "id", el id de alfabeto "alf_id" y el mensaje "txt" 
  	*/   
	Mensaje(const string& id, const string& alf_id, const string& txt);
	
	

	/** @brief Creadora con valore concreto. 
      \pre Cierto
      \post El resultado es un mensaje con el texto "mensaje".
  	*/   
	Mensaje(const string& mensaje);
	
	//Modificadoras


	/** @brief Codificación por la sustitución 

      \pre Cierto
      \post Devuelve un mensaje codificado por el método de la sustitución mediante la clave
  	*/   
	void cod_sust(const string& clave, const Cjt_Alfabetos& cja);
	
	/** @brief Codificación por la permutación

      \pre bloques > 0
      \post Devuelve un mensaje codificado por el método de la permutación dividido en bloques
  	*/   
	void cod_perm(int& bloques);
	
	/** @brief Decodificación del método sustitución

      \pre Cierto
      \post Devuelve un mensaje en el método de sustitución, decodificado mediante la clave
  	*/   
	void decod_sust(const string& clave, const Cjt_Alfabetos& cja);
	
	/** @brief Decodificación del método permutación

      \pre bloques > 0
      \post Devuelve un mensaje en el método de permutación, decodificado mediante el número de bloques
  	*/
	void decod_perm(int& bloques);
	
	//Consultoras
	
	/** @brief Consultar ID
      \pre Cierto
      \post Devuelve el identificador del mensaje
  	*/
	string consultar_id() const;
	
	/** @brief Consultar ID del alfabeto del mensaje
      \pre Cierto
      \post Devuelve el identificador del alfabeto del mensaje
  	*/
	string consultar_id_alf() const;

	//Escritura y lectura

	/** @brief Operación de lectura
      \pre Por el canal estándar de entrada hay un string para el id, un string para el contenido del mensaje.

      \post El contenido de la entrada está guardado en el parámetro implícito
  	*/
	void leer();

	/** @brief Operación de escritura de un mensaje
      \pre Cierto
      \post Escribe el mensaje por el canal estándar de salida
  	*/
	void escribir()const;
	

private:
	string id;
	string texto;
	string alf_id;
	//BinTree<char> formar_arbol(const string& t, int start, int end);
	//void intercambiar_nodos(BinTree<char>& a);
	//void escribir_arbol(const BinTree<char>& a);
};
#endif
