#include <bits/stdc++.h>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr){
    int n = arr.size();
    int ans = INT_MIN;
    int prev = 1;
    int suff = 1;
    for(int i = 0; i < n; i++){
        if(prev == 0) prev = 1;
        if (suff == 0) suff = 1;

        prev = prev * arr[i];
        suff = suff * arr[n-i-1];
        ans = max(ans, max(prev, suff));
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    cout << "The maximum product of the subarray within the given array is : " << subarrayWithMaxProduct(arr) << endl;
    return 0;
}