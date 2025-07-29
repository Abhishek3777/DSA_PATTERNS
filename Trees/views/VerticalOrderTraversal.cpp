/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            // step 1 create the map
            map<int, map<int, multiset<int>>> map; // vertical, level, values
            queue<pair<TreeNode*, pair<int, int>>> q;
            q.push({root, {0, 0}}); // node, vertical horizontal
    
            // perform bfs to mark nodes
    
            while (!q.empty()) {
                auto it = q.front();
                TreeNode* curr = it.first;
                int vertical = it.second.first;
                int horizontal = it.second.second;
                q.pop();
                // update in map
                map[vertical][horizontal].insert(curr->val);
    
                // push left -1, + 1
                if (curr->left) {
                    q.push({curr->left, {vertical - 1, horizontal + 1}});
                }
                if (curr->right) {
                    q.push({curr->right, {vertical + 1, horizontal + 1}});
                }
            }
            vector<vector<int>> ans;
            // take out from map
            for (auto p : map) {
                vector<int> col;
                for (auto q : p.second) {
                    col.insert(col.end(), q.second.begin(), q.second.end());
                }
                ans.push_back(col);
            }
            return ans;
        }
    };