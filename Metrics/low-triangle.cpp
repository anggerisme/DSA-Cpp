#include <iostream>

using namespace std;

class LowerTri{
    private:
        int *A; // Besar array untuk menyimpan low triangle matrix
        int n;
    public:
        /* Inisialisasi nilai n, jika tidak ada constructor yang menginisialisasi 
        maka default constructor ini akan menjadi nilai defaulntya*/
        
        LowerTri(){
            n = 2;
            A = new int[2 * (2 + 1) / 2];
        }
        LowerTri(int n){
            this->n = n;
            A = new int[n * (n + 1) / 2];
        }

        /* Destructor akan menghapus objek ketika sudah selesei
        Untuk objek yang disimpan di dalam heap, maka harus di
        hapus secara manual  */
        ~LowerTri(){
            // Karena Dynamic array, maka harus memakai subscript
            delete[] A;
        }

        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Show();
};

/* Untuk menyimpan nilai matrix diagonal hanya ketika i==j*/
void LowerTri::Set(int i, int j, int x){
    /*Hanya ketika indeks i >= j low triangle terbentuk*/
    if(i>=j){
        // Formula untuk mendapatkan elemen pada matriks agar sesuai dengan indeks array
        this->A[i*(i-1)/2+j-1] = x;
    }
}

/* Untuk mengembalikan nilai yang sudah disimpan*/
int LowerTri::Get(int i, int j){
    if(i>=j){
        return A[i*(i-1)/2+j-1];
    }
        return 0;
}

void LowerTri::Show(){
    int i, j;
    for (i = 1; i <= n ;i++){
        for (j = 1; j <= n;j++){
            if (i >= j){
                cout << this->A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else{
                cout << "0 ";
            }
        }
            cout << endl;
    }
}

int main(){
    int i, j;

    int d;
    cout << "Masukan dimensi : ";
    cin >> d;

    /* Inisialisasi Object yang akan match 
    dengan constructor yang punya parameter sama */
    
    LowerTri lm(d);
    /* Ukuran array untuk menyimpan hanya elemen bukan 0 */

    int x;
    cout << "Masukkan element :";
    /* Memasukkan input untuk matrix (0 dan non 0) */
    for (i = 1; i <= d;i++){
        for (j = 1; j <= d;j++){
            cin >> x;
            /*Karena lm adalah object
            maka ia dapat mengakses function pada class utama*/
            lm.Set(i, j, x);
            // cout << endl;
        }
    }

    lm.Show();
}
