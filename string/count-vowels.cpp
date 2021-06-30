#include <iostream>
#include <string>

using namespace std;

int v_count = 0; // Vowels counter
int c_count = 0; // Consonan counter

void vowels(char A[]){
    cout << &A << endl;
    for (int i = 0; A[i] != '\0';i++){
        if(A[i]=='a'|| 
           A[i]=='e'||
           A[i]=='u'||
           A[i]=='e'||
           A[i]=='o'||
           A[i]=='A'|| 
           A[i]=='E'||
           A[i]=='U'||
           A[i]=='E'||
           A[i]=='O'){
            v_count++;
    }
        else if(A[i]>=65 && A[i]<=122){
            c_count++;
            
        }
    }
        cout << "Jumlah huruf vokal : " << v_count << endl;
        cout << "Jumlah huruf Konsonan : " << c_count;
}
int main(){
    char A[]{};
    cout << &A << endl;

    cout << "Masukkan kata/kalimat : ";
    cin.getline(A, 100);
    vowels(A);
}