#include <bits/stdc++.h>
using namespace std;

int MaxConsecutiveOnes(vector<int> &arr){
    int maxi = 0;
    int cnt = 0;
    for(int i = 0; i <arr.size(); i++){
        if(arr[i] == 1){
            cnt++;
            maxi = max(maxi, cnt);
        }else{
            cnt = 0;
        }
    }

    return maxi;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0; i< n - 1 ; i++){
        cin >> arr[i];
    }
    cout << "The maximum number of consecutive one's is  : " << MaxConsecutiveOnes(arr) << endl;
    return 0;
}