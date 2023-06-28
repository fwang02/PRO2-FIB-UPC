/** @mainpage Cjt_Mensajes.cc
    @brief Operaciones de la clase Cjt_Mensajes
*/

#include "Cjt_Mensajes.hh"

Cjt_Mensajes::Cjt_Mensajes() {}

void Cjt_Mensajes::anadir_mensaje(const Mensaje& m)
{
	mensajes.insert(make_pair(m.consultar_id(),m));
	++num;
	cout << num << endl;
}

void Cjt_Mensajes::borrar_mensaje(const string& idm, Cjt_Alfabetos& cja)
{
	map<string,Mensaje>::iterator it = mensajes.find(idm);
	cja.dec_num_mensajes(it->second.consultar_id_alf());
	mensajes.erase(it);
	--num;
	cout << num << endl;
}

bool Cjt_Mensajes::existe(const string& idm) const
{
	return mensajes.find(idm) != mensajes.end();
}

bool Cjt_Mensajes::existe_alfabeto(const string& ida, Cjt_Alfabetos& cja) const
{	
	return cja.consultar(ida).tiene_mensajes();
	
}

Mensaje Cjt_Mensajes::consultar(const string& idm) const
{
	return mensajes.find(idm)->second;
}

void Cjt_Mensajes::leer(Cjt_Alfabetos& cja)
{
	cin >> num;
	
	Mensaje m;
	for (int i = 0; i < num; ++i) {
		m.leer();
		cja.inc_num_mensajes(m.consultar_id_alf());
		mensajes.insert(make_pair(m.consultar_id(),m));
	}
}

void Cjt_Mensajes::escribir() const
{
	int i = 1;
	for (map<string,Mensaje>::const_iterator it = mensajes.begin(); it != mensajes.end(); ++it) {
		cout << i << ". ";
		it->second.escribir();
		++i;
	}
}
