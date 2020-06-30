#pragma once
#include"Fila.h"
#include"Columna.h"
#include<fstream>
#include<vector>
#include<string>
#include<conio.h>
#include<iostream>
using namespace std;

class Tabla
{
private:
	vector<char> orden_tipos;
	vector<Fila*> *filas = new vector<Fila*>;
	vector<Columna*> *columnas = new vector<Columna*>;
public:
	short idx_col;
public:
	Tabla() {
		idx_col = 0;
	};
	~Tabla() {};

	void indexar(char tipo) { columnas->push_back(new Columna(tipo)); }

	void agregar_datos(Fila *f, short pos) { columnas->at(idx_col)->Add_element(f, pos); }

	void ordenar(ListView ^l, short n) { columnas->at(n)->ordenar(l, orden_tipos); }

	void mayorQue(String ^s, ListView ^l, short n, short pos) { columnas->at(n)->mayorQue(s, l, orden_tipos, pos); }

	void menorQue(String ^s, ListView ^l, short n, short pos) { columnas->at(n)->menorQue(s, l, orden_tipos, pos); }

	void empiezaCon(String ^s, ListView ^l, short n, short pos) { columnas->at(n)->empiezaCon(s, l, orden_tipos, pos); }

	void terminaCon(String ^s, ListView ^l, short n, short pos) { columnas->at(n)->terminaCon(s, l, orden_tipos, pos); }

	void contenidoEn(String ^s, ListView ^l, short n, short pos) { columnas->at(n)->contenidoEn(s, l, orden_tipos, pos); }

	void noContenidoEn(String ^s, ListView ^l, short n, short pos) { columnas->at(n)->noContenidoEn(s, l, orden_tipos, pos); }

	void agregar_tipo(char T) { orden_tipos.push_back(T); }

	char ordentipo(int i) { return orden_tipos.at(i); }

	int tamañofila(){return filas->size();}

	Fila* fila(int i) { return filas->at(i); }

	Columna*columna(int i) { return columnas->at(i); }

	void agregar_fila() { filas->push_back(new Fila()); }

	char tipo(int i) { return orden_tipos.at(i); }

	void guardar_fila() { 
		ofstream archivoo("guardado2.txt", ios::binary, ios::trunc);
		for (int i = 0; i < filas->size(); i++) {
			int tamañoint = filas->at(i)->ints.size(); int tamañofloat = filas->at(i)->floats.size();
			int tamañochar = filas->at(i)->chars.size(); int tamañostring = filas->at(i)->strings.size();
			archivoo.write((char*)&tamañoint, sizeof(int));
			archivoo.write((char*)&tamañofloat, sizeof(int));
			archivoo.write((char*)&tamañochar, sizeof(int));
			archivoo.write((char*)&tamañostring, sizeof(int));
			for (int j = 0; j < tamañoint; j++) {
				int a1 = filas->at(i)->ints.at(j).x;
				short b = filas->at(i)->ints.at(j).p;
				archivoo.write((char*)&a1, sizeof(int));
				archivoo.write((char*)&b, sizeof(short));
			}
			for (int j = 0; j < tamañofloat; j++) {
				float a2 = filas->at(i)->floats.at(j).x;
				short b = filas->at(i)->floats.at(j).p;
				archivoo.write((char*)&a2, sizeof(float));
				archivoo.write((char*)&b, sizeof(short));
			}
			for (int j = 0; j < tamañochar; j++) {
				char a3 = filas->at(i)->chars.at(j).x;
				short b = filas->at(i)->chars.at(j).p;
				archivoo.write((char*)&a3, sizeof(char));
				archivoo.write((char*)&b, sizeof(short));
			}
			for (int j = 0; j < tamañostring; j++) {
				string a4 = filas->at(i)->strings.at(j).x;
				short b = filas->at(i)->strings.at(j).p;
				archivoo.write((char*)&a4, sizeof(string));
				archivoo.write((char*)&b, sizeof(short));
			}
		}
		archivoo.close();
	}

	

};

