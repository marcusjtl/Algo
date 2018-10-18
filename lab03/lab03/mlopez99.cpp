#include <iostream>

using namespace std;

int mergeIt(int a[], int low, int mid, int high) {
    int temp[high];         //temporary array 

    int i = low;    //left side of array
    int j = mid + 1;    //right side of array

    int k = 0;  //counter

    while (i <= mid && j <= high) {        //i stays below mid and j stays below high
        if (a[i] <= a[j]) {              //ensures we don't go beyond middle
            temp[k++] = a[i++];         //inserts left side of array
        }

        else {
            temp[k++] = a[j++];     //inserts right side of array
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];     //goes through for extra elements of left side
    }

    while (j <= high) {
        temp[k++] = a[j++];     //goes through for extra elements of right side
    }

    for (k = 0, i = low; i <= high; ++i, ++k) {
        a[i] = temp[k];     //merges temporary array with main array
    }

}

void mergeSort(int a[], int low, int high) {
    int mid;
    
    if (low < high) {
        mid = (high + low) /2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        mergeIt(a, low, mid, high);
    }

}

int main () {
    int length;
    cin >> length; //takes in length of to be sorted

    int a[length]; //initializes array;

    for (int i = 0; i < length; i++) {
        cin >> a[i];    //inserts elements of array
    }

    int low = 0;    
    int high = length - 1;

    mergeSort(a, low, high);

    for (int i = 0; i < length; i++) {
        cout << a[i] << ";";
    }

    return 0;
}