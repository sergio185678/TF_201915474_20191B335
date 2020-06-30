#pragma once
#include<vector>
#include<string>
#include<conio.h>
#include<iostream>
using namespace std;
struct Entero {
	int x;
	short p;
	Entero(int i, short p): x(i), p(p) {}
};
struct Decimal1 {
	float x;
	short p;
	Decimal1(float i, short p) : x(i), p(p) {}
};
struct Cadena {
	string x;
	short p;
	Cadena(string i, short p) : x(i), p(p) {}
};
struct Char1 {
	char x;
	short p;
	Char1(char i, short p) : x(i), p(p) {}
};
class Fila
{
public:        /////////////
	vector<Entero> ints;
	vector<Decimal1> floats;
	vector<Char1> chars;
	vector<Cadena> strings;
public:
	Fila() {};
	~Fila() {};
	void agregar_valor_int(int i, short p) { ints.push_back(Entero(i,p)); }
	void agregar_valor_char(char i, short p) { chars.push_back(Char1(i,p)); }
	void agregar_valor_string(string i, short p) { strings.push_back(Cadena(i,p)); }
	void agregar_valor_float(float i, short p) { floats.push_back(Decimal1(i,p)); }

};

