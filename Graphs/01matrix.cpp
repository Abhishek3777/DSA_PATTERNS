## 🔢 Problem: 01 Matrix (LeetCode 542)
 Similar to Pacific Atlantic problem where we do the reverse
### 🧠 Problem Statement
Given a binary matrix `mat` of size `m x n`, return the distance of the nearest `0` for each cell. The distance between two adjacent cells is `1`.

---

### ✅ Optimized Approach: Multi-Source BFS

Instead of running BFS from each `1` (which leads to `O((m*n)^2)` complexity), we start BFS from all `0`s simultaneously. This way, we ensure each cell is visited once with the shortest distance calculated.

### 🧮 Time and Space Complexity
- **Time Complexity**: `O(m * n)`
- **Space Complexity**: `O(m * n)` (result matrix + BFS queue)

### 🧊 Key Concepts Used
- BFS (Breadth First Search)
- Multi-source BFSgit add .

- Queue for level-order traversal
- Direction arrays for 4-connected grid traversal

---

### 🧾 Code

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Push all 0s into the queue and mark their distances as 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    result[newRow][newCol] == -1) {
                    result[newRow][newCol] = result[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return result;
    }
};
