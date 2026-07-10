#include <bits/stdc++.h>
using namespace std;

int linearsearch(int n, int num, vector <int> &arr){
    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            return i;
        }
    }

    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    
    int num; 
    cin >> num;

    cout << "The index of the particular number is : " << linearsearch(n, num, arr)<< endl;
    return 0;
}