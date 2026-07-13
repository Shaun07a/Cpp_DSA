#include <bits/stdc++.h>
using namespace std;

int AppearOnce(vector<int> &arr){
    int n = arr.size();
    int xor1 = 0;
    for(int i = 0; i<n;i++){
        xor1 = xor1^(arr[i]);
    }

    return xor1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0; i< n  ; i++){
        cin >> arr[i];
    }
    cout << "The  number from the array  that appears only once and others twice is : " << AppearOnce(arr) << endl;
    return 0;
}