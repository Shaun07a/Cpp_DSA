#include <bits/stdc++.h>
using namespace std;

int SubarraywithGivenSumK(vector<int> & arr, int k){
    int n = arr.size();
    map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;

    }

    return cnt;
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
    cout << "The subarray within the array with given length " << k << " is : " << SubarraywithGivenSumK(arr, k)<<endl;
    return 0;
}