#include <bits/stdc++.h>
using namespace std;

void ReverseMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i = 0; i < n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}


int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m ; j++){
            cin >> matrix[i][j];
        }
    }

    ReverseMatrix(matrix);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m ; j++){
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    

    return 0;

}