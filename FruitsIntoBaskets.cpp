#include <bits/stdc++.h>
using namespace std;

int MaxLength(vector<int> &arr, int k) {
    int l = 0, r = 0;
    int maxlen = 0;

    map<int, int> mpp;

    while (r < arr.size()) {

        // Add current fruit
        mpp[arr[r]]++;

        // More than k different fruits
        while (mpp.size() > k) {

            mpp[arr[l]]--;

            if (mpp[arr[l]] == 0) {
                mpp.erase(arr[l]);
            }

            l++;
        }

        // Valid window
        maxlen = max(maxlen, r - l + 1);

        r++;
    }

    return maxlen;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << "Maximum length: " << MaxLength(arr, k) << endl;

    return 0;
}