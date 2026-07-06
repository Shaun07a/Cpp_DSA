#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    //precompute
    int Hash[13] = {0};
    for(int i = 0; i < n ; i++){
            Hash[arr[i]] += 1;
    }

   
    int q;
    cin >> q;
    for(int i = 0; i < n; i++){
        int number;
        cin >> number;
        //fetch
        cout << Hash[number]<< endl;

    }

    return 0;


}