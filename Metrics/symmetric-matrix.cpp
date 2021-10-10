#include <iostream>

using namespace std;

/*
    Program : Symmetric Matrix

    Property : m[i, j] = 0 if i<=j
                else m[i, j] = non zero
    
    Representasi : - Low triangle (i>j)
                    - Upper triangle (j>i)

*/

class Matrix{
    private:
        int *A;
        int n;
        int x;

    public:
    /* Default Constructor */
        Matrix(){
            int n = 2;
            A = new int[2 * (2 + 1) / 2];
        }

        Matrix(int n){
            this->n = n;
            /* Jumlah elemen yang akan disimpan selain 0 */
            A = new int[n * (n + 1) / 2];
        }

        ~Matrix(){
            delete[] A;
        }

        int Set(int i, int j, int x);
        int Get();
        void Show();
};

int Matrix::Set(int i, int j, int x){
    if(i>=j)
        A[i*(i-1)/2+j-1]=x;
    // else
    //     A[j*(j-1)/2+i-1]=x;
     
}

int Matrix::Get(){
    int i, j;
    if(i>=j){
        return A[i * (i - 1) / 2 + j - 1];
    }
    else
        return A[j * (j - 1) / 2 + i - 1];
}

void Matrix::Show(){
    int i, j;

    for (i = 1; i <= n;i++){
        for (j = 1; j <= n;j++){
            if(i>=j){
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else{
                cout << A[j * (j - 1) / 2 + i - 1] << " ";
            }
        }
        /* Baris baru pada tiap j selesei */
            cout << endl;
    }
    cout << sizeof(*A);
}

int main(){
    int i, j;

    int d;
    cout << "Masukkan dimensi";
    cin >> d;

    Matrix sm(d);

    int x;
    cout << "Masukkan elemen";
    for (i = 1; i <= d;i++){
        for (j = 1; j <= d;j++){
            cin >> x;
            sm.Set(i, j, x);
        }
    }

    sm.Show();
}

