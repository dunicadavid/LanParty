#include "party.h"

LanParty::LanParty()
{
	n = 0;
	capLista = NULL;
	incCoada = NULL;
	sfCoada = NULL;
	stW = NULL;
	stL = NULL;
	listaTop = NULL;
	listaAux = NULL;
	root = NULL;
	rootAVL = NULL;
}

LanParty::LanParty(int i, Team* tm, Coada* c1, Coada* c2, Stiva* s1, Stiva* s2, Stiva* l, Stiva* s3, Arbore* a1, Arbore* a2)
{
	n = i;
	capLista = tm;
	incCoada = c1;
	sfCoada = c2;
	stW = s1;
	stL = s2;
	listaTop = l;
	listaAux = s3;
	root = a1;
	rootAVL = a2;
}

void LanParty::Citire(istream& file)
{
	int x,puncteAux;
	string s,numeAux,prenumeAux;
	Team* k,* q;
	Player* playerAux;


	int nGenerat = 1;
	file >> n;
	while (nGenerat <= n)
		nGenerat *= 2;
	nGenerat /= 2;


	file >> x ;
	getline(file, s);
	s = s.substr(1, s.length() - 1);
	while(s[s.length()-1] == ' ')
		s = s.substr(0,s.length()-1);
	playerAux = new Player[x];
	for (int i = 0; i < x; i++)
	{
		file >> numeAux >> prenumeAux >> puncteAux;
		playerAux[i].GetFirstName(numeAux);
		playerAux[i].GetSecondName(prenumeAux);
		playerAux[i].GetPoints(puncteAux);
	}
	k = new Team();
	k->GetPlayers(x);
	k->GetNumeEchipa(s);
    k->GetP(playerAux);
	k->GetUrm(NULL);
	
	for (int i = 1; i < n; i++)
	{
		file >> x;
		getline(file, s);
		s = s.substr(1, s.length() - 1);
		while(s[s.length()-1] == ' ')
			s = s.substr(0,s.length()-1);
		playerAux = new Player[x];
		for (int j = 0; j < x; j++)
		{
			file >> numeAux >> prenumeAux >> puncteAux;
			playerAux[j].GetFirstName(numeAux);
			playerAux[j].GetSecondName(prenumeAux);
			playerAux[j].GetPoints(puncteAux);
		}
		q = new Team();
		q->GetPlayers(x);
		q->GetNumeEchipa(s);
		q->GetP(playerAux);
		q->GetUrm(k);
		k = q;
	} 
	capLista = k;

}

void LanParty::ReducereLista()
{
	int nGenerat = 1;
	while (nGenerat <= n)
		nGenerat *= 2;
	nGenerat /= 2;
	n -= nGenerat;
	Team* k;
	
	while (n)
	{
		Team* q = capLista;
		float y = capLista->ReturnMedie();
		for (k = capLista->ReturnUrm(); k != NULL; k = k->ReturnUrm())
		{
			if (k->ReturnMedie() < y)
			{
				y = k->ReturnMedie();
				q = k;
			}
		}

		StergeEchipa(q);
		n--;
	}
	n = nGenerat;
}

void LanParty::StergeEchipa(Team* teamMin)
{
	if (teamMin == capLista)
	{
		capLista = capLista->ReturnUrm();
		teamMin->~Team();	
	}
	else
	{
		Team* q = capLista;
		while (q->ReturnUrm() != teamMin)
			q = q->ReturnUrm();
		q->GetUrm(teamMin->ReturnUrm());
		teamMin->~Team();
	}
}

void LanParty::CompletareCoada()
{
	Team* q ;
	Coada* k, * o;
	k = new Coada();
	k->GetNume1(capLista->ReturnNumeEchipa());
	k->GetNota1(capLista->ReturnMedie());
	q = capLista->ReturnUrm();
	capLista->~Team();
	capLista = q;
	k->GetNume2(q->ReturnNumeEchipa());
	k->GetNota2(q->ReturnMedie());
	k->GetAnt(NULL);
	k->GetUrm(NULL);
	incCoada = k;
	for (q = q->ReturnUrm(); q != NULL;)
	{
		o = new Coada();
		o->GetNume1(q->ReturnNumeEchipa());
		o->GetNota1(q->ReturnMedie());
		q = q->ReturnUrm();
	    o->GetNume2(q->ReturnNumeEchipa());
		o->GetNota2(q->ReturnMedie());
		o->GetUrm(NULL);
		k->GetUrm(o);
		o->GetAnt(k);	
		k = o;
		capLista = q;
		q = q->ReturnUrm();
		capLista->~Team();
	}
	sfCoada = k;
}

void LanParty::CompletareListaTop()
{
	Stiva* q, * k, * g;
	k = new Stiva();
	q = stW;
	k->GetNume(q->ReturnNume());
	k->GetNota(q->ReturnNota());
	k->GetUrm(NULL);
	listaTop = k;
	for (q = q->ReturnUrm(); q != NULL; q = q->ReturnUrm())
	{
		g = new Stiva();
		g->GetNume(q->ReturnNume());
		g->GetNota(q->ReturnNota());
		g->GetUrm(NULL);
		k->GetUrm(g);
		k = g;
	}

}

void LanParty::RecompletareCoada(Stiva* st)
{
	Stiva* q =new Stiva();
	q = st;
	Coada* k, * o;
	k = new Coada();
	k->GetNume1(q->ReturnNume());
	k->GetNota1(q->ReturnNota());
	q = q->ReturnUrm();
	k->GetNume2(q->ReturnNume());
	k->GetNota2(q->ReturnNota());
	k->GetAnt(NULL);
	k->GetUrm(NULL);
	incCoada = k;
	for (q = q->ReturnUrm(); q != NULL; q = q->ReturnUrm())
	{
		o = new Coada();
		o->GetNume1(q->ReturnNume());
		o->GetNota1(q->ReturnNota());
		q = q->ReturnUrm();
	    o->GetNume2(q->ReturnNume());
		o->GetNota2(q->ReturnNota());
		o->GetUrm(NULL);
		k->GetUrm(o);
		o->GetAnt(k);
		
		k = o;
	}
	sfCoada = k;
}

void LanParty::CompletareArbore(ostream& file)
{
	Stiva* q = new Stiva();
	root = NULL;	
	for (q = listaTop; q != NULL; q = q->ReturnUrm())
	{
		root = InserareArbore(root, q);
	}

	file << endl << "TOP 8 TEAMS:"<<endl;
	afisareArbore(file, root, listaAux);
	root->~Arbore();
}

Arbore* LanParty::CreareElementArbore(string s, float f)
{
	Arbore* q = new Arbore();
	q->GetNota(f);
	q->GetNume(s);
	q->GetDr(NULL);
	q->GetSt(NULL);
	return q;
}

Arbore* LanParty::InserareArbore(Arbore* arb, Stiva* q)
{
	if (arb == NULL)
	{
		return CreareElementArbore(q->ReturnNume(), q->ReturnNota());
	}
	if (arb->ReturnNota() > q->ReturnNota())
	{
		arb->GetSt(InserareArbore(arb->ReturnSt(), q));
	}
	else if (arb->ReturnNota() < q->ReturnNota())
	{
		arb->GetDr(InserareArbore(arb->ReturnDr(), q));
	}
	else if (arb->ReturnNume() > q->ReturnNume())
	{
		arb->GetSt(InserareArbore(arb->ReturnSt(), q));
	}
	else 
	{
		arb->GetDr(InserareArbore(arb->ReturnDr(), q));
	}
	return arb;
}

Stiva* LanParty::CompletareNodLista(string s, float f, Stiva* cap)
{
	if (!cap)
	{
		cap = new Stiva();
		cap->GetNota(f);
		cap->GetNume(s);
		cap->GetUrm(NULL);
		return cap;
	}
	else
		cap->GetUrm(CompletareNodLista(s, f, cap->ReturnUrm()));
	return cap;

}

int LanParty::NodeHeight(Arbore* root)
{
	if (root == NULL) return-1;
	else return root->ReturnHeight();
}

Arbore* LanParty::RotatieDreapta(Arbore* z)
{
	Arbore* y = z->ReturnSt();
	Arbore* q = y->ReturnDr();
	y->GetDr(z);
	z->GetSt(q);
	z->GetHeight(max(NodeHeight(z->ReturnSt()), NodeHeight(z->ReturnDr())) + 1);
	y->GetHeight(max(NodeHeight(y->ReturnSt()), NodeHeight(y->ReturnDr())) + 1);
	return y;
}

Arbore* LanParty::RotatieStanga(Arbore* z)
{
	Arbore* y = z->ReturnDr();
	Arbore* q = y->ReturnSt();
	y->GetSt(z);
	z->GetDr(q);
	z->GetHeight(max(NodeHeight(z->ReturnSt()), NodeHeight(z->ReturnDr())) + 1);
	y->GetHeight(max(NodeHeight(y->ReturnSt()), NodeHeight(y->ReturnDr())) + 1);
	return y;
}

Arbore* LanParty::RotatieLR(Arbore* z)
{
	z->GetSt(RotatieStanga(z->ReturnSt()));
	return RotatieDreapta(z);
}

Arbore* LanParty::RotatieRL(Arbore* z)
{
	z->GetDr(RotatieDreapta(z->ReturnDr()));
	return RotatieStanga(z);
}


Arbore* LanParty::AdaugareNodAVL(Stiva* q)
{
	Arbore* node = new Arbore();
	if (rootAVL == NULL)
	{
		node->GetNota(q->ReturnNota());
		node->GetNume(q->ReturnNume());
		node->GetHeight(0);
		node->GetDr(NULL);
		node->GetSt(NULL);
		return node;
	}
	else
	{
		node = InserareAVL(rootAVL, q);
		return node;
	}

}


Arbore* LanParty::InserareAVL(Arbore* node,Stiva* q)
{
	if (node == NULL)
	{
		node = new Arbore();
		node->GetNota(q->ReturnNota());
		node->GetNume(q->ReturnNume());
		return node;
	}
	if (q->ReturnNota() <= node->ReturnNota())
	{
		Arbore* aux = InserareAVL(node->ReturnSt(), q);
		node->GetSt(aux);
	}
	else 
	{
		Arbore* aux = InserareAVL(node->ReturnDr(), q);
		node->GetDr(aux);
	}

	node->GetHeight(1 + max(NodeHeight(node->ReturnSt()), NodeHeight(node->ReturnDr())));

	int k = (NodeHeight(node->ReturnSt()) - NodeHeight(node->ReturnDr()));

	if (k > 1 && q->ReturnNota() <= node->ReturnSt()->ReturnNota())
		return RotatieDreapta(node);
	if (k < -1 && q->ReturnNota() > node->ReturnDr()->ReturnNota())
		return RotatieStanga(node);
	if (k > 1 && q->ReturnNota() > node->ReturnSt()->ReturnNota())
		return RotatieRL(node);
	if (k < -1 && q->ReturnNota() < node->ReturnDr()->ReturnNota())
		return RotatieLR(node);
	return node;
}

void LanParty::CreareAVL(ostream& file)
{
	Stiva* q = new Stiva();
	rootAVL = NULL;
	for (q = listaAux; q != NULL; q = q->ReturnUrm())
	{
		rootAVL = AdaugareNodAVL(q);
	}
	file << endl << "THE LEVEL 2 TEAMS ARE:" << endl;
		afisAVL(rootAVL, file, 1);
	rootAVL->~Arbore();
}

void LanParty::afisAVL(Arbore* a, ostream& file,int lvl) const
{
	Arbore* st = a->ReturnSt();
	Arbore* dr = a->ReturnDr();
	file << dr->ReturnDr()->ReturnNume() << endl;
	file << dr->ReturnSt()->ReturnNume() << endl;
	file << st->ReturnDr()->ReturnNume() << endl;
	file << st->ReturnSt()->ReturnNume() << endl;
}

void LanParty::GenerareMeciuri(ostream& file)
{
	int contor = 1;
	while (n > 2)
	{
		Coada* k;
		Stiva* l1, * m1, * l2, * m2;
		file <<endl<< "--- ROUND NO:" << contor << endl;
		for (k = incCoada; k != NULL; k = k->ReturnUrm())
		{
			file << k->ReturnNume1() << setw(34 - k->ReturnNume1().length()) << "-" << setw(33) << k->ReturnNume2() << endl;
		}

		k = sfCoada;
		if (k->ReturnNota1() > k->ReturnNota2())
		{
			//Completare stiva Winner Loser
			l1 = new Stiva();
			l1->GetNume(k->ReturnNume1());
			l1->GetNota(k->ReturnNota1() + 1);
			l1->GetUrm(NULL);
			stW = new Stiva();
			stW = l1;
			l2 = new Stiva();
			l2->GetNume(k->ReturnNume2());
			l2->GetNota(k->ReturnNota2() );
			l2->GetUrm(NULL);
			stL = new Stiva();
			stL = l2;
		}
		else
		{
			//Completare stiva Winner Loser
			l1 = new Stiva();
			l1->GetNume(k->ReturnNume2());
			l1->GetNota(k->ReturnNota2() + 1);
			l1->GetUrm(NULL);
			stW = new Stiva();
			stW = l1;
			l2 = new Stiva();
			l2->GetNume(k->ReturnNume1());
			l2->GetNota(k->ReturnNota1() );
			l2->GetUrm(NULL);
			stL = new Stiva();
			stL = l2;
		}

		sfCoada = sfCoada->ReturnAnt();
		k->~Coada();
		for (k = sfCoada; k != NULL;)
		{
			if (k->ReturnNota1() > k->ReturnNota2())
			{
				//Completare stiva Winner Loser
				m1 = new Stiva();
				m1->GetNume(k->ReturnNume1());
				m1->GetNota(k->ReturnNota1() + 1);
				m1->GetUrm(NULL);
				l1->GetUrm(m1);
				l1 = m1;
				m2 = new Stiva();
				m2->GetNume(k->ReturnNume2());
				m2->GetNota(k->ReturnNota2());
				m2->GetUrm(NULL);
				l2->GetUrm(m2);
				l2 = m2;
			}
			else
			{
				//Completare stiva Winner Loser
				m1 = new Stiva();
				m1->GetNume(k->ReturnNume2());
				m1->GetNota(k->ReturnNota2() + 1);
				m1->GetUrm(NULL);
				l1->GetUrm(m1);
				l1 = m1;
				m2 = new Stiva();
				m2->GetNume(k->ReturnNume1());
				m2->GetNota(k->ReturnNota1());
				m2->GetUrm(NULL);
				l2->GetUrm(m2);
				l2 = m2;

			}
			k = k->ReturnAnt();
			sfCoada->~Coada();
			sfCoada = k;
		}

		
		RecompletareCoada(stW);
		if (n == 16)
		{
			CompletareListaTop();
		}
		file <<endl<< "WINNERS OF ROUND NO:" << contor << endl;
		afisareWinners(file);
		stL->~Stiva();
		stW->~Stiva();
		n /= 2;
		contor++;
	}
	file << endl << "--- ROUND NO:" << contor << endl;
	file << incCoada->ReturnNume1() << setw(34 - incCoada->ReturnNume1().length()) << "-" << setw(33) << incCoada->ReturnNume2() << endl;
	Stiva* l1, * l2;
	if (incCoada->ReturnNota1() > incCoada->ReturnNota2())
	{
		l1 = new Stiva();
		l1->GetNume(incCoada->ReturnNume1());
		l1->GetNota(incCoada->ReturnNota1() + 1);
		l1->GetUrm(NULL);
		stW = new Stiva();
		stW = l1;
		l2 = new Stiva();
		l2->GetNume(incCoada->ReturnNume2());
		l2->GetNota(incCoada->ReturnNota2());
		l2->GetUrm(NULL);
		stL = new Stiva();
		stL = l2;
	}
	else
	{
		l1 = new Stiva();
		l1->GetNume(incCoada->ReturnNume2());
		l1->GetNota(incCoada->ReturnNota2() + 1);
		l1->GetUrm(NULL);
		stW = new Stiva();
		stW = l1;
		l2 = new Stiva();
		l2->GetNume(incCoada->ReturnNume1());
		l2->GetNota(incCoada->ReturnNota1());
		l2->GetUrm(NULL);
		stL = new Stiva();
		stL = l2;
	}
	stL->~Stiva();
	file << endl << "WINNERS OF ROUND NO:" << contor << endl;
	afisareWinners(file);
	stW->~Stiva();
}

void LanParty::afis(ostream& file) const
{
	for (Team* q = capLista; q != NULL; q = q->ReturnUrm())
	{
		q->afis(file);
	}
}

void LanParty::afisareWinners(ostream& file) const
{
	for (Stiva* q = stW; q != NULL; q = q->ReturnUrm())
	{
		q->afis(file);
	}
}

void LanParty::afisareArbore(ostream& file, Arbore* arb, Stiva* aux)
{
	if (arb != NULL)
	{
		afisareArbore(file, arb->ReturnDr(),aux);
		listaAux=CompletareNodLista(arb->ReturnNume(), arb->ReturnNota(), listaAux);
		arb->afis(file);
		afisareArbore(file, arb->ReturnSt(),aux);	
	}	
}

int LanParty::max(int a, int b)
{
	return ((a > b) ? a : b);
}
