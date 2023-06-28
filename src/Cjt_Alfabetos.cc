/** @mainpage Cjt_Alfabetos.cc
    @brief Operaciones de la clase Cjt_Alfabetos
*/

#include "Cjt_Alfabetos.hh"

//constructoras

Cjt_Alfabetos::Cjt_Alfabetos() {}

void Cjt_Alfabetos::anadir_alfabeto(const Alfabeto& a)
{
	alfabetos.insert(make_pair(a.consultar_id(),a));
	++num;
	cout << num << endl;
}

void Cjt_Alfabetos::borrar_alfabeto(const string& ida)
{
	alfabetos.erase(ida);
	--num;
	cout << num << endl;
}

void Cjt_Alfabetos::inc_num_mensajes(const string& ida)
{
	alfabetos.find(ida)->second.inc_num_mensajes();
}

void Cjt_Alfabetos::dec_num_mensajes(const string& ida)
{
	alfabetos.find(ida)->second.dec_num_mensajes();
}

bool Cjt_Alfabetos::existe(const string& ida) const
{
	return alfabetos.find(ida) != alfabetos.end();
}

Alfabeto Cjt_Alfabetos::consultar(const string& ida) const
{
	return alfabetos.find(ida)->second;
}

void Cjt_Alfabetos::leer()
{
	cin >> num;
	
	for (int i = 0; i < num; ++i) {
		Alfabeto a;
		a.leer();
		alfabetos.insert(make_pair(a.consultar_id(),a));
	}
}

void Cjt_Alfabetos::escribir() const
{
	int i = 1;
	for (map<string,Alfabeto>::const_iterator it = alfabetos.begin(); it != alfabetos.end(); ++it) {
		cout << i << ". ";
		it->second.escribir();
		++i;
	}
}
