// -------------------- 17. Merging array --------------------
    /*
    Note : 
        1. Hanya berlaku untuk sorted array.
        2.  Membutuhkan array ke 3.

    Ide Kunci :
        Ketika ada nilay array yang lebih kecil dari 2 array yang di compare, Maka Copy-kan nilai yg terkecil ke array yang baru.

    Algorithm : 
        1. Buat Array yg baru untuk menampung nilai nilai dari kedua array secara berurutan. Dalam kasus ini total ada 3 buah array
            Array baru ini bersifat dynamic (dibuat di dalam heap), jadi elemen dan ukuranya ditentukan diakhir.
        2. Buat 3 buah pointer/Iterator i, j, k.
        3. Compare A[i] dengan B[j] ketika ada nilai yg lebih kecil maka pindahkan nilai terkecil itu ke C[k].
        4. Iterator yg pada saat itu bernilai lebih kecil lakukan increament, itarator yg lebih besar jangan berjalan dulu (berhenti).
        5. Lakukan comparasi berikutnya, Jika iterator yg besar tadi lebih kecil nilainya dari iterator yg sudah maju, maka simpan nilai iterator besar ke C[k].

    Time taken = O(m+n)
*/
    

#include <stdio.h>
#include <stdlib.h> // malloc

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\nTampilkan elemen\n");
    for (i = 0; i < arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;

    /*
        Dynamic array : Karena nilai dan ukuran array ditentukan di akhir (at run-time)

        Syntax : 
            type data *ptr = (type data *)malloc(sizeof(type data));

    */
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    /*
        Jika salah satunya sudah habis (berarti ada array yg elemenya lebih banyak) maka perulangan berhenti.
    */
    while (i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    /*
        Setelah perulangan berhenti, maka array yang tersisa akan otomatis disimpan ke dalam array 3.
    */

    for (; i < arr1->length;i++){
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length;j++){
        arr3->A[k++] = arr2->A[j];
    }

    /*
        Terakhir jangan lupa ubah ukuran(size) dari dynamic array (arr3) sesuai
        dengan ukuran terakhirnya sesudah di jumlahkan.
    */

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

int main(){
    struct Array arr1={{2,9,21,28,35},10,5};
    struct Array arr2={{3,4,7,20},10,4};
    struct Array *arr3;

    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
}