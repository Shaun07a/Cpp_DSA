//Better
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findMissingRepastingNumbers(vector<int> &arr){
//     int n = arr.size();
//     int hash[n+1] = {0};
//     for(int i = 0; i < n; i++){
//         hash[arr[i]]++;
//     }

//     int repeating = -1, missing = -1;
//     for(int i = 1; i < n; i++){
//         if(hash[i] == 2) repeating = i;
//         else if(hash[i] == 0) missing = 0;
        
//         if(repeating != -1 && missing != -1){
//             break;
//         }
//     }

//     return {repeating, missing};
// }

// Optimal Solution (Math Solution)
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> findMissingRepeatingNumbers(vector<int> &arr){
//     long long n = arr.size();
//     long long SN = (n * (n + 1) )/ 2;
//     long long S2N = (n * (n+1) * (2*n+1)) / 2;
//     long long S = 0, S2 = 0;
//     for(int i = 0; i < n; i++){
//         S += arr[i];
//         S2 += (long long)arr[i] * (long long)arr[i];
//     }

//     long long val1 = S - SN;
//     long long val2 = S2 - S2N;
//     val2 = val2/val1;
//     long long x = (val1 + val2) / 2;
//     long long y = x - val1;
//     return {(int)x, (int)y};
// }

// Optimal Solution 2(XOR Solution)
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumber(vector<int> &arr){
    long long n = arr.size();
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }

    // int bitNo = 0;
    // while(1){
    //     if((xr & (1<<bitNo)) != 0){
    //         break;
    //     }
            
    //     bitNo++;
        
    // }

    int number = xr & ~(xr - 1); // bit manipulation
    int zero = 0;
    int one = 0;
    for(int i = 0; i < n; i++){
        if((arr[i] & (1<<number)) != 0){
            one = one ^ arr[i];
        }else{
            zero = zero ^ arr[i];
        }
    }

    for(int i = 1; i <=n; i++){
         if((i & (1<<number)) != 0){
            one = one ^ i;
        }else{
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == zero) cnt++;
    }

    if(cnt == 2) return {zero, one};
    return {one, zero};
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> MissingRepeating = findMissingRepeatingNumber(arr);
    cout << "The missing and Repeating Numbers are : " << endl;
    for(int i : MissingRepeating){
        cout << i << " ";
    }
    return 0;
}