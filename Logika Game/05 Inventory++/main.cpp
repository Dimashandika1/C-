#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int maks,hapus;

    int pilih = 1;
    vector <string> item;
    unsigned int maksInventory = 0;
    long int maksItem = item.size();
    vector <string>::iterator penunjuk;

    cout << "Jumlah Maksimal Inventory : "; cin >> maks;
    cout << "Max kapasitas inventory : ";
	cin >> maksInventory; //input maksimal kapasitas inventory
	cout << endl;
    awal:
        while(pilih!=0){
            cout << "\nPilihan Menu Inventory" <<endl;
            cout << "1. Tampilkan item" <<endl;
            cout << "2. Hapus item" <<endl;
            cout << "3. Tambah item" <<endl;
            cout << "0. Keluar" <<endl;
            cout << "Masukkan Pilihan : ";cin >> pilih;

            if(pilih==1){
                for(penunjuk = item.begin(); penunjuk!=item.end(); penunjuk++){
                        cout << "- " <<*penunjuk << endl;
                }
            }
            if(pilih==2){
                cout << "Hapus Item Ke- ";cin >> hapus;
                if(hapus<=item.size()){
                    item.erase(item.begin()+(hapus-1));
                    cout << "Item anda telah dihapus!" << endl;
                }else{
                    cout << "Tidak ada item yang di hapus!" << endl;
                }
            }
            if(pilih==3){
                if(item.size()<maks){
                    string input;
                    cout << "Masukan Item : "; cin >> input;
                    item.push_back(input);
                    cout << "Item telah ditambah" << endl;
                }else{
                    cout << "Item anda penuh!" << endl;
                }
            }
        }
//    for(penunjuk = item.begin(); penunjuk!= item.end(); penunjuk++){
//        cout << *penunjuk << endl;
//    }
//    cout << endl;
//    item.erase(item.begin());
//
//    for(penunjuk = item.begin(); penunjuk!= item.end(); penunjuk++){
//        cout << *penunjuk << endl;
//    }
//    ///cout << item.size() << endl;
    return 0;
}
