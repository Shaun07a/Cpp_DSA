#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxi = INT_MIN;
    for(int x : arr)
        maxi = max(maxi, x);
    return maxi;
}

int calculateTotalHours(vector<int> &arr, int hourly){
    int totalH = 0;
    for(int x : arr){
        totalH += ceil((double)x / hourly);
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> arr, int h){
    int low = 1;
    int high = findMax(arr);

    while(low <= high){
        int mid = low + (high - low) / 2;

        int totalH = calculateTotalHours(arr, mid);

        if(totalH <= h){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int hours;
    cin >> hours;

    cout << "The minimum rate to eat bananas in the given hour is : "
         << minimumRateToEatBananas(arr, hours)
         << " bananas/hr";
}