//Better when array contains positive, negative and zeors
// #include <bits/stdc++.h>
// using namespace std;

// int LongestSubarraywithSumk(vector<int> &arr, int k){
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;
//     for(int i = 0; i < arr.size(); i++){
//         sum += arr[i];
//         if(sum == k){
//             maxLen = max(maxLen, i+1);
//         }
//         int rem = sum - k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if(preSumMap.find(sum) == preSumMap.end()){
//             preSumMap[sum] = i;
//         }
//     }

//     return maxLen;

// }

// int main(){

//     int n, k;

//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> arr(n);

//     cout << "Enter the elements: ";
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     cout << "Enter the value of k: ";
//     cin >> k;

//     int ans = LongestSubarraywithSumk(arr, k);

//     cout << "Length of longest subarray = " << ans << endl;

//     return 0;
// }

//Optimal Solution : when array contains only positive and zeors
#include <bits/stdc++.h>
using namespace std;

int LongestSubarraywithSumk(vector<int> &arr, long long k){
    int right = 0, left = 0;
    long long sum = arr[0];
    int n = arr.size();
    int maxLen = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n){
            sum += arr[right];
        }
    }

    return maxLen;
}

int main(){

    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int ans = LongestSubarraywithSumk(arr, k);

    cout << "Length of longest subarray = " << ans << endl;

    return 0;
}