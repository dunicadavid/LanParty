#pragma once
#include "player.h"

class Team
{
private:
	int players;
	string numeEchipa;
	Player  *p;
	Team* urm;
public:
	Team();
	Team(int, string, Player*,Team*);
	Team(const Team&);
	Team& operator=(const Team&);
	~Team();
	void GetPlayers(int);
	void GetNumeEchipa(string);
	void GetP(Player*);
	void GetUrm(Team*);
	Team* ReturnUrm();
	float ReturnMedie();
	string ReturnNumeEchipa();
	void afis(ostream&) const;
};
