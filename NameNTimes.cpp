#include <bits/stdc++.h>
using namespace std;

void NameNTimes(int i , int n){
    if (i > n){
        return ;
    }

    cout << "Shaun" << endl;
    NameNTimes(i+1, n);
}

int main(){
    int i , n;
    cout << "Enter the value of i" << endl;
    cin >> i;
    cout << "Enter thr value of n" << endl;
    cin >> n;
    NameNTimes(i, n);
    return 0;
}