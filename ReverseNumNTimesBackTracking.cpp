#include <bits/stdc++.h>
using namespace std;

void ReverseNumberNTimesBackTracking(int i , int n){

    if (i > n){
        return ;
    }

    ReverseNumberNTimesBackTracking(i+1, n);
    cout << i << endl;

    
}

int main(){
    int i , n;
    cout << "Enter the value of i" << endl;
    cin >> i;
    cout << "Enter thr value of n" << endl;
    cin >> n;
    ReverseNumberNTimesBackTracking(i, n);
    return 0;
}