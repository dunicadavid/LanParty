#include "stiva.h"

Stiva::Stiva()
{
	numeEchipa;
	nota = 0;
	urm = NULL;
}

Stiva::Stiva(string s, float f, Stiva* u)
{
	numeEchipa = s;
	nota = f;
	urm = new Stiva();
	urm = u;
}
Stiva::Stiva(const Stiva& s)
{
	numeEchipa = s.numeEchipa;
	nota = s.nota;
	urm = new Stiva();
	urm = s.urm;
}

Stiva& Stiva::operator=(const Stiva& s)
{
	if (this != &s)
	{
		numeEchipa = s.numeEchipa;
		nota = s.nota;
		urm = new Stiva();
		urm = s.urm;
	}
	return *this;
}

Stiva::~Stiva()
{
	//numeEchipa = "";
	//nota = 0;
	if (urm != NULL)
	{
		delete urm;
	}
	urm = NULL;
}

void Stiva::GetNume(string s)
{
	numeEchipa = s;
}

void Stiva::GetNota(float f)
{
	nota = f;
}

void Stiva::GetUrm(Stiva* u)
{
	urm = u;
}

string Stiva::ReturnNume() const
{
	return numeEchipa;
}

float Stiva::ReturnNota() const
{
	return nota;
}

Stiva* Stiva::ReturnUrm() const
{
	return urm;
}

void Stiva::afis(ostream& file) const
{
	file << numeEchipa << setw(37 - numeEchipa.length()) << "-  " << fixed<<setprecision(2) << nota << endl;
}