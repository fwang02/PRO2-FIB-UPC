/** @mainpage Cjt_Alfabetos.cc
    @brief Operaciones de la clase Mensaje
*/

#include "Mensaje.hh"

BinTree<char> formar_arbol(const string& t, int start, int end)
{
	if (start > end) return BinTree<char>();
	int mid = (start+end)/2;
	BinTree<char>l = formar_arbol(t,start,mid-1);
	BinTree<char>r = formar_arbol(t,mid+1,end);
	return BinTree<char>(t[mid],l,r);
}

void intercambiar_nodos(BinTree<char>& a)
{
	if(not a.empty()) {
		BinTree<char> l;
		BinTree<char> r;
		if (not a.left().empty() and not a.right().empty()) {
			l = BinTree<char>(a.right().value(), a.left().left(),a.left().right());
			r = BinTree<char>(a.left().value(), a.right().left(),a.right().right());
			intercambiar_nodos(l);
			intercambiar_nodos(r);
		}
		else {
			l = a.left();
			r = a.right();
		}
		a = BinTree<char>(a.value(),l,r);
	}
}

void escribir_arbol(const BinTree<char>& a)
{
	if(not a.empty()) {
		escribir_arbol(a.left());
		cout << a.value();
		escribir_arbol(a.right());
	}
}


Mensaje::Mensaje() {}

Mensaje::Mensaje(const string& id, const string& alf_id, const string& txt)
{
	this->id = id;
	this->alf_id = alf_id;
	texto = txt;
}

Mensaje::Mensaje(const string& mensaje)
{
	texto = mensaje;
}

void Mensaje::cod_sust(const string& clave, const Cjt_Alfabetos& cja)
{
	int n = texto.length();
    int m = clave.length();
    Alfabeto a = cja.consultar(alf_id);
    string resultado = "";
    if (a.consultar_especial()) {
        for(int i = 0; i < n; ++i) {
            resultado += a.buscar_carac_esp(texto[i],clave[i%m]);
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            resultado += a.buscar_carac(texto[i],clave[i%m]);
        }
    }
    cout << '"' << resultado << '"' << endl;
}

void Mensaje::cod_perm(int& bloques) 
{
	int n = texto.length();
	if (bloques >= n) {
		BinTree<char>arbol_texto = formar_arbol(texto,0,n-1);
		intercambiar_nodos(arbol_texto);
		cout << '"';
		escribir_arbol(arbol_texto);
		cout << '"' << endl;
	}
	else {
		int bl = n/bloques;
		int ini=0;
		cout << '"';
		for(int i = 1; i <= bl; ++i) {
			BinTree<char>arbol_texto = formar_arbol(texto,ini,bloques*i-1);
			intercambiar_nodos(arbol_texto);
			escribir_arbol(arbol_texto);
			ini += bloques;
		}
		if (n % bloques != 0) {
			BinTree<char>arbol_texto = formar_arbol(texto,ini,n-1);
			intercambiar_nodos(arbol_texto);
			escribir_arbol(arbol_texto);
		}
		cout << '"' << endl;
	}
}

void Mensaje::decod_sust(const string& clave, const Cjt_Alfabetos& cja)
{
	int n = texto.length();
    int m = clave.length();
    Alfabeto a = cja.consultar(alf_id);
    string resultado = "";
    if (a.consultar_especial()) {
        for(int i = 0; i < n; ++i) {
			resultado += a.buscar_carac_ori_esp(texto[i],clave[i%m]);
        }
    }
    else {
        for(int i = 0; i < n; ++i) { 
            resultado += a.buscar_carac_ori(texto[i],clave[i%m]);
        }
    }
    cout << '"' << resultado << '"' << endl;
}

void Mensaje::decod_perm(int& bloques)
{
	cod_perm(bloques);
}

string Mensaje::consultar_id() const
{
	return id;
}

string Mensaje::consultar_id_alf() const
{
	return alf_id;
}

void Mensaje::leer()
{
	cin >> id >> alf_id;
	cin.ignore();
	getline(cin,texto);
}

void Mensaje::escribir()const
{
	cout << id << endl;
	cout << alf_id << endl;
	cout << '"' << texto << '"' << endl;
}



