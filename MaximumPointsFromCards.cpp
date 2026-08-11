#include <bits/stdc++.h>
using namespace std;

int MaxPoints(vector<int> &arr, int k){
    int n = arr.size();
    int lsum = 0, rsum = 0, maxsum = 0;
    for(int i = 0; i < k; i++){
        lsum = lsum + arr[i];
    }

    maxsum = lsum;
    int rindex = n - 1;
    for(int i = k-1; i >= 0; i--){
        lsum = lsum - arr[i];
        rsum = rsum + arr[rindex];
        maxsum = max(maxsum, lsum+rsum);
        rindex = rindex - 1;
    }

    return maxsum;

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
    cout << "The maximum sum that can be obtained from the given cards is :" << MaxPoints(arr, k) << endl;
    return 0;
}