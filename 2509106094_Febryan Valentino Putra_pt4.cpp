#include <iostream>
#include <string>

using namespace std;

struct Penumpang {
    string nama;
    string tiket;
    Penumpang* next; 
};

Penumpang* front = nullptr; 
Penumpang* rear = nullptr;  
Penumpang* top = nullptr;   

bool isEmptyQueue() { return front == nullptr; }
bool isEmptyStack() { return top == nullptr; }

void enqueue(string n, string t) {
    Penumpang* baru = new Penumpang;
    baru->nama = n;
    baru->tiket = t;
    baru->next = nullptr;

    if (isEmptyQueue()) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Berhasil tambah antrian " << n << " masuk antrian.\n";
}

void dequeueAndPush() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong.\n"; 
        return;
    }

    Penumpang* hapus = front;
    string n = hapus->nama;
    string t = hapus->tiket;

    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete hapus;

    Penumpang* baru = new Penumpang;
    baru->nama = n;
    baru->tiket = t;
    baru->next = top;
    top = baru;

    cout << "Tiket si " << n << " berhasil dicetak & masuk riwayat.\n";
}

void popRiwayat() {
    if (isEmptyStack()) {
        cout << "!! Underflow: Riwayat kosong.\n"; 
        return;
    }
    Penumpang* hapus = top;
    top = top->next;
    cout << "Riwayat sudah dihapus " << hapus->nama << " telah dihapus.\n";
    delete hapus;
}

void peekRiwayat(Penumpang* s) { 
    if (s == nullptr) {
        cout << "Antrian kosong.\n";
    } else {
        cout << "== PEEK RIWAYAT TERBARU ==\n";
        cout << "Nama : " << s->nama << "\nTiket: " << s->tiket << endl;
    }
}

void tampilAntrian() {
    cout << "\n--- DAFTAR ANTRIAN TIKET (QUEUE) ---\n";
    if (isEmptyQueue()) {
        cout << "(Kosong)\n";
    } else {
        Penumpang* bantu = front;
        while (bantu != nullptr) {
            cout << "[" << bantu->nama << " | " << bantu->tiket << "] -> ";
            bantu = bantu->next;
        }
        cout << "NULL\n";
    }
}

void tampilRiwayat() {
    cout << "\n--- RIWAYAT CETAK TIKET (STACK) ---\n";
    if (isEmptyStack()) {
        cout << "(Kosong)\n";
    } else {
        Penumpang* bantu = top;
        while (bantu != nullptr) {
            cout << "[" << bantu->nama << "]\n";
            bantu = bantu->next;
        }
    }
}

int main() {
    int pilihan;
    string n, t;

    do {
        cout << "\n=== SISTEM KERETA API (LINKED LIST) ===\n";
        cout << "1. Enqueue (Tambah Antrian)\n";
        cout << "2. Dequeue & Push (Cetak Tiket)\n";
        cout << "3. Pop (Hapus Riwayat)\n";
        cout << "4. Peek (Lihat Riwayat Teratas)\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Penumpang: "; cin >> n;
                cout << "Kode Tiket    : "; cin >> t;
                enqueue(n, t);
                break;
            case 2:
                dequeueAndPush();
                break;
            case 3:
                popRiwayat();
                break;
            case 4:
                peekRiwayat(top); 
                break;
            case 5:
                tampilAntrian();
                break;
            case 6:
                tampilRiwayat();
                break;
        }
    } while (pilihan != 0);

    return 0;
}