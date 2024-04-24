#include <iostream>
#include <string>
#include <limits>

#define CLEAR "cls"

using namespace std;

struct Helikopter {
    struct JenisHelikopter {
        string kecil = "Kecil";
        string sedang = "Sedang";
        string besar = "Besar";
    } jenisHelikopter;

    string nama;
    string jenis;
    int lama_sewa_hari;
};
const int maksimal_pesanan = 10;
int jumlah_pesanan = 0;
Helikopter helikopter[maksimal_pesanan];

bool login() {
    string username, password;
    int maksimal_salah = 0;

    while (maksimal_salah < 3) {
        cout << "=============================================================\n";
        cout << "Selamat datang di program rental helikopter\n";
        cout << "Silahkan masukkan nama admin: ";
        getline(cin, username);

        cout << "Silahkan masukkan kata sandi: ";
        getline(cin, password);

        if (username == "Rava Mahdi Mahdaveka" && password == "2309106036") {
            cout << "Login berhasil!\n";
            return true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Login gagal \n" ;
            maksimal_salah++;
        }
    }

    cout << "Kesempatan Anda habis, silahkan coba lain kali\n" ;
    return false;
}
void insertionSort(Helikopter arr[], int n) {
    int i, j;
    Helikopter key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].lama_sewa_hari > key.lama_sewa_hari) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSortDescending(Helikopter arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nama < arr[j + 1].nama) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSortAscending(int arr[], int n) {
    int minIndex;
    for (int i = 0; i < n-1; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int binarySearchAscending(Helikopter arr[], int n, string target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].nama == target)
            return mid;
        else if (arr[mid].nama < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}

int interpolationSearchDescending(Helikopter arr[], int n, string target) {
    int low = 0, high = n - 1;
    while (low <= high && target <= arr[low].nama && target >= arr[high].nama) {
        int pos = low + ((double)(high - low) / (arr[low].nama.compare(arr[high].nama))) * (arr[low].nama.compare(target));

        if (arr[pos].nama == target)
            return pos;
        else if (arr[pos].nama.compare(target) < 0)
            high = pos - 1;
        else
            low = pos + 1;
    }
    return -1;
}

void tambahPesanan(Helikopter *pesanan) {
    if (jumlah_pesanan < maksimal_pesanan) {
        cout << "Masukkan data perental helikopter:" << endl;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, pesanan[jumlah_pesanan].nama);

        Helikopter::JenisHelikopter jenis;
        cout << "Silahkan pilih jenis helikopter (1: Kecil, 2: Sedang, 3: Besar): ";
        int pilihan_jenis;
        while (true) {
            if (cin >> pilihan_jenis && pilihan_jenis >= 1 && pilihan_jenis <= 3) {
                cin.ignore();
                break;
            } else {
                cout << "Pilihan jenis helikopter tidak valid.\n Silahkan pilih jenis helikopter (1: Kecil, 2: Sedang, 3: Besar):" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (pilihan_jenis) {
            case 1:
                pesanan[jumlah_pesanan].jenis = jenis.kecil;
                break;
            case 2:
                pesanan[jumlah_pesanan].jenis = jenis.sedang;
                break;
            case 3:
                pesanan[jumlah_pesanan].jenis = jenis.besar;
                break;
        }

        cout << "Lama sewa (dalam hari): ";
        while (!(cin >> pesanan[jumlah_pesanan].lama_sewa_hari)) {
            cout << "Input tidak valid. Masukkan lama sewa (dalam hari): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        jumlah_pesanan++;
        cout << "Data pesanan berhasil ditambahkan." << endl;
    } else {
        cout << "Kapasitas pesanan penuh. Tidak dapat menambahkan data." << endl;
    }
}


void ubahPesanan(Helikopter *pesanan) {
    if (jumlah_pesanan > 0) {
        cout << "\nData Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "\nHelikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << pesanan[i].nama << endl;
            cout << "Jenis: " << pesanan[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << pesanan[i].lama_sewa_hari << endl;
        }
        int index;
        cout << "Masukkan indeks helikopter yang akan diubah (1-" << jumlah_pesanan << "): ";
        while (!(cin >> index) || index < 1 || index > jumlah_pesanan) {
            cout << "Indeks tidak valid. Masukkan indeks helikopter yang akan diubah (1-" << jumlah_pesanan << "): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Helikopter::JenisHelikopter jenis;
        cout << "\nMasukkan data pesanan yang baru" << endl;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, pesanan[index - 1].nama);

        cout << "Silahkan pilih jenis helikopter (1: Kecil, 2: Sedang, 3: Besar): ";
        int pilihan_jenis;
        while (true) {
            if (cin >> pilihan_jenis && pilihan_jenis >= 1 && pilihan_jenis <= 3) {
                cin.ignore();
                break;
            } else {
                cout << "Pilihan jenis helikopter tidak valid. Silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (pilihan_jenis) {
            case 1:
                pesanan[index - 1].jenis = jenis.kecil;
                break;
            case 2:
                pesanan[index - 1].jenis = jenis.sedang;
                break;
            case 3:
                pesanan[index - 1].jenis = jenis.besar;
                break;
        }

        cout << "Lama sewa (dalam hari): ";
        while (!(cin >> pesanan[index - 1].lama_sewa_hari)) {
            cout << "Input tidak valid. Masukkan lama sewa (dalam hari): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Data pesanan berhasil diubah." << endl;
    } else {
        cout << "Tidak ada data pesanan untuk diubah." << endl;
    }
}

void hapusPesanan(Helikopter *pesanan) {
    if (jumlah_pesanan > 0) {
        cout << "\nData Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "\nHelikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << pesanan[i].nama << endl;
            cout << "Jenis: " << pesanan[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << pesanan[i].lama_sewa_hari << endl;
        }
        int index;
        cout << "Masukkan indeks pesanan yang akan dihapus (1-" << jumlah_pesanan << "): ";
        while (!(cin >> index) || index < 1 || index > jumlah_pesanan) {
            cout <<"Indeks tidak valid. Masukkan indeks pesanan yang akan dihapus (1-" << jumlah_pesanan << "): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = index - 1; i < jumlah_pesanan - 1; i++) {
            pesanan[i] = pesanan[i + 1];
        }

        jumlah_pesanan--;
        cout << "Data pesanan berhasil dihapus." << endl;
    } else {
        cout << "Tidak ada data pesanan untuk dihapus." << endl;
    }
}


void tampilkanData(Helikopter *pesanan) {
    if (jumlah_pesanan > 0) {
        cout << "\nData Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "\nHelikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << pesanan[i].nama << endl;
            cout << "Jenis: " << pesanan[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << pesanan[i].lama_sewa_hari << endl;
        }
    } else {
        cout << "Tidak ada data pesanan untuk ditampilkan." << endl;
    }
}

void tampilkanMenu() {
    cout << "\n===================================\n";
    cout << "Silahkan pilih menu yang tersedia" << endl;
    cout << "1. Tambah pesanan" << endl;
    cout << "2. Ubah pesanan" << endl;
    cout << "3. Hapus pesanan" << endl;
    cout << "4. Tampilkan Data pesanan" << endl;
    cout << "5. Mencari data" << endl;
    cout << "6. Keluar" << endl;
}

void mainMenu() {
    int pilihan;

    do {
        tampilkanMenu();
        cout << "Masukkan pilihan (1-5): ";
        while (!(cin >> pilihan) || pilihan < 1 || pilihan > 5) {
            cout << "Pilihan tidak valid. Masukkan pilihan (1-5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "=========================\n";
        switch (pilihan) {
            case 1:
                system(CLEAR); 
                tambahPesanan(helikopter);
                break;
            case 2:
                system(CLEAR); 
                ubahPesanan(helikopter);
                break;
            case 3:
                system(CLEAR); 
                hapusPesanan(helikopter);
                break;
            case 4: {
                int urutan_tampilan;
                cout << "Pilih urutan tampilan data (1: Nama Descending, 2: Hari Ascending): ";
                while (!(cin >> urutan_tampilan) || urutan_tampilan < 1 || urutan_tampilan > 2) {
                    cout << "Pilihan tidak valid. Pilih urutan tampilan data (1: berdasarkan huruf nama dari akhir , 2: lama sewa paling sebentar ): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (urutan_tampilan == 1) {
                    bubbleSortDescending(helikopter, jumlah_pesanan);
                } else {
                    insertionSort(helikopter, jumlah_pesanan);
                }
                tampilkanData(helikopter);
                break;
            }
            case 5: {
                int urutan_pencarian;
                cout << "Pilih urutan pencarian (1: Ascending, 2: Descending): ";
                while (!(cin >> urutan_pencarian) || urutan_pencarian < 1 || urutan_pencarian > 2) {
                    cout << "Pilihan tidak valid. Pilih urutan pencarian (1: Ascending, 2: Descending): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                string target;
                cout << "Masukkan nama yang ingin dicari: ";
                cin >> target;

                if (urutan_pencarian == 1) {
                    // Pencarian secara ascending
                    insertionSort(helikopter, jumlah_pesanan);
                    int index = binarySearchAscending(helikopter, jumlah_pesanan, target);
                    if (index != -1) {
                        cout << "Data ditemukan pada indeks " << index + 1 << endl;
                    } else {
                        cout << "Data tidak ditemukan" << endl;
                    }
                } else {
                    // Pencarian secara descending
                    bubbleSortDescending(helikopter, jumlah_pesanan);
                    int index = interpolationSearchDescending(helikopter, jumlah_pesanan, target);
                    if (index != -1) {
                        cout << "Data ditemukan pada indeks " << index << endl;
                    } else {
                        cout << "Data tidak ditemukan" << endl;
                    }
                }
                break; // Kembalikan ke menu utama setelah selesai pencarian
            }

case 6:
    cout << "Program telah selesai, terima kasih." << endl;
    break;

            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (pilihan != 6);
}

int main() {
    if (!login()) {
        return 0;  
    }

    mainMenu();

    return 0;
}