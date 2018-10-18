#include <iostream>
#include <climits>

using namespace std;

int mergeIt(int a[], int low, int mid, int high) {
    int n1 = low;
    int n2 = mid + 1;

    int left[n1];
    int right[n2];

    for (int i = 0; i < mid; i++) {
        left[i] = a[i];
    }    

    for (int j = 0; j < high; j++) {
        right[j] = a[j];
    }
    
    int i = 0;
    int j = 0;

    for (int k = 0; k < high; k++) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i = i + 1;
        }

        else {
            a[k] = right[j];
            j = j + 1;
        }
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
        cin >> a[i];
    }

    int low = 0;
    int high = length - 1;

    mergeSort(a, low, high);

    for (int i = 0; i < length; i++) {
        cout << a[i] << ";";
    }

    return 0;
}