#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int target){
    int n = arr.size();
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] <= target){
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int ceil(vector<int> &arr, int target){
    int n = arr.size();
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target1, target2;
    cin >> target1 >> target2;
    cout << "The floor of the array is : " << floor(arr, target1) << endl;
    cout << "The ceil of the array is : " << ceil(arr, target2) << endl;
    return 0;
}