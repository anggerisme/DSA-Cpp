#include <iostream>

using namespace std;

class Array{
    public:
        int *A;
        int *B;
        int *C;

        int a[10];
        int b[10];
        int size_a;
        int size_b;
        int size_c;
        int length;

        Array();
        Array(int arr_a[], int arr_b[], int size_a, int size_b){
            // this->A = new int[size];
            this->A = arr_a;
            this->B = arr_b;
            this->size_a = size_a;
            this->size_b = size_b;
            // for (int i = 0; i < size_a;i++){
            //     cout << B[i] << "" << endl;
            // }
        }

        void arr(int x[], int y[], int length){
            int i = 0;
            for (; i < length;i++){
                a[i] = x[i];
                b[i] = y[i];
                // cout << a[i];
                // cout << " B =  " << b[i];
                
            }
            this->length = length;
        }
        void display(Array arr);
        void Union();
};

void Array::display(Array arr){
    cout << "Tampilkan elemen" << endl;
    for (int i = 0; i < arr.length; i++){
        cout << arr.C[i] << " ";
    }
}

void Array::Union(){
    /*
        Program : Union (Penggabungan) 
            Menggabungkan 2 buath array yang masing masing elemenya unik, artinya tidak ada perulangan elemen. Jika kedua elemen memiliki elemen yang sama maka diambila salah satu saja.
        Algorithm : 
            1. Unsorted Array
                1. Copy semua elemen pada array A ke array C (array bantu). 
                2. Kemudian copy array B ke Array C (yg sudah berisi elemen Array A) dan bandingkan apakah elemen pada array B sudah dipunyai array C?
                3. Jika iya maka TIDAK perlu di copy, Jika elemen tidak dipunyai, maka copy elemen Array B ke array C.

            Note :
                Mengenai time taken :
                    1. Copy semua elemen A = berarti sebanyak (n)
                    2. Peng-copyan kedua memerlukan waktu sebanyak (n) untuk menelusuri untuk memastikan tidak ada elemen yg sama,
                     ditambah waktu sebanyak n tergantung jumlah elemen pada array B.

                Jadi total keseluruhan : Time taken = O(n^2)

            2. Sorted Array
                1. Algorithm :
                    Untuk Sorted array cukup dengan teknik merging array. Algoritma kurang lebih sama dengan mergin sebelumnya, Hanya saja jika elemen bernilai sama
                    maka cukup copy salah satu (baik array A/B) kemudian iterator dari masing-masing array melakukan increament.
                2. Time taken O(n)
        
    */

    // int size = 6;
    C = new int[7];
    // cout << size_a;

    /*
        1. Copy semua elemen dari array A ke C
    */
    for (int k=0; k < size_a; k++)
        C[k] = A[k];
    // cout << C[1];
    /*
        2. Check apakah elemen array B ada di Array C
    */
    for (int i = 0;i < size_b; i++)
    {
        bool duplicate = false;
        int j=0;
        for (; j < size_a; j++){
            if (B[i] == C[j]){
                duplicate = true;
            }
            // else
            //     C[j] = b[i];
        }
        // cout << j;
        if (!duplicate){
            C[j] = B[i];
            // cout << C[j];
        }
        // size++;
    }
        for (int i = 0; i < 7;i++){
            cout << C[i] << " ";
        }
}

// Array::Array(int A, int size);

int main(){
    // Array A;
    int a[] = {21,22,23,24,25};
    int b[] = {23,24,25,26,27};
    Array A = Array{a, b, sizeof(a)/sizeof(int), sizeof(b)/sizeof(int)};
    // Array C;
    // cout << A.C[0];
    A.Union();

    // ------------------ 1. Static Array ------------------
    // int arr_A[] = {2, 9, 21, 28, 35};
    // int arr_B[] = {2, 3, 9, 18, 28};
    // A.arr(arr_A, arr_B, 5);
    // A.Union();

    // A.display(A);
}