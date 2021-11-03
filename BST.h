#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Arbore
{
private:
	string numeEchipa;
	float nota;
	int height;
	Arbore* st, * dr;
public:
	Arbore();
	Arbore(string, float, int, Arbore*, Arbore*);
	Arbore(const Arbore&);
	Arbore& operator=(const Arbore&);
	~Arbore();
	void GetSt(Arbore*);
	void GetDr(Arbore*);
	void GetNota(float);
	void GetNume(string);
	void GetHeight(int);
	int ReturnHeight() const;
	Arbore* ReturnSt() const;
	Arbore* ReturnDr() const;
	string ReturnNume() const;
	float ReturnNota() const;
	void afis(ostream&) const;

};
