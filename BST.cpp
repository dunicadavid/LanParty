#include "BST.h"

Arbore::Arbore()
{
	numeEchipa;
	nota = 0;
	height = 0;
	st = NULL;
	dr = NULL;
}

Arbore::Arbore(string s, float f, int i, Arbore* a1, Arbore* a2)
{
	numeEchipa = s;
	nota = f;
	height = i;
	st = new Arbore();
	st = a1;
    dr = new Arbore();
	dr = a2;
}
Arbore::Arbore(const Arbore& a)
{
	numeEchipa = a.numeEchipa;
	nota = a.nota;
	st = new Arbore();
	st = a.st;
	dr = new Arbore();
	dr = a.dr;
}

Arbore& Arbore::operator=(const Arbore& a)
{
	if (this != &a)
	{
		numeEchipa = a.numeEchipa;
		nota = a.nota;
		st = new Arbore();
		st = a.st;
		dr = new Arbore();
		dr = a.dr;
	}
	return *this;
}

Arbore::~Arbore()
{
	if (st != NULL)
	{
		delete st;
	}
	st = NULL;
	if (dr != NULL)
	{
		delete dr;
	}
	dr = NULL;
}

void Arbore::GetSt(Arbore* a)
{
	st = a;
}
void Arbore::GetDr(Arbore* a)
{
	dr = a;
}

void Arbore::GetNota(float f)
{
	nota = f;
}

void Arbore::GetNume(string s)
{
	numeEchipa = s;
}

void Arbore::GetHeight(int i)
{
	height = i;
}

int Arbore::ReturnHeight() const
{
	return height;
}

Arbore* Arbore::ReturnSt() const
{
	return st;
}

Arbore* Arbore::ReturnDr() const
{
	return dr;
}

string Arbore::ReturnNume() const
{
	return numeEchipa;
}

float Arbore::ReturnNota() const
{
	return nota;
}

void Arbore::afis(ostream& file) const
{
	file << numeEchipa << setw(37 - numeEchipa.length()) << "-  " << fixed << setprecision(2) << nota << endl;
}