#include <iostream>

using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
        void Display(Array arr);
};
// int Cube :: getVolume()
void Array::Display(Array arr){
    cout << "Tampilkan elemen" << endl;
    for (int i = 0; i < arr.length; i++){
        cout << arr.A[i];
    }
}

int main(){
    Array arr;
    int i, n;
    cout << "Masukkan ukuran array : ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    cout << "Masukkan jumlah elemen : ";
    cin >> n;
    for (i = 0;i<n;i++){
        cin >> arr.A[i];
    }
    arr.length = n;

    arr.Display(arr);
}