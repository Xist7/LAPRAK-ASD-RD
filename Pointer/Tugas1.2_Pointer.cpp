#include <iostream>
using namespace std;

void variasi(int *x, int y, int *z){
    for (int i=1;i<=y;i++){
        *x += i * i;

        *z *= (2*i)-1;
        
    }
    
}

int main() {
    int a=0;
    int b=4;
    int c=1;
    variasi(&a,b,&c);
    cout<<"Hasil a: "<<a<<endl;
    cout<<"Hasil c: "<<c<<endl;
}