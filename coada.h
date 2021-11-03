#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Coada
{
private:
	string numeEchipa1,numeEchipa2;
	float nota1,nota2;
	Coada* urm, * ant;
public:
	Coada();
	Coada(string, string, float, float, Coada*, Coada*);
	Coada(const Coada&);
	Coada& operator=(const Coada&);
	~Coada();
	void GetAnt(Coada*);
	void GetUrm(Coada*);
	void GetNume1(string);
	void GetNota1(float);
	void GetNume2(string);
	void GetNota2(float);
	Coada* ReturnUrm() const;
	Coada* ReturnAnt() const;
	string ReturnNume1() const;
	float ReturnNota1() const;
	string ReturnNume2() const;
	float ReturnNota2() const;
};