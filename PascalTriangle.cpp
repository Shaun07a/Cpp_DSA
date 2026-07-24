#include <bits/stdc++.h>
using namespace std;

vector<int> GenerateTows(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i = 1; i <=n; i++){
        ans.push_back(GenerateTows(i));
    }

    return ans;
}

int main() {
    int n;

    cout << "Enter the number of rows: ";
    cin >> n;

    vector<vector<int>> triangle = pascalTriangle(n);

    cout << "Pascal Triangle:\n";

    for (auto &row : triangle) {
        for (auto &num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}