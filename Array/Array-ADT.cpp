#include <iostream>

using namespace std;

class Array{
    public:
        int *A;
        int *B;
        int size;
        int length;
        void display(Array arr);
        void insert(int index, int value);
        void append(int value);
        int Delete(int index);
        int linear_search(int key);
        int binary_search(int key);//looping
        int Rbinary_search(int arr[], int low, int high, int key);
        int get(int index);
        int set(int index, int value);
        int max();
        int min();
        int sum();
        int Rsum();
        int avg();
        void reverse_copy();
        void reverse_swap();
        void rotate();
        void rotate2();
        void insert_in_sorted_array(int value);
        int checking_sorted_array();
        void sorting_array();
};

// -------------- 1. Display elemen --------------------
void Array::display(Array arr){
    cout << "Tampilkan elemen" << endl;
    for (int i = 0; i < arr.length; i++){
        cout << arr.A[i] << " ";
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
// -------------- 6. Get() value from given index --------------------
int Array::get(int index){
    if(index>=0 && index<length){
        return A[index];
    }
    return -1;
}

// -------------------- 7. Set() --------------------
int Array::set(int index, int value){
    if (index >= 0 && index<length){
        A[index] = value;
    }
    return A[index];
}

// -------------------- 8. Max() --------------------
int Array::max(){
    int max = A[0], i;
    for (i = 0; i < length;i++){
        if(max < A[i]){
            max = A[i];
        }
    }
        return max;
}

// -------------------- 9. Min() --------------------
int Array::min(){
    int min = A[0], i;
    for (i = 0; i < length;i++){
        if(min>A[i]){
            min = A[i];
        }
    }
    return min;
}

// -------------------- 10. Sum() --------------------
int Array::sum(){
    int total = 0, i;
    for (i = 0; i < length;i++){
        total = total + A[i];
    }
    return total;
}

// -------------------- 11. Avg() --------------------
int Array::avg(){
    int total, i;
    for (i = 0; i < length;i++){
        total = total + A[i];
    }
    return total / length;
}

// -------------------- 12. Reverse() --------------------

/* ---------- 12.1 Reverse by copying() ----------*/
void Array::reverse_copy(){
    for (int i = length - 1, j = 0; i >= 0;i--, j++){
        B[j] = A[i];
    }
}

/* ---------- 12.2 Reverse by swap() ----------*/
void Array::reverse_swap(){
    int temp;
    for (int i = 0, j = length - 1; i < j;i++, j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

// -------------------- 13. Rotate() --------------------
void Array::rotate(){
    int temp = A[length-1], i;
    for (i = length - 1; i >= 0;i--)
        A[i] = A[i - 1];

    A[0] = temp;
}

// ----------- 13. Rotate_by_swap() -----------
// void Array::swapping(int i, int j){
//     int temp = i;
//     A[0] = A[length - 1];
//     A[length - 1] = temp;
// }

// void Array::rotate2(){
//     int i = 0, j = length - 1;
//     while(i!=j){
//         swapping(i, j);
//         i++;
//     }

// }

// -------------------- 14. Insert element in sorted arrray() --------------------
void Array::insert_in_sorted_array(int value){
    /*
        Ide kunci : Selama A[i] > value maka terus lakukan pengisian nilai A[i+1] = A[i]
        -Jika A[i] < value maka BERHENTI dan lakukan   pengisian nilai pada
        - A[i+1] = value
        - length++
    */
    // -------- 1. For --------
    int i;
    for (i = length - 1; i >= 0;){
        if(A[i]>value){
            A[i + 1] = A[i];
            i--;
        }
        break;
    }
        A[i + 1] = value;
        length++;

    // -------- 2. While --------
        // while(A[i] > value){
        //     A[i + 1] = A[i];
        //     i--;
        // }
        // A[i + 1] = value;
        // length++;
}

// -------------------- 15. Checking whether array sorted or not() --------------------
int Array::checking_sorted_array(){
    /*
        Ide Kunci : Array yang terurut (sorted) ditandai ketika elemen sebelumnya (i) < dari elemen setelahnya (i+1)
    */
    int i;
    for (i = 0; i < length - 1;i++){
        if(A[i] > A[i+1])
            return 0; // Return false
    }
        return 1; // Return true - Array is sorted
}

int main(){
    Array arr;
    int i, n;
    cout << "Masukkan ukuran array : ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.B = new int[arr.size];
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
    // cout << "Rbinary search : " << arr.Rbinary_search(arr.A, 0, arr.length, 3) << endl;
    // cout << "Binary search : " << arr.binary_search(3) << endl;
    // cout << "linear search : " << arr.linear_search(3) << endl;
    // cout << arr.get(3) << endl;
    // cout << arr.set(3, 5) << endl;
    // cout << arr.max() << endl;
    // cout << arr.min() << endl;
    // cout << arr.sum() << endl;
    // cout << arr.avg() << endl;
    // arr.reverse_copy();
    // arr.reverse_swap();
    // arr.rotate();
    // arr.insert_in_sorted_array(5);
    // cout << arr.checking_sorted_array() << endl;
    arr.sorting_array();
    arr.

    arr.display(arr);
}