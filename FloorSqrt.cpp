#include <bits/stdc++.h>
using namespace std;

int FloorSqrt(int n){
    int low = 1;
    int high = n - 1;
    int ans = 1;
    while(low <= high){
        int mid = (low+high)/2;
        if((mid*mid) <= n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;

}

int main(){
    int n;
    cin>>n;
    int ans = FloorSqrt(n);
    cout << "The maximum element whose sqrt is closest to n is : " << ans << endl;
    return 0;
}