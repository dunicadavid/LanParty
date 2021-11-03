#include "player.h"

Player::Player()
{
	firstName;
	secondName;
	points = 0;
}

Player::Player(string s1, string s2, int i)
{
	firstName = s1;
	secondName = s2;
	points = i;
}

Player::~Player()
{
	firstName;
	secondName;
	points = 0;
}

int GetPoints(Player p)
{
	return p.points;
}

void Player::GetFirstName(string s)
{
	firstName = s;
}

void Player::GetSecondName(string s)
{
	secondName = s;
}

void Player::GetPoints(int i)
{
	points=i;
}

//void Player::Afisare(ostream& file)const
//{
//	file << firstName << " " << secondName << " " << points << endl;
//}

int Player::ReturnPoints()const
{
	return points;
}