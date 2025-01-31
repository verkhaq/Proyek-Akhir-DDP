#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Pelanggan {
    string nama;
    string id;
    int lamaSewa; 
};


struct Unit {
    string namaUnit;
    int stok;
    double hargaPerJam;
};


Unit daftarHarga[5] = {
    {"PS 5", 3, 13000.0},
    {"PS 4", 5, 10000.0},
    {"PS 3", 6, 5000.0},
    {"Nintendo", 2, 6000.0},
    {"Netflix", 4, 4000.0}
};


void tampilkanDaftarHarga() {
    cout << "Daftar Harga Tersedia:"<<endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << daftarHarga[i].namaUnit 
             << " (Stok: " << daftarHarga[i].stok << ") - Rp "
             << daftarHarga[i].hargaPerJam << "/jam"<<endl;
    }
}
//gilang rozan

void sewaGame() {
    Pelanggan pelanggan;

    
    cout << "Masukkan nama pelanggan: ";
    cin.ignore();
    getline(cin, pelanggan.nama);
    cout << "Masukkan ID pelanggan: ";
    cin >> pelanggan.id;
    

    
    tampilkanDaftarHarga();

    
    int pilihanUnit;
    cout << "Pilih nomor unit yang ingin disewa: ";
    cin >> pilihanUnit;

    if (pilihanUnit < 1 || pilihanUnit > 5) {
        cout << "Pilihan tidak valid!"<<endl;
        return;
    }

	cout << "Masukkan lama sewa (jam): ";
    cin >> pelanggan.lamaSewa;
    
    Unit& unitDipilih = daftarHarga[pilihanUnit - 1];

    
    if (unitDipilih.stok <= 0) {
        cout << "Maaf, stok game \"" << unitDipilih.namaUnit << "\" habis."<<endl;
        return;
    }

    
    double totalBiaya = unitDipilih.hargaPerJam * pelanggan.lamaSewa;

    
    cout << "\nDetail Penyewaan:"<<endl;
    cout << "Nama Pelanggan: " << pelanggan.nama <<endl;
    cout << "Rental Dipilih: " << unitDipilih.namaUnit <<endl;
    cout << "Lama Sewa: " << pelanggan.lamaSewa << " jam"<<endl;
    cout << "Total Biaya: Rp " << totalBiaya <<endl;

    
    unitDipilih.stok--;

    double uangDibayar;
    cout << "Masukkan uang yang dibayar: Rp ";
    cin >> uangDibayar;

    if (uangDibayar >= totalBiaya) {
        double kembalian = uangDibayar - totalBiaya;
        cout << "Kembalian: Rp " << kembalian <<endl;
        unitDipilih.stok--;
    } else {
        cout << "Uang tidak cukup."<<endl;
    }
    
    
    
    
    ofstream file("data_pelanggan.txt", ios::app);
    if (file) {
        file << pelanggan.nama << " | " << pelanggan.id << " | "
             << unitDipilih.namaUnit << " | " << pelanggan.lamaSewa
             << " jam | Rp " << totalBiaya <<endl;
        file.close();
        cout << "Data pelanggan berhasil disimpan."<<endl;
    } else {
        cout << "Gagal menyimpan data pelanggan."<<endl;
    }

    cout << "Transaksi berhasil! Terima kasih telah menyewa."<<endl;
}
//reza rizki f

int main() {
    int pilihan;

    do {
        cout << "\n=== Sigma Gaming ==="<<endl;
        cout << "1. Tampilkan Daftar Harga"<<endl;
        cout << "2. Booking"<<endl;
        cout << "3. Keluar"<<endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanDaftarHarga();
                break;
            case 2:
                sewaGame();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan layanan kami."<<endl;
                break;
            default:
                cout << "Pilihan tidak valid!"<<endl;
        }
    } while (pilihan != 3); //fahry m.walit

    return 0;
}
