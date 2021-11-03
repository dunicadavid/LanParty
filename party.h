#pragma once
#include "team.h"
#include "coada.h"
#include "stiva.h"
#include "BST.h"

class LanParty
{
private:
	int n;
	Team* capLista;
	Coada* incCoada, * sfCoada;
	Stiva* stW, * stL;
	Stiva* listaTop;   // cu toate ca este din clasa stiva am considerat-o ca o lista;
	Stiva* listaAux;
	Arbore* root, * rootAVL;
public:
	LanParty();
	LanParty(int, Team*, Coada*, Coada*, Stiva*, Stiva*, Stiva*, Stiva*, Arbore*, Arbore*);
	~LanParty(){}
	void Citire(istream&);
	void ReducereLista();
	void StergeEchipa(Team*);
	void CompletareListaTop();
	void CompletareCoada();
	void RecompletareCoada(Stiva*);
	void CompletareArbore(ostream&);
	Arbore* CreareElementArbore(string, float);
	Arbore* InserareArbore( Arbore*, Stiva*);
	Stiva* CompletareNodLista(string, float, Stiva*);
	//Functii AVL
	int NodeHeight(Arbore*);
	Arbore* RotatieDreapta(Arbore*);
	Arbore* RotatieStanga(Arbore*);
	Arbore* RotatieLR(Arbore*);
	Arbore* RotatieRL(Arbore*);
	Arbore* InserareAVL(Arbore*, Stiva*);
	void CreareAVL(ostream&);
	Arbore* AdaugareNodAVL(Stiva*);
	//
	void afisAVL(Arbore*, ostream&, int)const;
	void GenerareMeciuri(ostream&);
	virtual void afis(ostream&) const;
	void afisareWinners(ostream&) const;
	void afisareArbore(ostream&, Arbore*, Stiva*);
	//
	int max(int, int);
};