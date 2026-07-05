#include <bits/stdc++.h>
using namespace std;

void NumberNTimes(int i , int n){

    if (i > n){
        return ;
    }
    cout << i << endl;

    NumberNTimes(i+1, n);
}

int main(){
    int i , n;
    cout << "Enter the value of i" << endl;
    cin >> i;
    cout << "Enter thr value of n" << endl;
    cin >> n;
    NumberNTimes(i, n);
    return 0;
}