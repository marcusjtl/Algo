#include <iostream>
#include <climits>

using namespace std;

int FindMaxCrossingsSub(int a[], int low, int mid, int high ) {
    int left_sum = INT_MIN;
    int sum = 0;
     for (int i = mid; i >= low; i--) {
         sum = sum + a[i];
         if (sum > left_sum) {
             left_sum = sum;

         }
     }

     int right_sum = INT_MIN;
     sum = 0;

     for (int i = mid + 1; i <= high; i++) {
         sum = sum + a[i];
         if (sum > right_sum) {
             right_sum = sum;
         }
     }
     return left_sum + right_sum;
}

int FindMaxSub (int a[], int low, int high) {
    int mid;

    if (low == high) {
        return a[low];
    }
    else {
        mid = (low + high ) / 2;
        
    }

    return max(max(FindMaxSub(a, low, mid), FindMaxSub(a, mid+1, high)), FindMaxCrossingsSub(a, low, mid, high));
}

int MaxSubArray (int a[], int low, int high) {
    return FindMaxSub(a, low, high);
}

int main (int argc, char **argv) {
    int *Sequence;

    int length;
    cin >> length;  //Takes in length of array

    int a[length];  //Initializes array
    Sequence = new int[length];

    for (int i = 0; i < length; i++) {
        cin >> Sequence[i];
    }

    int low = 0;
    int high = length -1;

    cout << FindMaxSub(Sequence, 0, length-1);
    delete[] Sequence;
}