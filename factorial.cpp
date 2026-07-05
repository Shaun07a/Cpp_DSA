#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 0){
        return 1;
    }

    return n * fact(n-1);
}

int main(){
    int n = 5;
    cout << "Sum of first N numbers is : " << fact(n);
    return 0;
}