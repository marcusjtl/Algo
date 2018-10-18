#include <iostream>

using namespace std;

int partition(int a[], int low, int high) {
    int x = a[high]; 

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= x) {    //compares current index to last index
            i = i + 1;
            swap(a[i], a[j]);   //swap the values i & j
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

int partition_random(int a[], int low, int high){
      srand(time(NULL));    //initializess random seed

      int random = low + rand() % (high - low);     //randomizes from beginning to end of array

      swap(a[random], a[high]);

      return partition(a, low, high);
}

void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int p_index = partition_random(a, low, high);
        QuickSort(a, low, p_index - 1);
        QuickSort(a, p_index + 1, high);
    }
}

int main() {
    int length;
    cin >> length; //Takes in length of array

    int a[length]; //Initializes array

    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = length - 1;

    QuickSort(a, low, high);

    for (int i = 0; i < length; i++) {
        cout << a[i] << ";";
    }

    return 0;

}