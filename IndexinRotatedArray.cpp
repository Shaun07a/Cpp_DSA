#include <bits/stdc++.h>
using namespace std;

int IndexRotated(vector<int> &arr){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[low]<=arr[high]){
            if(arr[low]< ans){
                index = low;
                ans = arr[low];

            }
            break;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]< ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }else{
            
            high = mid - 1;
            if(arr[mid]<ans){
                index = mid;
                ans = arr[mid];
            }
        }
    }

    return index;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int index = IndexRotated(arr);
    cout << "The number of times array rotated is : " << index << endl;
    return 0;
}