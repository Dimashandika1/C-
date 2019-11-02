#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    srand( static_cast<unsigned int>(time(0)) );
    int jumlah_huruf;
    string kata;
    string kata_acak;
    //kata = "semarang";

    cout << "input kata : "; cin >> kata;
    cout << kata << endl;
    jumlah_huruf = kata.size();
    cout << "\nJumlah huruf dari " << kata << " adalah : " << jumlah_huruf << endl;

    vector<int> sudah;
    vector<int>::iterator penunjuk;

    for(int a=0; a<kata.size(); a++)
    {
        int kembar = 0;
        int angka = rand()%kata.size();
        if( sudah.size()>0 ){
            for(penunjuk = sudah.begin(); penunjuk != sudah.end(); penunjuk++){
                if( *penunjuk==angka ){
                    kembar=1;
                    a--;
                    break;
                }
            }
        }

        if(!kembar){
            sudah.push_back(angka);
            kata_acak.push_back(kata[angka]);
        }
    }
    cout << "\nKata Acak : " << endl;
    cout << kata_acak << endl;

    return 0;
}
