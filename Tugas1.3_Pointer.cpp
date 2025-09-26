#include <iostream>
using namespace std;

void balik (int *a, int n){
    int temp;
    for(int i=0; i<n/2;i++){
        temp = a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }

}

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cout << "Masukkan nilai a["<<i<<"]: ";
        cin >> a[i];
    }
    balik(a, n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}