#include <bits/stdc++.h>
using namespace std;

int LongestSub(string &s){
    int hash[256] = {-1};
    int l = 0, r = 0, maxlen = 0;
    int n = s.size();
    while(r < n){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        hash[s[r]] = r;
        maxlen = max(len, maxlen);
        r++;
    }

    return maxlen;
}

int main(){
    string s;
    cin >> s;
    cout << "The length of the longes substring without repeating characters is : " << LongestSub(s) << endl;
    return 0;
}