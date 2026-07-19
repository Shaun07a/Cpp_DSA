#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long sum = 0, maxi = LONG_MIN;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for(int i = 0; i < n; i++){

        if(sum == 0)
            start = i;

        sum += arr[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0)
            sum = 0;
    }

    // Print the subarray
    cout << "Maximum Sum Subarray: ";
    for(int i = ansStart; i <= ansEnd; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxi;
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long maxSum = maxSubarraySum(arr, n);

    cout << "The maximum sum of the given subarray is: " << maxSum << endl;

    return 0;
}