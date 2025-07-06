#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
        int m = heights.size();
        int n = heights[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int adjR = row + dr[i];
                int adjC = col + dc[i];

                if (adjR >= 0 && adjR < m && adjC >= 0 && adjC < n) {
                    if (!vis[adjR][adjC] && heights[adjR][adjC] >= heights[row][col]) {
                        vis[adjR][adjC] = true;
                        q.push({adjR, adjC});
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> alt(n, vector<bool>(m, false));

        queue<pair<int, int>> qpac;
        queue<pair<int, int>> qalt;

        for (int i = 0; i < n; i++) {
            pac[i][0] = true;
            qpac.push({i, 0});

            alt[i][m - 1] = true;
            qalt.push({i, m - 1});
        }

        for (int j = 0; j < m; j++) {
            pac[0][j] = true;
            qpac.push({0, j});

            alt[n - 1][j] = true;
            qalt.push({n - 1, j});
        }

        bfs(heights, qpac, pac);
        bfs(heights, qalt, alt);

        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && alt[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> result = sol.pacificAtlantic(heights);

    cout << "Cells from which water can flow to both Pacific and Atlantic oceans:\n";
    for (const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]\n";
    }

    return 0;
}
