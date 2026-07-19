#include <bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int Div){
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + ceil((double)arr[i] / (double)Div);
    }

    return sum;
}

int smallestDivisor(vector<int> &arr, int limit){
    int low = 1, high = *max_element(arr.begin(), arr.end());
    while(low<=high){
        int mid = (low + high) / 2;
        if(sumByD(arr, mid) <= limit){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return low;

}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int thresh;
    cin >> thresh;
    cout << "The samllest divisor which is the smaller than the threshold is : " << smallestDivisor(arr, thresh) << endl;
    return 0;

}