#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Struct untuk menyimpan data film
struct Film {
    char nama[20];
    int harga;
};

// Struct untuk node pada linked list
struct Node {
    Film film;
    int jumlah;
    Node* next;
};

// Fungsi untuk menghitung total harga dengan diskon
int hitungTotal(int harga, int jumlah) {
    if (jumlah >= 5) {
        return 0.6 * harga * jumlah; // Diskon 40%
    } else {
        return harga * jumlah;
    }
}

int main() {
    // Array film
    Film filmList[3] = {
        {"Ghostbuster", 35000},
        {"Oppenheimer", 45000},
        {"Ferrari", 60000}
    };

    char back;
    Node* head = nullptr; // Head dari linked list

    do {
        system("CLS");
        cout << "====================Cinema 24==================" << endl;
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Lihat Daftar Film" << endl;
        cout << "2. Pesan Tiket" << endl;
        cout << "3. Keluar" << endl;
        cout << "-----------------------------------------------" << endl;

        int choice;
        cout << "Pilih Menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                cout << "====================Cinema 24==================" << endl;
                cout << endl;
                cout << "Film yang Tersedia---" << endl;
                cout << "-----------------------------------------------" << endl;
                for (int i = 0; i < 3; ++i) {
                    cout << i+1 << ". " << filmList[i].nama << " = Rp " << filmList[i].harga << endl;
                }
                cout << "-----------------------------------------------" << endl;
                break;
            case 2:
                {
                system("CLS");
                cout << "====================Cinema 24==================" << endl;
                cout << endl;
                cout << "Film yang Tersedia---" << endl;
                cout << "-----------------------------------------------" << endl;
                for (int i = 0; i < 3; ++i) {
                    cout << i+1 << ". " << filmList[i].nama << " = Rp " << filmList[i].harga << endl;
                }
                cout << "-----------------------------------------------" << endl;

                cout << "(Masukan Film Berdasarkan Nomor)" << endl;
                cout << "Silahkan Pilih Film Anda: ";

                int filmIndex;
                cin >> filmIndex;
                filmIndex--; // Mengubah dari nomor film ke indeks array

                if (filmIndex < 0 || filmIndex >= 3) {
                    cout << "Pilihan Anda Tidak Ada !!" << endl;
                    continue;
                }

                cout << "Anda Memilih " << filmList[filmIndex].nama << endl;
                cout << endl;
                cout << "Jumlah Tiket yang Dibeli: ";

                int jumlah;
                cin >> jumlah;

                int total = hitungTotal(filmList[filmIndex].harga, jumlah);
                cout << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "====================Cinema 24==================" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "Film             : " << filmList[filmIndex].nama << endl;
                cout << "Jumlah Tiket     : " << jumlah << endl;
                cout << "Harga Tiket      : " << filmList[filmIndex].harga << " * " << jumlah << endl;
                cout << "Total Pembayaran : " << total << endl;

                // Membuat node baru
                Node* newNode = new Node;
                strcpy(newNode->film.nama, filmList[filmIndex].nama);
                newNode->film.harga = filmList[filmIndex].harga;
                newNode->jumlah = jumlah;
                newNode->next = nullptr;

                // Menambahkan node baru ke linked list
                if (head == nullptr) {
                    head = newNode;
                } else {
                    Node* temp = head;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
                }
                break;
            case 3:
                back = 'N';
                break;
            default:
                cout << "Pilihan Menu Tidak Valid!" << endl;
        }

        if (choice != 3) {
            cout << endl;
            cout << "Apakah Anda Mau Kembali ke Menu Utama? [Y/N]";
            cin >> back;
        }

    } while (back == 'Y' || back == 'y');

    // Menampilkan seluruh transaksi dari linked list
    cout << "Transaksi:" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->film.nama << " - " << temp->jumlah << " tiket" << endl;
        temp = temp->next;
    }

    // Menghapus semua node pada linked list untuk mencegah kebocoran memori
    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    cout << endl;
    cout << "Terima Kasih Telah Menggunakan Cinema 24" << endl;
    cout << "Selamat Menonton" << endl;

    return 0;
}
