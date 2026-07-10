//Brute Force
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findArrayIntersection(vector<int> &A, int n,  vector<int> &B, int m){
//     vector<int> ans;
//     int vis[m] = {0};
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(A[i] == B[j] && vis[j] == 0){
//                 ans.push_back(A[i]);
//                 vis[j] = 1;
//                 break;
//             }
//             if(B[j] > A[i]) break;
//         }
//     }

//     return ans;
// }

// int main() {

//     int n, m;
//     cin >> n >> m;

//     vector<int> A(n), B(m);

//     // Input first array
//     for (int i = 0; i < n; i++) {
//         cin >> A[i];
//     }

//     // Input second array
//     for (int i = 0; i < m; i++) {
//         cin >> B[i];
//     }

//     vector<int> ans = findArrayIntersection(A, n, B, m);

//     for (int x : ans) {
//         cout << x << " ";
//     }

//     return 0;
// }

//optimal

#include <bits/stdc++.h>
using namespace std;

vector<int> findArrayIntersection(vector<int> &A, int n,  vector<int> &B, int m){
    int i = 0;
    int j = 0;

    vector<int> ans;
    while(i<n and j <n){
        if(A[i] < B[j]){
            i++;
        }
        else if(B[j] < A[i]){
            j++;
        }

        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }


    }
    
    return ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);

    // Input first array
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Input second array
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> ans = findArrayIntersection(A, n, B, m);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}