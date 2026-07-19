//Better Solution
// #include <bits/stdc++.h>
// using namespace std;

// int MajorityElement(vector<int> &arr){
//     int n = arr.size();
//     map<int, int> mpp;
//     for(int i = 0 ; i < n; i++){
//         mpp[arr[i]]++;
//     }

//     for(auto it : mpp){
//         if(it.second > arr.size()/2){
//             return it.first;
//         }
//     }

//     return -1;
// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i< n; i++){
//         cin >> arr[i];
//     }

//     int major = MajorityElement(arr);
//     cout << "The element that appears more time than the size of the array is : " << major << endl;
//     return 0;
// }


//Optimal solution
#include <bits/stdc++.h>
using namespace std;

int MajorityElement(vector<int> &arr){
    int n = arr.size();
    int el;
    int cnt = 0;
    for(int i = 0 ; i < n; i++){
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        }
        else if(el == arr[i]){
            cnt++;
        }else{
            cnt--;
        }
    }

    int cnt1 = 0;
    for(int j = 0; j < n; j++){
        if(el = arr[j]){
            cnt1++;
        }

        if(cnt1 > n/2){
            return cnt1;
        }
    }

    return  -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }

    int major = MajorityElement(arr);
    cout << "The the number of times the majority element appears more time than the size of the array is : " << major << endl;
    return 0;
}