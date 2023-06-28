/** @file Cjt_Mensajes.hh
    @brief Especificación de la clase Cjt_Mensajes
*/

#ifndef _CJT_MENSAJES_HH_
#define _CJT_MENSAJES_HH_

#include "Mensaje.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Mensajes
    @brief Representa un conjunto de mensajes
*/
class Cjt_Mensajes
{
public:
	//Constructoras
	
	/** @brief Creadora por defecto.
      Se ejecuta automáticamente al declarar un conjunto de mensajes
      \pre Cierto
      \post El resultado es un conjunto de mensajes
  	*/
	Cjt_Mensajes();
	
	//Modificadoras
	
	/** @brief Añadir mensaje al conjunto
      \pre m no existe en el conjunto
      \post El parametro implícito contiene un mensaje "m" más el original
  	*/
	void anadir_mensaje(const Mensaje& m);
	
	/** @brief Borrar mensaje al conjunto
      \pre  El id existe en el parametro implícito 
      \post El parametro implícito pierde el mensaje con id "idm"
  	*/
	void borrar_mensaje(const string& idm, Cjt_Alfabetos& cja);
	
	//consultoras
	
	/** @brief Existe
      \pre  El mensaje con identificador "idm" existe
      \post Devuelve <em>true</em> si está dentro del conjunto, o <em>false</em> si no
  	*/
	bool existe(const string& idm) const;

	/** @brief Existe el alfabeto en los mensajes
      \pre  Cierto
      \post Devuelve <em>true</em> si está dentro del conjunto, o <em>false</em> si no
  	*/
	bool existe_alfabeto(const string& ida, Cjt_Alfabetos& cja) const;
	
	/** @brief Consultar un mensaje
      \pre El mensaje "idm" existe en el conjunto
      \post Devuelve el mensaje "idm" del conjunto
  	*/
	Mensaje consultar(const string& idm) const;
	
	//lectura y escriptura
	
	/** @brief Operación de lectura
      \pre Por el canal estándar de entrada hay un número n seguido de n mensajes
      \post El contenido de la entrada es guardado en el parámetro implícito
  	*/
	void leer(Cjt_Alfabetos& cja);
	
	/** @brief Operación de escritura
      \pre  Cierto
      \post Escribe el contenido del parámetro implícito por el canal estándar
            de salida por el orden alfabético
  	*/
	void escribir() const;

private:
	map<string,Mensaje> mensajes;
	int num;
};
#endif
