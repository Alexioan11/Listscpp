// LSI_lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Definire Structura NOD
struct Nod {
	int info;
	struct Nod* succ;
};

// !!! Fiecare functie, inafara de cea de initializare, trebuie inceputa cu o conditie:
//     Daca FRONT este NULL inseamna ca lista nu exista!, altfel, se fac operatiile pe lista.
Nod* init(const int info) {

	// Alocare Dinamica pentru un NOD nou.
	Nod* nodNou = new Nod;

	// Setare informatie in NOD nou.
	nodNou->info = info;

	// Setare urmatorul nod (NULL, la creare nu avem urmatorul NOD) deci il setam pe NULL. 
	nodNou->succ = NULL;

	// Functia returneaza noul NOD.
	return nodNou;
}



Nod* inserareInceput(Nod* front, const int info)
{
	if (front == NULL)
	{
		// Daca lista este goala, creem un nod nou. Acesta devine primul element din lista (front).
		front = init(info);
	}
	else
	{
		// Lista nu era goala. Creem un nod nou.
		Nod* NodNou = init(info);

		// Legam noul nod de vechiul prim nod.
		NodNou->succ = front;

		//Noul prim nod devine noul nod creat mai sus.
		front = NodNou;
	}

	// returnal noul prim nod din lista.
	return front;
}

Nod* inserareSfarsit(Nod* front, const int info)
{
	if (front == NULL) {
		return inserareInceput(front, info);
	}
	else {
		Nod* nodNou = init(info);
		Nod* temp = front;
		while (temp->succ != NULL) {
			temp = temp->succ;
		}
		temp->succ = nodNou;
	}


	return front;
}

Nod* inserareDupa(Nod* front, const int info, const int element)
{
	if (front == NULL) {
		cout << "Error! Lista este goala.";
		return front;
	}
	Nod* temp = front;
	while (temp != NULL && temp->info != element) {
		temp = temp->succ;
	}
	if (temp == NULL) {
		cout << "Elementul nu a fost gasit in lista.";
		return front;
	}
	else {
		Nod* nodNou = init(info);
		nodNou->succ = temp->succ;
		temp->succ = nodNou;
		cout << "Element inserat cu succes dupa " << element << ".";
	}

	return front;
}


Nod* inserareInainte(Nod* front, const int info, const int element)
{
	if (front == NULL) {
		cout << "Error! Lista este goala.";
		return front;
	}
	if (front->info == element) {
		return inserareInceput(front, info);
	}


	return front;
}

Nod* stergereInceput(Nod* front)
{
	if (front == NULL) {
		cout << "Error! Lista este goala.";
		return front;
	}
	else {
		Nod* salv = front;
		front = front->succ;
		delete salv;
	}

	return front;
}

Nod* stergereSfarsit(Nod* front)
{
	if (front == NULL) {
		cout << "Eroare-lista vida"<<endl;
		return front;	
	}
	if (front->succ == NULL) {
		delete front;
		return NULL;	
	}
	else {
		Nod* temp = front;
		while (temp->succ->succ != NULL) {
			temp = temp->succ;
		}
		Nod* salv = temp->succ;
		temp->succ = NULL;
		delete salv;
	}

	return front;
}

Nod* stergereMijloc(Nod* front, const int element)
{ 
	if (front == NULL) {
		cout << "Eroare-lista vida" << endl;
		return front;
	}
	if (front->info == element) {
		return stergereInceput(front);
	}
		
	else {
		Nod* temp = front;
		Nod* dupa = NULL;
		while(temp!= NULL && temp->info != element) {
			dupa = temp;
			temp = temp->succ;
		}
		if (temp == NULL) {
			cout << "Elementul nu a fost gasit in lista." << endl;
			return front;
		}
		Nod* salv = dupa->succ;
		dupa->succ = salv->succ;
		delete salv;
	}

	return front;
}



Nod* cautare(Nod* front, const int element)
{
	Nod* temp = front;
	while(temp!=NULL) {
		if (temp->info == element) {
			cout << "Elementul " << element << " a fost gasit in lista." << endl;
			return temp;
		}
		else {
			temp = temp->succ;

		}
	}
	cout << "Elementul " << element << " nu a fost gasit in lista." << endl;
	return NULL;


}

Nod* actualizare(Nod* front, const int element, int element_nou)
{
	Nod* adr = cautare(front, element);
	if (adr == NULL)
	{
		cout << "Elementul nu a fost gasit in lista." << endl;
	}
	else
	{
		adr->info = element_nou;
		cout << "Elementul " << element << " a fost actualizat cu succes la valoarea " << element_nou << "." << endl;
	}

	return front;
}

int minim(Nod* front)
{
	if (front == NULL)
	{
		cout << "Eroare-lista vida" << endl;
		
	}
	int min = front->info;
	Nod* temp = front->succ;
	while (temp != NULL) {
		if (temp->info < min) {
			min = temp->info;
		}
		temp = temp->succ;
	}
	cout << "Valoarea minima din lista este: " << min << endl;

	return min;
}

int maxim(Nod* front)
{
	if (front == NULL) {
		cout << "Eroare-lista vida" << endl;
	}
	int max = front->info;
	Nod* temp = front->succ;
	while (temp != NULL) {
		if (temp->info > max) {
			max = temp->info;
		}
		temp = temp->succ;
	}
	cout << "Valoarea maxima din lista este: " << max << endl;

	return max;
}

Nod* sortare(Nod* front)
{
	if (front == NULL || front->succ == NULL)
	{
		cout << "Lista este vida sau are un singur element, nu necesita sortare." << endl;
		return front;
	}
	Nod* i,*j;
	int temporar;
	for (i = front; i != NULL; i = i->succ) {
		for (j = i->succ; j != NULL; j = j->succ) {
			if (i->info > j->info) {
				temporar = i->info;
				i->info = j->info;
				j->info = temporar;
			}
		}
	}
	cout << "Lista a fost sortata cu succes." << endl;
	return front;
}
Nod* copiazaPareInlista(Nod* frontsursa)
{
	Nod* frontdestinatie = NULL;
	Nod* temp = frontsursa;
	while (temp != NULL) {
		if (temp->info % 2 == 0) {
			frontdestinatie = inserareSfarsit(frontdestinatie, temp->info);
		}
		temp = temp->succ;
	}
	return frontdestinatie;
}
int numaraImpare(Nod* front)
{
	int count = 0;
	Nod* temp = front;
	while (temp != NULL) {
		if (temp->info % 2 != 0) {
			count++;
		}
		temp = temp->succ;
	}
	cout << "Numarul de elemente impare din lista este: " << count << endl;
	return count;
}
int *copiazaImpareInVector(Nod* front, int &dim)
{
	dim = numaraImpare(front);
	if (dim == 0) {
		cout << "Nu exista elemente impare in lista." << endl;
		return nullptr;
	}
	int* vector = new int[dim];
	Nod* temp = front;
	int index = 0;
	while (temp != NULL) {
		if (temp->info % 2 != 0) {
			vector[index] = temp->info;
			index++;
		}
		temp = temp->succ;
	}
	return vector;
}

void afisare(Nod* front) {

	// Daca primul nod este NULL, lista este evident goala.
	if (front == NULL)
	{
		cout << "Lista este goala!." << endl;
	}
	// Altfel parcurgem toata lista, element cu element, si afisam pe ecran informatia din acel nod. (in cazul nostru, un numar intreg).
	else
	{
		// Facem o copie primului NOD. Mereu facem o copie a primului nod si lucram cu aceasta copie. Pentru a nu pierde primul NOD!
		Nod* temp = front;

		//Cat timp nu ajungem la finalul listei, afisam informatia si mergem la urmatorul nod.
		while (temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->succ;
		}
	}
	cout << endl;
}

void distrugere(Nod* front) {

	// Distrugem toata lista.
	// Parcurgem lista, facem copie pe rand fiecarui nod. Stergem aceasta copie. Apoi mergem inainte cu urmatorul NOD.
	while (front != NULL)
	{
		Nod* temp = front;
		front = front->succ;

		// Delete elibereaza memoria alocata cu new (pe scurt, stergem acel nod).
		delete temp;
	}
}

int main() {

	// Front este primul nod din lista simplu inlantuita. MEREU pastram adresa acestui NOD.
	// Cu primul nod avem acces la toata lista.
	Nod* front = NULL;

	front = inserareInceput(front, 3);
	front = inserareInceput(front, 5);
	front = inserareInceput(front, 4);
	afisare(front);




	// Dupa ce am terminat programul, stergem toata lista.
	distrugere(front);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
