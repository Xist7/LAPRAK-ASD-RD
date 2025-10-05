#include <iostream>
using namespace std;
//komentar baru hanya pada sorting, sisanya sama seperti latihan 1
struct node{
    int nilai;
    node* next;
};

struct list{
    node* first;
};

void empty(list *l){
    l -> first = nullptr;
}

void sort(list *l){
    if(l -> first != nullptr && l -> first -> next != nullptr){ //Cek apakah list memiliki lebih dari satu elemen
        node* i = l -> first;                   //Pointer i mulai dari node pertama
        while(i != nullptr){                    //Perulangan selama pointer i tidak menunjuk ke nullptr
            node* j = i -> next;                //Pointer j mulai dari node setelah i
            while(j != nullptr){                //Perulangan selama pointer j tidak menunjuk ke nullptr
                if(i -> nilai > j -> nilai){    //Jika nilai pada node i lebih besar dari nilai pada node j, maka tukar nilai
                    int temp = i -> nilai;      //Simpan nilai i ke variabel sementara
                    i -> nilai = j -> nilai;    //Ganti nilai i dengan nilai j
                    j -> nilai = temp;          //Ganti nilai j dengan nilai sementara (nilai i)
                }
                j = j -> next;                  //Pointer j pindah ke node berikutnya
            }
            i = i -> next;                      //Pointer i pindah ke node berikutnya
        }
    }
}

void inputfirst(int x, list *l){
    node* baru = new node;
    baru -> nilai = x;
    baru -> next = nullptr;

    if(l -> first == nullptr){
        l -> first = baru;
    } else {
        baru -> next = l -> first;
        l -> first = baru;
    }
    
}

void inputlast(int x, list *l){
    node* baru = new node;
    baru -> nilai = x;
    baru -> next = nullptr;
    if(l -> first == nullptr){
        l -> first = baru;
    } else {
        node* bantu = l -> first;
        while(bantu -> next != nullptr){
            bantu = bantu -> next;
        }
        bantu -> next = baru;
    }
    
}




void output(list *l){
    if(l -> first == nullptr){
        cout << "List kosong" << endl;
        return;
    }
    node* bantu = l -> first;
    while(bantu != nullptr){
        cout << bantu -> nilai << " -> ";
        bantu = bantu -> next;
    } cout << "nullptr";
    cout << endl;
}

int main(){
    list nilai;
    empty(&nilai);
    int pilihan, nilaiInput;
    do {
        cout << "\n=== MENU SINGLE LINKED LIST SORTING ===" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Print List" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilaiInput;
                inputfirst(nilaiInput, &nilai);
                //sort ascending
                sort(&nilai); //memanggil fungsi sort setiap kali ada penambahan data
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilaiInput;
                inputlast(nilaiInput, &nilai);
                sort(&nilai);
                break;
            case 3:
                output(&nilai);
                break;
        }

    }while (pilihan != 0);
}