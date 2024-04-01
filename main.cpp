#include <iostream>
using namespace std;

void menu();
void inputData();
void tampilData();
void editData();
void hapusData();
void clearCMD();

int simpananData; //untuk simpan data mahasiswa
int jmlData = 0; //untuk jumlah data

struct mahasiswa{
    string nama;
    string npm;
    float nilaiAbsen;
    float nilaiTugas;
    float UTS;
    float UAS;
    float nilaiAkhir;
    string nilaiHuruf;
};

mahasiswa mhs[100];

int main(){
    do{
        menu();
    }while(true);
    return 0;
}

//fungsi menu
void menu(){
    clearCMD();
    int pilihan;
    cout << "============================\n";
    cout << "||           MENU         ||\n";
    cout << "============================\n";
    cout << "[1] Input Data Mahasiswa \n";
    cout << "[2] Tampil Data Mahasiswa \n";
    cout << "[3] Edit Data Mahasiswa \n";
    cout << "[4] Hapus Data Mahasiswa \n";
    cout << "\nPilihan: ";
    cin >> pilihan;

    switch (pilihan){
    case 1:
        inputData();
        break;
    case 2:
        tampilData();
        break;
    case 3:
        editData();
        break;
    case 4:
        hapusData();
        exit(0);
        break;
    }
}

//input data
void inputData(){
    clearCMD();
    cout << "==================================\n";
    cout << "||          Input Data          ||\n";
    cout << "==================================\n";
    cout << "Jumlah data yang akan di input: ";
    cin >> simpananData;

    if (jmlData + simpananData > 100){
        cout << "Jumlah data telah melebihi batas maksimal" << endl;
        menu();
    }

    for (int i = 0; i < simpananData; i++){
        cout << "Data ke-" << i + 1 << endl;
        cout << "NPM\t\t: ";
        cin >> mhs[jmlData + i].npm;
        cout << "Nama\t\t: ";
        cin >> mhs[jmlData + i].nama;
        cout << "Nilai Absen\t: ";
        cin >> mhs[jmlData + i].nilaiAbsen;
        cout << "Nilai Tugas\t: ";
        cin >> mhs[jmlData + i].nilaiTugas;
        cout << "Nilai UTS\t: ";
        cin >> mhs[jmlData + i].UTS;
        cout << "Nilai UAS\t: ";
        cin >> mhs[jmlData + i].UAS;
        cout << endl;
    }

    jmlData += simpananData; //untuk nambah data

    cout << "Data telah berhasil di input!\nTekan [ENTER] untuk kembali ke menu" << endl;
    cin.ignore();
    cin.get();
    menu();
}

void clearCMD(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif // _WIN32
}

//tampilan data
void tampilData(){
    clearCMD();

    cout << "===================================\n";
    cout << "||          Tampil Data          ||\n";
    cout << "===================================\n";

    for (int i = 0; i < jmlData; i++){
        cout << "Data ke-" << i + 1 << endl;
        cout << "NPM\t\t: " << mhs[i].npm << endl;
        cout << "Nama\t\t: " << mhs[i].nama << endl;
        cout << "Nilai Absen\t: " << mhs[i].nilaiAbsen << endl;
        cout << "Nilai Tugas\t: " << mhs[i].nilaiTugas << endl;
        cout << "Nilai UTS\t: " << mhs[i].UTS << endl;
        cout << "Nilai UAS\t: " << mhs[i].UAS << endl;

        mhs[i].nilaiAkhir = 0.1 * mhs[i].nilaiAbsen + 0.2 * mhs[i].nilaiTugas + 0.3 * mhs[i].UTS + 0.4 * mhs[i].UAS;
        cout << "Nilai Akhir\t: " << mhs[i].nilaiAkhir << endl;

        if (mhs[i].nilaiAkhir > 80){
            mhs[i].nilaiHuruf = "A";
        }else if (mhs[i].nilaiAkhir > 70){
            mhs[i].nilaiHuruf = "B";
        }else if (mhs[i].nilaiAkhir > 60){
            mhs[i].nilaiHuruf = "C";
        }else {
            mhs[i].nilaiHuruf = "D";
        }

        cout << "Nilai Akhir (dalam huruf)\t: " << mhs[i].nilaiHuruf << endl;
        cout << endl;
    }

    int pilihan;
    cout << "Pilihan Menu: " << endl;
    cout << "[1] Kembali ke menu awal" << endl;
    cout << "[2] Keluar dari program" << endl;
    cin >> pilihan;

    if (pilihan == 1){
        menu();
    }else if (pilihan == 2){
        exit(0);
    }else {
        cout << "Pilihan anda tidak valid. Kembali ke menu dengan otomatis" << endl;
        menu();
    }
}

void editData(){
    clearCMD();
    string NPMData;
    bool ketemu = false;
    cout << "=================================\n";
    cout << "||          Edit Data          ||\n";
    cout << "=================================\n";

    cout << "Masukkan NPM dari data yang ingin di edit: ";
    cin >> NPMData;

    for (int i = 0; i <jmlData; i++){
        if (mhs[i].npm == NPMData){
            ketemu = true;
            cout << "Data ditemukan!\n" << endl;
            cout << "Masukkan data baru: "<< endl;
            cout << "NPM\t\t: ";
            cin >> mhs[i].npm;
            cout << "Nama\t\t: ";
            cin >> mhs[i].nama;
            cout << "Nilai Absen\t: ";
            cin >> mhs[i].nilaiAbsen;
            cout << "Nilai Tugas\t: ";
            cin >> mhs[i].nilaiTugas;
            cout << "Nilai  UTS\t: ";
            cin >> mhs[i].UTS;
            cout << "Nilai UAS\t: ";
            cin >> mhs[i].UAS;
            cout << endl;

            cout << "Data berhasil diubah!" << endl;
            break;
        }
    }

    if (!ketemu){
        cout << "Data tidak ditemukan, tekan [ENTER] untuk kembali ke menu" << endl;

        cin.ignore();
        cin.get();
        menu();
    }else {
        cout << "Tekan [ENTER] untuk kembali ke menu...." << endl;
        cin.ignore();
        cin.get();
        menu();
    }
}

//fungsi untuk menhapus data
void hapusData(){
    clearCMD();
    string NPMData;
    char konfirmHapus;
    bool ketemu = false;
    cout << "==================================\n";
    cout << "||          Hapus Data          ||\n";
    cout << "==================================\n";

    cout << "Masukkan NPM dari data yang ingin di hapus: ";
    cin >> NPMData;

    for (int i = 0; i < jmlData; i++){
        if (mhs[i].npm == NPMData){
            ketemu = true;

            cout << "Data telah ditemukan!" << endl;
            cout << "NPM\t\t: " << mhs[i].npm << endl;
            cout << "Nama\t\t: " << mhs[i].nama << endl;

            cout << "Apakah anda ingin menghapus data ini? (Y/N): ";
            cin >> konfirmHapus;
            cout << endl;

            if (konfirmHapus == 'Y' || konfirmHapus == 'y'){
                for (int j = 0; j < jmlData - 1; j++){
                    mhs[j] = mhs[j + 1];
                }
                jmlData--;
                cout << "Data telah dihapus!" << endl;
            }else {
                cout << "Penghapusan data dibatalkan." << endl;
            }
            break;
        }
    }

    if (!ketemu){
        cout << "Data tidak ditemukan, tekan [ENTER] untuk kembali ke menu" << endl;
        cin.ignore();
        cin.get();
    }else {
        cout << "Tekan [ENTER] untuk kembali ke menu...." << endl;
        cin.ignore();
        cin.get();
    }
    menu();
}
