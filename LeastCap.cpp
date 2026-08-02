#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int cap){
    int load = 0, days = 1;
    for(int i = 0; i < weights.size(); i++){
        if(load + weights[i] > cap){
            days += 1;
            load = weights[i];
            
        }
        else{
            load += weights[i];
        }
    }

    return days;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low <= high){
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if(numberOfDays <= d){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i< n; i++){
        cin >> arr[i];
    }
    int days;
    cin >> days;
    cout << "The least capacity the ship can carry in the given number of days is : " << leastWeightCapacity(arr, days) << endl;
    return 0;
}