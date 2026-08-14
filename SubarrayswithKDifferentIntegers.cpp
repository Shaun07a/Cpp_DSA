#include <bits/stdc++.h>
using namespace std;

int atmost(vector<int> &nums, int k){
    if(k < 0) return 0;
    int l = 0, r = 0, cnt = 0;
    unordered_map<int, int> mpp;
    while(r < nums.size()){
        mpp[nums[r]]++;
        while(mpp.size() > k){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }

            l++;
        }

        cnt += r - l + 1;
        r++;
    }

    return cnt;
}

int subarraywithKDistinct(vector<int> &nums, int k){
    return atmost(nums, k) - atmost(nums, k - 1);
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
    cout << "The number of subarrays with distinct k integers is : "<< subarraywithKDistinct(arr, k) << endl;
    return 0;
}