#include<iostream>
#include<vector>

using namespace std;

void countSort(vector<int> a[], int length, int p) {
   
    vector<int> * output;
    output = new vector<int>[length];
    
    int i; 
    int count[10] = {0};
    
    for (i = 0; i < length; i++) {
        count[ a[i][p]%10]++;
    }
    
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (i = length - 1; i >= 0; i--) {

        output[count[ a[i][p]%10 ] - 1] = a[i];
        count[ a[i][p]%10 ]--;
    
    }
    
    for (i = 0; i < length; i++) {

        a[i] = output[i];
    }
}


void radixsort(vector<int> a[], int length) {
    
    for (int p = 9; p >= 0 ; p--) {

        countSort(a, length, p);
    }
}

void print(vector<int> a[], int length) {
    
    for (int i = 0; i < length; i++) {
        
        for(vector<int>::iterator out = a[i].begin(); out != a[i].end();out++) {
            cout << *out << ";";
        }
        cout << endl;
    }
}

int main() {
    int length;
    cin >> length;  //Take in length of VECTOR
    
    int n;

    vector<int> *a;
    a = new vector<int>[length];    //initialize VECTOR
    
    for(int i =0; i < length ;i++) {

        for(int j = 0; j < 10; j++) {
            
            cin >> n;       //insert into VECTOR

            a[i].push_back(n);
        }
    }
    
    radixsort(a, length);
    print(a, length);
    
    return 0;
}