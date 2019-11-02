#include <iostream>
#include <string>
using namespace std;

int main()
{
    string item = "";
    string item_sblm = "";
    string item_trhbt = "";
    string item_trlmh = "";
    float stat = 0;
    float stat_sblm = 0;
    float stat_trhbt = 0;
    float stat_trlmh = 0;
    char ulang = 'y';
    bool first = true;

    while(ulang=='y'){
        cout << "\nMasukkan item anda : "; cin >> item;
        cout << "Masukkan Status : "; cin >> stat;
        cout << "Item anda adalah = " << item << endl;
        cout << "Status item = " << stat << endl;

        if(first==true){
            item_sblm ="Tidak ada";
            item_trhbt= item;
            item_trlmh = item;
            stat_trhbt = stat;
            stat_trlmh = stat;
        }else{
            if(stat>=stat_trhbt){
                stat_trhbt = stat;
                item_trhbt = item;
            }else{
                if(stat<=stat_trlmh){
                    stat_trlmh = stat;
                    item_trlmh = item;
                }
            }

        }

        cout << "Item Sebelumnya = " << item_sblm ;
        cout << "\nItem Terhebat = " << item_trhbt ;
        cout << "\nItem Terlemah = " << item_trlmh ;
        item_sblm = item;
        stat_sblm = stat;
        first = false;
        cout << "" << endl;
        cout << "\nIngin Input ulang ? (y/n)"; cin >> ulang;
    }
    return 0;
}
