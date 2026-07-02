// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     int n;
//     cout << "Enter a decimal number :";
//     cin >> n;

//     int ans = 0;
//     int i = 0;
//     while(n!=0){
//         int bit = n & 1;

//         ans = (bit * pow(10,i)) + ans;

//         n = n >> 1;
//         i++;
//     }

//     cout << "Answer is :" <<  ans << endl;
// }

//Decimal to Binary

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     int ans = 0;
//     int place = 1;

//     while (n != 0) {
//         int bit = n & 1;
//         ans += bit * place;
//         place *= 10;
//         n >>= 1;
//     }

//     cout << ans;
// }

//Negative Decimal to Binary
// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 31; i >= 0; i--) {
//         cout << ((n >> i) & 1);
//     }

//     cout << endl;

//     return 0;
// }

//Binary to Decimal
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 0, ans = 0;

    while(n!=0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2, i);
        }

        n = n / 10;
        i++;
    }

    cout << ans << endl;
}