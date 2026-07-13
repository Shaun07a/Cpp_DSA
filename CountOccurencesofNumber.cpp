// #include <bits/stdc++.h>
// using namespace std;

// int lowerBound(vector<int> &arr, int n, int x){
//     int low = 0;
//     int high = n - 1;
//     int ans = n;
//     while(low <= high){
//         int mid = (low + high) / 2;
//         if(arr[mid]>= x){
//             ans = mid;
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// int upperBound(vector<int> &arr, int n, int x){
//     int low = 0;
//     int high = n - 1;
//     int ans = n;
//     while(low <= high){
//         int mid = (low + high) / 2;
//         if(arr[mid]> x){
//             ans = mid;
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }

//     return ans;
// }

// pair <int, int> firstandlastoccurence(vector<int> &arr, int n, int k){
//     int lb = lowerBound(arr, n, k);
//     if(lb == n || arr[lb] != k) return {-1, -1};
//     return {lb, upperBound(arr, n, k) - 1};
// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i<n;i++){
//         cin >> arr[i];
//     }
//     int target;
//     cin >> target;
//     pair<int,int> ans = firstandlastoccurence(arr, n, target);

//     cout << ans.first << " " << ans.second << endl;

//     return 0;
// }


//second approach
#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            first = mid;
            high = mid - 1;
        }else if(arr[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurence(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int last = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            last = mid;
            low = mid + 1;
        }else if(arr[mid] < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return last;
}

pair <int, int> firstandlastoccurence(vector<int> &arr, int n, int k){
    int first = firstOccurence(arr, n, k);
    if(first == -1) return {-1, -1};
    int last = lastOccurence(arr, n, k);
    return {first, last};
}

int count(vector<int> &arr, int n , int k){
    pair<int, int> count = firstandlastoccurence(arr, n, k);
    if(count.first == -1) return 0;
    return count.second - count.first + 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int ans = count(arr, n, target);

    cout << "The count of target is : " << ans << endl;

    return 0;
}