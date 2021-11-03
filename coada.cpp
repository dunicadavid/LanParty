#include "coada.h"

Coada::Coada()
{
	numeEchipa1;
	numeEchipa2;
	nota1 = 0;
	nota2 = 0;
	urm = NULL;
	ant = NULL;
}

Coada::Coada(string s1, string s2, float f1, float f2, Coada* u, Coada* a)
{
	numeEchipa1 = s1;
	nota1 = f1;
	numeEchipa2 = s2;
	nota2 = f2;
	urm = new Coada();
	urm = u;
	ant = new Coada();
	ant = a;
}

Coada::Coada(const Coada& c)
{
	numeEchipa1 = c.numeEchipa1;
	nota1 = c.nota1;
	numeEchipa2 = c.numeEchipa2;
	nota2 = c.nota2;
	urm = new Coada();
	urm = c.urm;
	ant = new Coada();
	ant = c.ant;
}

Coada& Coada::operator=(const Coada& c)
{
	if (this != &c)
	{
		numeEchipa1 = c.numeEchipa1;
		nota1 = c.nota1;
		numeEchipa2 = c.numeEchipa2;
		nota2 = c.nota2;
		urm = new Coada();
		urm = c.urm;
		ant = new Coada();
		ant = c.ant;
	}
	return *this;
}

Coada::~Coada()
{
	numeEchipa1;
	nota1 = 0;
	numeEchipa2;
	nota2 = 0;
	urm = NULL;
	ant = NULL;
}

void Coada::GetUrm(Coada* c)
{
	urm = c;
}

void Coada::GetAnt(Coada* c)
{
	ant = c;
}

void Coada::GetNota1(float f)
{
	nota1 = f;
}

void Coada::GetNota2(float f)
{
	nota2 = f;
}

void Coada::GetNume1(string s)
{
	numeEchipa1 = s;
}

void Coada::GetNume2(string s)
{
	numeEchipa2 = s;
}


Coada* Coada::ReturnUrm()const
{
	return urm;
}

Coada* Coada::ReturnAnt() const
{
	return ant;
}

string Coada::ReturnNume1() const
{
	return numeEchipa1;
}

string Coada::ReturnNume2() const
{
	return numeEchipa2;
}

float Coada::ReturnNota1() const
{
	return nota1;
}

float Coada::ReturnNota2() const
{
	return nota2;
}
