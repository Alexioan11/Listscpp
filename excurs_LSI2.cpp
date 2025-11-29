// excurs_LSI2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<string>
struct Autoturism
{
    string marca;
    string culoare;
    int nr_inmatriculare;
    
};
struct Nod
{
    Autoturism info;
    Nod* next;
};
Nod* creare_nod(Autoturism a)
{
    Nod* nou = new Nod;
    nou->info = a;
    nou->next = NULL;
    return nou;
}
Nod* inseraresfarsit(Nod* front, const Autoturism a)
{
    Nod* nou = creare_nod(a);

    if (front== NULL)
        return nou; 

    Nod* temp = front;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nou;

    return front; 
}
void afisare(Nod* front)
{
    Nod* temp = front;
    if (front == NULL) {
        cout << "coada este goala " << endl;
    }
    while (temp != NULL)
    {
        cout << "Marca: " << temp->info.marca << " Culoare: " << temp->info.culoare << " Numar inmatriculare: " << temp->info.nr_inmatriculare << endl;
        temp = temp->next;
	}

}
Nod* rearanjareMASINI(Nod* frontsursa)
{
    Nod* frontALB = NULL;
	Nod* frontROSU = NULL;
	Nod* frontAltele = NULL;
    Nod* temp = frontsursa;
 
    while (temp != NULL) {
        Nod* curent = temp;
		temp = temp->next;
        curent->next = NULL;
        string culoare = curent->info.culoare;
        if (culoare == "alb") {
			curent->next = frontALB;
            frontALB = curent;
        }
		else if (culoare == "rosu") {
			frontROSU = inseraresfarsit(frontROSU, curent->info);
            delete curent;
        }
        else {
			frontAltele = inseraresfarsit(frontAltele, curent->info);
			delete curent;
        }
    }
    Nod* frontNou = frontALB;

    // Conecteaza Alb la Altele
    if (frontALB!= NULL) {
        Nod* ultimAlb = frontALB;
        while (ultimAlb->next != NULL) ultimAlb = ultimAlb->next;
        ultimAlb->next = frontAltele;
    }
    else {
        frontNou = frontAltele;
    }

    // Conecteaza Altele (sau Alb) la Rosu
    Nod* ultim = frontNou;
    if (ultim != NULL) {
        while (ultim->next != NULL) ultim = ultim->next;
        ultim->next = frontROSU;
    }
    else {
        // Cazul in care lista initiala era goala, dar acum frontNou e NULL
        if (frontROSU != NULL) frontNou = frontROSU;
    }

    return frontNou;
}
Nod*eliminamasinisub1000(Nod* front)
{
    Nod* temp = front;
    Nod* prev = NULL;
    while (temp != NULL) {
        if (temp->info.nr_inmatriculare < 1000) {
            Nod* de_sters = temp;
            if (prev == NULL) {
                front = temp->next;
                temp = front;
            }
            else {
                prev->next = temp->next;
                temp = prev->next;
            }
            delete de_sters;
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return front;
}
int numaraDACIA(Nod* front)
{
    int contor = 0;
    Nod* temp = front;
    while (temp != NULL) {
        if (temp->info.marca == "Dacia") {
            contor++;
        }
        temp = temp->next;
	}
	return contor;
}
int main()
{
    Nod* coada = NULL;
	Autoturism a1 = { "Dacia", "alb", 1234 };
	Autoturism a2 = { "Ford", "rosu", 5678 };
	Autoturism a3 = { "Dacia", "albastru", 91011 };
	Autoturism a4 = { "Toyota", "alb", 2345 };
	coada = inseraresfarsit(coada, a1);
	coada = inseraresfarsit(coada, a2);
	coada = inseraresfarsit(coada, a3);
	coada = inseraresfarsit(coada, a4);
    cout << "Coada initiala: " << endl;
    afisare(coada);
    coada = rearanjareMASINI(coada);
    cout << "\nCoada dupa rearanjare: " << endl;
    afisare(coada);
    coada = eliminamasinisub1000(coada);
    cout << "\nCoada dupa eliminarea masinilor cu nr_inmatriculare < 1000: " << endl;
    afisare(coada);
    int numarDacia = numaraDACIA(coada);
    cout << "\nNumarul de masini Dacia in coada: " << numarDacia << endl;
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
