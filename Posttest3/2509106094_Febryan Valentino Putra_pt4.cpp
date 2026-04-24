#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* front = NULL; 
Node* rear = NULL;  
Node* top = NULL;   

void enqueue(string nama) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "  berhasil input '" << nama << "' ditambahkan ke antrian.\n";
}

void simpan_data(string nama) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->next = top;
    top = newNode;
}

void dequeue() {
    if (front == nullptr) {
        cout << "  Waduh, Antrian masih kosong bos!\n";
        return;
    }
    Node* temp = front;
    string dataDiproses = temp->nama;
    front = front->next;
    
    if (front == nullptr) rear = nullptr;

    simpan_data(dataDiproses);
    
    delete temp;
    cout << "  [-] '" << dataDiproses << "' selesai diproses & masuk riwayat.\n";
}

void popRiwayat() {
    if (top == nullptr) {
        cout << "  [!] Underflow: Riwayat kosong!\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << "  [x] Riwayat '" << temp->nama << "' dihapus.\n";
    delete temp;
}

void peekRiwayat() {
    if (top == nullptr) {
        cout << "  [!] Riwayat kosong.\n";
    } else {
        cout << "  [*] Terakhir diproses: " << top->nama<< endl;
    }
}

void lihat_list() {
    cout << "\n--- DAFTAR ANTRIAN (QUEUE) ---" << endl;
    if (front == nullptr) {
        cout << "  (Kosong)" << endl;
        return;
    }
    Node* curr = front;
    int i = 1;
    while (curr != nullptr) {
        cout << "  " << i++ << ". " << curr->nama<< endl;
        curr = curr->next;
    }
}

void tampilRiwayat() {
    cout << "\n--- RIWAYAT PEMROSESAN (STACK) ---" << endl;
    if (top == nullptr) {
        cout << "  (Kosong)" << endl;
        return;
    }
    Node* curr = top;
    while (curr != nullptr) {
        cout << "  [Selesai] " << curr->nama << endl;
        curr = curr->next;
    }
}

int main() {
    int pilihan;
    string input;

    do {
        cout << "\n========== SISTEM GUDANG ==========";
        cout << "\n1. Enqueue (Tambah Antrian)";
        cout << "\n2. Dequeue (Proses Antrian)";
        cout << "\n3. Peek (Lihat Riwayat Teratas)";
        cout << "\n4. Pop (Hapus Riwayat Terakhir)";
        cout << "\n5. Tampilkan Semua";
        cout << "\n0. Keluar";
        cout << "\nPilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama barang: ";
                getline(cin, input);
                enqueue(input);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekRiwayat();
                break;
            case 4:
                popRiwayat();
                break;
            case 5:
                lihat_list();
                tampilRiwayat();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}