#include <bits/stdc++.h>
using namespace std;



int secondLargest(vector<int> &arr, int n){
    int Largest = arr[0];
    int sLargest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > Largest){
            sLargest = Largest;
            Largest = arr[i];
        }

        if(arr[i] < Largest && arr[i] > sLargest){
            sLargest = arr[i];
        }
    }

    return sLargest;
}

int secondSmallest(vector<int> &arr, int n){
    int Smallest = arr[0];
    int sSmallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < Smallest){
            sSmallest = Smallest;
            Smallest = arr[i];
        }

        if(arr[i] != Smallest && arr[i] < sSmallest){
            sSmallest = arr[i];
        }
    }

    return sSmallest;
}


vector <int> getSecondOrderElements(int n, vector<int> &arr){
    int sLargest = secondLargest(arr, n);
    int sSmallest = secondSmallest(arr, n);

    return{sLargest, sSmallest};
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> order = getSecondOrderElements(n, arr);

    cout << "The second largest element is "
         << order[0]
         << " and the second smallest element is "
         << order[1] << endl;

    return 0;
}