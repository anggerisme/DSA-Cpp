#include <iostream>

using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
        void display(Array arr);
        void append(Array *arr, int value);
};

// -------------- Inserting elemen --------------------
void Array::display(Array arr){
    cout << "Tampilkan elemen" << endl;
    for (int i = 0; i < arr.length; i++){
        cout << arr.A[i];
    }
}

// -------------- Append elemen --------------------
void Array::append(Array *arr, int value){
    if(arr->length<arr->size){
        arr->A[length++] = value;
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


    arr.append(&arr, 10);
    arr.display(arr);
}