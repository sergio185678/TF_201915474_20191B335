#pragma once
#include "AVLBST.h"
#include "Fila.h"
#include <functional>

class Columna
{
	char tipo;
	// keys
	function<int(Fila*, short)> k1 = [](Fila* f, short pos) {
		for (short i = 0; i < f->ints.size(); ++i) {
			if (f->ints.at(i).p == pos)
				return f->ints.at(i).x;
		}
	};
	function<char(Fila*, short)> k2 = [](Fila* f, short pos) {
		for (short i = 0; i < f->chars.size(); ++i) {
			if (f->chars.at(i).p == pos)
				return f->chars.at(i).x;
		}
	};
	function<float(Fila*, short)> k3 = [](Fila* f, short pos) {
		for (short i = 0; i < f->floats.size(); ++i) {
			if (f->floats.at(i).p == pos)
				return f->floats.at(i).x;
		}
	};
	function<string(Fila*, short)> k4 = [](Fila* f, short pos) {
		for (short i = 0; i < f->strings.size(); ++i) {
			if (f->strings.at(i).p == pos)
				return f->strings.at(i).x;
		}
	};

	//posibles árboles
	AVLBST<Fila*, int> *idxI;
	AVLBST<Fila*, char> *idxC;
	AVLBST<Fila*, float> *idxF;
	AVLBST<Fila*, string> *idxS;

public:

	Columna(char t) :tipo(t)
	{
		if (tipo == 'I') {
			idxI = new AVLBST<Fila*, int>(k1);
		}
		else if (tipo == 'C') {
			idxC = new AVLBST<Fila*, char>(k2);
		}
		else if (tipo == 'F') {
			idxF = new AVLBST<Fila*, float>(k3);
		}
		else if (tipo == 'S') {
			idxS = new AVLBST<Fila*, string>(k4);
		}
	};
	~Columna() {};
	void Add_element(Fila *f, short pos)
	{
		if (tipo == 'I') {
			idxI->add(f, pos);
		}
		else if (tipo == 'C') {
			idxC->add(f, pos);
		}
		else if (tipo == 'F') {
			idxF->add(f, pos);
		}
		else if (tipo == 'S') {
			idxS->add(f, pos);
		}
	}
	void ordenar(ListView ^l, vector<char> orden)
	{
		if (tipo == 'I') {
			idxI->inOrder(l, orden);
		}
		else if (tipo == 'C') {
			idxC->inOrder(l, orden);
		}
		else if (tipo == 'F') {
			idxF->inOrder(l, orden);
		}
		else if (tipo == 'S') {
			idxS->inOrder(l, orden);
		}
	}
	void mayorQue(String ^s, ListView ^l, vector<char> orden, short pos)
	{
		if (tipo == 'I') {
			idxI->greaterThan(Convert::ToInt32(s), l, orden, pos);
		}
		else if (tipo == 'C') {
			idxC->greaterThan(Convert::ToChar(s), l, orden, pos);
		}
		else if (tipo == 'F') {
			idxF->greaterThan(Convert::ToDouble(s), l, orden, pos);
		}
		else if (tipo == 'S') {
			idxS->greaterThan(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
	}
	void menorQue(String ^s, ListView ^l, vector<char> orden, short pos)
	{
		if (tipo == 'I') {
			idxI->lowerThan(Convert::ToInt32(s), l, orden, pos);
		}
		else if (tipo == 'C') {
			idxC->lowerThan(Convert::ToChar(s), l, orden, pos);
		}
		else if (tipo == 'F') {
			idxF->lowerThan(Convert::ToDouble(s), l, orden, pos);
		}
		else if (tipo == 'S') {
			idxS->lowerThan(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
	}
	void empiezaCon(String ^s, ListView ^l, vector<char> orden, short pos)
	{
		if (tipo == 'I') {
			idxI->startsWith_2(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
		else if (tipo == 'C') {
			idxC->startsWith_3(Convert::ToChar(s), l, orden, pos);
		}
		else if (tipo == 'F') {
			idxF->startsWith_2(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
		else if (tipo == 'S') {
			idxS->startsWith(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
	}
	void terminaCon(String ^s, ListView ^l, vector<char> orden, short pos)
	{
		if (tipo == 'I') {
			idxI->finishWith_2(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
		else if (tipo == 'C') {
			idxC->startsWith_3(Convert::ToChar(s), l, orden, pos);
		}
		else if (tipo == 'F') {
			idxF->finishWith_2(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
		else if (tipo == 'S') {
			idxS->finishWith(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
		}
	}
	void contenidoEn(String ^s, ListView ^l, vector<char> orden, short pos)
	{
		if (tipo == 'S') 
			idxS->containedIn(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
	}
	void noContenidoEn(String ^s, ListView ^l, vector<char> orden, short pos)
	{
		if (tipo == 'S')
			idxS->notContainedIn(msclr::interop::marshal_as<std::string>(s), l, orden, pos);
	}
};


