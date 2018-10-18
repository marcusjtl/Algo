#include <iostream>

using namespace std;

void insertionSort(int a[], int length) {
    for (int i = 1; i < length; i++) {
        int key = a[i];
        //Insert a[i] into sorted sequence a[1 .. j - 1]
        int j = i - 1;   

        while (j >= 0 && key > a[j]) {      //Reverse Reverse
            a[j + 1] = a[j];
            j = j - 1;
        } 

        a[j + 1] = key;
    }
}

int main() {
    int length;
    cin >> length; //Takes in length of array

    int a[length];  // initialize array at entered length 

    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }

    insertionSort(a, length); //Calls insertionSort with array 'a' & length

    for (int i = 0; i < length; i++) {
        cout << a[i] << ";";
    }

    return 0;
}
