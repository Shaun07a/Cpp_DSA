#include <bits/stdc++.h>
using namespace std;

string removeOuterParenthesis(string s){
    string result = "";
    int level = 0;
    for(char ch : s){
        if(ch == '('){
            if(level > 0) result += ch;

            level++;
        }
        else if(ch == ')'){
            level--;
            if(level > 0) result += ch;

        }
    }

    return result;
}

int main(){
    string s;
    cin >> s;
    string ans = removeOuterParenthesis(s);
    cout << "The final answer is : " << ans;
}