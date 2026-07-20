#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &arr){
    int n = arr.size();
    int mini = arr[0];
    int maxProfit = 0;
    for(int i = 0; i<n;i++){
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);
    }

    return maxProfit;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "The maximum profit that can be encountered is : " << maximumProfit(arr) << endl;
    return 0;
}