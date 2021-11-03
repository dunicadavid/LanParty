#include "party.h"

int main(int argc, char** argv)
{
	ifstream fin1(argv[2], ios::in);
	ofstream fout(argv[3], ios::out);
	ifstream fin2(argv[1], ios::in);
	LanParty x;
	x.Citire(fin1);

	int v[5];
	for (int i = 0; i < 5; i++)
		fin2 >> v[i];
	

	if(v[0] == 1 && v[1] == 0)
	    x.afis(fout);

	if (v[1] == 1)
	{
		x.ReducereLista();
		x.afis(fout);
	}

	if (v[2] == 1)
	{
		x.CompletareCoada();
		x.GenerareMeciuri(fout);
	}


	if (v[3] == 1)
	{
		x.CompletareArbore(fout);
	}
	

	if (v[4] == 1)
	{
		x.CreareAVL(fout);
	}
	
	return 0;
}
