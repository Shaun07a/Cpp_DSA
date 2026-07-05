#include <bits/stdc++.h>
using namespace std;

void ReverseNumNTimes(int i , int n){

    if (i < 1){
        return ;
    }
    cout << i << endl;
    
    ReverseNumNTimes(i-1, n);
}

int main(){
    int i , n;
    cout << "Enter the value of i" << endl;
    cin >> i;
    cout << "Enter thr value of n" << endl;
    cin >> n;
    ReverseNumNTimes(n, n);
    return 0;
}