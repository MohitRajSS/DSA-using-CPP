#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    distance[source.first][source.second] = 0;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++) {
            int delrow = r + drow[i];
            int delcol = col + dcol[i];

            if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m &&
                grid[delrow][delcol] == 1 && distance[delrow][delcol] > dis + 1) {
                distance[delrow][delcol] = dis + 1;
                if (delrow == destination.first && delcol == destination.second) {
                    return dis + 1;
                }
                q.push({dis + 1, {delrow, delcol}});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    pair<int, int> source = {0, 0};
    pair<int, int> destination = {0, 1};

    int result = shortestPath(grid, source, destination);
    cout << "The shortest path is: " << result << endl;

    return 0;
}
