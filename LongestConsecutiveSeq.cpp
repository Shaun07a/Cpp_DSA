#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &arr){
    if(arr.size() == 0) return 0;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int lastSmaller = INT_MIN;
    int longest = 1;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] - 1 == lastSmaller){
            cnt++;
            lastSmaller = arr[i];
        }
        else if(lastSmaller != arr[i]){
            cnt = 1;
            lastSmaller = arr[i];
        }

        longest = max(longest, cnt);
    }

    return longest;
        
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "The longest consecutive sequence within the array is : " << longestSuccessiveElements(arr) << endl;
    return 0;
}
    

//Optimal
// int longestSuccessiveElement(vector<int> arr){
//     int n = arr.size();
//     if(n==0) return 0;
//     int longest = 1;
//     unordered_set<int> st;
//     for(int i = 0; i < n; i++){
//         st.insert(arr[i]);
//     }

//     for(auto it : st){
//         if(st.find(it - 1) == st.end()){
//             int cnt = 1;
//             int x = it;
//             while(st.find(x+1) != st.end()){
//                 x = x + 1;
//                 cnt = cnt + 1;

//             }

//             longest = max(longest, cnt);
//         }
//     }

//     return longest;
// }