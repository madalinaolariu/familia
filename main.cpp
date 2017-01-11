#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

struct Membru
{
    string nume;

    bool barbat;
};

struct Arbore
{
    Membru arb[100];

    int legaturi[100][100];
    int tipLegaturi[100][100];

    int nrLegaturi[100];

    int nrMembri;
};

Arbore arbore;

void init()
{

}

void adaugare(Membru m)
{
    arbore.arb[arbore.nrMembri] = m;

    arbore.nrMembri++;
}

int found(string a)
{
    for(int i = 0; i < arbore.nrMembri; i++)
    {
        if(arbore.arb[i].nume == a) return i;
    }

    return -1;
}

void parent(int a, int b)
{
    arbore.legaturi[a][arbore.nrLegaturi[a]] = b;
    arbore.tipLegaturi[a][arbore.nrLegaturi[a]] = 1;
    arbore.nrLegaturi[a]++;

    arbore.legaturi[b][arbore.nrLegaturi[b]] = a;
    arbore.tipLegaturi[b][arbore.nrLegaturi[b]] = -1;
    arbore.nrLegaturi[b]++;
}


void cititre()
{
    string x, y;

    cout << "\n\t\t\tAdaugati membrii arborelui genealogic\n";
    cout<<"\n\n\t Daca ati terminat apasati tasta S\n";

    while(1)
    {
        cout<<"\n Nume membru: \n";


        getline(cin, x);

        if(x == "S") break;


        cout<<" Daca "<<x<<" este femeie apasati F, daca este barbat apasati B: ";
        while(getline(cin, y))
        {
            if(y == "F" || y == "B") break;

            cout << "Comanda invalida\n";
        }

        Membru a;

        a.nume = x;
        a.barbat = false;
        if(y == "B") a.barbat = true;

        adaugare(a);
    }

    while(1)
    {
        system("cls");

        cout << "\n\t\tInserati relatiile parinte-copil\n\n";

        int a, b;

        bool breakpoint = false;
        cout<<"\tDaca ati terminat apasati tasta S\n\n";
        while(1)
        {
            cout << "Introduceti numele parintelui:\n";

            getline(cin, x);

            if(x == "S")
            {
                breakpoint = true;
                break;
            }

            a = found(x);

            if(a == -1) cout << "Nume invalid, introduceti din nou!\n";

            else break;
        }

        if(breakpoint) break;

        while(1)
        {
            cout << "Introduceti numele copilului:\n";

            getline(cin, y);

            b = found(y);

            if(b == -1) cout << "Nume invalid, introduceti din nou\n";

            else break;
        }

        parent(a, b);

        cout << "\t\tLegatura realizata cu succes\n";

        Sleep(1500);
    }

    system("cls");
}
