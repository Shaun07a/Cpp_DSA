#include <bits/stdc++.h>
using namespace std;

string TwoSum(int n, vector<int> &arr, int k){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int a = arr[i];
        int more = k - a;
        if(mpp.find(more) != mpp.end()){
             return "YES"; //return {mpp[more], i};
        }
        mpp[a] = i;
    }

    return "NO";
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << "Does there exist two numbers whose sum is same as the target : " << TwoSum(n, arr, target);
    return 0;
}