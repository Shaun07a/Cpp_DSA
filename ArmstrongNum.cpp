#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dup = n;
    int rev = 0;
    int sum = 0;
    while(n !=0){
        int ld = n % 10;
        sum = sum + (ld * ld *ld);
        n = n / 10;

    }

    if(sum == dup ){
        cout << "It is an armstrong number" << endl;
    }else{
        cout<<"It is not an armstrong number"<< endl;
    }
}