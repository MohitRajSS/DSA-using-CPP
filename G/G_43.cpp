#include<iostream>
#include<vector>

using namespace std;

int findCity(int n,int m,vector<vector<int>>&edges,int distanceThreshold){
    int dist[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=1e9;
        }
    }


    for(auto it:edges){
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]==1e9 || dist[k][j]==1e9)continue;
                dist[i][j]=min(dist[i][j],dist[i][k]);
            }
        }
    }
    int countCity=n;
    int cityNo=-1;
    for(int city=0;city<n;city++){
        int count=0;
        for(int adjCity=0;adjCity<n;adjCity++){
            if(dist[city][adjCity]<=distanceThreshold){
                count++;
            }
        }
        if(count<=countCity){
            countCity=count;
            cityNo=city;
        }
    }
    return cityNo;
}

int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	//Solution obj;
	int cityNo = findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}