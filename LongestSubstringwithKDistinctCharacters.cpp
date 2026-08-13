#include <bits/stdc++.h>
using namespace std;

int Maxlength(string &s, int k){
    int maxlen = 0, l = 0, r =0;
    map<char, int> mpp;
    int n = s.size();
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l = l + 1;
        }

        if(mpp.size() <= k){
            maxlen = max(maxlen, r - l + 1);
            
        }

        r =  r + 1;
        
    }

    return maxlen;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << "The maximum length of the substring with k distinct is :" << Maxlength(s, k) << endl;
    return 0;
}