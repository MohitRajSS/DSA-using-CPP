#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<int>>& visited, int delrow[], int delcol[]) {
    visited[i][j] = 1;
    int n = mat.size();
    int m = mat[0].size();
    for (int k = 0; k < 4; k++) {
        int row = i + delrow[k];
        int col = j + delcol[k];
        if (row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && mat[row][col] == 'O') {
            dfs(row, col, mat, visited, delrow, delcol);
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, 1, 0}; 
    int delcol[] = {0, 1, 0, -1}; 
    for (int i = 0; i < m; i++) {
        if (!visited[0][i] && mat[0][i] == 'O') {
            dfs(0, i, mat, visited, delrow, delcol); 
        }
        if (!visited[n - 1][i] && mat[n - 1][i] == 'O') {
            dfs(n - 1, i, mat, visited, delrow, delcol);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i][0] && mat[i][0] == 'O') {
            dfs(i, 0, mat, visited, delrow, delcol); 
        }
        if (!visited[i][m - 1] && mat[i][m - 1] == 'O') {
            dfs(i, m - 1, mat, visited, delrow, delcol); 
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && mat[i][j] == 'O') {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}

int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<char>> result = fill(n, m, mat);

    for (auto row : result) {
        for (auto ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
