#include "team.h"

Team::Team()
{
	players = 0;
	numeEchipa;
	p = NULL;
	urm = NULL;
}

Team::Team(int i, string s, Player *ply, Team* tm)
{
	players = i;
	numeEchipa = s;
	//p = new Player[sizeof(Player) * players + 1];
	p = new Player();
	for (int x = 0; x < i; p[x] = ply[x], x++);
	urm = new Team();
	urm = tm;
}

Team::Team(const Team& t)
{
	players = t.players;
	numeEchipa = t.numeEchipa;
	//p = new Player[sizeof(Player) * players + 1];
	p = new Player();
	for (int x = 0; x < players; p[x] = t.p[x], x++);
	urm = new Team();
	urm = t.urm;
}

Team& Team::operator=(const Team& t)
{
	if (this != &t)
	{
		players = t.players;
		numeEchipa = t.numeEchipa;
		//p = new Player[sizeof(Player) * players + 1];
		p = new Player();
		for (int x = 0; x < players; p[x] = t.p[x], x++);
		urm = new Team();
		urm = t.urm;
	}
	return *this;
}

Team::~Team()
{
	players = 0;
	numeEchipa="";
	p = NULL;
	urm=NULL;
}

void Team::GetPlayers(int i)
{
	players = i;
}

void Team::GetNumeEchipa(string s)
{
	numeEchipa = s;
}

void Team::GetP(Player* pl)
{
	p = pl;
}

void Team::GetUrm(Team* tm)
{
	urm = tm;
}

void Team::afis(ostream& file) const
{
	file << numeEchipa;
	file << endl;
	//for (int i = 0; i < players; i++)
	//{
	//	p[i].Afisare(file);
	//}
	//file << endl;
}

float Team::ReturnMedie()
{
	float medie = 0;
	for (int i = 0; i < players; medie += p[i].ReturnPoints(), i++);
	return medie / players;
}

string Team::ReturnNumeEchipa()
{
	return numeEchipa;
}

Team* Team::ReturnUrm()
{
	return urm;
}