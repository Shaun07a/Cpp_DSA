#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n <= 1){
        return n;
    }

    int first = f(n-1);
    int last = f(n-2);

    return first + last;
}

int main(){
    
    cout << f(4);
    return 0;
}