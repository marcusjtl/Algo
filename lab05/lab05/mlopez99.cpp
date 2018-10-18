#include <iostream>

using namespace std;

void MaxHeapify(int a[], int i, int length) {
    //int left, right, temp;

    int large = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < length && a[left] > a[large]) {
        large = left;
    }

    //else large = i;

    if (right < length && a[right] > a[large]) {
        large = right;
    }

    if (large != i) {
        swap(a[i], a[large]);
        MaxHeapify(a, large, length);
    }

}

void BuildMaxHeap(int a[], int length) {
    for (int i = length / 2; i >= 0; i--) {
        MaxHeapify(a, i, length);
    }
}


void HeapSort(int a[], int length) {

    BuildMaxHeap(a, length);

    for (int i = length-1; i >= 0; i--) {
        swap(a[0], a[i]);
        MaxHeapify(a, 0, i);
    }
}

int main () {
    int length;
    int *a;
    cin >> length;      //Takes in length of array

    a = new int [length];      //Initialize array

    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }
    
    HeapSort(a, length);

    for (int i = 0; i < length; i++) {
        cout << a[i] << ";";
    }

    delete [] a;
}