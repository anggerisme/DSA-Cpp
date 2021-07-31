#include <iostream>

using namespace std;

class Array{
    public:
        int *A;
        int size;
        int length;
        void display(Array arr);
        void insert(int index, int value);
        void append(int value);
        int Delete(int index);

};

// -------------- 1. Display elemen --------------------
void Array::display(Array arr){
    cout << "Tampilkan elemen" << endl;
    for (int i = 0; i < arr.length; i++){
        cout << arr.A[i];
    }
}

// -------------- 2. Inserting elemen --------------------
void Array::insert(int index, int value){
    for (int i = length; i > index;i--){
        A[i] = A[i - 1];
    }
    A[index] = value;
    length++;
}

// -------------- 3. Append elemen --------------------
void Array::append(int value){
    if(length<size){
        A[length++] = value;
    }
}

// -------------- 4. Deleting elemen --------------------
int Array::Delete(int index){
    int i;
    int x=0;

    if(index>=0 && index<length){
        x = A[index]; // Index yang akan dihapus
        for (i = index; i < length;i++){
            A[i] = A[i + 1]; // Copy index terkini dengan nilai index yg ada di depanya
            length--; // Kurangi panjang array (karena sudah dihapus)
            
            return x; // Nilai yg dihapus
        }
        return 0;
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

    // arr.append(&arr, 10);
    system("cls");
    cout << arr.Delete(2) << endl;
    arr.insert(2, 3);
    arr.display(arr);
}