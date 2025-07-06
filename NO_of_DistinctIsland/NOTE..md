# 🏝️ Count Distinct Islands - Approach and Complexity

## ✅ Problem Statement:
Given a 2D grid of `0s` and `1s`, count the number of **distinct islands**.  
Two islands are considered distinct if their **shapes** are different, regardless of their positions.

---

## 🚀 Approach:

1. **DFS Traversal**:
   - Use DFS to explore each unvisited land cell (`1`).
   - For each island, store the path using relative coordinates to its starting point.

2. **Relative Shape Tracking**:
   - Store each island's relative cell positions as a vector of pairs: `(row - row0, col - col0)`.
   - Add this vector to a set to automatically handle uniqueness.

3. **Visited Matrix**:
   - A 2D `visited` matrix ensures no land cell is visited more than once.

4. **Count Unique Shapes**:
   - The size of the set gives the count of distinct islands.

---

## ⏱️ Time Complexity:

Let `N = number of rows`, `M = number of columns` in the grid.

- **Grid Traversal**: `O(N × M)`
- **DFS Traversal**: Each cell is visited once → `O(N × M)`
- **Set Insertion**: For `K` islands of max size `L` → `O(K × L log K)` (amortized)

### 🔹 Total Time: `O(N × M + K × L log K)`

---

## 📌 Example:

```cpp
Input:
grid = {
  {1, 1, 0, 0, 0},
  {1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1},
  {0, 0, 0, 1, 1}
}

Output:
Number of distinct islands: 1

```











---

## 🧠 BFS Function Code:

```cpp
void bfs(int row0, int col0, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>>& shape) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row0, col0});
    visited[row0][col0] = 1;
    shape.push_back({0, 0});  // relative position

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !visited[nr][nc] && grid[nr][nc] == 1) {
                visited[nr][nc] = 1;
                q.push({nr, nc});
                shape.push_back({nr - row0, nc - col0});
            }
        }
    }
}
```
