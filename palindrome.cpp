#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int rev = 0;
    int dup = n;
    while(dup!=0){
        int last_digit = dup % 10;
        rev = (rev * 10) + last_digit;
        dup = dup / 10;
    }

    if (rev == n){
        cout << "The number is a palindrome" << endl;

    }else{
        cout << "It is not a palindrome" << endl;
    }

}