#include <iostream>
using namespace std;

void ganjil(int *x, int y){ // Subprogram untuk menjumlahkan bilangan ganjil
    for (int i=1;i<=y;i++){
        if(i%2==1){
            *x = *x + i;
        }
    }
}

int main (){
    int a=0;
    int b;
    cout << "Masukan angka: ";cin >> b;
    ganjil(&a,b);
    cout << a;
}