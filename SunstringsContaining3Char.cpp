#include <bits/stdc++.h>
using namespace std;

int TotalSubs(string &s){
    int lastseen[3] = {-1, -1, -1};
    int n = s.size();
    int cnt = 0;

    for(int i = 0; i < n; i++){
        lastseen[s[i] - 'a'] = i;

        if(lastseen[0] != -1 &&
           lastseen[1] != -1 &&
           lastseen[2] != -1){

            cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
        }
    }

    return cnt;
}

int main(){
    string s;
    cin >> s;

    cout << "The total number of substrings containing a, b and c is: "
         << TotalSubs(s) << endl;

    return 0;
}