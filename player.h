#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

class Player
{
private:
    string firstName;
    string secondName;
    int points;
public:
    Player();
    Player(string, string, int);
    ~Player();
    friend int GetPoints(Player);
    void GetFirstName(string);
    void GetSecondName(string);
    void GetPoints(int);
    int ReturnPoints()const;
   // void Afisare(ostream&) const;
};