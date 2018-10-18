#include <iostream>

using namespace std;

int main() {
    int length; //Takes in length of array
    cin >> length;

    int a[length];

    int FindMe; //User enters number to find
    cin >> FindMe;

    for (int i = 0; i < length; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < length; i++) {
        int counter = i;
        if (a[i] == FindMe) {
            cout << i << endl;
            return 0;
        }  
    }

    cout << -1 << endl;
}
