#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr){
    int n = arr.size();
    if(n ==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 0;
    int high = n - 2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]){
            return arr[mid];
        }

        //we are on ledt half
        if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1] )){
            low = mid + 1;
        }else{
            // we are on right half
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int dup = singleNonDuplicate(arr);
    cout << "The Single Non Duplicate value in the array is : " << dup << endl;
    return 0;
}