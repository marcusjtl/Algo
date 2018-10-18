#include <iostream>

using namespace std;

int binarySearch(int FindMe, int a[], int low, int high) {
    if (high < low) {
        return -1;
    }
        
    int mid = (low + high)/2;

    if (a[mid] == FindMe) {
        return mid;                             
    }

    else if (FindMe < a[mid]) {
        binarySearch(FindMe, a, low, mid-1);   
    }

    else {
        binarySearch(FindMe, a, mid+1, high);   
    }
    
}

int main() {
    int length; //length of array
    cin >> length;

    int FindMe; //number to find
    cin >> FindMe;

    int a[length]; // initalizes array

    for (int i = 0; i < length; i++) {
        cin >> a[i];    
    }
    
    int low = 0;
    int high = length - 1;
    
    cout << binarySearch(FindMe, a, low, high);     //calls binarySearch and when finished prints out result

    

}