#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Stiva
{
private:
	string numeEchipa;
	float nota;
	Stiva* urm;
public:
	Stiva();
	Stiva(string, float, Stiva*);
	Stiva(const Stiva&);
	Stiva& operator=(const Stiva&);
	~Stiva();
	void GetNume(string);
	void GetNota(float);
	void GetUrm(Stiva*);
	string ReturnNume() const;
	float ReturnNota() const;
	Stiva* ReturnUrm() const;
	void afis(ostream&)const;
};