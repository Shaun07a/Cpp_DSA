// #include <bits/stdc++.h>
// using namespace std;

// void leftRotateArray(vector<int> &arr, int n, int d) {

//     d = d % n;

//     vector<int> temp(d);

//     // Store first d elements
//     for (int i = 0; i < d; i++) {
//         temp[i] = arr[i];
//     }

//     // Shift remaining elements left
//     for (int i = d; i < n; i++) {
//         arr[i - d] = arr[i];
//     }

//     // Copy temp elements to the end
//     for (int i = n - d; i < n; i++) {
//         arr[i] = temp[i - (n - d)];
//     }
// }

// int main() {

//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int d;
//     cin >> d;

//     leftRotateArray(arr, n, d);

//     for (int x : arr) {
//         cout << x << " ";
//     }

//     return 0;
// }

// for rignt rotate : n - k

// optimal solution in perspective of space complexity
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void leftRotateArray(int arr[], int n, int d) {

    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d;
    cin >> d;

    leftRotateArray(arr, n, d);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}

//reverse function
// void Reverse(int arr[], int start, int end){
//     while(start < end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }