// exercitii_cursLSI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct produs
{

    int codprodus;
    int cantitate;
	float pret;
};
struct nod
{
    produs info;
    nod* next;
};
float ValoareTotala(nod* front)
{
    if (front == NULL) {
		cout << "Lista este vida.\n";
        return 0;
    }
	float valoare_totala = 0;
    nod* p = front;
    while (p != NULL) {
        valoare_totala += p->info.cantitate * p->info.pret;
        p = p->next;
    }
	return valoare_totala;
}
nod* init(const produs p)
{
    nod* nou = new nod;
    nou->info = p;
    nou->next = NULL;
	return nou;
}
nod*inserareinceput(nod* front, const produs p)
{
    nod* nou = init(p);
    nou->next = front;
    return nou;
}
void distrugerelista(nod*& front)
{
    nod* p = front;
    while (p != NULL) {
        nod* temp = p;
        p = p->next;
        delete temp;
    }
    front = NULL;
}
int main()
{
	nod* front = NULL;
    produs p1 = { 101, 5, 10.0f };
    produs p2 = { 102, 3, 20.0f };
    produs p3 = { 103, 2, 15.0f };
    front = inserareinceput(front, p1);
    front = inserareinceput(front, p2);
    front = inserareinceput(front, p3);
    float valoare_totala = ValoareTotala(front);
    cout << "Valoarea totala a produselor din lista: " << valoare_totala << endl;
    distrugerelista(front);
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
