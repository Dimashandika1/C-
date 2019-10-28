#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    string nama;
    vector<vector<string>>Inventory;
    vector<vector<string>>Monster{{"Parasyte"}, {"Dark Angel"}, {"Demon"}, {"Hybrid"}, {"Gauna"}};
    vector<vector<string>>Item {{"Regen HP", "30"},{"Lily leaf", "25"},{"Orchid", "40"},{"Dandelion","20"},{"Petunia", "35"}};
    vector<vector<string>>::iterator penunjuk;
    vector<string>::iterator penun;

    int maks_invent = 5;
    int cariitem=0;
    int item_rand=0;
    int item_jual=0;
    int pilihan=0;
    char jawab2='y';
    int pilihtindakan1=0;
    int maks_monster;
    int pilihkota=0;
    int jumlah_invent=0;
    maks_monster = Monster.size();
    int monster_rand = 0;
    int pilihjual = 0;
    int pilihpetualang=0;
    int pilihtindakan2=0;
    int pilihtindakan=0;
    int tidur = 0;
    int nyawa=100;
    int pilihmuseum = 0;
    int nyawa1,angka=500;


        awal:
        cout << "\t\t\t SELAMAT DATANG DI DUNIA FANTASI"<<endl;
        cout << "\t Anda telah menjadi orang yang terpilih sebagai pahlawan"<<endl;
        maks_invent = Inventory.size();
        cout << "\t\t\t\t1. Mulai game"<<endl;
        cout << "\t\t\t\t2. Exit"<<endl<<endl;
        cout << "Silahkan input pilihan : ";cin >>pilihan;
        if(pilihan==1){
            cout << "\nSilahkan masukkan nama anda : "; cin >> nama;
            cout << "\n\t\tHai "<<nama<<", saya adalah admin. Mari berjelajah bersama!!"<<endl;
            cout << "Disini anda bisa menjelajahi dunia kami"<<endl;
            menu:
                cout << "1. Pergi ke gua"<<endl;
                cout << "2. Pergi ke sungai"<<endl;
                cout << "3. Pergi ke kota"<<endl;
                cout << "Silahkan pilih : ";cin >>pilihpetualang;
                    if(pilihpetualang==1){
                        cout << "\nAnda sudah berada di gua"<<endl;
                        cout << "LIHAT!! Di depan ada monster gua"<<endl;
                        srand(unsigned(time(0)));
                        monster_rand = rand()%maks_monster;
                        srand((unsigned)time(NULL));
                        nyawa1 = rand()%angka+1;
                        cout << "Monster yang keluar adalah "<<Monster[monster_rand][0]<<" Nyawanya adalah : "<<nyawa1<<endl;
                        lari:
                        cout << "\nSilahkan pilih tindakan : "<<endl;
                        cout << "1. Serang!!"<<endl;
                        cout << "2. Bertahan!!"<<endl;
                        cout << "3. Lari!!"<<endl;
                        cin >>pilihtindakan;
                        if(pilihtindakan==1){
                                cout << "\nAnda berhasil menyerang monster"<<endl;
                                nyawa1=nyawa1-40;
                                cout << "Sisa nyawa adalah : "<<nyawa1<<endl;
                                if(nyawa1<=0){
                                        cout << "\nMonster sudah mati!" << endl;
                                        cout << "Selamat anda sudah mengalahkan monster! :)" <<endl;
                                        cout << "Pilih melanjutkan perjalanan ke.." << endl;
                                    goto menu;
                                }
                            goto lari;

                     }
                        else if(pilihtindakan==2){
                            cout << "\nTidaakkk!! Monster menyerang anda!" << endl;
                            cout << "Anda berhasil bertahan dari serangan monster!!"<<endl;
                            nyawa=nyawa-5;
                            cout << "Sisa nyawa : "<<nyawa<<endl;
                            if(nyawa<=0){
                                cout << "Nyawa anda telah habis!!" <<endl;
                                cout << "Game Over /o\\ !!" <<endl;
                                goto awal;
                            }
                            cout << " "<<endl;
                            goto lari;

                        }
                        else{
                            cout << "\nAnda berhasil melarikan diri."<<endl;
                            goto menu;
                        }

                    }
                    else if(pilihpetualang==2){
                        item_rand = Item.size();
                        cout << "\nAnda sudah berada di sungai"<<endl;
                        cout << "Anda bisa mencari item disini!"<<endl;
                        srand(unsigned(time(NULL)));
                        cariitem = (rand()%item_rand);
                        sungai:
                        cout << "Silahkan pilih tindakan : "<<endl;
                        cout << "1. Cari item"<<endl;
                        cout << "2. Pergi kerumah"<<endl;
                        cout << "3. kembali"<<endl;
                        cin >>pilihtindakan1;
                        if(pilihtindakan1==1){
                                 if(jumlah_invent>=maks_invent){
                                        cout << "Maaf Inventory anda sudah penuh"<<endl;
                                        goto sungai;
                                }
                                else {
                                        cout << "\nAnda berhasil menemukan item!!"<<endl;
                                        cout << "Item yang berhasil didapat : "<<Item[cariitem][0]<< " Status : "<<Item[cariitem][1]<<endl;
                                        Inventory.push_back(vector<string>({Item[cariitem][0]}));
                                        Inventory[jumlah_invent].push_back(Item[cariitem][1]);
                                        jumlah_invent++;
                                        goto sungai;
                                }
                        }
                        else if (pilihtindakan1==2){
                            cout << "\nAnda sudah berada di rumah anda!"<<endl;
                            cout << "Petunjuk : Jika anda beristirahat dirumah, anda bisa memulihkan nyawa anda."<<endl;
                            rumah:
                            cout << "Silahkan pilih tindakan :"<<endl;
                            cout << "1. Tidur "<<endl;
                            cout << "2. Keluar dari rumah"<<endl;
                            cin >>pilihtindakan2;
                            if(pilihtindakan2==1){
                                    if(tidur<=5){
                                        cout << "Anda sudah berisitirahat"<<endl;
                                        nyawa=nyawa+10;
                                        cout << "Nyawa anda "<<nyawa<<endl;
                                        }
                                    else {
                                        cout << "Maaf anda tidak bisa terlalu banyak beristirahat!"<<endl;
                                        goto rumah;
                                    }
                                    tidur++;
                                    goto rumah;
                            }
                            else {
                                cout << "\nAnda sudah berada di luar rumah"<<endl;
                                goto sungai;
                            }
                        }
                        else {
                            goto menu;
                        }
                    }
                    else if(pilihpetualang==3){
                        kota:
                        cout << "\nAnda sudah berada di kota"<<endl;
                        cout << "Silahkan pilih tindakan anda di kota :"<<endl;
                        cout << "1. Menambah nyawa dengan Jual item"<<endl;
                        cout << "2. Pergi ke museum"<<endl;
                        cout << "3. Kembali ke halaman utama"<<endl;
                        cin  >> pilihkota;
                        if(pilihkota==1){
                            cout << "\nAnda sudah berada di tempat penjualan item"<<endl;
                            inven:
                            cout << "Silahkan pilih :"<<endl;
                            cout << "1. Lihat Inventory"<<endl;
                            cout << "2. Jual Item"<<endl;
                            cout << "3. Kembali ke kota"<<endl;
                            cin >> pilihjual;
                            if(pilihjual==1){
                                for(penunjuk = Inventory.begin();penunjuk != Inventory.end();penunjuk++){
                                    for(penun = penunjuk->begin();penun != penunjuk->end();penun++){
                                        cout << *penun << " ";
                                        }
                                    cout <<endl;
                                }
                                goto inven;
                            }
                            else if(pilihjual==2){
                                if(jumlah_invent <=0){
                                    cout << "Maaf, anda tidak punya item "<<endl;
                                    }
                                else {
                                    tengah:
                                        cout << "Item yang akan dijual item ke :";cin >>item_jual;
                                            if(item_jual>jumlah_invent){
                                                cout << "Maaf Item tidak ada"<<endl;
                                                goto tengah;
                                            }
                                            else {
                                                Inventory.erase(Inventory.begin() + (item_jual-1));
                                                jumlah_invent--;
                                                nyawa = nyawa + 30;
                                                cout << "Item berhasil Dijual"<<endl;
                                                cout << "Nyawa anda adalah : "<<nyawa<<endl;
                                                cout << "Jumlah Inventory sekarang : " <<jumlah_invent<<endl;
                                            }
                                }
                                goto inven;
                            }
                            else {
                                goto kota;
                            }
                        }
                        else if(pilihkota==2){
                            museum:
                            cout << "\nAnda sudah berada di museum."<<endl;
                            cout << "Silahkan pilih tindakan :"<<endl;
                            cout << "1. Melihat sejarah dunia"<<endl;
                            cout << "2. Kembali ke kota"<<endl;
                            cin >> pilihmuseum;
                            if(pilihmuseum==1){
                                    while(jawab2=='y' ||jawab2=='Y'){
                                        cout << "\nStory Telling.." << endl;
                                        cout << "Dahulu kala.. Terdapat kota yang di padati oleh banyak penduduk dan di pimpin oleh seorang raja yang adil.. " << endl;
                                        system("pause");
                                        cout << "\nAwalnya kehidupan di kota ini berjalan normal, para penduduk hidup sejahtera dari sektor pertanian dan perekonomiannya .." << endl;
                                        system("pause");
                                        cout << "\nsebelum akhirnya datang para monster yang mengerikan menghancurkan kota ini dan ingin menguasai seluruh dunia isekai ini..." <<endl;
                                        system("pause");
                                        cout << "\nSaat itu dunia isekai penuh dengan kehancuran yang di sebabkan oleh para monster laknat tersebut.." << endl;
                                        system("pause");
                                        cout << "\nPara penduduk hidup dengan ketakutan yang mendalam, sambil berusaha bertahan hidup dengan cara melawan para monster.." << endl;
                                        system("pause");
                                        cout << "\nnamun setelah sekian lama penduduk mengalami penderitaan, datanglah sekelompok pahlawan berusaha menghabisi para monster laknat!.." << endl;
                                        system("pause");
                                        cout << "\nPara penduduk pun seakan mendapat udara segar akan kehidupan yg telah lama di renggut monster yang datang dari dunia lain tersebut.." << endl;
                                        system("pause");
                                        cout << "\nSetelah pertempuran sekian lama.. akhirnya para pahlawan dan penduduk pun meraih kemenangan, monster pun lenyap tak tersisa.." << endl;
                                        system("pause");
                                        cout << "\nDan akhirnya para penduduk pun dapat hidup dengan tenang dan mulai membangun kembali kehidupan yg telah di renggut oleh para monster..."<<endl;
                                        system("pause");
                                        cout << "\nNamun kini, seolah tak mau menerima kekalahan nya, para monster pun berusaha kembali untuk menguasai dunia isekai yg dulu pernah di kuasai nya.."<<endl;
                                        system("pause");
                                        cout << "\nKini sudah menjadi tugas anda sebagai pahlawan untuk menghentikan rencana dari para monster untuk menguasai kembali dunia isekai yang damai ini..."<<endl;
                                        system("pause");
                                    cout << "Ingin membaca lagi ? (y/n)";cin >>jawab2;
                                    }
                                    goto museum;
                            }
                            else {
                                goto kota;
                        }
                    }
                        else {
                            goto awal;
                        }
                    }

    }
            else {

            }
    return 0;
}
