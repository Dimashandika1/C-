#include <iostream>
#include <string>
#include <vector>

using namespace std;

///Begin class pet
class Pet{
public:
    static int s_JumlahPet;
    ///Konstruktor
    Pet(string nama, int kenyang, int senang);

    ///Method/fungsi
    void virtual bicara();
    void makan(int makanan);
    void main(int fun, int lapar);
    string getNama() const;
protected:
    ///atribut
    string m_Nama;
    int m_Kenyang, m_Senang;
};

int Pet::s_JumlahPet=0;

///Definisi constructor
Pet::Pet(string nama, int kenyang, int senang):/*nama->isi m_Nama*/m_Nama(nama), m_Kenyang(kenyang), m_Senang(senang){
    s_JumlahPet++;
    cout << "\nNew pet!!" << endl;
    cout << "Nama : " << m_Nama << endl;
    cout << "Tingkat kenyang : " << m_Kenyang << endl;
    cout << "Tingkat senang : " << m_Senang <<endl;
}

///Definisi Fungsi/Method
void Pet::bicara(){
    cout << "\nHalo!!, aku adalah : " << m_Nama << endl;
    cout << "Tingkat kenyang : " << m_Kenyang << endl;
    cout << "Tingkat senang : " << m_Senang << endl;
}
void Pet::makan(int makanan){
    cout << "\nNyammm!!" << endl;
    m_Kenyang=m_Kenyang+makanan;
    cout << "Tingkat kekenyangan : " << m_Kenyang << endl;
    if(m_Kenyang>10){
        cout << "Saya sudah kenyang!!" << endl;
        m_Senang=m_Senang-10;
        cout << "Tingkat kesenangan" << m_Senang << endl;
    }
}

///End class pet
void Pet::main(int fun, int lapar){
    cout << "\nHoreyy!!" << endl;
    m_Senang=m_Senang+fun;
    cout << "Tingkat senang : " << m_Senang << endl;
    m_Kenyang=m_Kenyang-lapar;
    cout << "Tingkat kenyang : " << m_Kenyang << endl;
    if(m_Kenyang<2){
        cout << "Saya lapar! Stop bermain dan beri aku makanan!!" << endl;
    }
}
    string Pet::getNama() const{
        return m_Nama;
    }
///Begin class farm
class Farm {
public:
    Farm(int kapasitas);//Construktor
    void tambah(const Pet& pet);
    void penghuniFarm() const;
private:
    vector<Pet>m_Pet;
};

Farm::Farm(int kapasitas){
    m_Pet.reserve(kapasitas);
}

void Farm::tambah(const Pet& pet){
    m_Pet.push_back(pet);
}

void Farm::penghuniFarm() const {
    if(m_Pet.empty()){
        cout << "Farm masih kosong gan!!" << endl;
    }else{
        cout << "\nDaftar pet : " << endl;
        vector<Pet>::const_iterator nav;
        for(nav=m_Pet.begin();nav!=m_Pet.end();nav++){
            cout << "Nama Pet : " << nav->getNama() << endl;
        }
    }
}
///Begin class dragon
class Dragon:public Pet{
public:
    Dragon(string nama, int kenyang, int senang, int skillPoint);
    void virtual bicara();
private:
    int m_skillPoint;

};

Dragon::Dragon(string nama, int kenyang, int senang, int skillPoint):Pet(nama,kenyang,senang),m_skillPoint(skillPoint){
    cout << "\nNew Dragon !!" << endl;
}

void Dragon::bicara(){
    cout << "\nAku adalah dragon bernama : " << m_Nama<< endl;
    cout << "Tingkat kenyang : " << m_Kenyang << endl;
    cout << "Tingkat senang : " << m_Senang << endl;
    cout << "Skill point : " << m_skillPoint << endl;
}
int main()
{
    int pilih=1, pilihmakan=1, pilihmain=1;
    Pet pet1("Kocheng", 0, 0);
    Pet pet2("Oyen", 0, 0);
    Pet pet3("bar bar", 0, 0);
    Dragon dragon1("Cxuaxzk",0,0,10);
    Farm farm1(5);
    cout << "Jumlah pet : " << Pet::s_JumlahPet << endl;
    farm1.tambah(pet2);
    farm1.tambah(pet1);
    farm1.penghuniFarm();
    pet1.bicara();
    pet2.makan(2);
    pet3.bicara();

//        pets.main(2);
//        pets.bicara();
//    while (pilih!=0){
//        menu:
//        cout << "\nSilahkan pilih tindakan" << endl;
//        cout << "1. Bicara" << endl;
//        cout << "2. Beri makanan" << endl;
//        cout << "3. Bermain" << endl;
//        cout << "4. Keluar" << endl;
//        cout << "Jumlah pet : " << Pet::s_JumlahPet << endl;
//        cout << "Masukkan pilihan anda.. : ";cin >> pilih;
//
//        if(pilih==1){
//           pets.bicara();
//        }else if(pilih==2){
//            makan:
//            cout << "\nSilahkan pilih makanan yang di berikan.." << endl;
//            cout << "1. Buah (0)" << endl;
//            cout << "2. Daging (5)" << endl;
//            cout << "3. Makanan kaleng (3)" << endl;
//            cout << "4. Kembali ke menu.." << endl;
//            cout << "Silahkan masukkan pilihan anda.. : ";cin >> pilihmakan;
//
//            if(pilihmakan==1){
//                pets.makan(0);
//                goto makan;
//            }else if(pilihmakan==2){
//                pets.makan(5);
//                goto makan;
//            }else if(pilihmakan==3){
//                pets.makan(3);
//                goto makan;
//            }else if(pilihmakan==4){
//                goto menu;
//            }else{
//                cout << "\nInputan anda salah!!" << endl;
//                goto makan;
//            }
//        }else if(pilih==3){
//            main:
//            cout << "\nSilahkan pilih permainan.." << endl;
//            cout << "1. Bermain bola (+5), kenyang(-3)" << endl;
//            cout << "2. Lempar tangkap (+4), kenyang(-2)" << endl;
//            cout << "3. Lari-lari (+3), kenyang(-2)" << endl;
//            cout << "4. kembali ke menu.." << endl;
//            cout << "Silahkan masukkan pilihan anda.. : ";cin >> pilihmain;
//
//            if(pilihmain==1){
//                pets.main(5,3);
//                goto main;
//            }else if(pilihmain==2){
//                pets.main(4,2);
//                goto main;
//            }else if(pilihmain==3){
//                pets.main(3,2);
//                goto main;
//            }else if(pilihmain==4){
//                goto menu;
//            }else{
//                cout << "\nInputan anda salah!!" << endl;
//                goto main;
//            }
//        }else{
//            break;
//        }
//
//    }

    return 0;
}
