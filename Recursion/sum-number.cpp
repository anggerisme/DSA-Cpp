/*
    ***************
    Program : sum of number
    
    Konsep :
    Barisan bilangan asli yang dijumlahkan (Deret bilangan).

    Metode :
    1. Formula
    Dengan menuliskan formula deret aritmatika yang sudah kita tahu. Ini merupakan metode tercepat dan simple. 
    --------- (n*(2*a + (n-1)*b))/2 ----------------  
    2. Looping
    Idenya disini adalah meng-iterasi seluruh deret aritmatika dan setiap kali proses iterasi tambahkan value/nilai pd saat itu
    ke variable sum sehingga setiap kali iterasi, nilai sum akan terus bertambah. 

    3. Recursion function
    Menggunakan konsep recursi untuk menghitung seluruh deret aritmatika sejumlah n. Recursiv function akan bekerja pada saat returning time.
    
    

    **************
*/

#include <iostream>

using namespace std;

/*
    **************
    1. Formula

int sum(int size, int n[]) {
    int beda = n[1] - n[0];
    return (size * (2 * n[0] + ((size - 1)*beda))) / 2;
}

int main(){
	int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int r;
    r = sum(size, arr);
	cout << r;
	
}

*/
// -----------------------------------
/*
    **************
    2. Looping

int sum(int n) {
    int i, sum = 0;
    for (i = 1; i <= n;i++){
        sum = sum + i;
    }
        return sum;
}

int main(){
	int r;
	r = sum(5);
	cout << r;
	
}
    **************
*/
// -----------------------------------
/*
    **************
    3. Recursion method

int sum(int n) {
	if (n == 0) {
		return 0;
	}
	else
		return sum(n - 1) + n;
}

int main(){
	int r;
	r = sum(5);
	cout << r;
	

}

*/