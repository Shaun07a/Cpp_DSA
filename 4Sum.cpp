//Brute
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> fourSum(vector<int> &arr, int target){
//     int n = arr.size();
//     set<vector<int>> st;
//     for(int i = 0;i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 for(int l = k + 1; l < n; l++){
//                     long long sum = arr[i] + arr[j];
//                     sum += arr[k];
//                     sum += arr[l];
//                     if(sum == target){
//                         vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }               
//                 }
//             }
//         }
//     }

//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

//Better
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> fourSum(vector<int> &arr, int target) {
//     int n = arr.size();
//     set<vector<int>> st;

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {

//             unordered_set<int> hashset;

//             // Traverse from right to left
//             for (int k = n - 1; k > j; k--) {

//                 long long sum = 1LL * arr[i] + arr[j] + arr[k];
//                 long long fourth = 1LL * target - sum;

//                 if (hashset.find((int)fourth) != hashset.end()) {
//                     vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }

//                 hashset.insert(arr[k]);
//             }
//         }
//     }

//     return vector<vector<int>>(st.begin(), st.end());
// }

//Optimal
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0 ; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j<n; j++){
            if(j != i + 1 && arr[j] == arr[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target){
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
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

    int target;
    cin >> target;

    vector<vector<int>> ans = fourSum(arr, target);

    cout << "Quadruplets are:\n";

    for (auto &v : ans) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}