#include <iostream>

using namespace std;

int main (){
    string Nama = "Rava Mahdi Mahdaveka" ;
    string Nim = "2309106036";
    int pilih;
    double jumlah ;
    string nama , nim ;

    int salah = 0 ;
    
    while (salah <3){
        cout << "masukkan nama :";getline (cin, nama ) ; 
        cout << "masukkan nim :" ;getline (cin, nim) ;

        if (nama==Nama && nim == Nim ){
            cout << "anda berhasil login\n";
            break;

        }else {
            cout << "login gagal\n";
            salah++;
        }
        if (salah==3){
            cout <<"anda telah salah sebanyak 3 kali , silahkan coba lain kali\n";
            return 0 ;
        }

    }
    while (true){
        cout << "silahkan pilih menu yang tersedia\n";
        cout << "1. Rupiah ke (Dollar, Euro, Yen)"<< endl;
        cout << "2. Dollar ke (Rupiah, Euro, Yen)"<< endl;
        cout << "3. Euro ke (Rupiah, Dollar, Yen)"<< endl;
        cout << "4. Yen ke (Rupiah, Dollar, Euro)"<< endl;
        cout << "5. keluar" << endl;
        cout << "masukkan nomor pilihan anda :";cin >> pilih ;
        if (pilih==5){
            cout << "\nanda telah keluar dari perogram";
            break;
        }else if ( pilih > 0 && pilih < 6 ){
        cout << "masukkan jumlah yang ingin di konversi : "; cin >> jumlah;
        }else {
            cout << "pilihan tidak tersedia , silahkan pilih lagi \n" ;
            continue;
        }
        

        switch (pilih){
            case 1:
                cout << "==================\n" ;
                cout << jumlah << " rupiah ke\n";
                cout << "Dollar : " << (jumlah * 0.000064 )<< endl;
                cout << "Euro   : " << (jumlah*0.00006 )<< endl;
                cout << "Yen    : " << (jumlah*0.0096)<< endl;
                cout << "==================\n" ;
                break;
            case 2:
                cout << "==================\n" ;
                cout << jumlah << " dollar ke\n";
                cout << "Rupiah : "<< (jumlah*15701.95) << endl;
                cout << "Euro   : "<< (jumlah*0.92) << endl;
                cout << "Yen    : " << (jumlah*150.10) << endl;
                cout << "==================\n" ;
                break;
            case 3:
                cout << "==================\n" ;
                cout << jumlah << " euro ke\n";
                cout << "Rupiah : " << (jumlah*17043.68)<< endl;
                cout << "Dollar : " << (jumlah*1.09) << endl;
                cout << "Yen    : " <<(jumlah*162.93) << endl;
                cout << "==================\n" ;
                break;
            case 4:
                cout << "==================\n" ;
                cout << jumlah << " yen ke\n";
                cout << "Rupiah : "<<(jumlah*104.61)<< endl;
                cout << "Dollar : "<<(jumlah*0.0067)<< endl;
                cout << "Euro   : " << (jumlah*0,0061 )<<endl;
                cout << "==================\n" ;
                break;
            default :
                cout << "masukkan angka\n";
                break;

        }
    }
    return 0 ;
}