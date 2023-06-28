/** @mainpage program.cc
    @brief Programa principal desde donde se llaman las diferentes funciones
           necesarias para cada uno de los comandos.
*/

#include "Cjt_Mensajes.hh"

int main() 
{
    Cjt_Alfabetos alfabetos;
    alfabetos.leer();
    Cjt_Mensajes mensajes;
    mensajes.leer(alfabetos);

    string cmd;
    cin >> cmd;
    while (cmd != "fin") {
		cout << "#" << cmd;
        if(cmd == "nuevo_mensaje" or cmd == "nm") {
			Mensaje m;
			m.leer();
            cout << ' ' << m.consultar_id() << ' ' << m.consultar_id_alf() << endl;
            if (alfabetos.existe(m.consultar_id_alf())) {
                if (not mensajes.existe(m.consultar_id())) {
                    alfabetos.inc_num_mensajes(m.consultar_id_alf());
                    mensajes.anadir_mensaje(m);
                }
                else cout << "error: ya existe un mensaje con ese identificador" << endl;               
            }
            else cout << "error: el alfabeto no existe" << endl;

        }
        else if(cmd == "nuevo_alfabeto" or cmd == "na"){
            string ida;
            cin >> ida;
            cout << ' ' << ida << endl;
            string alf;
            cin.ignore();
            getline(cin,alf);
            if (not alfabetos.existe(ida)) {
                Alfabeto a(ida,alf);
                alfabetos.anadir_alfabeto(a);
            }
            else cout << "error: el alfabeto ya existe" << endl;
        }
        else if(cmd == "borra_mensaje" or cmd == "bm"){
            string idm;
            cin >> idm;
            cout << ' ' << idm << endl;
            if (mensajes.existe(idm)) {
				mensajes.borrar_mensaje(idm,alfabetos);
            }
            else cout << "error: el mensaje no existe" << endl;
        }
        else if(cmd == "borra_alfabeto" or cmd == "ba"){
            string ida;
            cin >> ida;
            cout << ' ' << ida << endl;
            if (alfabetos.existe(ida)) {
                if (not mensajes.existe_alfabeto(ida,alfabetos)) {
                    alfabetos.borrar_alfabeto(ida);
                }
                else cout << "error: hay mensajes guardados con el alfabeto" << endl;
            }
            else cout << "error: el alfabeto no existe" << endl;
        }
        else if(cmd == "listar_mensajes" or cmd == "lm") {
			cout << endl;
            mensajes.escribir();
        }
        else if(cmd == "listar_alfabetos" or cmd == "la") {
			cout << endl;
            alfabetos.escribir();
        }
        else if(cmd == "codificar_sustitucion_guardado" or cmd == "csg") {
            string idm;
            cin >> idm;
            string cl;
            cin.ignore();
            getline(cin,cl);
            cout << ' ' << idm << ' ' << '"' << cl << '"' << endl;
            if (mensajes.existe(idm)) {
                mensajes.consultar(idm).cod_sust(cl,alfabetos);
            }
            else cout << "error: el mensaje no existe" << endl;
        }
        else if(cmd == "codificar_sustitucion" or cmd == "cs"){
			string ida;
			cin >> ida;
			cin.ignore();
            string cl;
            getline(cin,cl);
            string txt;
			getline(cin,txt);
            cout << ' ' << ida << ' ' << '"' << cl << '"' << endl;
			if (alfabetos.existe(ida)) {
				alfabetos.consultar(ida).cod_sust(txt,cl);
			}
			else cout << "error: el alfabeto no existe" << endl;
			
        }
        else if(cmd == "decodificar_sustitucion" or cmd == "ds"){
			string ida;
			cin >> ida;
			cin.ignore();
			string cl;
			getline(cin,cl);
			string txt;
			getline(cin,txt);
			cout << ' ' << ida << ' ' << '"' << cl << '"' << endl;
			if (alfabetos.existe(ida)) {	
				alfabetos.consultar(ida).decod_sust(txt,cl);
			}
			else cout << "error: el alfabeto no existe" << endl;
        }
        else if(cmd == "codificar_permutacion_guardado" or cmd == "cpg"){
			string idm;
            int b;
            cin >> idm >> b;
            cout << ' ' << idm << ' ' << b << endl;
            if (mensajes.existe(idm)) {
                mensajes.consultar(idm).cod_perm(b);
            }
            else cout << "error: el mensaje no existe" << endl;
        }
        else if(cmd == "codificar_permutacion" or cmd == "cp"){
            int b;
            cin >> b;
            cout << ' ' << b << endl;
            string mensaje;
            cin.ignore();
            getline(cin,mensaje);
            Mensaje m(mensaje);
            m.cod_perm(b);
        }
        else if(cmd == "decodificar_permutacion" or cmd == "dp"){
            int b;
            cin >> b;
            cout << ' ' << b << endl;
            string mensaje;
            cin.ignore();
            getline(cin,mensaje);
            Mensaje m(mensaje);
            m.decod_perm(b);
        }
        cin >> cmd;
    }
}
