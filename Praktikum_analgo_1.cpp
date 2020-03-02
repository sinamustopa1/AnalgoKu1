/*
Nama : Sina Mustopa
NPM : 140810180017
Kelas : A 
Deskripsi : Stable Matching Problem pada Kasus pasangan
*/

#include <string.h>
#include <stdio.h>
#include <iostream>
#define N 5

using namespace std;


bool chooseMen(int prioritas[2 * N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prioritas[w][i] == m1)
            return true;

        if (prioritas[w][i] == m)
            return false;
    }
} 
void stable(int prioritas[2 * N][N])
{
    int pasanganWanita[N];

    bool priaJomblo[N];

    memset(pasanganWanita, -1, sizeof(pasanganWanita));
    memset(priaJomblo, false, sizeof(priaJomblo));
    int jumlahJomblo = N;

    while (jumlahJomblo > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (priaJomblo[m] == false)
                break;

        for (int i = 0; i < N && priaJomblo[m] == false; i++)
        {
            int w = prioritas[m][i];

            if (pasanganWanita[w - N] == -1)
            {
                pasanganWanita[w - N] = m;
                priaJomblo[m] = true;
                jumlahJomblo--;
            }

            else
            {
                int m1 = pasanganWanita[w - N];

                if (chooseMen(prioritas, w, m, m1) == false)
                {
                    pasanganWanita[w - N] = m;
                    priaJomblo[m] = true;
                    priaJomblo[m1] = false;
                }
            } 
        }
    }
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "  Pria ---------- Wanita  " << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++)
    {
        if (i < N)
        {
            if (pasanganWanita[i] == 0)
                man = "victor";
            if (pasanganWanita[i] == 1)
                man = "wyatt";
            if (pasanganWanita[i] == 2)
                man = "xavier";
            if (pasanganWanita[i] == 3)
                man = "yancey";
            if (pasanganWanita[i] == 4)
                man = "zeus";
                
            if (i == 0)
                woman = "amy";
            if (i == 1)
                woman = "bertha";
            if (i == 2)
                woman = "clare";
            if (i == 3)
                woman = "diane";
            if (i == 4)
                woman = "erika";
        }
        cout << " " << man << "\t\t  " << woman << endl;
    }
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
}

int main()
{
    int prioritas[2 * N][N] = {{6, 5, 8, 9, 7},
                           	{8, 6, 5, 7, 9},
                            {6, 9, 7, 8, 5},
                            {5, 8, 7, 6, 9},
                            {6, 8, 5, 9, 7},
                            {4, 0, 1, 3, 2},
                            {2, 1, 3, 0, 4},
                            {1, 2, 3, 4, 0},
                            {0, 4, 3, 2, 1},
                            {3, 1, 4, 2, 0}};
    stable(prioritas);

    return 0;
}
 
