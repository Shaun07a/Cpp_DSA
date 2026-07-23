// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> zeroMatrix(vector<vector<int>>matrix, int n, int m){
//     int row[n] = {0};
//     int col[m] = {0};
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(matrix[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;

//             }
//         }
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(row[i] || col[j]){
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     return matrix;

// }

// int main(){
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> matrix(n, vector<int> (m));
//     for(int i = 0; i < n;i++){
//         for(int j = 0; j < m ; j++){
//             cin >> matrix[i][j];
//         }
//     }

//     vector<vector<int>> zero = zeroMatrix(matrix, n, m);
//     for(int i = 0; i < n;i++){
//         for(int j = 0; j < m ; j++){
//             cout << zero[i][j] << " ";
//         }

//         cout << endl;
//     }

    

//     return 0;

// }

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>>matrix, int n, int m){
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
            

                if(j != 0){
                    matrix[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m;j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j = 0; j<m;j++){
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0){
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;

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

    vector<vector<int>> zero = zeroMatrix(matrix, n, m);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m ; j++){
            cout << zero[i][j] << " ";
        }

        cout << endl;
    }

    

    return 0;

}