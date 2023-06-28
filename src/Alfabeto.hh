/** @file Alfabeto.hh
    @brief Especificación de la clase Alfabeto
*/

#ifndef _ALFABETO_HH_
#define _ALFABETO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
using namespace std;

/** @class Alfabeto
    @brief Representa un alfabeto
*/
class Alfabeto
{
public:
	//Constructoras
	
	/** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un alfabeto
      \pre Cierto
      \post El resultado es un alfabeto
  	*/
	Alfabeto();

	/** @brief Creadora con valor concreto. 

      \pre Cierto
      \post El resultado es un alfabeto con el identificador "id" y alf "a"
  	*/
	Alfabeto(const string& id,const string& a);
	
	//Modificadoras
	
	/** @brief Codificación por la sustitución 

      \pre Cierto
      \post Devuelve un mensaje codificado por el método de la sustitución mediante la clave
  	*/   
	void cod_sust(const string& mensaje, const string& clave);
	
	
	/** @brief Decodificación del método sustitución

      \pre Cierto
      \post Devuelve un mensaje en el método de sustitución, decodificado mediante la clave
  	*/  
	void decod_sust(const string& mensaje, const string& clave);

	/** @brief Incremento del número de mensajes que usa el alfabeto
      \pre Cierto
      \post Devuelve el número de mensajes más uno
  	*/
	void inc_num_mensajes();
	
	
	/** @brief Decremento del número de mensajes que usa el alfabeto
      \pre Cierto
      \post Devuelve el número de mensajes menos uno
  	*/
	void dec_num_mensajes();
	//Consultoras
	
	/** @brief Consultar ID
      \pre Cierto
      \post Devuelve el identificador del alfabeto
  	*/
	string consultar_id() const;
	
	/** @brief Consultar número de mensajes del alfabeto
      \pre Cierto
      \post Devuelve el número de mensajes del alfabeto
  	*/
	int consultar_num_mens() const;
	
	/** @brief Consultar el tipo del alfabeto
      \pre Cierto
      \post Devuelve true si es espcial, o false si es normal
  	*/
	bool consultar_especial() const;
	
	/** @brief Consultar el número de mensajes del alfabeto es 0 o no
      \pre Cierto
      \post Devuelve true el num de mensajes es 0, o false si es >0
  	*/
	bool tiene_mensajes()const;
	
	/** @brief Buscar la posición en el alfabeto especial
      \pre Cierto
      \post Devuelve un caracter encontrado por la posición de carácter "mens" y de "clav"
  	*/
	char buscar_carac_esp(const char& mens, const char& clav) const;
	
	/** @brief Buscar la posición en el alfabeto normal
      \pre Cierto
      \post Devuelve un caracter encontrado por la posición de carácter "mens" y de "clav"
  	*/
	char buscar_carac(const char& mens, const char& clav) const;

	/** @brief Buscar la posición original en el alfabeto normal
      \pre Cierto
      \post Devuelve un caracter encontrado por la posición de carácter "mens" y de "clav"
  	*/
	char buscar_carac_ori(const char& mens, const char& clav) const;
	
	/** @brief Buscar la posición original en el alfabeto especial
      \pre Cierto
      \post Devuelve un caracter encontrado por la posición de carácter "mens" y de "clav"
  	*/
	char buscar_carac_ori_esp(const char& mens, const char& clav) const;
	//Escritura y lectura

	/** @brief Operación de lectura
      \pre Por el canal estándar de entrada hay un string para el id, un string para el contenido del alfabeto
      \post El contenido de la entrada está guardado en el parámetro implícito
  	*/
	void leer();

	/** @brief Operación de escritura
      \pre Cierto
      \post Escribe el alfabeto por el canal estándar de salida
  	*/
	void escribir() const;

private:
	string id;
	string alf;
	map<char,int> map_pos;
	int num_mensajes;
	bool especial;
	void formar_map();
	bool es_especial() const;
};
#endif
