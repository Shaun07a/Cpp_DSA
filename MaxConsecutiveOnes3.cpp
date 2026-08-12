#include <bits/stdc++.h>
using namespace std;

int MaxLength(vector<int> &arr, int k){
    int l = 0, r = 0, zeros = 0, maxlen = 0;
    while(r < arr.size()){
        if(arr[r] == 0){
            zeros++;
        }
        while( zeros > k){
            if(arr[l] == 0){
                zeros--;
            }
            l++;
        }
        if(zeros <= k){
            int len = r - l + 1;
            maxlen = max(len, maxlen);
        }
        r++;
    }

    return maxlen;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;
    cout << "The length of consecutive ones within the array is : " << MaxLength(arr, k) << endl;
    return 0;
}