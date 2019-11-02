#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int i,angka, input, random, nyawa=3, n=100;
    char jwb='y';
    awal:

    while (jwb=='y'||jwb=='y'){
    cout << "\nMasukkan nilai dari (10-100) :"; cin >> angka;
    if(angka<10){
        cout << "Angka yg anda input terlalu kecil gan!!" << endl;
        goto awal;
    }
    else if(angka>100){
        cout << "Angka yg anda input terlalu besar pak!!" << endl;
        goto awal;
    }
    cout << "Silahkan tebak nilai dari 0 - " << angka << "!!" << endl;
    srand((unsigned)time(NULL));
    random = rand()%angka+1;
    cout << "(CHEAT : Ini adalah angka yg harusnya di tebak ) : " << random << endl;


        while(nyawa>0){
            cout << "\nMasukkan tebakan anda : "; cin >> input;
            if(input==random){
                cout << "\nSelamat tebakan anda Benar!" <<endl;
                break;
            }else{
                if(input<random){
                    cout << "\nTebakan Anda terlalu kecil !!" << endl;
                    cout << "Tebakan Anda salah, nyawa " << nyawa-1 << endl;
                    nyawa--;
                }if(input>random){
                    cout << "\nTebakan Anda terlalu Besar !!" << endl;
                    cout << "Tebakan Anda salah, nyawa " << nyawa-1 << endl;
                    nyawa--;
                }
            }

        }
            if(nyawa==0){
                cout << "Game Over!" << endl;
            }
    cout << "Ingin mengulang game ? (y/n)"; cin >> jwb;
    nyawa=3;
    cout << "" << endl;
    }
    cout << "" << endl;
    cout << "Terimakasih telah memainkan game ini!" << endl;
    return 0;
}
