// #include <bits/stdc++.h>
// using namespace std;

// vector<int> rearrangeArray(vector<int> &arr){
//     int n = arr.size();
//     vector<int> ans(n,0);
//     int posIndex = 0, negIndex = 1;
//     for(int i = 0; i<n;i++){
//         if(arr[i]<0){
//             ans[negIndex] = arr[i];
//             negIndex += 2;
//         }else{
//             ans[posIndex] = arr[i];
//             posIndex += 2;
//         }
//     }

//     return ans;
// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     vector<int> ans = rearrangeArray(arr);

//     for(int x : ans){
//         cout << x << " ";
//     }

//     return 0;
// }

//optiml
#include <bits/stdc++.h>
using namespace std;

vector<int> alternateNumbers(vector<int> &arr){
    vector<int> pos,neg;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size();i++){
            arr[index] = pos[i];
            index++;
        }

    }
    else{
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;   
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> ans = alternateNumbers(arr);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

