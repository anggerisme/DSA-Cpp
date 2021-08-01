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
        int linear_search(int key);
        int binary_search(int key);//looping
        int Rbinary_search(int arr[], int low, int high, int key);
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

// -------------- 5. Searching elemen --------------------
/*
    Improving linear search
    1. Transposition
    2. Move to front/head
*/
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// ----------- 5.1 Linear search ----------- 
int Array::linear_search(int key){
    for (int i = 0; i < length;i++){
        if(key == A[i]){
            /* 1. Tranposition
                Reducing index slowly
            */
            // swap(&A[i], &A[i - 1]);
            /* 2. Move to head 
                Directly move index searched into front
            */
            swap(&A[i], &A[0]);
            return i;
        }
    }
        return -1;
}

// ----------- 5.2 Binary search -----------

// 1. Looping method
int Array::binary_search(int key){
    int low=0, high, mid;
    high = length-1; // Karena index dimulai dari 0

    while(low<=high){
        mid = (low + high) / 2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            high = mid - 1;
        else
            low = mid + 1;
        
    }
    return -1;
}

//2. Recursive Method
int Array::Rbinary_search(int arr[], int low, int high, int key){
    if(low<=high){
        int mid = (low + high) / 2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            return Rbinary_search(arr, low, mid - 1, key);
        else
            return Rbinary_search(arr, mid+1, high, key);
    }
    return -1;
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
    // cout << arr.Delete(2) << endl;
    // arr.insert(2, 3);
    cout << "Rbinary search : " << arr.Rbinary_search(arr.A, 0, arr.length, 3) << endl;
    cout << "Binary search : " << arr.binary_search(3) << endl;
    cout << "linear search : " << arr.linear_search(3) << endl;
    arr.display(arr);
}