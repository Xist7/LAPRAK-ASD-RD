#include <iostream>
using namespace std;    

struct node{   //Struct node
    int nilai;
    string nama;
    node* next;
};

struct list{  //Struct list, node pertama
    node* first;
};

void empty(list *l){ //Fungsi untuk mengosongkan list
    l -> first = nullptr;
} 

void inputfirst(int x, string y, list *l){ //Fungsi untuk memasukkan data di awal list
    node* baru = new node;         //Membuat node baru
    baru -> nilai = x;             //Memasukkan data nilai ke node baru
    baru -> nama = y;              //Memasukkan data nama ke node baru 
    baru -> next = nullptr;        //Menginisialisasi next node baru dengan nullptr
    if(l -> first == nullptr){     //Jika list kosong
        l -> first = baru;         //Maka node baru menjadi node pertama
    } else {
        baru -> next = l -> first; //Jika list tidak kosong, maka next node baru menunjuk ke node pertama
        l -> first = baru;          //Node baru menjadi node pertama
    }

}

void output(list *l){               //Fungsi untuk menampilkan isi list
    if(l -> first == nullptr){      //Jika list kosong
        cout << "List kosong" << endl;
        return;
    }
    node* bantu = l -> first;                           //Membuat pointer bantu yang menunjuk ke node pertama
    while(bantu != nullptr){                            //Perulangan selama pointer bantu tidak menunjuk ke nullptr
        cout << "Nama: " << bantu -> nama << endl;      //Menampilkan data nama dan nilai pada node
        cout << "Nilai: " << bantu -> nilai << endl;    
        bantu = bantu -> next;                          //Pointer bantu pindah ke node berikutnya
    }
}

int main() {
    list data;
    empty(&data);
    int pilihan, nilai;
    string nama;

    do {
        cout << "\n=== MENU SINGLE LINKED LIST ===" << endl; //Menu utama
        cout << "1. Insert First" << endl;
        cout << "2. Print List" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {               
            case 1:
                cout << "Masukkan nama: ";  //Input nama
                cin.ignore();               //Membersihkan buffer input
                getline(cin, nama);         //Menggunakan getline untuk input nama yang mengandung spasi
                cout << "Masukkan nilai: "; //Input nilai
                cin >> nilai;
                inputfirst(nilai, nama, &data); //Memanggil fungsi inputfirst untuk memasukkan data ke list
                break;
            case 2:
                output(&data);
                break;
        }

    }while (pilihan != 0);
} 

