/** @mainpage Alfabeto.cc
    @brief Operaciones de la clase Alfabeto
*/

#include "Alfabeto.hh"

//constructoras
Alfabeto::Alfabeto()
{
    num_mensajes = 0;
}

Alfabeto::Alfabeto(const string& id, const string& a)
{
    this->id = id;
    alf = a;
    especial = es_especial();
    num_mensajes = 0;
    if (not especial) formar_map();
}

//modificadoras

void Alfabeto::cod_sust(const string& mensaje, const string& clave) {
	int n = mensaje.length();
    int m = clave.length();
    string resultado = "";
    if (especial) {
        for(int i = 0; i < n; ++i) {
            resultado += buscar_carac_esp(mensaje[i],clave[i%m]);
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            resultado += buscar_carac(mensaje[i],clave[i%m]);
        }
    }
    cout << '"' << resultado << '"' << endl;
}

void Alfabeto::decod_sust(const string& mensaje, const string& clave)
{
	int n = mensaje.length();
    int m = clave.length();
    string resultado = "";
    if (especial) {
        for(int i = 0; i < n; ++i) {
			resultado += buscar_carac_ori_esp(mensaje[i],clave[i%m]);
        }
    }
    else {
        for(int i = 0; i < n; ++i) { 
            resultado += buscar_carac_ori(mensaje[i],clave[i%m]);
        }
    }
    cout << '"' << resultado << '"' << endl;
}

void Alfabeto::inc_num_mensajes()
{
    ++num_mensajes;
}

void Alfabeto::dec_num_mensajes()
{
	--num_mensajes;
}
//consultoras
bool Alfabeto::tiene_mensajes() const
{
	return num_mensajes != 0;
}

string Alfabeto::consultar_id() const
{
	return id;
}

int Alfabeto::consultar_num_mens() const
{
	return num_mensajes;
}

bool Alfabeto::consultar_especial() const
{
	return especial;
}

char Alfabeto::buscar_carac_esp(const char& mens, const char& clav) const
{
	int i = mens-alf[0];
    int j = clav-alf[0];
    return alf[(i+j)%alf.length()];
}

char Alfabeto::buscar_carac(const char& mens, const char& clav) const
{
	int i = map_pos.find(mens)->second;
	int j = map_pos.find(clav)->second;
	return alf[(i+j)%alf.length()];
}

char Alfabeto::buscar_carac_ori(const char& mens, const char& clav) const
{
	int k = map_pos.find(mens)->second;
	int j = map_pos.find(clav)->second;
	int res;
	if (k-j < 0) res = k-j+alf.length();
	else res = k-j;
	return alf[res];
}

char Alfabeto::buscar_carac_ori_esp(const char& mens, const char& clav) const
{
	int i = mens-alf[0];
    int j = clav-alf[0];
    int res;
	if (i-j < 0) res = i-j+alf.length();
	else res = i-j;
    return alf[res];
}
//lectura
void Alfabeto::leer()
{
    cin >> id;
    cin.ignore();
    getline(cin,alf);
    especial = es_especial();
    num_mensajes = 0;
    if (not especial) formar_map();
}

//escriptura
void Alfabeto::escribir() const
{
    cout << id << endl;
    if (especial) {
        cout << "especial [" << alf[0] << ".." << alf[alf.size()-1] << "] "  << num_mensajes << " mensajes" << endl;
    }
    else cout << "normal " << '"' << alf << '"' << ' ' << num_mensajes << " mensajes" << endl;
}

//operación privada
void Alfabeto::formar_map()
{
    for (int i = 0; i < alf.length(); ++i) {
		map_pos.insert(make_pair(alf[i],i));
    }
}

bool Alfabeto::es_especial() const
{
	int i = 0;
	while (i < alf.length()-1 and alf[i]+1 == alf[i+1]) ++i;
	if (i == alf.length()-1) return true;
	else return false;
}
