// We are given an “N*M” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix,
// such that there is a minimum cost past that we select.
#include<iostream>
#include<vector>
using namespace std;

int min_path_sum(vector<vector<int>>&grid,int m,int n){
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<m,i++){
        for(int j=1;j<n;j++){
            int up=0;
            if(i>0){
                up+=dp[i-1][j];
            }else{
                up+=INT_MAX;
            }
            int left=0;
            if(j>0){
                left+=dp[i][j-1];
            }else{
                left+=INT_MAX;
            }
            dp[i][j]=min(up,left);
        }
    }
    return dp[m-1][n-1];
}

int main(){

    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    cout<<min_path_sum(matrix,n,m);
    return 0;
}