#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int n){
    int xor1=0,xor2 =0;
    for(int i = 0; i < n - 1; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }

    xor1 = xor1 ^ n;
    return (xor1 ^ xor2);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0; i< n - 1 ; i++){
        cin >> arr[i];
    }
    cout << "The missing number from the array is : " << missingNumber(arr, n) << endl;
    return 0;
}