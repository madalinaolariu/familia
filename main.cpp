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






int sign(int a)
{
    if(a > 0) return 1;

    if(a < 0) return -1;

    return 0;
}

void curat(int v[], int &sfv, bool &ok, int vizitat[])
{
    for(int i = 0; i < 100; i++)
    {
        v[i] = 0;
        vizitat[i] = 0;
    }

    sfv = 0;

    ok = false;
}

void afisareRudenie(int v[], int sfv, Membru a, Membru b)
{
    if(sfv == 0)
    {
        if(v[0] == -1)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "fiul lui " << b.nume;

            else
            {
                cout << "fiica ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
        if(v[0] == -2)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "nepotul lui" << b.nume;
            else
            {
                cout << "nepoata ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
        if(v[0] == -3)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "stranepotul lui "<<b.nume;
            else
            {
                cout << "stranepoata ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
        if(v[0] == 1)
        {
            cout << a.nume << " este ";

            if(a.barbat)
            {
                cout<<"tatal ";
                if(!b.barbat)
                {


                    if(b.nume[b.nume.size()-1] == 'a')
                    {
                        string x;
                        x=b.nume;
                        x[x.size() - 1] ='e';
                        x.append("i");
                        cout << x;
                    }
                    else cout << "lui " << b.nume;
                }
            }

            if(!a.barbat)
            {
                cout << "mama ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
}
        if(v[0] == 2)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "bunicul lui"<<b.nume;
            else
            {
                cout << "bunica ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
        if(v[0] == 3)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "strabunicul lui "<<b.nume;
            else
            {
                cout << "strabunica ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
    }
    if(sfv == 1)
    {
        if(v[0] == 1 && v[1] == -1)
        {
            cout << a.nume << " este ";

            if(a.barbat)
            {cout << "sotul ";



                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }

            else cout<<"sotia lui "<<b.nume;
        }
        if(v[0] == -2 && v[1] == 2)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "verisorul lui "<<b.nume;
            else
            {
                cout << "verisoara ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
        if(v[0] == -1 && v[1] == 1)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "fratele lui"<<b.nume;
            else
            {
                cout << "sora ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
        if(v[0] == -2 && v[1] == 1)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "nepotul lui "<<b.nume;
            else
            {
                cout << "nepoata ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }


         if(v[0] == -1 && v[1] == 2)
        {
            cout << a.nume << " este ";

            if(a.barbat) cout << "unchiul lui "<<b.nume;
            else
            {
                cout << "matusa ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
    }
    if(sfv == 2)
    {
        if(v[0] == -1 && v[1] == 2 && v[2] == -1 || v[0] == 1 && v[1] == -2 && v[2] == 1)
        {
            cout<< a.nume << " este ";

            if(a.barbat) cout << "cumnatul lui "<<b.nume;
            else
            {
                cout << "cumnata ";

                if(b.nume[b.nume.size()-1] == 'a')
                {
                    string x;
                    x=b.nume;
                    x[x.size() - 1] ='e';
                    x.append("i");

                    cout << x;
                }
                else cout << "lui " << b.nume;
            }
        }
    }
    if(sfv > 2)
      cout << a.nume << " este ruda indepartata cu " << b.nume;

}
void dfs(int a, int b, bool &ok, int vizitat[], int &sfv, int v[], Membru initial, Membru cautat)
{
    if(vizitat[a] == 0) vizitat[a] = 1;
    else return;

    if(a == b)
    {
        ok = true;

        afisareRudenie(v, sfv, initial, cautat);

        cout << endl;
    }

    for(int i = 0; i < arbore.nrLegaturi[a]; i++)
    {
        int x = arbore.legaturi[a][i];

        if(sign(v[sfv]) == 0)
        {
            v[sfv] += arbore.tipLegaturi[a][i];

            dfs(x, b, ok, vizitat, sfv, v, initial, cautat);

            v[sfv] -= arbore.tipLegaturi[a][i];
        }
        else
        {
            if(sign(v[sfv]) == arbore.tipLegaturi[a][i])
            {
                v[sfv] += arbore.tipLegaturi[a][i];

                dfs(x, b, ok, vizitat, sfv, v, initial, cautat);

                v[sfv] -= arbore.tipLegaturi[a][i];
            }
            else
            {
                sfv++;
                v[sfv] += arbore.tipLegaturi[a][i];

                dfs(x, b, ok, vizitat, sfv, v, initial, cautat);

                v[sfv] -= arbore.tipLegaturi[a][i];
                sfv--;
            }
        }
    }
}
