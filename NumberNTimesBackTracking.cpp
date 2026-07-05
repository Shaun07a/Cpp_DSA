#include <bits/stdc++.h>
using namespace std;

void NumNTimesBackTracking(int i , int n){

    if (i < 1){
        return ;
    }

    NumNTimesBackTracking(i-1, n);
    cout << i << endl;
    
    
}

int main(){
    int i , n;
    cout << "Enter the value of i" << endl;
    cin >> i;
    cout << "Enter thr value of n" << endl;
    cin >> n;
    NumNTimesBackTracking(n, n);
    return 0;
}