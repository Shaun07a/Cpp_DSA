#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int Rev_Num = 0;
     while(n != 0){
        int ld = n % 10;
        Rev_Num = (Rev_Num * 10) + ld;
        n = n / 10;
        
     }

     cout <<"The reverse of the number is :" << Rev_Num << endl;
}