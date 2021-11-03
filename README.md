# LanParty
[En]
C++ OOP project. This application shows participants and teams, matches and a simulation of results based on players powerrank.PROJECT PORPOUSE:  I tested self created lists,  stacks and tails which are connected  through pointers. Project also contains BST and AVL.

[Ro]
Fisier de intelegere al codului :

1. Main
   variabila de tip clasa LanParty, x, insereaza toate celelalte clase, astfel facand tranzitia dintre ele.
   Functia x.Citire(fin1); imi citeste din fisierul fin1 echipele intr-o lista
   Functia x.afis(fout); imi afiseaza numele fiecarei echipe in fisierul fout
   Funtia x.ReducereLista() imi elimina echipele care nu satisfac cerinta
   Apoi se repeta functia de afisare pentru a afisa lista redusa la subpunctul 2
   Functia x.CompletareCoada(); imi adauga in coada elementele listei 2 cate doua in noua clasa Coada
   Functia x.Generare meciuri(fout); imi genereaza meciurile din coada si mi le baga fie in stiva Winners sau cea Losers si apoi repeta pana la castigator + concomitent afiseaza winners
   Functia x.CompletareArbore(fout); imi completeaza din lista nou creata cu top 8 arborele de tip BST si imi afisaza top 8 echipe
   Functia x.CreareAVL(fout); imi creaza un arbore AVL cu lista de echipe (sortata) top 8 si apoi imi afiseaza echipele de pe nivelul 2 al arborelui

2. Player
   Clasa Player din player.h este utilizata ca parametru in clasa Team (din team.h) pentru a stoca fiecare jucator din echipa + scorul
   Clasa contine: 
   private: atributele firstName, secondName, points;
   public: functiile de constructie si destructie +functii de atribuire sau returnare a valoriilor

3. Team
   Clasa Team din team.h este o clasa de tip lista care stocheaza echipele participante la LanParty
   Clasa contine:
   private: atributele players(nr de jucatori ai echipei) , numeEchipa , *p (vector alocat dinamic pentru a introduce un numar egalu cu players de playeri din clasa Player), *urm (pointer de tip Team pentru a indica adresa urmatorului element din lista)
   public: functiile de constructie si destructie +functii de atribuire a valorilor din Team (cele de tip GetCeva) si functii de returnare a valoriilor private din Team (cele de tip ReturnCeva) + functie de afisare a echipei
 
4. Coada
   Clasa Coada din coada.h este o clasa de tip dublu inlantuita avand un pointer atat pentru elementul anterior cat si pentru cel precedent
   Clasa contine:
   private: atributele numeEchipa1, numeEchipa2, note1, note2 (note retine media echipei), *urm si *ant (pointeri ce retin adresa elementului anterior si ulterior)
   public: functiile de constructie si destructie +functii de atribuire a valorilor din Coada (cele de tip GetCeva) si functii de returnare a valoriilor private din Coada (cele de tip ReturnCeva)

5. Stiva
   Clasa Stiva din stiva.h este o clasa asemanatoare cu clasa lista Team. Aceasta retine prin doi parametrii din clasa LanParty stivele stW(stiva winners) si stL(stiva losers)
   PRECIZARE: avand in vedere ca stiva este o lista simplu inlantuita, deoarece este de tip LIFO am folosit aceasta clasa pe post de lista in care am stocat primele 8 echipe la pentru subpunctul 4 si 5
   Clasa contine:
   private: numeEchipa, nota(media echipei), *urm (pointer sper urmatorul element);
   public: functiile de constructie si destructie +functii de atribuire a valorilor din Stiva (cele de tip GetCeva) si functii de returnare a valoriilor private din Stiva (cele de tip ReturnCeva) + functie de afisare a echipei

6. Arbore
   Clasa Arbore din BST.h am folosit-o atat pentru a stoca arborele BST cat si cel AVL, insa in arborele BST parametrul height a fost nefolosit
   Clasa contine:
   private: numeEchipa, nota(media echipei), *st si *dr (pointer sper fii nodului), height(folosit la AVL pentru inaltimea fiecarui nod);
   public: functiile de constructie si destructie +functii de atribuire a valorilor din Arbore (cele de tip GetCeva) si functii de returnare a valoriilor private din Arbore (cele de tip ReturnCeva) + functie de afisare a echipei

7. LanParty
   Clasa LanParty din party.h incorporeaza pointerii spre toate clasele descrise mai sus.
   Clasa contine:
private:
	int n;   (numarul de echipe)                                             
	Team* capLista;     (pointer spre lista initiala)
	Coada* incCoada, * sfCoada;       (pointeri pentru finalul si inceputul cozii utilizate pentru eliminarea termenilor de la final si introducerea din cap)
	Stiva* stW, * stL;       (pointeri spre stivele de castigatori si pierzatori)
	Stiva* listaTop;     (LISTA pentru top 8)
	Stiva* listaAux;     (LISTA pentru top 8 sortata)
	Arbore* root, * rootAVL;        (root - pointer pentru BST, rootAVL - pointer pentru AVL)
public:
	LanParty();   (functie de constructor)
	LanParty(int, Team*, Coada*, Coada*, Stiva*, Stiva*, Stiva*, Stiva*, Arbore*, Arbore*);     (functie de constructor)
	~LanParty(){}    (functie de destructor)
	void Citire(istream&);     (functie care completeaza lista capLista)
	void ReducereLista();      (functie care reduce lista capLista)
	void StergeEchipa(Team*);       (functie care sterge echipa din capLista  -  functie folosita in ReducereLista())
	void CompletareListaTop();       (functie de completare a listei listaTop din stiva de winners cand mai sunt 8 echipe in joc)
	void CompletareCoada();        (functie ce imi completeaza din lista initiala capLista echipele in coada)
	void RecompletareCoada(Stiva*);       (functie ce imi recompleteaza coada cu stiva de winners dupa fiecare runda)
	void CompletareArbore(ostream&);      (functie ce imi completeaza arborele BST)
	Arbore* CreareElementArbore(string, float);     (fct ce imi creaza un element de arbore  -  folosit in InserareArbore())
	Arbore* InserareArbore( Arbore*, Stiva*);    (functie ce imi introduce elementele din stiva in arbore  -  folosita in CreareArbore())
	Stiva* CompletareNodLista(string, float, Stiva*);  (functie ce imi introduce cate un element nou un lista listaAux  -  folosit in afisareArbore()  astfel creez o lista sortata cu primii 8 care ma va ajuta la arborele AVL)
	//Functii AVL
	int NodeHeight(Arbore*);
	Arbore* RotatieDreapta(Arbore*);
	Arbore* RotatieStanga(Arbore*);
	Arbore* RotatieLR(Arbore*);
	Arbore* RotatieRL(Arbore*);
	Arbore* InserareAVL(Arbore*, Stiva*);    (functie auxiliara folosita in AdaugareNodAVL()  care se foloseste si de functiile de rotatie de mai sus)
	void CreareAVL(ostream&);    (fct de creare si afisare a arborelui AVL)
	Arbore* AdaugareNodAVL(Stiva*);         (functie de adaugare fiecarui element din lista in arborele AVL  -  folosita in CreareAVL())
	//
	void afisAVL(Arbore*, ostream&, int)const;     (functie care afisaza elementele de pe nivelul 2 AVL)
	void GenerareMeciuri(ostream&);            (functie care imi genereaza meciurile printr-un loop pana cand se afla castigatorul  -  este functia principala care imi apeleaza majoritatea functiilor de mai sus pentru crearea, generarea si afisarea meciurilor si a castigatorilor)
	virtual void afis(ostream&) const;      (functie de afisare a listei initiale)
	void afisareWinners(ostream&) const;        (functie de afisare a stivei de winners)
	void afisareArbore(ostream&, Arbore*, Stiva*);   (functie ce imi afisaza arborele BST in ordine descrescatoare + imi creaza lista sortata listaAux)
	//
	int max(int, int);
