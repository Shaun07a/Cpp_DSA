// #include <bits/stdc++.h>
// using namespace std;

// int binarySearch(vector<int> &arr, int n, int target){
//     int low = 0;
//     int high = n - 1;
//     while(low <= high){
//         int mid = (low + high) / 2;
//         if(arr[mid] == target){
//             return mid;
//         }
//         else if(target > arr[mid]){
//             low = mid + 1;
//         }
//         else{
//             high = mid - 1;
//         }
//     }

//     return -1;
// }

// int main(){
//     int n; 
//     cin >> n;
//     vector<int> arr(n);
//     for(int i =0; i < n; i++){
//         cin >> arr[i];
//     }
//     int target;
//     cin >> target;
//     cout << "The index of the target element is : " << binarySearch(arr, n, target) << endl;
//     return 0;
// }

//Recursive function
#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int low, int high, int target){
    if(low > high) return -1;

    int mid = (low + high) /2;

    if(arr[mid] == target) return mid;

    else if (target > arr[mid]) return bs(arr, mid + 1, high, target);

    return bs(arr, low, mid - 1, target);

}

int search(vector<int> nums, int target){
    return bs(nums, 0, nums.size()-1, target);
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << "The index of the target element is : " << search(arr, target) << endl;
    return 0;
}

